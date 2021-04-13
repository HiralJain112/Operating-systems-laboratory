#include<stdio.h>
#include<conio.h>

int main()
{
             int n,Bt[10],Wt[10],Tat[10],i,At[10],j;
             
             printf("\nEnter the number of processes= ");
             scanf("%d",&n);
             printf("\nEnter the arrival time for all processes: ");
             for(i=0;i<n;i++)
             {
                 printf("\nArrival Time for process P%d= ",i+1);
                 scanf("%d",&At[i]);
             }
             printf("\nEnter the Burst Time for all processes: ");
             for(i=0;i<n;i++)
             {
                 printf("\nBurst Time for process P%d= ",i+1);
                 scanf("%d",&Bt[i]);
             }
             Wt[0]=0;
             for(i=1;i<n;i++)
             {
                 j=i-1;
                 Wt[i]=0;
                 while(j>=0)
                 {
                    Wt[i]=Wt[i]+Bt[j];
                    j--;
                 }
                 Wt[i]=Wt[i]-At[i];
                 Tat[i]=Wt[i]+Bt[i];
             }
             Tat[0]=Wt[0]+Bt[0];
             printf("\nProcess no. AT BT WT TAT");
             for(i=0;i<n;i++)
             {
                 printf("\nP%d           %d %d  %d  %d",i+1,At[i],Bt[i],Wt[i],Tat[i]);
             }
    getch();
    return 0;
}
