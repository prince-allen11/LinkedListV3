#include<stdio.h>
#include<stdlib.h>
#include <time.h>
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
void main()
{	
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head=NULL,*pos=NULL,*tail=NULL;
	int ch,entry,c,d,a,data,i,num=100;
	printf("\n1.INSERT\n2.DISPLAY\n3.COUNT\n4.SEARCH\n5.EXIT");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				for(i=0;i<num;i++)
				{
					entry=rand()%100;
					if(head==NULL)
					{
						head=(struct node*)malloc(sizeof(struct node));
						head->data=entry;
						pos=head;
						tail=head;
					}
					else
					{
						tail->next=(struct node*)malloc(sizeof(struct node));
						tail=tail->next;
						tail->data=entry;
					}
					
				}
				break;
			}
			case 2:
			{
				pos=head;
				printf("\n Elements are:");
				while(pos!=NULL)
				{
					printf("\t %d",pos->data);
					pos=pos->next;
				}
				break;
			}
			case 3:
			{	
				pos=head;
				while(pos!=NULL)
				{
					c=c+1;
					pos=pos->next;
				}
				printf("\n Number of elements:%d",c);
				break;		
			}
			case 4:
			{	struct timeval t0;
  				struct timeval t1;
   				float elapsed;
				a=0;
				pos=head;
				printf("Enter element to be searched for:");
				scanf("%d",&d);
				gettimeofday(&t0, NULL);
				while(pos!=NULL)
				{
					if(pos->data==d)
					{
						a=1;
						break;
					}
					pos=pos->next;
				}
				if(a==1)
				{
					printf("Element found!");
				}
				else
				{
					printf("Element not found!");
				}
   				gettimeofday(&t1, NULL);
				elapsed = timedifference_msec(t0, t1);
				printf("Code executed in %f milliseconds.\n", elapsed);
				break;
			}
			case 5:
			{
				printf("************************************************************");
				exit(0);
			}
		}
		printf("\n");
	}
}









