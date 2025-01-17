﻿{--референс (процедуры, циклы, ветвления, переменные, и прочие фишки, связанные с интерпретатором команд)
{
ctrl+u удалить все символы от курсора до начала строки
ctrl+k удалить все символы от курсора до конца строки
ctrl+w удалить слово перед курсором
ctrl+b переместить курсор на один символ влево
ctrl+f переместить курсор на один символ вправо
ctrl+t поменять местами символ слева от курсора и под курсором
ctrl+h удалить символ слева от курсора
ctrl+a переместить курсор в начало строки
ctrl+e переместить курсор в конец строки
ctrl+p предыдущая команда в истории bash
ctrl+n следующая команда в истории bash
ctrl+r реверсивный поиск команд в истории bash
ctrl+y вставляет последнюю удаленную с помощью ctrl+u или ctrl+k строку
ctrl+m выполнение команды, аналог [Enter]
ctrl+o выполняет команду, при этом оставляя ее в командной строке для дальнейшего использования.
ctrl+l очистить экран, аналог команды clear.
ctrl+s стоп режим. Блокирует вывод на консоль. При этом все данные отображенные на экране остаются не измененными.
Tab+Tab выводит список команд. При наличии какого нибудь символа(-ов) выводит команды по введенным символам.
    Примечание:ввод осуществляется как и в режиме ввода. Будьте осторожны.
ctrl+q выход из стоп-режима.
ctrl+d выйти из терминала
ctrl+c отменить последнюю введенную команду
ctrl+x,ctrl+v показать версию bash 
}
•sh 		shell
•xargs 		для формирования списка аргументов и выполнение команды 
•alias 		для сокращения команд и их последовательностей. 
•mkfifo 	именованные каналы
{•test 		для проверки типа файла и сравнения значений
! expr — истина, если выражение expr ложь.
expr1 -a expr2 — истина, если оба выражения expr1 и expr2 истина.
expr1 -o expr2 — истина, если или expr1 или expr2 истина.

arg1 %оператор% arg2 -eq, -ne, -lt, -le, -gt, или -ge — эти арифметические бинарные операции возвращают истину,
	если arg1 равно, не равно, меньше чем, меньше чем или равно, больше чем, или больше или равно чем arg2, соответственно.
	arg1 и arg2 могут быть положительными целыми, отрицательными целыми, или специальными выражениями -l string, которые вычисляют длину string.
-z string — истина, если длина string равна нулю.
-n string string — истина, если длина string не ноль.
string1 = string2 — истина, если строки равны.
string1 != string2 — истина, если строки не равны.
-n string — истина, если длина string не равна нулю

-e file — истина, если file существует.
-d file — истина, если file существует и каталог.
-L file — истина, если file существует и символьная ссылка.
-f file — истина, если file существует и обычный файл.
-c file — истина, если file существует и символьное устройство.
-S file — истина, если file существует и сокет.
-b file — истина, если file существует и является специальным блочным устройством.
-p file — истина, если file существует и является именованным каналом (pipe).
-g file — истина, если file существует и имеет установленным групповой идентификатор (set-group-id).
-k file — истина, если file имеет установленным «sticky» бит.
-u file — истина, если file существует и имеет установленным бит пользователя (set-user-id).
-r file — истина, если file существует и читаем.
-w file — истина, если file существует и записываем.
-x file — истина, если file существует и исполняем.
-t [fd] — истина, если fd открыт на терминале. Если fd пропущен, по умолчанию 1 (стандартное устройство вывода).
-O file — истина, если file существует и его владелец имеет эффективный идентификатор пользователя.
-G file — истина, если file существует и его владелец имеет эффективный идентификатор группы.
-s file — истина, если file существует и имеет размер больше чем ноль.
file1 -nt file2 — истина, если file1 новее (дата модификации) чем file2.
file1 -ot file2 — истина, если file1 старее чем file2.
file1 -ef file2 — истина, если file1 и file2 имеют то же устройство и номер inode .
}
•false 		возвратить значение 1, 
•true 		возвратить значение 0
•env 		исполняющая команду с изменением окружения
•fc 		служащая для редактирования списка ранее введенных команд, а также их выполнения. Аналогична history.
•sleep 		выполняющая задержку на указанное время 
.mkfifo		Создаёт FIFO (именованные каналы)
>> hup - двигаться вперед, понукать лошадь
 nohup		выполняет команду, игнорир
}
{--перемещение по папкам и просмотр папок
•pwd 		(print working directory) выводит полный путь от корневого каталога к текущему рабочему каталогу
•ls 		печатает в стандартный вывод содержимое директорий.
•cd 		команда командной строки для изменения текущего рабочего каталога
.dir		То же самое, что и ls -C -b (список файлов выводится в колонках с вертикальной сортировкой)
.vdir 		То же самое, что и ls -l -b (выводит список файлов в длинном формате)

•du 		программа для оценки занимаемого файлового пространства.
•file 		предназначенная для определения типа файла.
{•find 		утилита поиска файлов по имени и другим свойствам
-name — искать по имени файла, при использовании подстановочных образцов параметр заключается в кавычки.
-type — тип искомого: f=файл, d=каталог, l=ссылка (link), p=FIFO (First In, First Out), s=сокет.
-user — владелец: имя пользователя или UID.
-group — владелец: группа пользователя или GID.
-perm — указываются права доступа.
-size — размер: указывается в 512-байтных блоках или байтах (признак байтов — символ «c» за числом).
-atime — время последнего обращения к файлу.
-ctime — время последнего изменения владельца или прав доступа к файлу.
-mtime — время последнего изменения файла.
-newer другой_файл — искать файлы созданные позже, чем другой_файл.
-delete — удалять найденные файлы.
-ls — генерирует вывод как команда ls -dgils.
-print — показывает на экране найденные файлы.
-exec command {} \; — выполняет над найденным файлом указанную команду; обратите внимание на синтаксис.
-ok — перед выполнением команды указанной в -exec, выдаёт запрос.
-depth или -d — начинать поиск с самых глубоких уровней вложенности, а не с корня каталога.
-maxdepth — максимальный уровень вложенности для поиска. «-maxdepth 0» ограничивает поиск текущим каталогом.
-prune — используется, когда вы хотите исключить из поиска определённые каталоги.
-mount или -xdev — не переходить на другие файловые системы.
-regextype тип — указание типа используемых регулярных выражений.
-P — не разворачивать символические ссылки (поведение по умолчанию).
-L — разворачивать символические ссылки.
SINOPSIS
OPTIONS
EXPRESSIONS
TESTS
ACTIONS
UNUSIALFILENAMES
OPERATORS
STANDARDS CONFORMANCE (соответствие)
ENVINRONMENT VARIABLES
XAMPLES
EXIT STATUS
SEE ALSO
HISTORY
NON-BUGS
BUGS

}
}
{--редактирование папок
•touch 		для установки времени последнего изменения файла или доступа в текущее время
•ln 		устанавливающая связь между файлом и именем файла. (hard link, symbolic linc)
•cp 		команда Unix в составе GNU Coreutils, предназначенная для копирования файлов из одного в другие каталоги (возможно, с другой файловой системой)
•mv 		для перемещения или переименования файлов.
•rm 		для удаления файлов из файловой системы
•mkdir 		команда для создания новых каталогов
•rmdir 		удаляет каталог из файловой системы
•link 		создаёт ссылку на файл  
•unlink 
.chroot		изменение корневого каталога
.mknod 		Создаёт специальные файлы
}
{--просмотр текста
•more 		для просмотра содержимого текстовых файлов
•nl 		выводящая указанный файл на стандартный вывод, добавляя номера строк
•od 		для вывода дампа файла в восьмеричном формате. С разными параметрами, с помощью od можно увидеть содержимое файла в шестнадцатеричном, восьмеричном, десятичном и пр.(можно даже одновременно во всех форматах) виде с любого места любой длиной.
•paste 		рассматривает файлы, как вертикальные колонки, соединяет их и выводит в стандартный поток вывода.
.dircolors	Устанавливает цветовую схему для вывода команды ls
}
{--ручное редактирование текста
•echo 		редназначенная для отображения строки текста
•printf 	вывода в различные потоки значений разных типов, отформатированных согласно заданному шаблону
•read 		читает строку со стандартного ввода
{	текстовые редакторы
•ed 		первый стандартный текстовый редактор операционной системы UNIX, применялся в начале 1970-х. Расширенная его версия, известная как ex, послужила основой редактора vi.
•ex 		расширение редактора ed, наиболее значительным добавлением к которому является возможность экранного редактирования
•vi 		серия текстовых редакторов
}
.shred 		Перезаписывает файлы чтобы скрыть содержимое (так называемое безопасное удаление), и опционально удаляет файлы
}
{--автоматическое редактирование и обработка текста
{	для двоичных файлов
•nm 		печатающая информацию о бинарных файлах (объектных файлах, библиотеках, исполняемых файлах и т. д.), прежде всего таблицу имён. 
•strings 	применяемая для поиска печатаемых строк в двоичных файлах
•uudecode 	представление двоичных данных в текстовом формате
•uuencode 	представление двоичных данных в текстовом формате
}
•wc 		выводящая число переводов строк, слов и байт для каждого указанного файла и итоговую строку, если было задано несколько файлов
•pr 		Разбивает ФАЙЛЫ на страницы или колонки для печати
{	для путей и мен файлов
•basename 	basename — встроенная утилита unix-систем, убирающая имена каталогов и суффикс из имени файла.
•dirname 	предназначенная для преобразования абсолютного или относительного пути к файлу или директории в имя родительской директории.
}
{	табуляции, кодировка, преобразования
•expand 	преобразующая табуляции в пробелы, сохраняя форматированность текста.
•unexpand 	преобразовывающая пробелы в табуляции
•iconv 		для преобразования текста из одной кодировки в другую
•tr 		для преобразования символов
}
{	простая общая обработка
•tee 		выводит на экран, или же перенаправляет, выходной материал команды и копирует его в файл или в переменную

•split 		копирующая файл и разбивающая его на отдельные файлы заданной длины
•cat 		утилита UNIX, выводящая последовательно указанные файлы (или устройства), таким образом, объединяя их в единый поток

•cmp 		Unix-утилита, сравнивает два файла, и если они различаются, сообщает о первом байте и строке, где было обнаружено различие.
•diff 		утилита сравнения файлов, выводящая разницу между двумя файлами
•sort 		выводящая сортированное слияние указанных файлов на стандартный вывод с использованием установленной в среде локали.
•uniq 		можно вывести или отфильтровать повторяющиеся строки в отсортированном файле
•comm 		утилита unix, читает файл1 и файл2, которые должны быть предварительно лексически отсортированы, и генерирует вывод, состоящий из трёх колонок текста: строки, найденные только в файле файл1; строки, найденные только в файле файл2; и строки, общие для обоих файлов. 
•join 		объединяющая строки двух упорядоченных текстовых файлов на основе наличия общего поля

•dd 		программа UNIX, предназначенная как для копирования, так и для конвертации файлов
•head 		выводящая первые n строк из файла, по умолчанию n равно 10
•tail 		выводящая несколько (по умолчанию 10) последних строк из файла.
}
{	сложная общая обработка
•csplit 	разбивает файл на отдельные части, определённые шаблоном  

•grep 		находит на вводе строки, отвечающие заданному регулярному выражению, и выводит их
•cut 		команда выборки отдельных полей из строк файла
•awk 		интерпретируемый скриптовый C-подобный язык построчного разбора и обработки входного потока (например, текстового файла) по заданным шаблонам. Работает в bash (SH) скриптах.
•sed 		потоковый текстовый редактор (а также язык программирования), применяющий различные предопределённые текстовые преобразования к последовательному потоку текстовых данных.
}
}
{--установка и удаление пакетов команд и программ
}
{--справка
•man 		для форматирования и вывода справочных страниц, которая предоставляется почти со всеми *nix-дистрибутивами
}
--...
{--архиваторы
•ar 		unix-утилита, создающая и модифицирующая архивы, а также извлекающая файлы из архива. 
•compress 	сжимает данные для хранения, разжимает и показывает сжатые файлы
•uncompress 	сжимает данные для хранения, разжимает и показывает сжатые файлы
•zcat 			сжать или распаковать файлы  
}
{--системы контроля версий (контроль файлов)
•cksum 		рассчитывает количество байт и контрольную сумму (CRC) в файле по стандарту ISO/IEC 8802-3:1989. 
•hash 		хеширование
•patch 		для переноса правок (изменений) между разными версиями текстовых файлов. 
{•sccs 		frontend для подсистемы sccs
•admin 		создание и управление sccs-файлами (первая в мире система контроля версий)
•delta 		создает разность для данного sccs файла
•get 		вычисляет версию для sccs файла
}
}
{--сеть и интернет
•write 		позволяющая отправить сообщение другому пользователю, который имеет сессию в этой же системе
•lp 		вызывающая печать файлов и связанной с ними информации на принтере

•uucp 		команда копирования файлов между двумя компьютерами под управлением операционной системы UNIX, использующая одноимённый протокол

ssh			secure shell
	ssh [[user@]host]
scp			secure copy
	scp src dst
	[[user@]host:]file   //отн /home/user или абсолютный
}
{--прочее общее администрирование системы 
	(дата-время, включение, выключение компа
	управление процессами
	пользователи, права, сопоставления файлов, 
	начальная загрузка, 
	драйвера, 
	диски)
{	получение общей информации о системе (время, пользователь, локаль, терминал)
•uname 		выводящая информацию о системе.
•cal 		UNIX?утилита, отображающая простой календарь
•date 		утилита Unix для работы с системными часами. 
•id 		выводящая информацию об указанном пользователе USERNAME или текущем пользователе
•logname 	выводящая имя пользователя, вызывающего команду
•locale 	выводящая информацию о локали. (это набор параметров, включая набор символов, язык пользователя, страну, часовой пояс, а также другие предустановки, которые пользователь ожидает видеть в пользовательском интерфейсе)
•tty 		выводящая имя терминала, соединённого со стандартным вводом
}
{	выполнение по расписанию
•at 		unix-утилита, читающая команды со стандартного входного потока и группирующая их в виде задания at для выполнения позже, в заданное время.
•crontab (cron)	демон-планировщик задач в UNIX-подобных операционных системах, использующийся для периодического выполнения заданий в определённое время.
}
{	управление процессами
•logger 	предоставляющая командный интерфейс для модуля системного журнала syslog.
•time 		щающая время выполнения простой команды или получение подсказки по ресурсу
•ps 		выводящая отчёт о работающих процессах.
•kill 		посылает указанный сигнал указанному процессу. Если не указано ни одного сигнала, посылается сигнал SIGTERM. Сигнал SIGTERM завершит те процессы, которые не обрабатывают его приход
•wait 		Ждёт завершения указанного процесса и возвращает статус его завершения.
•nice 		утилита, запускающая программу с измененным приоритетом для планировщика задач
•renice 	позволяющая изменить приоритет запущенных задач. 
•fg 		служащих для управления процессами. Команда позволяет возобновить работу приостановленного процесса или вывести его из фонового режима.
•nohup 		запускающая указанную команду с игнорированием сигналов потери связи (hangup)таким образом, команда будет продолжать выполняться в фоновом режиме и после того, как пользователь выйдет из системы
}
{	пользователи
•who 		показывает текущих пользователей в компьютерной системе
}
{	права доступа
•chgrp 		утилита UNIX. Может использоваться непривелигированными пользователями для изменения группы файлов
•chmod 		программа для изменения прав доступа к файлам и директориям
•chown 		UNIX?утилита, изменяющая владельца и/или группу для указанных файлов
•umask 		изменяющая права доступа, которые присваиваются новым файлам и директориям по умолчанию
•mesg 		управляет доступом на запись для терминала данного пользователя. Обычно используется для разрешения или запрета другим пользователям писать на терминал данного пользователя.
}
{	диски
•df 		показывает список всех файловых систем по именам устройств, сообщает их размер, занятое и свободное пространство и точки монтирования.
•fuser 		идентифицирующая процессы, которые используют указанные файлы или сокеты.
.sync 		Записывает на диск буферы файловых систем
}
}
{--модели одних систем в других системах
}
--...
{--наборы компиляторов
•m4 		Макропроцессор m4,
•c99 		стандартный компилятор
•fort77 	компилятор фортрана
}
{--иде
•ctags 		утилита, собирающая информацию об именах и позициях переменных, функций и процедур, встречающихся в исходном коде
}
{--автотулс
•make 		автоматизирующая процесс преобразования файлов из одной формы в другую
}
{--скриптовые языки
•bc 		интерактивный интерпретатор Си-подобного языка, позволяет выполнять вычисления с произвольно заданной точностью. 
•expr 		вычисляющая значение выражения и выводящая результат на стандартный вывод
.factor		выдает простые множители числа
•lex 		программа для генерации лексических анализаторов, обычно используемая совместно с генератором синтаксических анализаторов yacc
•yacc 		компьютерная программа, служащая стандартным генератором синтаксических анализаторов (парсеров)
}
{рабочий стол
{gnome
    gconf-editor  графический аналог утилиты gconftool
    дает доступ к настройкам, хранящимся в xml файлах
    gconftool
}
}
------------------------------------------------
• - POSIX
. - GNU only
------------------------------------------------

install 	Копирует файлы и устанавливает атрибуты
•bg 
•jobs 

•asa 
•batch 
•cflow 
•command 
•cxref 
•fold 
•gencat 
•getconf 
•getopts 
•ipcrm 
•ipcs 
•localedef 
•mailx 		
•newgrp 
•pathchk 
•pax 
•prs 
•qalter 
•qdel 
•qhold 
•qmove 
•qmsg 
•qrerun 
•qrls 
•qselect 
•qsig 
•qstat 
•qsub 
•rmdel 
•sact 
•strip 
•stty 
•tabs 
•talk 
•tput 
•tsort 
•type 
•ulimit 
•unalias 
•unget 
•uustat 
•uux 
•val 
•what 
