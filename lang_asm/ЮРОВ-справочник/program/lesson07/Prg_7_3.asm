;---------Prg_7_3.asm----------------------
;�ணࠬ�� �८�ࠧ������ ��㧭�筮�� ��⭠����筮�� �᫠
;� ����筮� �।�⠢����� � �ᯮ�짮������ ������� xlat.
;�室: ��室��� ��⭠����筮� �᫮; �������� � ����������.
;��室: १���� �८�ࠧ������ � ॣ���� al.
.data	; ᥣ���� ������
message	db	'������ ��� ��⭠������ ����,$'
tabl	db	48 dup (0),0,1,2,3,4,5,6,7,8,9, 8 dup (0), 
		db	0ah,0bh,0ch,odh,0eh,0fh,27 dup (0)
		db	0ah,0bh,0ch,odh,0eh,0fh, 153 dup (0)
.stack 256	;ᥣ���� �⥪�
.code
;��砫� ᥣ���� ����
proc main	;��砫� ��楤��� main
	mov ax,@data	;䨧��᪨� ���� ᥣ���� ������ � ॣ���� ax
	mov	ds,ax	;ax �����뢠�� � ds
	lea	bx,tabl	;����㧪� ���� ��ப� ���� � ॣ���� bx
	mov	ah,9
	mov	dx,offset message
	int	21h	;�뢥�� �ਣ��襭�� � �����
	xor	ax,ax	;������ ॣ���� ax
	mov	ah,1h	;���祭�� 1h � ॣ���� ah
	int	21h	;������ ����� ���� � al
	xlat		;��४���஢�� ��ࢮ�� ���������� ᨬ���� � al 
	mov	dl,al
	shl	dl,4	;ᤢ�� dl ����� ��� �᢮�������� ���� ��� ����襩 ����
	int	21h	;���� ��ண� ᨬ���� � al
	xlat	;��४���஢�� ��ண� ���������� ᨬ���� � al
	add	al,dl	;᪫��뢠�� ��� ����祭�� १����
	mov	ax,4c00h	;����뫪� 4c00h � ॣ���� ax 
	int	21h	;�����襭�� �ணࠬ��
endp	main		;����� ��楤��� main
code	ends	;����� ᥣ���� ����
end	main		;����� �ணࠬ�� � �窮� �室� main

