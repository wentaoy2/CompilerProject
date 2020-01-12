	.text
	.file	"isvoid_o.ll"
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
	.globl	Main_func               # -- Begin function Main_func
	.p2align	4, 0x90
	.type	Main_func,@function
Main_func:                              # @Main_func
	.cfi_startproc
# %bb.0:                                # %entry
	movq	%rdi, -8(%rsp)
	cmpq	$0, 8(%rdi)
	sete	%al
	retq
.Lfunc_end1:
	.size	Main_func, .Lfunc_end1-Main_func
	.cfi_endproc
                                        # -- End function
	.globl	Main_main               # -- Begin function Main_main
	.p2align	4, 0x90
	.type	Main_main,@function
Main_main:                              # @Main_main
	.cfi_startproc
# %bb.0:                                # %entry
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, 8(%rsp)
	testq	%rdi, %rdi
	je	.LBB2_7
# %bb.1:                                # %tmp.0
	movq	(%rdi), %rax
	callq	*80(%rax)
	testb	$1, %al
	je	.LBB2_4
# %bb.2:                                # %condTrue.0
	movq	8(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB2_7
# %bb.3:                                # %tmp.2
	movq	(%rdi), %rax
	movl	$String.1, %esi
	jmp	.LBB2_6
.LBB2_4:                                # %condFalse.1
	movq	8(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB2_7
# %bb.5:                                # %tmp.4
	movq	(%rdi), %rax
	movl	$String.2, %esi
.LBB2_6:                                # %end.2
	callq	*48(%rax)
	movq	%rax, 16(%rsp)
	movq	8(%rsp), %rax
	addq	$24, %rsp
	retq
.LBB2_7:                                # %abort
	callq	abort
.Lfunc_end2:
	.size	Main_main, .Lfunc_end2-Main_main
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
	movq	$0, 8(%rax)
	popq	%rcx
	retq
.Lfunc_end3:
	.size	Main_new, .Lfunc_end3-Main_new
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
	.long	((0+8)&-1)*2
	.quad	str.Main
	.quad	Main_new
	.quad	Object_abort
	.quad	Object_type_name
	.quad	Object_copy
	.quad	IO_out_string
	.quad	IO_out_int
	.quad	IO_in_string
	.quad	IO_in_int
	.quad	Main_func
	.quad	Main_main
	.size	Main_vtable_prototype, 96

	.type	str.3,@object           # @str.3
str.3:
	.asciz	"<basic class>"
	.size	str.3, 14

	.type	String.3,@object        # @String.3
	.globl	String.3
	.p2align	3
String.3:
	.quad	String_vtable_prototype
	.quad	str.3
	.size	String.3, 16

	.type	str.2,@object           # @str.2
str.2:
	.asciz	"not ok"
	.size	str.2, 7

	.type	String.2,@object        # @String.2
	.globl	String.2
	.p2align	3
String.2:
	.quad	String_vtable_prototype
	.quad	str.2
	.size	String.2, 16

	.type	str.1,@object           # @str.1
str.1:
	.asciz	"ok"
	.size	str.1, 3

	.type	String.1,@object        # @String.1
	.globl	String.1
	.p2align	3
String.1:
	.quad	String_vtable_prototype
	.quad	str.1
	.size	String.1, 16

	.type	str.0,@object           # @str.0
str.0:
	.asciz	"isvoid_o.cl"
	.size	str.0, 12

	.type	String.0,@object        # @String.0
	.globl	String.0
	.p2align	3
String.0:
	.quad	String_vtable_prototype
	.quad	str.0
	.size	String.0, 16


	.section	".note.GNU-stack","",@progbits
