;prg_8.6.asm
masm
model	small
stack	256
.data
del_b	label	byte
del	dw	29876
delt	db	45
.code	;ᥣ���� ����
main:	;�窠 �室� � �ணࠬ��
	mov	ax,@data
	mov	ds,ax
;...
	xor	ax,ax
;��᫥���騥 ��� ������� ����� �������� ����� mov ax,del
	mov	ah,del_b	;���訩 ���� �������� � ah
	mov	al,del_b+1	;����訩 ���� �������� � al
	div	delt	;� al - ��⭮�, � ah - ���⮪
;...
 	exit:
	mov	ax,4c00h	;�⠭����� ��室
	int	21h
end	main		;����� �ணࠬ��

