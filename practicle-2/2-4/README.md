ПРАКТИКА 2: ПОТОКИ, СИНХРОНИЗАЦИЯ, СИГНАЛЫ

Задание 2-4: Отладка с strace
Описание задания: Написать программу, открывающую несуществующий файл. Запустить strace ./program 2>&1 | grep open. Найти ошибку ENOENT. Исправить программу
Требования:
Используйте strace для анализа системных вызовов
Сохраните команды и результаты в analysis.txt

Результаты вывода:

Вывод программы с ошибкой:

openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "nofile.txt", O_RDONLY) = -1 ENOENT (No such file or directory)
write(2, "fopen: No such file or directory"..., 33fopen: No such file or directory

Результат после Правки программы (заставляем её создать файл, если такового нет):

openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "file.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666) = 3

Примечания:
task.c - программа с ошибкой
corr_task.c - программа исправленная

Вывод:
strace показывает реальные системные вызовы и коды ошибок ядра



