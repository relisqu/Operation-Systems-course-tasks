#include <pthread.h>
#include <stdio.h>
#define shelf_size 15
char products[shelf_size];
int  consumer,producer, pos;
long long int timer;

void* Produce(void* a){
    while(1){
        if(producer != 0)
            continue;
        if(pos == shelf_size){
            consumer = 0;
            producer = 1;
            printf("Produced all letters. Current time: %lld.\n", timer++);
            continue;
        }

        products[pos] = 'a' + pos;
	printf("Produced letter: %c\n",products[pos]);
        pos++;
    }
    pthread_exit(0);
    return 0;
}

void* Consume(void* a){
    while(1){
        if(consumer != 0)
            continue;
        if(pos == 0){
            consumer = 1;
            producer = 0;
	    printf("Consumed all letters.\n");
            continue;
        }
        printf("Consumed letter: %c\n", products[--pos]);
    }
    pthread_exit(0);
    return 0;
}


int main(){
    producer = 1;

    pthread_t tProd,tCon;
    pthread_create(&tProd,0,Produce,0);
    pthread_create(&tCon,0,Consume,0);
    while(1);
}
