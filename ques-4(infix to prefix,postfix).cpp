#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;
int top=-1;
char stack[100];

push(char eval)						
{
	stack[++top]=eval;
}

char pop()							
{
	return (stack[top--]);
}

int callpost(char eval)				
{
	switch(eval)
	{
		case '#':
			return 0;
		case '(':
			return 1;
		case '<':
		case '>':
			return 2;
		case '-':
		case '+':
			return 3;
		case '*':
		case '/':			
			return 4;
	}
}


int callpre(char eval)				
{
	switch(eval)
	{
		case '#':
			return 0;
		case ')':
			return 1;
		case '<':
		case '>':
		case '<=':
		case '>=':
			return 2;
		case '-':
		case '+':
			return 3;
		case '*':
		case '/':			
			return 4;
	}
}



int main()							
{
	char exp1[100],exp[100];
	int n=0;
	cout<<"enter an infix expression\n";
	gets(exp1);
	while(n!=3)
	{
		cout<<"\n1: prefix conversion\n";
		cout<<"2: postfix conversion\n";
		cout<<"3: stop\n";
		cin>>n;
		char ch,post[100],eval;
		int k=0,i=0;
		push('#');
		strcpy(exp,exp1);
		
		
		if(n==1)								
		{
			strrev(exp);
			while(exp[i++]!='\0')
			{		
				ch=exp[i-1];
				if(ch==')')
					push(ch);
				else if(isalnum(ch))
					post[k++]=ch;
				else if(ch=='(')
				{
					while(stack[top]!=')')
						post[k++]=pop();
					eval=pop();
				}
				else
				{
					while(callpre(stack[top])>callpre(ch))
						post[k++]=pop();
					push(ch);
				}
			}
		}
		
		
		
		else if(n==2)								
		{
			while(exp[i++]!='\0')
			{
				ch=exp[i-1];
				if(ch=='(')
					push(ch);
				else if(isalnum(ch))
					post[k++]=ch;
				else if(ch==')')
				{
					while(stack[top]!='(')
						post[k++]=pop();
					eval=pop();
				}
				else
				{
					while(callpost(stack[top])>=callpost(ch))
						post[k++]=pop();
					push(ch);
				}
			}
		}
		
		
		else if(n==3)								
			exit(0);
		else
		{
			cout<<"Invalid input\n";
			exit(1);
		}
		
		
		
					
		while(stack[top]!='#')
			post[k++]=pop();
		post[k]='\0';
		
		if(n==1)
		{
			int q;
			strrev(post);
			cout<<"prefix conversion-\t"<<endl<<post<<endl<<endl;			
			cout<<"\n1:Evaluate this prefix expression-\n";
			cout<<"2:No evaluation\n";
			cin>>q;
			if(q==1)
			{
				float stacke[100];
				int val;
				i=strlen(post)-1;
				while(i>=0)
				{
					if(isalpha(post[i]))
					{
						printf("Enter  the value of %c\n",post[i]);
							scanf("%d",&val);
						stacke[++top]=val;
					}
					else
					{
						switch(post[i])
						{
							case '>':
								if(stacke[top]>stacke[top-1])
								stacke[top-1]=1;
								else
									stacke[top-1]=0;
								top--;
								break;
							case '<':
								if(stacke[top]<stacke[top-1])
								stacke[top-1]=1;
								else
									stacke[top-1]=0;
								top--;
								break;
							case '+':
								stacke[top-1]=stacke[top]+stacke[top-1];
								top--;
								break;
							case '-':
								stacke[top-1]=stacke[top]-stacke[top-1];
								top--;
								break;
							case '*':
								stacke[top-1]=stacke[top]*stacke[top-1];
								top--;
								break;
							case '/':
								stacke[top-1]=stacke[top]/stacke[top-1];
								top--;
								break;	
						}
					}
					i--;
				}
				cout<<endl<<"Value after evaluation of prefix expression is"<<endl<<stacke[top];
			}
		}
		else if(n==2)
		{
			int q;
			cout<<"postfix conversion is-\t"<<endl<<post<<endl<<endl;			
			cout<<"\n1:Evaluate this postfix expression-";
			cout<<"\n2:No evaluation\n";
			cin>>q;
			if(q==1)
			{
				float stacke[100];
				int val;
				i=0;
				while(post[i]!='\0')
				{
					if(isalpha(post[i]))
					{
						printf("Enter  the value of %c\n",post[i]);
						scanf("%d",&val);
						stacke[++top]=val;
					}
					else
					{
						switch(post[i])
						{
							case '>':
								if(stacke[top-1]>stacke[top])
								stacke[top-1]=1;
								else
									stacke[top-1]=0;
								top--;
								break;
							case '<':
								if(stacke[top-1]<stacke[top])
								stacke[top-1]=1;
								else
									stacke[top-1]=0;
								top--;
								break;
							case '+':
								stacke[top-1]=stacke[top-1]+stacke[top];
								top--;
								break;
							case '-':
								stacke[top-1]=stacke[top-1]-stacke[top];
								top--;
								break;
							case '*':
								stacke[top-1]=stacke[top-1]*stacke[top];
								top--;
								break;
							case '/':
								stacke[top-1]=stacke[top-1]/stacke[top];
								top--;
								break;
						}
					}
					i++;
				}
				cout<<endl<<"Value after evaluation of postfix expression is"<<endl<<stacke[top];
			}
		}
	}
}
