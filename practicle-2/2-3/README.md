ПРАКТИКА 2: ПОТОКИ, СИНХРОНИЗАЦИЯ, СИГНАЛЫ

Задание 2-3: Обработка сигналов
Описание задания: Программа выводит "Working..." каждую секунду (бесконечный цикл). При SIGINT (Ctrl+C) выводит "Caught SIGINT" и корректно завершается
Требования:
Используйте signal() или sigaction()
Обработчик должен быть async-signal-safe (используйте write() вместо printf())
Флаги: volatile sig_atomic_t

Результаты вывода:
Working...
Working...
Working...
Working...
^CCaught SIGINT

Примечания:
Программа корректно завершилась при Ctrl+C, вывела Caught SIGINT

Вывод:
В обработчике сигнала только async-signal-safe функции



