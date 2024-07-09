	global _Lithium_Entry

	extern MessageBox

	section .text
_Lithium_Entry:
	rax, 60
	xor rdi, rdi
	syscall

	section .rodata
