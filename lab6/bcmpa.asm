section .text
	global main
	extern old_main
	extern read_file
	
main:
      push	ebp
      mov	ebp, esp
      push	DWORD[ebp+12]
      call	read_file
      push	eax
      push	DWORD[ebp+8]
      call	read_file
      push	eax
      call	old_main
      mov	esp, ebp
      pop	ebp
      ret
