	.file	"testCompile.c"
	.text
	.globl	_mutistore
	.def	_mutistore;	.scl	2;	.type	32;	.endef
_mutistore:
	subl	$28, %esp
	movl	36(%esp), %eax
	movl	%eax, 4(%esp)
	movl	32(%esp), %eax
	movl	%eax, (%esp)
	call	_mult2
	movl	40(%esp), %edx
	movl	%eax, (%edx)
	addl	$28, %esp
	ret
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	_mult2;	.scl	2;	.type	32;	.endef
