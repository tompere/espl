 
section .text
	global cmpstr
cmpstr:
	push	ebp
	mov	ebp, esp
	jmp	loop
	mov  esi,0
	mov	eax, DWORD [ebp+8]; first parameter
	mov  edi,0
	mov	ebx, DWORD [ebp+12]; first parameter
loop:
	mov	ecx, BYTE [eax+esi]
	mov	edx, BYTE [ebx+edi]
	cmp	ebx, 0 		; if ( str1[i] == 0 ) break;better to do test
	je	notEqual
	cmp	ebx, ecx	
	jne 	notEqual		;if ( str1[i] != str2[i] ) break;
        inc     esi
	inc 	DWORD[ebp+8]		;increase first pointer; 
	inc 	DWORD[ebp+12]		;increase second pointer	  
	jmp 	loop		; end of loop
	
notEqual:
	jg	ABiger
	jl	BBiger
	mov 	eax,0
	jmp 	end
	
ABiger:
	mov 	eax,1
	jmp 	end
BBiger:
	mov 	eax,2
	jmp 	end
	
end:	
	mov esp, ebp
	pop ebp
	ret
	
