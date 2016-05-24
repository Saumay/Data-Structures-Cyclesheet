#include<stdio.h>
#define max 5

int front=0,rear=-1,child=0,adult=0,queue[40];

isempty()
{
	if(rear==-1 && front==0)
		return 1;
	else
		return 0;
}

void age(int x)
{
	if(x<18)
		child++;
	else
		adult++;
}

void enqueue(int y)
{	
	int l;
	l=y%max;
	if(l+1==1 && y!=1)
		printf("\nSeats for ride full..!\nAssembling riders for next ride\n");
	rear++;
	queue[rear]=y;	
}

void dequeue()
{
		front++;
}

void current_status()
{
	int i; 
	printf("\nCurrent Status:\n");
	for(i=front;i<=rear;i++)
		printf("%d\n",queue[i]);
}

void riders_list()
{
	int j;
	printf("\nRiders list in proper order:\n");
	if(rear<max)
		{
		for(j=front;j<=rear;j++)
			printf("%d\n",queue[j]);
		}
	else
		{
		for(j=front;j<max;j++)
			printf("%d\n",queue[j]);
		}	
}

void ride()
{	
	int nr=rear-front;
	if((nr+1)>=max)
	{
		int k,c;
		for(k=front;k<max;k++)
			dequeue();
		for(c=front;c<=rear;c++)
			queue[c-max]=queue[c];
		rear=rear-max;
		front=front-max;
	}
	else if(isempty())
		printf("\nNot enough riders!!\n%d more riders required\n",5);
	else
		printf("\nNot enough riders!!\n%d more riders required\n",5-nr);
}

void VIP_enqueue(int x)
{
	int c;
	for(c=rear;c>=front;c--)
		queue[c+1]=queue[c];
	queue[front]=x;
	rear++;
}

void display_age()
{
	printf("\nNo. of adult riders in the list=%d",adult);
	printf("\nNo. of child riders in the list=%d\n",child);
}

main()
{
	int ch,age1,a=0;
	while(ch!=7)
	{
		printf("\n\nEnter your choice:\n\n1-Add a person\n2-Current status of ride\n3-Riders list in proper order\n4-VIP entry\n5-Display no. of adults nd children in the list\n6-Go for a ride\n7-Exit\n");
		scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					a++;
					printf("\nPerson %d:\n",a);
					printf("Enter the age of person-");
					scanf("%d",&age1);
					age(age1);
					enqueue(a);
					break;
				case 2:
					current_status();
					if(isempty())
						printf("No riders for the ride.");
					break;
				case 3:
					riders_list();
					if(isempty())
						printf("No riders for the ride.");
					break;
				case 4:
					a++;
					printf("\nPerson %d:\n",a);
					printf("Enter the age of person-");
					scanf("%d",&age1);
					age(age1);
					VIP_enqueue(a);
					break;
				case 5:
					display_age();
					break;
				case 6:
					adult=0;
					child=0;
					ride();
					break;
			}
	}
return 0;
}
