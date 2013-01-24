section .text
	
global _start
global read
global write
global open
global close
global strlen

extern main
_start:
;	lea ecx, [esp+4] ;move pointer to argv
        mov ecx, esp
	add ecx, 4
	push ecx		;push argv into stack
	push DWORD [esp+4] ;push argc into stack
	call	main	;do main from lwc.c
	mov     ebx,eax		
	mov	eax,1 	;exit the main program
	int 0x80	;execute the system call 

read:
	mov eax,3 ; linux system call- read
	mov ebx,[esp+4]
	mov ecx,[esp+8]
	mov edx,[esp+12]
	int 0x80	;execute the system call 
	ret
	
write:
	mov eax,4 ; linux system call- write
	mov ebx,[esp+4]
	mov ecx,[esp+8]
	mov edx,[esp+12]
	int 0x80	;execute the system call 
	ret
	
open:
	mov eax,5; linux system call- open
	mov ebx,[esp+4]
	mov ecx,[esp+8]
	mov edx,[esp+12]
	int 0x80	;execute the system call 
	ret
	
close:
	mov eax,6; linux system call- close
	mov ebx,[esp+4]
	int 0x80	;execute the system call 
	ret
	
strlen: ; strlen(s)
	push ebp
	mov ebp, esp
	mov eax, [ebp+8]
	dec eax

loop:
	inc eax
	mov ecx, [eax]
	test cl,cl
	jne loop
	
	sub eax, [ebp+8]
	mov esp, ebp
	pop ebp
	ret
