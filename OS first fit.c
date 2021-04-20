#include<stdio.h>
#define max 10

void main()
{
	int frag[max],Block_no[max],Process_size[max],i,j,no_of_blocks,no_of_processes,temp;
	static int Block_Size[max]/*Block_no[max]*/;
	int flag,flagn[max];

	printf("\n\tDynamic Memory Allocation : First Fit");
	printf("\nEnter the number of blocks:");
	scanf("%d",&no_of_blocks);
	printf("Enter the number of Process:");
	scanf("%d",&no_of_processes);
	printf("\nEnter the sizes of the blocks:-\n");

	for(i=1;i<=no_of_blocks;i++) {
		printf("B %d:",i);
		scanf("%d",&Block_Size[i]);
		Block_no[i] = i;
	}
	printf("Enter the sizes of the Processes :-\n");

	for(i=1;i<=no_of_processes;i++) {
		printf("P %d:",i);
		scanf("%d",&Process_size[i]);
	}
	int x = 1;
	printf("\n\nProcess_No\tProcess_Size\tBlock_No\tBlock_Size\tRemaining Memory(fragment)\n");
	for(i=1;i<=no_of_processes;i++)
	{
		flag = 1;
		for(j=x;j<=no_of_blocks;j++)		
		{
			if(Process_size[i] <= Block_Size[j]){
				flagn[j] = 1;
				printf("%-15d\t%-15d\t%-15d\t%-15d\t",i, Process_size[i],Block_no[j],Block_Size[j]);
				Block_Size[j] = Block_Size[j] - Process_size[i];
				printf("%-15d\n",Block_Size[j]);
				break;
			}
			else
			{flagn[j] = 0;
				x = 1;
			flag++;
			}
		}
		if(flag > no_of_blocks)
		printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n",i, Process_size[i],"HOLE","HOLE","HOLE");
	}
 return 0;
}
