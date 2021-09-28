#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX_PROCESS 100

int main() {
    int bt[MAX_PROCESS], at[MAX_PROCESS], tat[MAX_PROCESS], wt[MAX_PROCESS], et[MAX_PROCESS];
    bool executed[MAX_PROCESS] = {};

    int i,j;
    float totalTAT = 0.0, totalWT = 0.0;
    int n, min_at = INT_MAX;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Arrival time and Burst time for each process:\n");

    for (i = 0; i < n; i++) {
        printf("Arrival time of process[%d]: ", i + 1);
        scanf("%d", &at[i]);
        if (at[i] < min_at)
            min_at = at[i];
        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int cur_time = min_at;
    for (i = 0; i < n; i++) {
        int pos = 0, min_bt = INT_MAX;
        for (j = 0; j < n; j++) {
            if (!executed[j] && at[j] <= cur_time && bt[j] < min_bt) {
                pos = j;
                min_bt = bt[j];
            }
        }
        executed[pos] = true;
        cur_time += bt[pos];
        et[pos] = cur_time; // calculate ET

        tat[pos] = et[pos] - at[pos]; // calculate TAT
        totalTAT += tat[pos];

        wt[pos] = tat[pos] - bt[pos]; // calculate WT
        totalWT += wt[pos];
    }

    printf("P#\t AT\t BT\t ET\t TAT\t WT\n\n");
    for (i = 0; i < n; i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, at[i], bt[i], et[i], tat[i], wt[i]);

    printf("Average TAT = %f\n", totalTAT/n);
    printf("Average WT = %f\n", totalWT/n);
}

