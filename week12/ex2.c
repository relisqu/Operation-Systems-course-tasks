#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <linux/input-event-codes.h>
 
int main(void){
    char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event evt;
    int fd = open(dev, O_RDONLY);
    if (fd < 0) exit(EXIT_FAILURE);
    while(1){
        ssize_t b = read(fd, &evt, sizeof(evt));
        if (evt.type != EV_KEY || evt.value == 2)continue;
        if(evt.value){
            printf("\nPRESSED ");
        }else{
            printf("\nRELEASED ");
        }
        printf("%x (%d)\n", evt.code, evt.code);
        fflush(stdout);
    }
    exit(EXIT_SUCCESS);
}
