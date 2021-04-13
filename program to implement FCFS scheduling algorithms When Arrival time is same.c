//program to implement FCFS scheduling algorithms When Arrival time is same.

#include<stdio.h>
#include<conio.h>

int main()
{
             int n,Bt[10],Wt[10],Tat[10],i,At;
             
             printf("\nEnter the number of processes= ");
             scanf("%d",&n);
             printf("\nEnter the same arrival time for all processes: ");
             scanf("%d",&At);
             printf("\nEnter the Burst Time for all processes: ");
             for(i=0;i<n;i++)
             {
                 printf("\nBurst Time for process P%d= ",i+1);
                 scanf("%d",&Bt[i]);
             }
             Wt[0]=0;
             for(i=1;i<n;i++)
             {
                 Wt[i]=Wt[i-1]+Bt[i-1];
                 Tat[i]=Wt[i]+Bt[i];
             }
             Tat[0]=Wt[0]+Bt[0];
             printf("\nProcess no. AT BT WT TAT");
             for(i=0;i<n;i++)
             {
                 printf("\nP%d           %d %d  %d   %d ",i+1,At,Bt[i],Wt[i],Tat[i]);
             }
    getch();
    return 0;
}

