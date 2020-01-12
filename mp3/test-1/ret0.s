	.text
	.file	"ret0.ll"
	.globl	Main_main               # -- Begin function Main_main
	.p2align	4, 0x90
	.type	Main_main,@function
Main_main:                              # @Main_main
	.cfi_startproc
# %bb.0:                                # %entry
	xorl	%eax, %eax
	testb	%al, %al
	jne	.LBB0_2
# %bb.1:                                # %true.0
	movl	$27, -4(%rsp)
	movl	-4(%rsp), %eax
	retq
.LBB0_2:                                # %false.1
	movl	$0, -4(%rsp)
	movl	-4(%rsp), %eax
	retq
.Lfunc_end0:
	.size	Main_main, .Lfunc_end0-Main_main
	.cfi_endproc
                                        # -- End function
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	Main_main
	movl	%eax, %ecx
	movl	$.str, %edi
	xorl	%eax, %eax
	movl	%ecx, %esi
	callq	printf
	xorl	%eax, %eax
	popq	%rcx
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	.str,@object            # @.str
	.section	.rodata,"a",@progbits
	.globl	.str
	.p2align	4
.str:
	.asciz	"Main.main() returned %d\n"
	.size	.str, 25


	.section	".note.GNU-stack","",@progbits
