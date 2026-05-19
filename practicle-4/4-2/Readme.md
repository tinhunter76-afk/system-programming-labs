Перед тем, как компилировать, создаём текстовый файл, из которого будем считать.
Название: text.txt
Содержимое:
Apple and banana
Amazing animals

Компиляция: gcc -Wall -Wextra -o task task.c
запуск: ./task
результат: Number of 'a' and 'A': 9
