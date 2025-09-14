.model small
.stack 200h
.data
.code

MAIN:
	.startup
	mov AX, @data
	mov DS, AX

	mov dx, 03h
	mov bx, 08h
	mov cx, 00h
	mov ax, 00h
	
	cmp dx, 6Ah
	jl VERO
	jge ciclo
	cmp dx, 0AAh
	jle ciclo
	cmp dx, 9CCCh
	jg CONTINUA
	
		VERO:
			inc cx
			cmp cx, bx
			jle VERO
			jg FINE
		ciclo:
			inc dx
			inc ax
			cmp dx, 91AAh
			jg FINE
			jl ciclo
		CONTINUA:
			mov dh, dl
			mov dl, dh
			jmp FINE
			
	FINE:
	mov ah, 4ch
	int 21h
	.exit
END

;DX=33
