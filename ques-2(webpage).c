#include<stdio.h>
int stk[50],top=1,current=1;

forw()
{
	if(current==top)
	{
		top++;
		current++;
	}
	else
		current++;
}


back()
{
	current--;
}

displayfs()
{	
	int i;
	if(top==current)
	printf("\nNo pages in forward stack");
	else
	{
	printf("The pages in forward stack are\n");
	for(i=top;i>current;i--)
	printf("%d\n",i);
	}
}

displaybs()
{	
	int j;
	if(current==1)
	printf("\nNo pages in backward stack");
	else
	{
	printf("The pages in backward stack are\n");
	for(j=(current-1);j>0;j--)
	printf("%d\n",j);
	}
}

main()
{
int ch1,ch;
printf("!_HOME PAGE_!\npage no.-1\n\n1-Forward\n");
scanf("%d",&ch1);
if(ch1==1)
forw();
	
	do
    {
    if(current<1)
		{
		printf("\nNO PREVIOUS PAGE\nRedirecting to home page...");
		current=1;
		}
	else
	{
    printf("\n\nCurrent webpage-%d", current);
    printf("\nEnter your choice: \n 1-Forward \n 2-Backward \n 3-See front stack \n 4-See back stack \n 5-Exit \n ");
    scanf("%d", &ch);
    if(ch==1)
    forw();
    else if(ch==2)
    back();
    else if(ch==3)
    displayfs();
    else if(ch==4)
    displaybs();
    else if(ch==5)
    break;
    }}while(ch==1 || ch==2 || ch==3 || ch==4 || ch==5);
}
