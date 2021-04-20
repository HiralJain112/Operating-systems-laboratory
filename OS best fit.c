#include<stdio.h>
#define max 10

int main()
{
 int frag[max],Block_size[max],Process_size[max],i,j,no_of_blocks,no_of_processes,temp;
 static int Block_no[max];

 printf("\n\tDynamic Memory Allocation : First Fit");
	printf("\nEnter the number of blocks:");
	scanf("%d",&no_of_blocks);
	printf("Enter the number of Process:");
	scanf("%d",&no_of_processes);
	printf("\nEnter the sizes of the blocks:-\n");

	for(i=1;i<=no_of_blocks;i++) {
		printf("B %d:",i);
		scanf("%d",&Block_size[i]);
		Block_no[i] = i;
	}
	printf("Enter the sizes of the Processes :-\n");

	for(i=1;i<=no_of_processes;i++) {
		printf("P %d:",i);
		scanf("%d",&Process_size[i]);
	}
int y,m,z,temp1,flag;
for(y=1;y<=no_of_blocks;y++)
  {
    for(z=y;z<=no_of_blocks;z++)
    {
      if(Block_size[y]>Block_size[z])
      {
        temp=Block_size[y];
        Block_size[y]=Block_size[z];
        Block_size[z]=temp;
        
        temp1=Block_no[y];
        Block_no[y]=Block_no[z];
        Block_no[z]=temp1;
      }
    }
  }
  int flagn[max];
  printf("\n\nProcess_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment\n");
    for(i=1;i<=no_of_processes;i++)
    {
      flag = 1;
      for(j=1;j<=no_of_blocks;j++)
      {
        if(Process_size[i] <= Block_size[j]){
          flagn[j] = 1;
          printf("%-15d\t%-15d\t%-15d\t%-15d\t",i, Process_size[i],Block_no[j],Block_size[j]);
          Block_size[j] = Block_size[j] - Process_size[i];
          printf("%-15d\n",Block_size[j]);
          break;
        }
        else
        {flagn[j] = 0;
        flag++;
        }
      }
      if(flag > no_of_blocks)
      printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n",i, Process_size[i],"HOLE","HOLE","HOLE");
    }
return 0;    
}
