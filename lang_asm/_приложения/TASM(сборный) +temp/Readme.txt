��������� ������ �� ������������� ���������������
..........................................
0. ���������� ����� tasm.exe � tlink.exe � ����� C:\Documents and Settings\���_������������\
1. �������� �������� ��������� � �������� ���������
2. ��������� ��� � ����� C:\Documents and Settings\���_������������\ � ����������� *.asm (�������������, ����� � *.txt), ��������, Go_Baby.asm, 
3. ��������� ��������� ������� (����-���������-cmd)

�����

Microsoft Windows XP [������ 5.1.2600]
(?) 1985-2001.

C:\Documents and Settings\���_������������>

4. ������ ��������� ���� Go_Baby.obj.

�����

tasm Go_Baby.asm

�����

C:\Documents and Settings\���_������������\tasm Go_Baby.asm
Turbo Assembler  Version 4.1  Copyright (c) 1988, 1996 Borland International	{�������}

Assembling file:   Go_Baby.asm                {��� ��������� �����}
Error messages:    None			      {��������� � �������}
Warning messages:  None                       {��������������}
Passes:            1 			      {����� ��������}
Remaining memory:  445k

C:\Documents and Settings\���_������������>

���� ������� ������, �� ������������ � ��������� ��������, ������ �������� � ������ ������������

5. ������ ����������� ���� �� ���������� ����� 

tlink.exe Go_Baby.obj /t

�����

Turbo Link  Version 7.1.30.1. Copyright (c) 1987, 1996 Borland International   {�������}

���� /t ����������, ��� ��������� com-���������, ��� ��� ���������� ������������ exe-���������

6. ��������� ���������

Go_Baby