{--�������� (���������, �����, ���������, ����������, � ������ �����, ��������� � ��������������� ������)
�sh 		shell
�xargs 		��� ������������ ������ ���������� � ���������� ������� 
�alias 		��� ���������� ������ � �� �������������������. 
�mkfifo 	����������� ������
�test 		��� �������� ���� ����� � ��������� ��������
�false 		���������� �������� 1, 
�true 		���������� �������� 0
�env 		����������� ������� � ���������� ���������
�fc 		�������� ��� �������������� ������ ����� ��������� ������, � ����� �� ����������. ���������� history.
�sleep 		����������� �������� �� ��������� ����� 
}
{--����������� �� ������ � �������� �����
�pwd 		(print working directory) ������� ������ ���� �� ��������� �������� � �������� �������� ��������
�ls 		�������� � ����������� ����� ���������� ����������.
�cd 		������� ��������� ������ ��� ��������� �������� �������� ��������
�du 		��������� ��� ������ ����������� ��������� ������������.
�file 		��������������� ��� ����������� ���� �����.
�find 		������� ������ ������ �� ����� � ������ ���������
}
{--�������������� �����
�touch 		��� ��������� ������� ���������� ��������� ����� ��� ������� � ������� �����
�ln 		��������������� ����� ����� ������ � ������ �����. (hard link, symbolic linc)
�cp 		������� Unix � ������� GNU Coreutils, ��������������� ��� ����������� ������ �� ������ � ������ �������� (��������, � ������ �������� ��������)
�mv 		��� ����������� ��� �������������� ������.
�rm 		��� �������� ������ �� �������� �������
�mkdir 		������� ��� �������� ����� ���������
�rmdir 		������� ������� �� �������� �������
�link 		������ ������ �� ����  
�unlink 
.chroot		��������� ��������� ��������
}
{--�������� ������
�more 		��� ��������� ����������� ��������� ������
�nl 		��������� ��������� ���� �� ����������� �����, �������� ������ �����
�od 		��� ������ ����� ����� � ������������ �������. � ������� �����������, � ������� od ����� ������� ���������� ����� � �����������������, ������������, ���������� � ��.(����� ���� ������������ �� ���� ��������) ���� � ������ ����� ����� ������.
�paste 		������������� �����, ��� ������������ �������, ��������� �� � ������� � ����������� ����� ������.
}
{--������ �������������� ������
�echo 		�������������� ��� ����������� ������ ������
�printf 	������ � ��������� ������ �������� ������ �����, ����������������� �������� ��������� �������
�read 		������ ������ �� ������������ �����
{	��������� ���������
�ed 		������ ����������� ��������� �������� ������������ ������� UNIX, ���������� � ������ 1970-�. ����������� ��� ������, ��������� ��� ex, ��������� ������� ��������� vi.
�ex 		���������� ��������� ed, �������� ������������ ����������� � �������� �������� ����������� ��������� ��������������
�vi 		����� ��������� ����������
}
}
{--�������������� �������������� � ��������� ������
{	��� �������� ������
�nm 		���������� ���������� � �������� ������ (��������� ������, �����������, ����������� ������ � �. �.), ������ ����� ������� ���. 
�strings 	����������� ��� ������ ���������� ����� � �������� ������
�uudecode 	������������� �������� ������ � ��������� �������
�uuencode 	������������� �������� ������ � ��������� �������
}
�wc 		��������� ����� ��������� �����, ���� � ���� ��� ������� ���������� ����� � �������� ������, ���� ���� ������ ��������� ������
�pr 		��������� ����� �� �������� ��� ������� ��� ������
{	��� ����� � ��� ������
�basename 	basename � ���������� ������� unix-������, ��������� ����� ��������� � ������� �� ����� �����.
�dirname 	��������������� ��� �������������� ����������� ��� �������������� ���� � ����� ��� ���������� � ��� ������������ ����������.
}
{	���������, ���������, ��������������
�expand 	������������� ��������� � �������, �������� ����������������� ������.
�unexpand 	����������������� ������� � ���������
�iconv 		��� �������������� ������ �� ����� ��������� � ������
�tr 		��� �������������� ��������
}
{	������� ����� ���������
�tee 		������� �� �����, ��� �� ��������������, �������� �������� ������� � �������� ��� � ���� ��� � ����������

�split 		���������� ���� � ����������� ��� �� ��������� ����� �������� �����
�cat 		������� UNIX, ��������� ��������������� ��������� ����� (��� ����������), ����� �������, ��������� �� � ������ �����

�cmp 		Unix-�������, ���������� ��� �����, � ���� ��� �����������, �������� � ������ ����� � ������, ��� ���� ���������� ��������.
�diff 		������� ��������� ������, ��������� ������� ����� ����� �������
�sort 		��������� ������������� ������� ��������� ������ �� ����������� ����� � �������������� ������������� � ����� ������.
�uniq 		����� ������� ��� ������������� ������������� ������ � ��������������� �����
�comm 		������� unix, ������ ����1 � ����2, ������� ������ ���� �������������� ���������� �������������, � ���������� �����, ��������� �� ��� ������� ������: ������, ��������� ������ � ����� ����1; ������, ��������� ������ � ����� ����2; � ������, ����� ��� ����� ������. 
�join 		������������ ������ ���� ������������� ��������� ������ �� ������ ������� ������ ����

�dd 		��������� UNIX, ��������������� ��� ��� �����������, ��� � ��� ����������� ������
�head 		��������� ������ n ����� �� �����, �� ��������� n ����� 10
�tail 		��������� ��������� (�� ��������� 10) ��������� ����� �� �����.
}
{	������� ����� ���������
�csplit 	��������� ���� �� ��������� �����, ����������� ��������  

�grep 		������� �� ����� ������, ���������� ��������� ����������� ���������, � ������� ��
�cut 		������� ������� ��������� ����� �� ����� �����
�awk 		���������������� ���������� C-�������� ���� ����������� ������� � ��������� �������� ������ (��������, ���������� �����) �� �������� ��������. �������� � bash (SH) ��������.
�sed 		��������� ��������� �������� (� ����� ���� ����������������), ����������� ��������� ��������������� ��������� �������������� � ����������������� ������ ��������� ������.
}
}
{--������ ������/��������
}
{--�������
�man 		��� �������������� � ������ ���������� �������, ������� ��������������� ����� �� ����� *nix-��������������
}
--...
{--����������
�ar 		unix-�������, ��������� � �������������� ������, � ����� ����������� ����� �� ������. 
�compress 	������� ������ ��� ��������, ��������� � ���������� ������ �����
�uncompress 	������� ������ ��� ��������, ��������� � ���������� ������ �����
�zcat 			����� ��� ����������� �����  
}
{--������� �������� ������ (�������� ������)
�cksum 		������������ ���������� ���� � ����������� ����� (CRC) � ����� �� ��������� ISO/IEC 8802-3:1989. 
�hash 		�����������
�patch 		��� �������� ������ (���������) ����� ������� �������� ��������� ������. 
{�sccs 		frontend ��� ���������� sccs
�admin 		�������� � ���������� sccs-������� (������ � ���� ������� �������� ������)
�delta 		������� �������� ��� ������� sccs �����
�get 		��������� ������ ��� sccs �����
}
}
{--���� � ��������
�write 		����������� ��������� ��������� ������� ������������, ������� ����� ������ � ���� �� �������
�lp 		���������� ������ ������ � ��������� � ���� ���������� �� ��������

�uucp 		������� ����������� ������ ����� ����� ������������ ��� ����������� ������������ ������� UNIX, ������������ ���������� ��������
}
{--������ ����� ����������������� ������� 
	(����-�����, ���������, ���������� �����
	���������� ����������
	������������, �����, ������������� ������, 
	��������� ��������, 
	��������, 
	�����)
{	��������� ����� ���������� � ������� (�����, ������������, ������, ��������)
�uname 		��������� ���������� � �������.
�cal 		UNIX?�������, ������������ ������� ���������
�date 		������� Unix ��� ������ � ���������� ������. 
�id 		��������� ���������� �� ��������� ������������ USERNAME ��� ������� ������������
�logname 	��������� ��� ������������, ����������� �������
�locale 	��������� ���������� � ������. (��� ����� ����������, ������� ����� ��������, ���� ������������, ������, ������� ����, � ����� ������ �������������, ������� ������������ ������� ������ � ���������������� ����������)
�tty 		��������� ��� ���������, ������������ �� ����������� ������
}
{	���������� �� ����������
�at 		unix-�������, �������� ������� �� ������������ �������� ������ � ������������ �� � ���� ������� at ��� ���������� �����, � �������� �����.
�crontab (cron)	�����-����������� ����� � UNIX-�������� ������������ ��������, �������������� ��� �������������� ���������� ������� � ����������� �����.
}
{	���������� ����������
�logger 	��������������� ��������� ��������� ��� ������ ���������� ������� syslog.
�time 		������ ����� ���������� ������� ������� ��� ��������� ��������� �� �������
�ps 		��������� ����� � ���������� ���������.
�kill 		�������� ��������� ������ ���������� ��������. ���� �� ������� �� ������ �������, ���������� ������ SIGTERM. ������ SIGTERM �������� �� ��������, ������� �� ������������ ��� ������
�wait 		��� ���������� ���������� �������� � ���������� ������ ��� ����������.
�nice 		�������, ����������� ��������� � ���������� ����������� ��� ������������ �����
�renice 	����������� �������� ��������� ���������� �����. 
�fg 		�������� ��� ���������� ����������. ������� ��������� ����������� ������ ����������������� �������� ��� ������� ��� �� �������� ������.
�nohup 		����������� ��������� ������� � �������������� �������� ������ ����� (hangup)����� �������, ������� ����� ���������� ����������� � ������� ������ � ����� ����, ��� ������������ ������ �� �������
}
{	������������
�who 		���������� ������� ������������� � ������������ �������
}
{	����� �������
�chgrp 		������� UNIX. ����� �������������� �������������������� �������������� ��� ��������� ������ ������
�chmod 		��������� ��� ��������� ���� ������� � ������ � �����������
�chown 		UNIX?�������, ���������� ��������� �/��� ������ ��� ��������� ������
�umask 		���������� ����� �������, ������� ������������� ����� ������ � ����������� �� ���������
�mesg 		��������� �������� �� ������ ��� ��������� ������� ������������. ������ ������������ ��� ���������� ��� ������� ������ ������������� ������ �� �������� ������� ������������.
}
{	�����
�df 		���������� ������ ���� �������� ������ �� ������ ���������, �������� �� ������, ������� � ��������� ������������ � ����� ������������.
�fuser 		���������������� ��������, ������� ���������� ��������� ����� ��� ������.
}
}
{--������ ����� ������ � ������ ��������
}
--...
{--������ ������������
�m4 		�������������� m4,
�c99 		����������� ����������
�fort77 	���������� ��������
}
{--���
�ctags 		�������, ���������� ���������� �� ������ � �������� ����������, ������� � ��������, ������������� � �������� ���� ������������ ��������
}
{--��������
�make 		���������������� ������� �������������� ������ �� ����� ����� � ������
}
{--���������� �����
�bc 		������������� ������������� ��-��������� �����, ��������� ��������� ���������� � ����������� �������� ���������. 
�expr 		����������� �������� ��������� � ��������� ��������� �� ����������� �����
.factor		������ ������� ��������� �����
�lex 		��������� ��� ��������� ����������� ������������, ������ ������������ ��������� � ����������� �������������� ������������ yacc
�yacc 		������������ ���������, �������� ����������� ����������� �������������� ������������ (��������)
}
------------------------------------------------
� - POSIX
. - GNU only
------------------------------------------------

�bg 
�jobs 

�asa 
�batch 
�cflow 
�command 
�cxref 
�fold 
�gencat 
�getconf 
�getopts 
�ipcrm 
�ipcs 
�localedef 
�mailx 		
�newgrp 
�pathchk 
�pax 
�prs 
�qalter 
�qdel 
�qhold 
�qmove 
�qmsg 
�qrerun 
�qrls 
�qselect 
�qsig 
�qstat 
�qsub 
�rmdel 
�sact 
�strip 
�stty 
�tabs 
�talk 
�tput 
�tsort 
�type 
�ulimit 
�unalias 
�unget 
�uustat 
�uux 
�val 
�what 