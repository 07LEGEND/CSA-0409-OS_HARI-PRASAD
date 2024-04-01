#include<stdio.h>
int main()
{
	int i,n,sum,wt,tat,twt,ttat;
	int t[10];
	float awt,atat;
	 printf("enter number of processor:\n");
	 scanf("%d",&n);
	 for(i=0;i<n;i++)
	 {
	 	printf("enter the burst time:\n",i+1);
	 	scanf("%d",&t[i]);
	 	
	 }
	 printf("\n\n first come first serve scheduling algorithm \n");
	 printf("\n proccess id \t waiting time \t turn around time \n");
	 printf("1\t\t 0 \t\t %d\n",t[0]);
	 sum=0;
	 twt=0;
	 ttat=t[0];
	 for(i=1;i<n;i++)
	 {
	 	sum+=t[i-1];
	 	wt=sum;
	 	tat=sum+t[i];
	 	twt=twt+wt;
	 	ttat=ttat+tat;
	 	printf("\n %d \t\t %d\t\t%d",i+1,wt,tat);
	 	printf("\n\n");
	 }
	 awt=(float)twt/n;
	 atat=(float)ttat/n;
	 printf("\n average waiting time %4.2f",awt);
	 printf("\n average turnaround time %4.2f",atat);
	 
	 
}
