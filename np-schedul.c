#include <stdio.h>

int main() {
    int pr, i, t = 0;
    float avg;
    printf("Enter the number of processes: \n");
    scanf("%d", &pr);

    char P[10][10]; // 2D array to store process names
    int Burst_Time[10], Wait_Time[10];

    for(i = 0; i < pr; i++) {
        printf("Enter the name of process %d: \n", i + 1);
        scanf("%s", P[i]);
        printf("Enter the burst time of %s: \n", P[i]);
        scanf("%d", &Burst_Time[i]);
    }

    Wait_Time[0] = 0;
    for(i = 1; i < pr; i++) {
        Wait_Time[i] = Wait_Time[i - 1] + Burst_Time[i - 1];
        t += Wait_Time[i];
    }

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\n");
    for(i = 0; i < pr; i++) {
        printf("%s\t%d\t\t%d\n", P[i], Burst_Time[i], Wait_Time[i]);
    }

    avg = (float)t / pr;
    printf("Total waiting time: %d\n", t);
    printf("Average waiting time: %.2f\n", avg);

    return 0;
}
