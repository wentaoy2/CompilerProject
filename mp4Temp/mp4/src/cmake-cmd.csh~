#/bin/csh -f
#------------------------------------------------------------------------------
# cmake command line to configure LLVM builds
#------------------------------------------------------------------------------

#Only these variables need to be edited for each LLVM tree
set LLVMROOT = /class/cs426/llvm
set LLVMSRCROOT = ${LLVMROOT}/llvm-9.0.0.src
set LLVMOBJROOT = ${LLVMROOT}/llvm-9.0.0.obj

cmake -G "Unix Makefiles" \
	-DCMAKE_C_COMPILER=/class/cs426/GCC/bin/gcc \
	-DCMAKE_CXX_COMPILER=/class/cs426/GCC/bin/g++ \
	-DCMAKE_INSTALL_PREFIX=${LLVMOBJROOT} \
	-DCMAKE_BUILD_TYPE=RelWithDebInfo \
	-DLLVM_ENABLE_ASSERTIONS=On \
	-DBUILD_SHARED_LIBS=On \
	-DLLVM_TARGETS_TO_BUILD=X86 \
	${LLVMSRCROOT}

