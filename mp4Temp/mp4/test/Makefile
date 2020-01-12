CC = clang

# Change this to your llvm object code tree
MP4LLVMOBJROOT = /class/cs426/llvm/llvm-9.0.0.obj
OPT = opt -load ${MP4LLVMOBJROOT}/lib/LLVMMP4.so

# Change this to run whatever optimization passes you want
OPTS = -mem2reg -instcombine -simplifycfg -adce -inline -globaldce -sroa -early-cse -sccp -jump-threading -correlated-propagation -simplifycfg -instcombine -simplifycfg -reassociate -scalar-evolution -licm -adce -simplifycfg -instcombine -globaldce

# Make a .ll file from a .bc file, using llvm-dis
%.ll: %.bc
	llvm-dis < $< > $@

# Make a .bc file from a .c file by running through clang, with
# optimizations turned off, and then running a few basic optimizations.
# 
%.bc: %.c
	$(CC) -c -O0 -emit-llvm $< -o - | opt -globaldce -mem2reg -instcombine -constprop  > $@

# Run the optimizations specified in OPTS
%-opt.bc: %.bc
	$(OPT) $(OPTS) < $< > $@

clean :
	rm -f *.bc *.ll
