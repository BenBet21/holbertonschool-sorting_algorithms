#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[] = {7, 13, 19, 48, 52, 71, 73, 86, 96, 99};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", numbers[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    return 0;
}
