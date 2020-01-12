#include "llvm/IR/Function.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Operator.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/LoopPass.h"

 #include "llvm/Analysis/ValueTracking.h"
 #include "llvm/ADT/Optional.h"
 #include "llvm/ADT/SmallPtrSet.h"
 #include "llvm/Analysis/AssumptionCache.h"
 #include "llvm/Analysis/InstructionSimplify.h"


#include "llvm/Transforms/Utils/LoopUtils.h"
#include "llvm/Transforms/Scalar.h"
#include <iostream>
using namespace llvm;

namespace {
  class LICM : public LoopPass {
  private:
    Loop *curLoop;
    LoopInfo * LI;
    DominatorTree * DT;
    bool changed = false;
    BasicBlock * Preheader;

  public:
    static char ID; // Pass identification, replacement for typeid

    LICM() : LoopPass(ID) {}

    bool runOnLoop(Loop *L, LPPassManager &LPM) override {
	curLoop = L;
	return doLICM();
    }

    /// This transformation requires natural loop information & requires that
    /// loop preheaders be inserted into the CFG...
    //
    // !!! PLEASE READ getLoopAnalysisUsage(AU) defined in
    // !!! lib/Transforms/Utils/LoopUtils.cpp
    void getAnalysisUsage(AnalysisUsage &AU) const override {

      AU.addRequired<DominatorTreeWrapperPass>();
      AU.addPreserved<DominatorTreeWrapperPass>();
      AU.addRequired<LoopInfoWrapperPass>();
      AU.addPreserved<LoopInfoWrapperPass>();



      // We must also preserve LoopSimplify and LCSSA. We locally access their IDs
      // here because users shouldn't directly get them from this header.
/*
      AU.addRequired<DominatorTree>();
      AU.addPreserved<DominatorTree>();
      AU.addRequired<LoopInfo>();
      AU.addPreserved<LoopInfo>();
*/
      //extern char &LoopSimplifyID;
      //AU.addRequiredID(LoopSimplifyID);
      //AU.addPreservedID(LoopSimplifyID);


      //AU.setPreservesAll();
      //AU.addPreserved<DominatorTreeWrapperPass>();
      //AU.addPreserved<LoopInfoWrapperPass>();
      //AU.addRequiredID(ID);
      //AU.addRequired<LoopInfo>();
      //AU.addRequired<DominatorTree>();

      getLoopAnalysisUsage(AU);
    }

  private:
    bool doLICM();

    bool safeToHoist(Instruction &Inst){
    if (isSafeToSpeculativelyExecute(&Inst))
      return true;
    return computed(Inst);
 }

 bool isLoopInvariant(Instruction &Inst){
   // && !isa<CmpInst>(Inst) &&!isa<InsertElementInst>(Inst)
   // && !isa<ExtractElementInst>(Inst) && !isa<ShuffleVectorInst>(Inst)
   // && !isa<ExtractValueInst>(Inst) && !isa<InsertValueInst>(Inst))
  if (!isa<BinaryOperator>(Inst) && !(Inst.isShift())
  && !isa<SelectInst>(Inst) && !isa<CastInst>(Inst)
   && !isa<GetElementPtrInst>(Inst))
     return false;

     for (unsigned i = 0; i < Inst.getNumOperands(); i++){
       if (!dyn_cast<Constant>(Inst.getOperand(i))){
       if (Instruction *I = dyn_cast<Instruction>(Inst.getOperand(i))){
         if(curLoop->contains(I) ){
           return false;
         }

       }else{
         return false;
       }

     }
   }
     return true;
   }

   bool computed(Instruction &I){
     if (I.getParent() == curLoop->getHeader())
       return true;
     SmallVector<BasicBlock*, 8> ExitBlocks;
     curLoop->getExitBlocks(ExitBlocks);
     for (unsigned i = 0; i < ExitBlocks.size(); i++){
       if (!DT->dominates(I.getParent(), ExitBlocks[i]))
         return false;
      }
     if (ExitBlocks.empty())
       return false;
     return true;
   }

   void Hoist(DomTreeNode * hd){
     BasicBlock *BB = hd->getBlock();
     if (!curLoop->contains(BB)) return;
     if (LI->getLoopFor(BB) == curLoop){
       for (BasicBlock::iterator IT = BB->begin(); IT != BB->end();) {
             Instruction &I = *IT;
             IT++;
             if (isLoopInvariant(I) && safeToHoist(I)){
               I.moveBefore(Preheader->getTerminator());
               changed = true;
             }

          }
     }

     const std::vector<DomTreeNode*> &Children = hd->getChildren();
     for (unsigned i = 0, e = Children.size(); i != e; i++)
            Hoist(Children[i]);
   }


  };
}

char LICM::ID = 0;
RegisterPass<LICM> X("wentaoy2-licm", "Loop Invariant Code Motion (MP4)",
		     false /* Only looks at CFG? */,
		     false /* Analysis Pass? */);



// Implement LICM algorithm here
bool LICM::doLICM()
{
  //errs() << "hello!" << "\n";
  //std::cout << "hello!" << "\n";
  //LI = &getAnalysis<LoopInfo>();
  //DT = &getAnalysis<DominatorTree>();
DT = &getAnalysis<DominatorTreeWrapperPass>().getDomTree();
LI = &getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
  Preheader = curLoop->getLoopPreheader();
  DomTreeNode * hd = DT->getNode(curLoop->getHeader());
  Hoist(hd);
  return changed;
}
