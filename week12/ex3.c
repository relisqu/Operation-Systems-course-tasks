#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <linux/input.h>
#include <linux/input-event-codes.h>
 
const int codes[3][3] = {
        {0,  25, 18}, //pe
        {46, 30, 25}, //cap
        {46, 30, 20} //cat
};
 
void add_to_queue(int *queue, int value, int size) {
    for (int i = 1; i < size; i++) {
        queue[i - 1] = queue[i];
    }
    queue[size - 1] = value;
}
 
int main(void) {
    char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int current_code_queue[3] = {0, 0, 0};
 
    int fd = open(dev, O_RDONLY);
    if (fd < 0) exit(EXIT_FAILURE);
 
    struct input_event evt;
    while (1) {
        ssize_t b = read(fd, &evt, sizeof(evt));
        if (evt.type == EV_KEY) {
            if (evt.value == 1) add_to_queue(current_code_queue, evt.code, 3);
            else continue;
 
            for (int i = 0; i < 3; i++) {
                int got_any_combination = 1;
                for (int j = 0; j < 3; j++) {
                    if (codes[i][j] == 0) continue;
                    if (current_code_queue[j] != codes[i][j]) {
                        got_any_combination = 0;
                        break;
                    }
                }
                if (got_any_combination) {
                    switch (i) {
                        case 0:
                            printf("\nI passed the Exam!\n");
                            break;
                        case 1:
                            printf("\nGet some cappuccino!\n");
                            break;
                        case 2:
                            printf("\nMeow meow meow!\n");
                            break;
                    }
                    break;
                }
            }
            fflush(stdout);
        }
    }
    exit(EXIT_SUCCESS);
}
