#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Type.h"
#include "llvm/ADT/DepthFirstIterator.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/Transforms/Utils/Local.h"
#include <set>
#include <vector>
#include <iostream>

using namespace llvm;

namespace {
  //===-------------------------------------------------------------------===//
  // ADCE Class
  //
  // This class does all of the work of Aggressive Dead Code Elimination.
  //
  class ADCE : public FunctionPass {
  private:
    Function *Func;                      // Function we are working on
    std::vector<Instruction*> WorkList;  // Instructions that just became live
    std::set<Instruction*>    LiveSet;   // Set of live instructions

    //===-----------------------------------------------------------------===//
    // The public interface for this class
    //
  public:
    static char ID; // Pass identification
    ADCE() : FunctionPass(ID) {}

    // Execute the Aggressive Dead Code Elimination algorithm on one function
    //
    bool runOnFunction(Function &F) override {
      Func = &F;
      bool Changed = doADCE();
      assert(WorkList.empty());
      LiveSet.clear();
      return Changed;
    }

    // getAnalysisUsage
    //
    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.setPreservesCFG();
    }

  private:
    // doADCE() - Run the Aggressive Dead Code Elimination algorithm, returning
    // true if the function was modified.
    //
    bool doADCE();
    void markLive(Instruction *I) {
        if (!LiveSet.insert(I).second) return;
        WorkList.push_back(I);
      }
  };
}  // End of anonymous namespace

char ADCE::ID = 0;
static RegisterPass<ADCE> X("wentaoy2-adce", "Aggressive Dead Code Elimination (MP4)",
			    false /* Only looks at CFG? */,
			    false /* Analysis Pass? */);

// Implement ADCE algorithm here
bool ADCE::doADCE()
{
  df_iterator_default_set<BasicBlock*> Reachable;
  for (BasicBlock* BBT : depth_first_ext(Func, Reachable)) {
	   BasicBlock * BB =  BBT;

	    for (BasicBlock::iterator IT = BB->begin(); IT != BB->end(); ) {
	      Instruction *I = &*IT;
        IT++;
	      //a volatileload, or astore, call, unwind,or free
        //isa<CallBase>(I)
	      if (I->mayHaveSideEffects() || isa<CallBase>(I) || I->isTerminator() || I->mayWriteToMemory()
        || (isa<LoadInst>(I) && dyn_cast<LoadInst>(I)->isVolatile())
      ) {
	        markLive(I);
	      }

	      else if (isInstructionTriviallyDead(I)) {

	        //BB->getInstList().erase(IT);
          I->eraseFromParent();
	      }
	    }
	  }

    std::set<BasicBlock*> AliveBlocks;
    while (!WorkList.empty()) {
        Instruction *I = WorkList.back();
        WorkList.pop_back();

        BasicBlock *BB = I->getParent();
        if (!Reachable.count(BB))
          continue;
          for (unsigned i = 0; i <I->getNumOperands(); i++)
            if (Instruction *Operand = dyn_cast<Instruction>(I->getOperand(i)))
              markLive(Operand);
      }


      for (auto BT = Func->begin(); BT != Func->end(); BT++)
      {
        BasicBlock *BB = &*BT;
        if (!Reachable.count(BB))
          continue;
          for (BasicBlock::iterator IT = BB->begin(); IT != BB->end();) {
    	      Instruction *I = &*IT;
            IT++;
            if (!LiveSet.count(I)){
              I->dropAllReferences();
            }
          }
        }

        for (auto BT = Func->begin(); BT != Func->end(); BT++)
        {
          BasicBlock *BB = &*BT;
          if (!Reachable.count(BB))
            continue;
            for (BasicBlock::iterator IT = BB->begin(); IT != BB->end();) {
      	      Instruction *I = &*IT;
              IT++;
              if (!LiveSet.count(I)){
                I->eraseFromParent();
              }
            }
          }

          //remove blocks???

      return !WorkList.empty();

  //return false;
}
