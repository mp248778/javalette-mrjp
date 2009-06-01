	.file	"asd.bc"


	.text
	.align	16
	.globl	lala6
	.type	lala6,@function
lala6:
.Leh_func_begin1:
	pushq	%rbp
.Llabel1:
	movq	%rsp, %rbp
.Llabel2:
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	$0, -8(%rbp)
	testl	%edi, %edi
	jg	.LBB1_3	# true_body
.LBB1_1:	# false_body
	movq	%rsp, %rax
	leaq	-16(%rax), %rcx
	movq	%rcx, %rsp
	movl	$10, -16(%rax)
	movl	$10, %eax
.LBB1_2:	# false_body
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LBB1_3:	# true_body
	xorl	%edi, %edi
	call	lala6
	jmp	.LBB1_2	# false_body
	.size	lala6, .-lala6
.Leh_func_end1:


	.align	16
	.globl	main
	.type	main,@function
main:
.Leh_func_begin2:
	pushq	%rbp
.Llabel3:
	movq	%rsp, %rbp
.Llabel4:
	pushq	%rbx
	subq	$24, %rsp
	movl	$3, -12(%rbp)
	movl	$3, -16(%rbp)
	movl	$4, -20(%rbp)
	movl	$4, -16(%rbp)
	jmp	.LBB2_3	# cond
.LBB2_1:	# for
	movq	%rsp, %rax
	leaq	-16(%rax), %rcx
	movq	%rcx, %rsp
	movl	$3, -16(%rax)
	movq	%rsp, %rax
	leaq	-16(%rax), %rcx
	movq	%rcx, %rsp
	movl	$3, -16(%rax)
.LBB2_2:	# afterCompoundInstr
	incl	-16(%rbp)
.LBB2_3:	# cond
	movl	-16(%rbp), %ebx
	movq	%rsp, %rax
	leaq	-16(%rax), %rcx
	movq	%rcx, %rsp
	movl	$4, -16(%rax)
	movl	$4, %edi
	call	lala6
	cmpl	%eax, %ebx
	jl	.LBB2_1	# for
.LBB2_4:	# merge
	movl	-16(%rbp), %eax
	leaq	-8(%rbp), %rsp
	popq	%rbx
	popq	%rbp
	ret
	.size	main, .-main
.Leh_func_end2:
	.section	.eh_frame,"aw",@progbits
.LEH_frame0:
.Lsection_eh_frame:
.Leh_frame_common:
	.long	.Leh_frame_common_end-.Leh_frame_common_begin
.Leh_frame_common_begin:
	.long	0x0
	.byte	0x1
	.asciz	"zR"
	.uleb128	1
	.sleb128	-8
	.byte	0x10
	.uleb128	1
	.byte	0x1B
	.byte	0xC
	.uleb128	7
	.uleb128	8
	.byte	0x90
	.uleb128	1
	.align	8
.Leh_frame_common_end:

.Llala6.eh:
	.long	.Leh_frame_end1-.Leh_frame_begin1
.Leh_frame_begin1:
	.long	.Leh_frame_begin1-.Leh_frame_common
	.long	.Leh_func_begin1-.
	.long	.Leh_func_end1-.Leh_func_begin1
	.uleb128	0
	.byte	0x4
	.long	.Llabel1-.Leh_func_begin1
	.byte	0xE
	.uleb128	16
	.byte	0x4
	.long	.Llabel2-.Llabel1
	.byte	0x86
	.uleb128	2
	.byte	0xD
	.uleb128	6
	.align	8
.Leh_frame_end1:
.Lmain.eh:
	.long	.Leh_frame_end2-.Leh_frame_begin2
.Leh_frame_begin2:
	.long	.Leh_frame_begin2-.Leh_frame_common
	.long	.Leh_func_begin2-.
	.long	.Leh_func_end2-.Leh_func_begin2
	.uleb128	0
	.byte	0x4
	.long	.Llabel3-.Leh_func_begin2
	.byte	0xE
	.uleb128	16
	.byte	0x83
	.uleb128	3
	.byte	0x4
	.long	.Llabel4-.Llabel3
	.byte	0x86
	.uleb128	2
	.byte	0xD
	.uleb128	6
	.align	8
.Leh_frame_end2:

	.section	.note.GNU-stack,"",@progbits
