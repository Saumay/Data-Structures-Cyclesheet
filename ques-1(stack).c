#include<stdio.h>
int stk[100],top=-1,head,s;

isempty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
isfull()
{
	if(top==(100-1))
	return 1;
	else
	return 0;
}

void push(int x)
{	if(isfull())
		printf("Stack Overflow");
	else
		{
		top++;
		stk[top]=x;
		}
}

void pop()
{
	if(isempty())
		printf("Stack Underflow");
	else	
		top--;
}

void middle_element()
{
	if(s%2==0)
	{
		printf("middle elements %d %d",stk[(s/2)-1],stk[(s/2)]);
	}
	else
		printf("middle element %d",stk[s/2]);
}

display_last_element()
{	
	printf("Last reg. no. entered= %d",stk[head]);
}

display_first_element()
{
	printf("First reg. no .entered= %d ",stk[0]);
}

void input()
{
	int i,reg_no;
	printf("No. of students:");
	scanf("%d",&s);
	for(i=1;i<=s;i++)
	{
		printf("Enter reg. no.");
		scanf("%d",&reg_no);
		push(reg_no);
	}
	head=top;
}

//for displaying full stack
void display_full()
{
	int j;
	for(j=top;j>=0;j--)
	printf("%d\n",stk[j]);
}

//for displaying first ten students
void display()
{
	int k;
	printf("\n\nReg. no. of ten students who submitted first:\n");
	for(k=top;k>=10;k--)
	pop();
	display_full();	
}

search(int y)
{
	int a,count=0;
	for(a=head;a>=0;a--)
	{
		if(stk[a]==y)
		count++;
	}
		if(count!=0)
		printf("Student has submitted the assignment..");
		else
		printf("Student has not submitted the assignment..");
	
}
main()
{
	int ch,d;
	input();
	printf("\n\nFull stack:\n");
	display_full();
	while(ch!=6)
		{
		printf("\n\nEnter your choice:\n1-Display reg. no. of student who submitted first\n2-Display reg. no. of student who submitted last\n3-Display reg. no. of 10 students who submitted first\n4-check whether a student has submitted assignment or not\n5-To find the middle element\n6-exit\n\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				display_first_element();
				break;
			case 2:
				display_last_element();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("search for reg. no.");
				scanf("%d",&d);
				search(d);
				break;
			case 5:
				middle_element();
				break;
			case 6:
				break;
		}
		}
}
