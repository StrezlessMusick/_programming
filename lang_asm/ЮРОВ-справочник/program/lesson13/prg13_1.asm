;prg13_1.asm
;prg_3_1.asm � ���ம�।�����ﬨ
init_ds	macro
;����� ����ன�� ds �� ᥣ���� ������
	mov	ax,data
	mov	ds,ax
	endm
out_str	macro	str
;����� �뢮�� ��ப� �� ��࠭.
;�� �室� - �뢮����� ��ப�.
;�� ��室�- ᮮ�饭�� �� ��࠭�.
push	ax
mov	ah,09h
mov	dx,offset str
int	21h
pop	ax
	endm

clear_r	macro	rg
;���⪠ ॣ���� rg
	xor	rg,rg
	endm

get_char	macro
;���� ᨬ����
;�������� ᨬ��� � al
	mov	ah,1h
	int	21h
	endm

conv_16_2	macro
;����� �८�ࠧ������ ᨬ���� ��⭠����筮� ����
;� �� ������ ���������� � al
	sub	dl,30h
	cmp	dl,9h
	jle	$+5
	sub	dl,7h
	endm

exit	macro
;����� ���� �ணࠬ��
	mov	ax,4c00h
	int 21h
	endm

data	segment para public 'data'
message	db	'������ ��� ��⭠������ ���� (�㪢� A,B,C,D,E,F - �ய���): $'
data	ends

stk	segment stack
	db	256 dup('?')
stk	ends

code	segment para public 'code'
	assume	cs:code,ds:data,ss:stk
main	proc
	init_ds
	out_str	message
	clear_r	ax
	get_char
	mov	dl,al
	conv_16_2
	mov	cl,4h
	shl	dl,cl
	get_char
	conv_16_2
	add	dl,al
	xchg	dl,al	;१���� � al
	exit
main	endp
code	ends
end	main

