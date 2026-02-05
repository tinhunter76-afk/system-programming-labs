ПРАКТИКА 1: СИСТЕМНЫЕ ВЫЗОВЫ, ПРОЦЕССЫ, ФАЙЛЫ
Задание 1-3: Файловая система и права
Описание задания: Создать директорию mydir, 5 файлов file1.txt-file5.txt. Установить права: file1=644, file2=755, file3=600, file4=444, file5=700. Вывести ls -l mydir
Требования:
Bash скрипты
Работа с правами доступа (chmod)
Запуск: chmod +x script.sh && ./script.sh

Результат вывода:

vboxuser@ubuntu1:/media/sf_ucheba/SisProg/Pr-01/003$ chmod +x task.sh && ./task.sh
total 0
-rwxrwx--- 1 root vboxsf 0 Feb  5 14:11 file1.txt
-rwxrwx--- 1 root vboxsf 0 Feb  5 14:11 file2.txt
-rwxrwx--- 1 root vboxsf 0 Feb  5 14:11 file3.txt
-rwxrwx--- 1 root vboxsf 0 Feb  5 14:11 file4.txt
-rwxrwx--- 1 root vboxsf 0 Feb  5 14:11 file5.txt

Примечания: работа делалась в блокноте, запусказась в терминале Ubuntu.


