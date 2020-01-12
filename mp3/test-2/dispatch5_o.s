	.text
	.file	"dispatch5_o.ll"
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
	movq	8(%rdi), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.1:                                # %ok.1
	movq	(%rdi), %rax
	callq	*48(%rax)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.2:                                # %ok.0
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rax
	movq	16(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.3:                                # %ok.3
	movq	(%rdi), %rax
	callq	*48(%rax)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.4:                                # %ok.2
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rax
	movq	24(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.5:                                # %ok.5
	movq	(%rdi), %rax
	callq	*48(%rax)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.6:                                # %ok.4
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rax
	movq	40(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.7:                                # %ok.7
	movq	(%rdi), %rax
	callq	*48(%rax)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.8:                                # %ok.6
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rax
	movq	40(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.9:                                # %ok.9
	callq	*C_vtable_prototype+48(%rip)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.10:                               # %ok.8
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rax
	movq	40(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.11:                               # %ok.11
	callq	*B_vtable_prototype+48(%rip)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.12:                               # %ok.10
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rax
	movq	40(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.13:                               # %ok.13
	callq	*A_vtable_prototype+48(%rip)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.14:                               # %ok.12
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rax
	movq	32(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.15:                               # %ok.15
	movq	(%rdi), %rax
	callq	*48(%rax)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.16:                               # %ok.14
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rax
	movq	32(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.17:                               # %ok.17
	callq	*B_vtable_prototype+48(%rip)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.18:                               # %ok.16
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rax
	movq	32(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.19:                               # %ok.19
	callq	*A_vtable_prototype+48(%rip)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.20:                               # %ok.18
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	movq	(%rsp), %rax
	movq	8(%rax), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.21:                               # %ok.21
	callq	*A_vtable_prototype+48(%rip)
	movq	(%rsp), %rdi
	testq	%rdi, %rdi
	je	.LBB1_23
# %bb.22:                               # %ok.20
	movq	(%rdi), %rcx
	movl	%eax, %esi
	callq	*56(%rcx)
	popq	%rcx
	retq
.LBB1_23:                               # %abort
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
	pushq	%rbx
	.cfi_def_cfa_offset 16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	.cfi_offset %rbx, -16
	movl	Main_vtable_prototype+4(%rip), %edi
	callq	malloc
	movq	%rax, %rbx
	movq	$Main_vtable_prototype, (%rbx)
	movq	%rbx, 8(%rsp)
	callq	A_new
	movq	%rax, 8(%rbx)
	callq	B_new
	movq	%rax, 16(%rbx)
	callq	C_new
	movq	%rax, 24(%rbx)
	callq	B_new
	movq	%rax, 32(%rbx)
	callq	C_new
	movq	%rax, 40(%rbx)
	movq	%rbx, %rax
	addq	$16, %rsp
	popq	%rbx
	retq
.Lfunc_end2:
	.size	Main_new, .Lfunc_end2-Main_new
	.cfi_endproc
                                        # -- End function
	.globl	A_f                     # -- Begin function A_f
	.p2align	4, 0x90
	.type	A_f,@function
A_f:                                    # @A_f
	.cfi_startproc
# %bb.0:                                # %entry
	movq	%rdi, -8(%rsp)
	movl	$5, %eax
	retq
.Lfunc_end3:
	.size	A_f, .Lfunc_end3-A_f
	.cfi_endproc
                                        # -- End function
	.globl	A_new                   # -- Begin function A_new
	.p2align	4, 0x90
	.type	A_new,@function
A_new:                                  # @A_new
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	A_vtable_prototype+4(%rip), %edi
	callq	malloc
	movq	$A_vtable_prototype, (%rax)
	movq	%rax, (%rsp)
	popq	%rcx
	retq
.Lfunc_end4:
	.size	A_new, .Lfunc_end4-A_new
	.cfi_endproc
                                        # -- End function
	.globl	B_new                   # -- Begin function B_new
	.p2align	4, 0x90
	.type	B_new,@function
B_new:                                  # @B_new
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	B_vtable_prototype+4(%rip), %edi
	callq	malloc
	movq	$B_vtable_prototype, (%rax)
	movq	%rax, (%rsp)
	popq	%rcx
	retq
.Lfunc_end5:
	.size	B_new, .Lfunc_end5-B_new
	.cfi_endproc
                                        # -- End function
	.globl	C_f                     # -- Begin function C_f
	.p2align	4, 0x90
	.type	C_f,@function
C_f:                                    # @C_f
	.cfi_startproc
# %bb.0:                                # %entry
	movq	%rdi, -8(%rsp)
	movl	$6, %eax
	retq
.Lfunc_end6:
	.size	C_f, .Lfunc_end6-C_f
	.cfi_endproc
                                        # -- End function
	.globl	C_new                   # -- Begin function C_new
	.p2align	4, 0x90
	.type	C_new,@function
C_new:                                  # @C_new
	.cfi_startproc
# %bb.0:                                # %entry
	pushq	%rax
	.cfi_def_cfa_offset 16
	movl	C_vtable_prototype+4(%rip), %edi
	callq	malloc
	movq	$C_vtable_prototype, (%rax)
	movq	%rax, (%rsp)
	popq	%rcx
	retq
.Lfunc_end7:
	.size	C_new, .Lfunc_end7-C_new
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
	.long	((0+8)&-1)*6
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

	.type	str.A,@object           # @str.A
str.A:
	.asciz	"A"
	.size	str.A, 2

	.type	A_vtable_prototype,@object # @A_vtable_prototype
	.globl	A_vtable_prototype
	.p2align	4
A_vtable_prototype:
	.long	6                       # 0x6
	.long	(0+8)&-1
	.quad	str.A
	.quad	A_new
	.quad	Object_abort
	.quad	Object_type_name
	.quad	Object_copy
	.quad	A_f
	.size	A_vtable_prototype, 56

	.type	str.B,@object           # @str.B
str.B:
	.asciz	"B"
	.size	str.B, 2

	.type	B_vtable_prototype,@object # @B_vtable_prototype
	.globl	B_vtable_prototype
	.p2align	4
B_vtable_prototype:
	.long	7                       # 0x7
	.long	(0+8)&-1
	.quad	str.B
	.quad	B_new
	.quad	Object_abort
	.quad	Object_type_name
	.quad	Object_copy
	.quad	A_f
	.size	B_vtable_prototype, 56

	.type	str.C,@object           # @str.C
str.C:
	.asciz	"C"
	.size	str.C, 2

	.type	C_vtable_prototype,@object # @C_vtable_prototype
	.globl	C_vtable_prototype
	.p2align	4
C_vtable_prototype:
	.long	8                       # 0x8
	.long	(0+8)&-1
	.quad	str.C
	.quad	C_new
	.quad	Object_abort
	.quad	Object_type_name
	.quad	Object_copy
	.quad	C_f
	.size	C_vtable_prototype, 56

	.type	str.1,@object           # @str.1
str.1:
	.asciz	"<basic class>"
	.size	str.1, 14

	.type	String.1,@object        # @String.1
	.globl	String.1
	.p2align	3
String.1:
	.quad	String_vtable_prototype
	.quad	str.1
	.size	String.1, 16

	.type	str.0,@object           # @str.0
str.0:
	.asciz	"dispatch5_o.cl"
	.size	str.0, 15

	.type	String.0,@object        # @String.0
	.globl	String.0
	.p2align	3
String.0:
	.quad	String_vtable_prototype
	.quad	str.0
	.size	String.0, 16


	.section	".note.GNU-stack","",@progbits
