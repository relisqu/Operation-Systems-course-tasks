#include <stdio.h>
#include <stdlib.h>

FILE *input_file;
long n_frames, hit = 0, miss=0;

struct frame {
    unsigned char age;
    int page_num;
} *frames;

void init_frames() {
    frames = malloc(n_frames*sizeof(struct frame));
    if (frames == NULL) {
        exit(EXIT_FAILURE);
    }

    for (long i = 0; i < n_frames; ++i) {
        frames[i].age = 0;
        frames[i].page_num = -1;
    }
}

void read_file(char *name) {
    input_file = fopen(name, "r");
    if (input_file == NULL) {
        free(frames); //File is locked/missing - exit program
        exit(EXIT_FAILURE);
    }
}

void get_n_frames() {
    printf("Enter number of frames: ");
    scanf("%ld", &n_frames);
    printf("\n");
}

// Aging algorithm
void update_frames(int next_page) {
    long min_index = 0;
    for (long i = 0; i < n_frames; ++i) {
        if(frames[i].page_num == -1) {
            min_index = i;
            break;
        }
        if (frames[i].age < frames[min_index].age) {
            min_index = i;
        }
        frames[i].age >>= 1;//Aging all pages
    }

    for (long i = 0; i < n_frames; ++i) {
        if (frames[i].page_num == next_page) { //Hit case

            frames[i].age |= (1 << 7);
            hit++;
            return;
        }
    }
    miss++; //Miss case
    frames[min_index].age = 1 << 7;
    frames[min_index].page_num = next_page;
}

void print_results() {
    printf("Hits number: %ld\n", hit);
    printf("Misses number: %ld\n", miss);
    printf("Hits/Misses ratio: %f\n", (double)hit/miss);
}

int main() {
    get_n_frames();
    init_frames();
    read_file("input.txt");

    int next_page;
    while (fscanf(input_file, "%d", &next_page) != EOF) {
        update_frames(next_page);
    }

    print_results();
    free(frames);
}

