#include<stdio.h>

int main()
{
char stk[50],exp[50];
int i,top=-1,a=0,b=0,c=0;

printf("enter the expression:");
gets(exp);

for(i=0;exp[i]!='\0';i++)
{
	if(exp[i]=='(') 
		{
		a++;
		top++;
 		stk[top]=exp[i];
		}
		
	else if(exp[i]=='[')
		{
		b++;
		top++;
 		stk[top]=exp[i];
		}
		
	else if(exp[i]=='{')
		{
		c++;
		top++;
 		stk[top]=exp[i];
		}
		
	else if(exp[i]==')')
		{
		a--;
		if (stk[top]=='(')
 			top--;
		}
		
	else if(exp[i]==']')
		{
		b--;
		if(stk[top]=='[')
  			top--;
		}
		
	else if(exp[i]=='}')
		{
		c--;
		if(stk[top]=='{')
 			top--;
		}
	}
if(top==-1 && a==0 && b==0 && c==0)
	printf("expression is balanced");
else if(exp[0]==')' || exp[0]==']' || exp[0]=='}')
	printf("Invalid Input\nClosing %c bracket found without any previous opening bracket",exp[0]);
else
	{
	printf("unbalanced parenthesis\n");
	if(a<0)
		{
		a=-a;
		printf("missing %d ( bracket\n",a);
		}
	else if(a>0)
		printf("missing %d ) bracket\n",a);
	
	if(b<0)
		{
		b=b*(-1);	
		printf("missing %d [ bracket\n",b);
		}
	else if(b>0)
		printf("missing %d ] bracket\n",b);
		
	if(c<0)
		{
		c=c*(-1);
		printf("missing %d { bracket\n",c);
		}
	else if(c>0)
		printf("missing %d } bracket\n",c);
	}
}

