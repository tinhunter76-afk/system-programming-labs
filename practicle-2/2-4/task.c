#include <stdio.h>

int main(void) {
    FILE *f = fopen("nofile.txt", "r");
    if (!f) {
        perror("fopen");
        return 1;
    }
    fclose(f);
    return 0;
}