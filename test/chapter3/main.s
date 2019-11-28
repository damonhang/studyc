	.file	"main.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "hello, world\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$16, %esp
	call	___main
	movl	$13, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$1, (%esp)
	call	_write
	movl	$0, (%esp)
	call	__exit
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	_write;	.scl	2;	.type	32;	.endef
	.def	__exit;	.scl	2;	.type	32;	.endef
