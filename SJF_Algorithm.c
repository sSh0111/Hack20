#include<stdio.h>
 
int main()
{
    int bt[20], p[20], wt[20], tat[20], i, j, n, total=0, pos, temp;
    float avg_wt, avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("process %d : ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //to store process number(process id)
    }
 
    //sorting burst time in ascending order(Selection sort)
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process is always zero
 
    //to calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //calculating average waiting time
    total=0;
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculating turnaround time
        total+=tat[i];
        printf("\np%d\t\t%d\t\t%d\t\t\t%d",i,bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //calculating average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
    
    printf("\n\nSubmitted by \'Yash Ray\', 19BCE0235");
    return 0;
}
