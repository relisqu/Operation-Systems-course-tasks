#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int process_number = 0, nres = 0;
    char *input_line = malloc(255 * sizeof(char));
    FILE *f = fopen("input.txt", "r");

    int *e = malloc(255 * sizeof(int));

    fgets(input_line, 255, f);

    char *cur_token = strtok(input_line, " ");

    while (cur_token != NULL) {
        e[nres++] = atoi(cur_token);
        cur_token = strtok(NULL, " ");
    }
    e = realloc(e, nres * sizeof(int));
    fgets(input_line, 255, f);
    fgets(input_line, 255, f);

    int *a = malloc(nres * sizeof(int));
    int i = 0;

    cur_token = strtok(input_line, " ");

    while (cur_token != NULL) {
        a[i++] = atoi(cur_token);
        cur_token = strtok(NULL, " ");
    }

    fgets(input_line, 255, f);
    fgets(input_line, 255, f);
    int **c = malloc(255 * sizeof(int *));

    while (strcmp(input_line, "\n")) {
        c[process_number] = malloc(nres * sizeof(int));

        cur_token = strtok(input_line, " ");
        int k = 0;
        while (cur_token != NULL) {
            c[process_number][k++] = atoi(cur_token);
            cur_token = strtok(NULL, " ");
        }

        process_number++;
        fgets(input_line, 255, f);
    }

    c = realloc(c, process_number * sizeof(int *));

    fgets(input_line, 255, f);

    int **r = malloc(process_number * sizeof(int *));
    int j = 0;
    while (fgets(input_line, 255, f)) {
        r[j] = malloc(nres * sizeof(int));

        cur_token = strtok(input_line, " ");
        int k = 0;
        while (cur_token != NULL) {
            r[j][k++] = atoi(cur_token);
            cur_token = strtok(NULL, " ");
        }

        ++j;
    }
    fclose(f);
    free(cur_token);
    free(input_line);


    printf("\nE:\n");
    for (int i = 0; i < nres; ++i) {
        printf("%d ", e[i]);
    }
    printf("\n\nA:\n");

    for (int i = 0; i < nres; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n\nC:\n");

    for (int i = 0; i < process_number; ++i) {
        for (int k = 0; k < nres; ++k) {
            printf("%d ", c[i][k]);
        }
        printf("\n");
    }
    printf("\nR:\n");
    for (int i = 0; i < process_number; ++i) {
        for (int k = 0; k < nres; ++k) {
            printf("%d ", r[i][k]);
        }
        printf("\n");
    }

    char wasChanged = 1;
    char *process_executed = malloc(process_number * sizeof(char));

    for (int i = 0; i < process_number; ++i) {
        process_executed[i] = 0;
    }

    while (wasChanged) {
        wasChanged = 0;

        for (int cur_proc = 0; cur_proc != process_number; ++cur_proc) {
            if (process_executed[cur_proc])
                continue;

            char process_executable = 1;
            for (int cur_res = 0; cur_res != nres; ++cur_res) {
                if (a[cur_res] + c[cur_proc][cur_res] < r[cur_proc][cur_res]) {
                    process_executable = 0;
                    break;
                }
            }

            if (process_executable) {
                wasChanged = 1;

                for (int cur_res = 0; cur_res != nres; ++cur_res) {
                    a[cur_res] += c[cur_proc][cur_res];
                }

                process_executed[cur_proc] = 1;
            }
        }

        printf("List of executed processes: \n");
        for (int i = 0; i != process_number; ++i) {
            if (process_executed[i]) {
                printf("Process[%d] was executed. \n", i);
            } else {
                printf("Process[%d] wasn't executed. \n", i);
            }
        }
        printf("\nCurrent available resources: \n");
        for (int i = 0; i != nres; ++i) {
            printf("%d ", a[i]);
        }
    }

    int deadlock_number = 0;

    for (int i = 0; i < process_number; ++i) {
        if (!process_executed[i]) {
            ++deadlock_number;
        }
    }

    if (!deadlock_number) {
        printf("\nNo deadlocks found.\n");
    } else {
        printf("\nThere are %d deadlocked processes.\n", deadlock_number);
    }

    return 0;
}
