#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_PROCESS 100

int main() {
    int bt[MAX_PROCESS], original_bt[MAX_PROCESS], at[MAX_PROCESS], tat[MAX_PROCESS],
    wt[MAX_PROCESS], et[MAX_PROCESS];
    bool executed[MAX_PROCESS];

    int i,n, quantum;
    float totalTAT = 0.0, totalWT = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter quantum: ");
    scanf("%d", &quantum);

    printf("Enter Arrival time and Burst time for each process:\n");

    for (i = 0; i < n; i++) {
        printf("Arrival time of process[%d]: ", i + 1);
        scanf("%d", &at[i]);
        executed[i] = false;
        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        original_bt[i] = bt[i];
    }

    int cur_time = at[0], finished = 0;
    i = 0;
    while (finished != n) {
        if (executed[i] == true) {
            i = (i + 1)%n;
            continue;
        }
        // if process can be completed fully
        if (bt[i] <= quantum) {
            cur_time += bt[i];
            et[i] = cur_time; // calculate ET

            tat[i] = et[i] - at[i]; // calculate TAT
            totalTAT += tat[i];

            wt[i] = tat[i] - original_bt[i]; // calculate WT
            totalWT += wt[i];
            finished++;
            executed[i] = true;
            i = (i + 1)%n;
        } else {
            // else do it partly and move to next process
            cur_time += quantum;
            bt[i] -= quantum;
            i = (i + 1)%n;
        }
    }

    printf("P#\t AT\t BT\t ET\t TAT\t WT\n\n");
    for (i = 0; i < n; i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, at[i], bt[i], et[i], tat[i], wt[i]);

    printf("Average TAT = %f\n", totalTAT/n);
    printf("Average WT = %f\n", totalWT/n);
}

