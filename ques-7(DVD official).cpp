#include<iostream>
#include<string.h>
#include<stdio.h>
#define max 5
using namespace std;

char Q[max],A[50];
int rear=-1,front=-1;

int isempty()
{
	if(rear==-1 && front==-1)
		return 1;
	else
		return 0;
}

int isfull()
{
	if(front==(rear+1)%max)
		return 1;
	else
		return 0;
}


void enque(char x)
{
	if(isfull())
		printf("Queue overflow");
	else if(isempty())
		{
		front=0;
		rear=0;
		Q[rear]=x;
		}
	else
		{
		rear=(rear+1)%max;
		Q[rear]=x;
		}
}

void deque()
{
	if(isempty())
		printf("Queue underflow");
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
		front=(front+1)%max;
}

void display()
{
	int i;
	
	if(rear==front)
		printf("%c",Q[rear]);
	else if(rear>front)
		{
		for(i=front;i<=rear;i++)
			printf("%c",Q[i]);
		}
	else if(front>rear)
		{
		for(i=front;i<max;i++)
			printf("%c",Q[i]);
		for(i=0;i<=rear;i++)
			printf("%c",Q[i]);
		}
}

void write(char* A)
{
	int i;
	printf("\n\nIn buffer-\n");
	for(i=0;i<max;i++)
		{
		enque(A[i]);
		printf("%c",A[i]);
		}
}

void burn(char c,int a)
{
		printf("\n\nIn Buffer-\n");
		if(a>=(strlen(A)+max-1))
			printf("Empty buffer");
		else if(a>(strlen(A)-1))
			{
			deque();
			display();
			}
		else
			{
			deque();
			enque(c);
			display();
			}
}


void burned_data(int a)
{
	int i;
	printf("\n\nBurned data-\n");
	for(i=0;i<=a-max;i++)
		printf("%c",A[i]);
		
}

void data_to_be_burned(int a)
{
	int i;
	printf("\nData to be burned-\n");
	if(a>=(strlen(A)-1))
		printf("Empty");
	else
		{
		for(i=a+1;i<=strlen(A);i++)
		printf("%c",A[i]);
		}
}


int main()
{
	int ch;
	int a=max;
	printf("Enter a string-\n");
	scanf (" %[^\n]s",A);         //delimiter->[^\n]
	write(A);
	while(ch!=2)
	{
		printf("\n\n\nEnter your choice:\n1-Read data\n2-exit\n\n");
		scanf("%d",&ch);
		switch(ch)
			{
			case 1:
				if(a>=(strlen(A)+max))
					{
					printf("\n\n!..ALL DATA IS BURNED..!\n");
					break;
					}
				burned_data(a);
				burn(A[a],a);
				printf("\n\nRear index=%d",rear);
				printf("\nFront index=%d\n",front);
				data_to_be_burned(a);
				a++;
				break;
			case 2:
				break;
			}
	}
return 0;
}
