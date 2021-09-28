#include <stdio.h>
#define MAX_PROCESS 100

int main() {
    int bt[MAX_PROCESS], at[MAX_PROCESS], tat[MAX_PROCESS];
    int wt[MAX_PROCESS], et[MAX_PROCESS];

    int n,i;
    float totalTAT = 0.0, totalWT = 0.0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Arrival time and Burst time for each process:\n");

    for (i = 0; i < n; i++) {
        printf("Arrival time of process[%d]: ", i + 1);
        scanf("%d", &at[i]);

        printf("Burst time of process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int cur_time = at[0];
    for (i = 0; i < n; i++) {
        cur_time += bt[i];
        et[i] = cur_time; // calculate ET

        tat[i] = et[i] - at[i]; // calculate TAT
        totalTAT += tat[i];

        wt[i] = tat[i] - bt[i]; // calculate WT
        totalWT += wt[i];
    }
    
    printf("P#\t AT\t BT\t ET\t TAT\t WT\n\n");
    for (i = 0; i < n; i++)
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i+1, at[i], bt[i], et[i], tat[i], wt[i]);

    printf("Average TAT = %f\n", totalTAT/n);
    printf("Average WT = %f\n", totalWT/n);
}
