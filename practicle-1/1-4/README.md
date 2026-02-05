ПРАКТИКА 1: СИСТЕМНЫЕ ВЫЗОВЫ, ПРОЦЕССЫ, ФАЙЛЫ
Задание 1-4: Диагностика процессов
Описание задания:
1.Запустить sleep 300 &
2.Найти PID: ps aux | grep sleep
3.Вывести /proc/[PID]/status
4.Отправить SIGTERM: kill [PID]
5.Проверить завершение
Требования:
Используйте утилиты: ps, top, lsof, /proc, kill
Сохраните команды и результаты

Результаты вывода:

1.
[1] 6208

2.
vboxuser    6208  0.0  0.0   8296  2052 pts/0    S    14:29   0:00 sleep 300
vboxuser    6229  0.0  0.0   9152  2276 pts/0    S+   14:33   0:00 grep --color=auto sleep

3.
Фрагмент вывода:
ame:	sleep
Umask:	0002
State:	S (sleeping)
Tgid:	6249
Ngid:	0
Pid:	6249
PPid:	5945
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	256
Groups:	27 986 1000 
NStgid:	6249
NSpid:	6249
NSpgid:	6249
NSsid:	5945

4.
kill 6249

5.
vboxuser    6277  0.0  0.0   9152  2280 pts/0    S+   14:49   0:00 grep --color=auto sleep



Дополнения:
Работа делалась в терминале Ubuntu
В 3 пришлось перезапускать sleep 300 &, получать новый код 6249 и уже по нему работать.
в 4 Kill по умолчанию SIGTERM




