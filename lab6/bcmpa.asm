section .CODE
	global main
	extern old_main

main:
      push	ebp
      mov	ebp, esp
      mov	ecx, DWORD[ebp+12]  ;save the argv[1] addres
      mov	edx, DWORD[ebp+8]	; save the argv[2] addres
	  call	open				;open both files and save the contant to ecx
	  call	read
	  mov	ebx,0 ;y?
	  mov BX, placeOfChar
	  jmp	diffloop
	 
	 ; push	ecx
	  ;push	edx
     ; call	old_main
    ;  mov	esp, ebp
     ; pop	ebp
      ;ret	
	  
read:
	mov eax,3 ; linux system call- read
    ;mov ecx,[esp+8]
    ;mov edx,[esp+12]
	int 0x80	;execute the system call 
	ret
	
write: ; i think it;s not in use
	mov	ebx,1	;file descriptor (stdout)
	mov	eax,4	;system call number (sys_write)
	int	0x80	;call kernel
	ret
	
open:
	mov eax,5; linux system call- open
    ;mov ecx,[esp+8]
    ;mov edx,[esp+12]
	int 0x80	;execute the system call 
	ret
	
close:
	mov eax,6; linux system call- close
	mov ecx,[esp+8]
	mov edx, [esp+12]
	int 0x80	;execute the system call 
	ret

	
diffloop:
	inc		BX
	movzx	AX, BYTE [ecx]		; take one byte each time to AX	
	movzx	AL, BYTE [edx]		; take one byte each time to BX
	cmp	AX, 0 		; if ( str1[i] == 0 ) break;
	je	end
	cmp	AL, 0 		; if ( str2[i] == 0 ) break;
	je	end
	cmp AX,AL		
	jne printline	;if not equal write the line
	je	continue	;else continue
	
continue:	
	inc	ecx
	inc edx
	jmp diffloop

printline:
;clean the registers
;go to func
; retrive registers
	mov	edx,len1	;message length
	mov	ecx,msgSec1	;message to write
	call write
	mov	ecx,placeOfChar
	call write
	
	mov	edx,len2	;message length
	mov	ecx,msgSec2	;message to write
	call write
	mov	ecx,AX  ;______________invalid
	call write
	mov	edx,len3	;message length
	mov	ecx,msgSec3	;message to write
	mov	ecx,BX		;______________invalid
	call write
	;nwln
	jmp continue

	
end:	
	mov esp, ebp
	pop ebp
	ret
	
section .data
		placeOfChar Db 1
		msgSec1		Db 'byte ','\0'
		len1	equ	$ - msgSec1	       	 ;length of our dear string
		msgSec2		Db ' -','\0'
		len2	equ	$ - msgSec2	       	 ;length of our dear string
		msgSec3		Db ' +','\0'
		len3	equ	$ - msgSec3	       	 ;length of our dear string
		
		
