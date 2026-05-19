#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main() {

    const char *filename = "text.txt";

    // открытие файла
    int fd = open(filename, O_RDONLY);

    if (fd < 0) {
        perror("open");
        return 1;
    }

    // получение информации о файле
    struct stat st;

    if (fstat(fd, &st) < 0) {
        perror("fstat");
        close(fd);
        return 1;
    }

    // размер файла
    size_t filesize = st.st_size;

    // отображение файла в память
    char *data = mmap(
            NULL,
            filesize,
            PROT_READ,
            MAP_PRIVATE,
            fd,
            0
    );

    if (data == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    // подсчёт символов 'a' и 'A'
    int count = 0;

    for (size_t i = 0; i < filesize; i++) {

        if (data[i] == 'a' || data[i] == 'A') {
            count++;
        }
    }

    // вывод результата
    printf("Number of 'a' and 'A': %d\n", count);

    // освобождение отображения
    if (munmap(data, filesize) < 0) {
        perror("munmap");
    }

    // закрытие файла
    close(fd);

    return 0;
}