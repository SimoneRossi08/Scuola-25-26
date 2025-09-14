.model small
.stack 200h
.data
.code

MAIN:
	.startup
	mov AX, @data
	mov DS, AX
	
	mov cx, 07h
	mov dx, 03h
	
	add dx, 0Ah
	add cx, 1Ah
	
	mov ax, dx
	mov dx, cx
	mov cx, ax
	
	mov ax, dx
	add cx, dx
	
	inc dx
	
	mov ah, 4ch
	int 21h
	.exit
END

;AX=14
;DX=11
;CX=31