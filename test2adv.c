#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char input[99];
    char line[99];
    char key[99], value[99];
    int found;

    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("�Һ��ź�����ȷʵ�޷����ļ�\n");
        return 1;
    }

    while (1) {
        printf("�������룺");
        scanf("%98s", input);

        if (strcmp(input, "Quit") == 0) {
            break;
        }
        found = 0;   

        while (fgets(line, sizeof(line), fp)) {
            if (sscanf(line, "%98[^:]:%98s", key, value) == 2) {
                if (strcmp(input, key) == 0) {
                    printf("%s\n", value);
                    found = 1;
                    break;
                }
            }
        }

        if (!found) {
            printf("Error\n");
        }
    }

    fclose(fp);
    return 0;
}
