	.file	"colin.c"
	.text
	.globl	max
	.type	max, @function
max:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L2
	movl	-4(%rbp), %eax
	jmp	.L3
.L2:
	movl	-8(%rbp), %eax
.L3:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	max, .-max
	.type	imax, @function
imax:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jle	.L5
	movl	-4(%rbp), %eax
	jmp	.L6
.L5:
	movl	-8(%rbp), %eax
.L6:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	imax, .-imax
	.section	.rodata
.LC0:
	.string	"a = %d, b = %d, c = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$2, -4(%rbp)
	movl	$3, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	-12(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	setg	%al
	addl	$1, -4(%rbp)
	addl	$1, -8(%rbp)
	testb	%al, %al
	je	.L8
	movl	-4(%rbp), %eax
	addl	$1, -4(%rbp)
	jmp	.L9
.L8:
	movl	-8(%rbp), %eax
	addl	$1, -8(%rbp)
.L9:
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	-8(%rbp), %edx
	addl	$1, -8(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, -4(%rbp)
	movl	%edx, %esi
	movl	%eax, %edi
	call	max
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	-8(%rbp), %edx
	addl	$1, -8(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, -4(%rbp)
	movl	%edx, %esi
	movl	%eax, %edi
	call	imax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %ecx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
