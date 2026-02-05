#!/bin/bash

# Остановка при любой ошибке
set -e

DIR="mydir"

# Создание директории
mkdir -p "$DIR"

# Создание файлов
touch "$DIR/file1.txt"
touch "$DIR/file2.txt"
touch "$DIR/file3.txt"
touch "$DIR/file4.txt"
touch "$DIR/file5.txt"

# Установка прав доступа
chmod 644 "$DIR/file1.txt"
chmod 755 "$DIR/file2.txt"
chmod 600 "$DIR/file3.txt"
chmod 444 "$DIR/file4.txt"
chmod 700 "$DIR/file5.txt"

# Вывод содержимого директории с правами
ls -l "$DIR"