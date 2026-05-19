Запуск клиента и сервера - в разных терминалах!

компиляция сервера: gcc -Wall -Wextra -o server server.c
запуск: ./server
результат:
Server is waiting on port 8080...
Message sent to client.

компиляция клиента: gcc -Wall -Wextra -o client client.c
запуск: ./client
Результат: Received from server: Hello from server
