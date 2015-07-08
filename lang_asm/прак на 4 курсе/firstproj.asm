.include "can128def.inc"
.list
.def tmp=R16; 8 ��� ; �������� ���
.equ tcount=0xA531 ; �������� �������
.cseg ; ��� ��� ������ - ���������
.org 0 ; ����� � 0�� ������
; 0� ����� - ������� �������� ����������, �� ��� ��� ���������� ��������
; 0� ������ - ������ �������������
met: ; �����
; rjmp met ; ������ � �����

ldi tmp, low(RAMEND)
out SPL, tmp
ldi tmp, high(RAMEND) ; ������ ����� �����
out SPH, tmp

; DDRA - �������� �� ����(0) ��� �����(1) ����� ����� � ���� ������
ldi tmp, 0xFF ; ���� A �� �����
out DDRA, tmp

ldi tmp, 0b1000 ; PG3 �� �����
out DDRG, tmp

;ldi tmp, 0xFF ; �������� ������
;out PORTA, tmp

.def loop0=R17
.def loop1=R18
.def loop2=R19
.def loop3=R19
ldi loop3,0 
ldi loop2,12 
ldi loop1,18 
ldi loop0,50 

start:
RCALL wait2
ldi tmp, 0xFF
out portA,tmp
ldi tmp, 0b1000
out portG,tmp
RCALL wait2
ldi tmp, 0
out portA,tmp
out portG,tmp
RJMP start


		wait3: ;---------------
push tmp
mov tmp, loop3
push loop2
ldi loop2, 255
push loop1
ldi loop1, 255
push loop0
ldi loop0, 255

	s31:
cpi tmp, 0
BREQ s32
RCALL wait2
dec tmp
RJMP s31
	s32:

pop loop0
pop loop1
pop loop2
RCALL wait2
pop tmp
RET

		wait2: ;---------------
push tmp
mov tmp, loop2
push loop1
push loop0
ldi loop1, 255
ldi loop0, 255

	s21:
cpi tmp, 0
BREQ s22
RCALL wait1
dec tmp
RJMP s21
	s22:

pop loop0
pop loop1
RCALL wait1
pop tmp
RET

		wait1: ;---------------loop1*1292+12 + loop0*5+10(+2)//������ �� 2000 ��������
push tmp		; 2
mov tmp, loop1	; 1
push loop0		; 2		
ldi loop0, 255	; 1
				; 
	s11:		; 
cpi tmp, 0		; 1
BREQ s12		; 1/2
RCALL wait0		; 1287
dec tmp			; 1
RJMP s11		; 2
	s12:		; 
				; 
pop loop0		; 2
RCALL wait0		; loop0*5+10   (+2)
pop tmp			; 2
RET				; 4

		wait0: ;----------------loop0*5+10   (+2)
push tmp 		; 2
mov tmp,loop0 	; 1
	s01:
cpi tmp, 0 		; 1
BREQ s02 		; 1/2
;nop
dec tmp 		; 1
RJMP s01 		; 2
	s02:
pop tmp			; 2
RET				; 4
















