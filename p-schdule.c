#include <stdio.h>
struct Process
{
int WT, AT, BT, TAT;
};
struct Process a[10];
void main()
{
int i, n, count, t, temp[10], short_P;
count = 0;
t = 0;
float Total_WT, Total_TAT, Avg_WT, Avg_TAT;
printf("Enter the number of processes : ");
scanf("%d", &n);
printf("Enter the arrival time and burst time :\n");
printf("AT BT\n");
for(i=0;i<n;i++)
{
scanf("%d %d", &a[i].AT, &a[i].BT);
temp[i]=a[i].BT;
}
a[9].BT=10000;
for(t=0;count!=n;t++)
{
short_P=9;
for(i=0;i<n;i++)
{
if(a[i].BT<a[short_P].BT && (a[i].AT<=t &&
a[i].BT>0))
{
short_P=i;
}
}
a[short_P].BT = a[short_P].BT-1;
if(a[short_P].BT==0)
{
count++;
a[short_P].WT =
t+1-a[short_P].AT-temp[short_P];
a[short_P].TAT = t+1-a[short_P].AT;
Total_WT = Total_WT+a[short_P].WT;
Total_TAT = Total_TAT+a[short_P].TAT;
}
}

Avg_WT = Total_WT/n;
Avg_TAT = Total_TAT/n;
printf("WT\tTAT\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\n", i+1, a[i].WT, a[i].TAT);
}
printf("THE AVERAGE WAITING TIME IS :%f\n",Avg_WT);
printf("THE AVERAGE TURN AROUND TIME IS: %f\n",Avg_TAT);
}