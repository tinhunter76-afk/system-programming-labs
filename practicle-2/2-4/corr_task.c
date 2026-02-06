#include <stdio.h>

int main(void) {
    FILE *f = fopen("file.txt", "w");
    if (!f) {
        perror("fopen");
        return 1;
    }

    fprintf(f, "Hello\n");
    fclose(f);
    return 0;
}