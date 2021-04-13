//program to implement SJF with FCFS scheduling algorithms When Arrival time is same.

#include<stdio.h>
#include<conio.h>

int main()
{
             int n,Bt[10],Wt[10],Tat[10],i,At,j,temp,p[10];
             float avgTAT,avgWt,NTAT[10];
             
             printf("\nEnter the number of processes= ");
             scanf("%d",&n);
             printf("\nEnter the same arrival time for all processes: ");
             scanf("%d",&At);
             printf("\nEnter the Burst Time for all processes: ");
             for(i=0;i<n;i++)
             {
                 printf("\nBurst Time for process P%d= ",i+1);
                 scanf("%d",&Bt[i]);
                 p[i]=i+1;
             }
             for(j=1;j<n;j++)
             {
               temp=Bt[j];
               i=j-1;
               while(i>=0 && Bt[i]>temp)
               {
                 Bt[i+1]=Bt[i];
                 p[i+1]=p[i];
                 i--;
               }
               Bt[i+1]=temp;
               p[i+1]=j+1;
             }
             Wt[0]=0;
             for(i=1;i<n;i++)
             {
                 Wt[i]=Wt[i-1]+Bt[i-1];
                 Tat[i]=Wt[i]+Bt[i];
             }
             Tat[0]=Wt[0]+Bt[0];
             printf("\nProcess no. AT BT WT TAT   NTAT");
             avgTAT=0;
             for(i=0;i<n;i++)
             {
                 NTAT[i]=(float)Tat[i]/Bt[i];
                 printf("\nP%d           %d %d  %d   %d  %f",p[i],At,Bt[i],Wt[i],Tat[i],NTAT[i]);
             
                 avgTAT+=Tat[i];
                 avgWt+=Wt[i];
             }
             avgTAT=(float)avgTAT/n;
             avgWt=(float)avgWt/n;
             printf("\n Average Turn around time =%f\n Average Waiting time =%f",avgTAT,avgWt);
    getch();
    return 0;
}
