	.file	"example.c"
	.section	.rodata
.LC0:
	.string	"Stuff"
.LC1:
	.string	"More Stuff"
.LC2:
	.string	"example.c"
.LC3:
	.string	"1 == 2"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$.LC0, %edi
	call	puts
	movl	$.LC1, %edi
	call	puts
	movl	$__PRETTY_FUNCTION__.2178, %ecx
	movl	$14, %edx
	movl	$.LC2, %esi
	movl	$.LC3, %edi
	call	__assert_fail
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.type	__PRETTY_FUNCTION__.2178, @object
	.size	__PRETTY_FUNCTION__.2178, 5
__PRETTY_FUNCTION__.2178:
	.string	"main"
	.ident	"GCC: (Debian 4.7.2-5) 4.7.2"
	.section	.note.GNU-stack,"",@progbits
