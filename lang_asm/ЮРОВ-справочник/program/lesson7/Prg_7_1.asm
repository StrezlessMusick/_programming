;---------Prg_7_1.asm---------------
;�ணࠬ�� ,��������� ��� �७�.
;��������� ����� ��㪠 �� 450 �� �� 2100 ��.
;�ᯮ������ ����� delay (����প�).
;�� ����室�����
;����� �������� ���祭�� ����প� (�� 㬮�砭�� - ��� ������ Pentium).
;------------------------------------
masm
model	small
stack	100h
delay macro time
;����� ����প�, ��� ⥪�� ��࠭�稢����� ��४⨢��� macro � endm.
;�� �室� - ���祭�� ����প� (� ���)
	local	ext,iter
	push	cx
	mov	cx,time
ext:
	push	cx
	mov	cx,5000
iter:
	loop	iter
	pop	cx
	loop	ext
	pop	cx
endm
.data	;ᥣ���� ������
tonelow	dw	2651	;������ �࠭�� ���砭�� = 450 ��
cnt	db	0	;����稪 ��� ��室� �� �ணࠬ��
temp	dw	?	;������ �࠭�� ���砭��
.code	;ᥣ���� ����
main:	;�窠 �室� � �ணࠬ��
	mov	ax,@data	;��뢠�� ॣ���� ds � ᥣ���⮬
	mov	ds,ax	;������ �१ ॣ���� ax
	xor	ax,ax	;��頥� ax
go:
;����ᨬ ᫮�� ���ﭨ� 10110110b(0�6h) � �������� ॣ���� (���� 43h)
	mov	al,0B6h
	out	43h,al
	in	al,61h	;����稬 ���祭�� ���� 61h � al
	or	al,3	;���樠�����㥬 ������� � ������ ⮪ � ���� 61h
	out	61h,al
	mov	cx,2083	;������⢮ 蠣�� ��㯥��⮣� ��������� ⮭�
musicup:
;� ax ���祭�� ������ �࠭��� ����� 
	mov	ax,tonelow
	out	42h,al	;� ���� 42h ����襥 ᫮�� ax :al
	xchg	al,ah	;����� ����� al � ah
	out	42h,al	;� ���� 42h ���襥 ᫮�� ax:ah
	add	tonelow,1	;����蠥� ⮭
	delay 1	;����প� �� 1 ���
	mov	dx,tonelow	;� dx ⥪�饥 ���祭�� �����
	mov	temp,dx	;temp - ���孥� ���祭�� ����� 
	loop	musicup	;������� 横� ����襭��
	mov	cx,2083	; ����⠭����� ���稪 横��
musicdown:
	mov	ax,temp	;� ax ���孥� ���祭�� �����
	out	42h,al	;� ���� 42h ����襥 ᫮�� ax :al
	mov	al,ah	;����� ����� al � ah
	out	42h,al;� ���� 42h ���襥 ᫮�� ax :ah
	sub	temp,1	;�������� �����
	delay 1	;����প� �� 1 ���
	loop musicdown	;������� 横� ���������
nosound:
	in	al,61h	;����稬 ���祭�� ���� 61h � AL
	and	al,0FCh	;�몫���� �������
	out	61h,al	;� ���� 61h
	mov	dx,2651	;��� ��᫥����� 横���
	mov	tonelow,dx
	inc	cnt	;㢥��稢��� ����稪 ��室��, � ���� 
;������⢮ ���砭�� �७�
	cmp	cnt,5	;5 ࠧ ? 
	jne	go	;�᫨ ���, ��� �� ���� go
	exit:
	mov	ax,4c00h	;�⠭����� ��室
	int	21h
end main	;����� �ணࠬ��

