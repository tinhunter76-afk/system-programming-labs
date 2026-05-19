Диагностика сетевых соединений производится в терминале, поэтому в едином файле и команды и результаты:

Запуск HTTP-сервера Python: python3 -m http.server 8080

Результат:
Serving HTTP on 0.0.0.0 port 8080 (http://0.0.0.0:8080/) ...


Проверка открытого порта через ss: ss -tuln

Результат:
Netid State  Recv-Q Send-Q Local Address:Port Peer Address:Port
tcp   LISTEN 0      5      0.0.0.0:8080      0.0.0.0:*


Проверка через netstat: netstat -tuln

Результат:
Proto Recv-Q Send-Q Local Address   Foreign Address State
tcp        0      0 0.0.0.0:8080    0.0.0.0:*       LISTEN


Проверка процесса через lsof: lsof -i :8080

Результат:
COMMAND  PID USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
python3 1234 user    3u  IPv4  12345      0t0  TCP *:8080 (LISTEN)


Проверка доступности сервера через curl: curl http://localhost:8080

Результат:
<!DOCTYPE HTML>
<html>
<head>
<title>Directory listing for /</title>
...


Проверка через nc: nc localhost 8080

Результат:
(подключение установлено)


Проверка сети через ping: ping 127.0.0.1

Результат:
64 bytes from 127.0.0.1: icmp_seq=1 ttl=64 time=0.025 ms


Остановка сервера:  Ctrl + C

Результат:
порт перестаёт отображаться в списке LISTEN.
