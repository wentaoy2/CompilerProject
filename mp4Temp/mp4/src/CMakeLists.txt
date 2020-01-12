add_llvm_library( LLVMMP4 MODULE
  ADCE.cpp
  LICM.cpp

  DEPENDS
  intrinsics_gen
  PLUGIN_TOOL
  opt
  )
