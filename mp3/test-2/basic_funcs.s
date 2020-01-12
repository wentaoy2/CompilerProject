	.text
	.file	"basic_funcs.ll"
	.globl	main                    # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	callq	Main_new
	movq	%rax, %rdi
	callq	Main_main
	xorl	%eax, %eax
	popq	%rcx
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.globl	Main_main               # -- Begin function Main_main
	.p2align	4, 0x90
	.type	Main_main,@function
Main_main:                              # @Main_main
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movq	%rdi, (%rsp)
	testq	%rdi, %rdi
	je	.LBB1_13
# %bb.1:                                # %tmp.0
	movq	(%rdi), %rax
	callq	*32(%rax)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_13
# %bb.2:                                # %tmp.2
	movq	(%rdi), %rcx
	movq	%rax, %rsi
	callq	*48(%rcx)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_13
# %bb.3:                                # %tmp.4
	movq	(%rdi), %rax
	movl	$879, %esi              # imm = 0x36F
	callq	*56(%rax)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_13
# %bb.4:                                # %tmp.6
	movq	(%rdi), %rax
	callq	*32(%rax)
	testq	%rax, %rax
	je	.LBB1_13
# %bb.5:                                # %tmp.8
	movq	(%rax), %rcx
	movl	$String.1, %esi
	movq	%rax, %rdi
	callq	*56(%rcx)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_13
# %bb.6:                                # %tmp.10
	movq	(%rdi), %rcx
	movq	%rax, %rsi
	callq	*48(%rcx)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_13
# %bb.7:                                # %tmp.12
	movq	(%rdi), %rax
	callq	*32(%rax)
	testq	%rax, %rax
	je	.LBB1_13
# %bb.8:                                # %tmp.14
	movq	(%rax), %rcx
	movq	%rax, %rdi
	callq	*48(%rcx)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_13
# %bb.9:                                # %tmp.16
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_13
# %bb.10:                               # %tmp.18
	movq	(%rdi), %rax
	callq	*32(%rax)
	testq	%rax, %rax
	je	.LBB1_13
# %bb.11:                               # %tmp.20
	movq	(%rax), %rcx
	movl	$2, %esi
	movl	$2, %edx
	movq	%rax, %rdi
	callq	*64(%rcx)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_13
# %bb.12:                               # %tmp.22
	movq	(%rdi), %rcx
	movq	%rax, %rsi
	callq	*48(%rcx)
	movq	(%rsp), %rax
	popq	%rcx
	retq
.LBB1_13:                               # %abort
	callq	abort
.Lfunc_end1:
	.size	Main_main, .Lfunc_end1-Main_main
	.cfi_endproc
                                        # -- End function
	.globl	Main_new                # -- Begin function Main_new
	.p2align	4, 0x90
	.type	Main_new,@function
Main_new:                               # @Main_new
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	Main_vtable_prototype+4(%rip), %edi
	callq	malloc
	movq	$Main_vtable_prototype, (%rax)
	movq	%rax, (%rsp)
	popq	%rcx
	retq
.Lfunc_end2:
	.size	Main_new, .Lfunc_end2-Main_new
	.cfi_endproc
                                        # -- End function
	.type	str.Object,@object      # @str.Object
	.section	.rodata,"a",@progbits
str.Object:
	.asciz	"Object"
	.size	str.Object, 7

	.type	Object_vtable_prototype,@object # @Object_vtable_prototype
	.globl	Object_vtable_prototype
	.p2align	4
Object_vtable_prototype:
	.long	0                       # 0x0
	.long	(0+8)&-1
	.quad	str.Object
	.quad	Object_new
	.quad	Object_abort
	.quad	Object_type_name
	.quad	Object_copy
	.size	Object_vtable_prototype, 48

	.type	str.Int,@object         # @str.Int
str.Int:
	.asciz	"Int"
	.size	str.Int, 4

	.type	Int_vtable_prototype,@object # @Int_vtable_prototype
	.globl	Int_vtable_prototype
	.p2align	4
Int_vtable_prototype:
	.long	1                       # 0x1
	.long	(0+16)&-1
	.quad	str.Int
	.quad	Int_new
	.quad	Object_abort
	.quad	Object_type_name
	.quad	Object_copy
	.size	Int_vtable_prototype, 48

	.type	str.Bool,@object        # @str.Bool
str.Bool:
	.asciz	"Bool"
	.size	str.Bool, 5

	.type	Bool_vtable_prototype,@object # @Bool_vtable_prototype
	.globl	Bool_vtable_prototype
	.p2align	4
Bool_vtable_prototype:
	.long	2                       # 0x2
	.long	(0+16)&-1
	.quad	str.Bool
	.quad	Bool_new
	.quad	Object_abort
	.quad	Object_type_name
	.quad	Object_copy
	.size	Bool_vtable_prototype, 48

	.type	str.String,@object      # @str.String
str.String:
	.asciz	"String"
	.size	str.String, 7

	.type	String_vtable_prototype,@object # @String_vtable_prototype
	.globl	String_vtable_prototype
	.p2align	4
String_vtable_prototype:
	.long	3                       # 0x3
	.long	((0+8)&-1)*2
	.quad	str.String
	.quad	String_new
	.quad	Object_abort
	.quad	Object_type_name
	.quad	Object_copy
	.quad	String_length
	.quad	String_concat
	.quad	String_substr
	.size	String_vtable_prototype, 72

	.type	str.IO,@object          # @str.IO
str.IO:
	.asciz	"IO"
	.size	str.IO, 3

	.type	IO_vtable_prototype,@object # @IO_vtable_prototype
	.globl	IO_vtable_prototype
	.p2align	4
IO_vtable_prototype:
	.long	4                       # 0x4
	.long	(0+8)&-1
	.quad	str.IO
	.quad	IO_new
	.quad	Object_abort
	.quad	Object_type_name
	.quad	Object_copy
	.quad	IO_out_string
	.quad	IO_out_int
	.quad	IO_in_string
	.quad	IO_in_int
	.size	IO_vtable_prototype, 80

	.type	str.Main,@object        # @str.Main
str.Main:
	.asciz	"Main"
	.size	str.Main, 5

	.type	Main_vtable_prototype,@object # @Main_vtable_prototype
	.globl	Main_vtable_prototype
	.p2align	4
Main_vtable_prototype:
	.long	5                       # 0x5
	.long	(0+8)&-1
	.quad	str.Main
	.quad	Main_new
	.quad	Object_abort
	.quad	Object_type_name
	.quad	Object_copy
	.quad	IO_out_string
	.quad	IO_out_int
	.quad	IO_in_string
	.quad	IO_in_int
	.quad	Main_main
	.size	Main_vtable_prototype, 88

	.type	str.2,@object           # @str.2
str.2:
	.asciz	"<basic class>"
	.size	str.2, 14

	.type	String.2,@object        # @String.2
	.globl	String.2
	.p2align	3
String.2:
	.quad	String_vtable_prototype
	.quad	str.2
	.size	String.2, 16

	.type	str.1,@object           # @str.1
str.1:
	.asciz	"Frugel"
	.size	str.1, 7

	.type	String.1,@object        # @String.1
	.globl	String.1
	.p2align	3
String.1:
	.quad	String_vtable_prototype
	.quad	str.1
	.size	String.1, 16

	.type	str.0,@object           # @str.0
str.0:
	.asciz	"basic_funcs.cl"
	.size	str.0, 15

	.type	String.0,@object        # @String.0
	.globl	String.0
	.p2align	3
String.0:
	.quad	String_vtable_prototype
	.quad	str.0
	.size	String.0, 16


	.section	".note.GNU-stack","",@progbits
