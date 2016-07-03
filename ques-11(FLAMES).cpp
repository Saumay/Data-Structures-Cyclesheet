#include<iostream>
#include<string.h>
using namespace std;
int flag=1;

struct node
{
	node* next;
	char data;
};

node* head=NULL;
node* last=NULL;

void i_last(char val)
{
	node* n;
	n=new node;
	n->next=n;
	n->data=val;
	if(head==NULL)
	{
		head=n;
		last=n;
	}
	else
	{
		last->next=n;
		n->next=head;
		last=n;
	}
}

display()
{
	node* temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<temp->data;
	
}


int uncommon_letters(char A[],char B[])
{
	int a,b,uncommon,k;
	uncommon=strlen(A)+strlen(B);
	for(a=0;a<strlen(A);a++)
	{
		for(b=0;b<strlen(B);b++)
		{
			if(A[a]==B[b])
			{
				uncommon=uncommon-2;
				for(k=b;k<strlen(B);k++)
				{
					B[k]=B[k+1];
				}
				break;
			}
			
		}
	}
	cout<<endl<<"No. of uncommon letters are-"<<endl<<uncommon<<endl<<endl;
	return uncommon;
}

middle_level(node* source,int num)
{	
	if(source->next==source)
	{
		return source->data;
	}
	int i;
	node* temp=source;
	node* suc;
	node* pre;
	for(i=1;i<num;i++)
	{
		pre=temp;
		temp=temp->next;
	}
	if(temp==head)
		head=head->next;
	suc=temp->next;
	//cout<<pre->data<<temp->data<<suc->data<<endl;
	pre->next=suc;
	delete temp;
	cout<<"Loop-"<<flag<<endl;
	display();
	cout<<endl<<endl;
	flag++;
	middle_level(suc,num);
}


high_level(int num)
{
	int i,j;
	node* pre;
	node* suc;
	node* temp=head;
	node* first_del;
	node* link=head;
	for(j=1;j<=5;j++)
	{
		//cout<<"Loop-"<<j<<endl;
		for(i=1;i<num;i++)
		{
			pre=temp;
			temp=temp->next;
		}
		suc=temp->next;
		if(temp==head)
		{
			head=head->next;
		}
		
		if(num==6 && j==1)
		{
			temp=last;
			suc=head;
			first_del=temp;
			while(link->next!=last)
			{
				link=link->next;
			}
		}
		else
		{
			pre->next=suc;
			last->next=temp;
			temp->next=head;
			last=temp;
			if(j==1)
				first_del=temp;
		
			if(last==link || j==1)
			{
				if(j!=1)
					link->next=first_del;
				while(link->next!=first_del)
				{
					link=link->next;
					//cout<<link->data;
				}
			}
		}
		temp=suc;
		link->next=first_del;
		/*cout<<"List before deletion-";
		display();
		cout<<endl;
		link->next=head;
		cout<<"List after deletion-";
		cout<<endl<<endl;	
		display();*/
	}
	return head->data;
}


create_list()
{
	head=NULL;
	node* temp=head;
	i_last('F');
	i_last('L');
	i_last('A');
	i_last('M');
	i_last('E');
	i_last('S');
}

print_relationship(char c)
{
	switch(c)
	{
		case 'F':
			cout<<endl<<"Friend";
			break;
		case 'L':
			cout<<endl<<"Love";
			break;
		case 'A':
			cout<<endl<<"Affection";
			break;
		case 'M':
			cout<<endl<<"Marriage";
			break;
		case 'E':
			cout<<endl<<"Enmity";
			break;
		case 'S':
			cout<<endl<<"Sister";
			break;
	}
}

main()
{
	int uncommon,ch;
	char name1[20],name2[20];
	char middle,high;
	
	
	//display();
	while(ch!=3)
	{
		cout<<endl<<"Enter your choice-"<<endl<<"1-MIDDLE Level"<<endl<<"2-HIGH level"<<endl<<"3-Exit"<<endl;
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
				create_list();
				cout<<"Enter name 1:"<<endl;
				cin>>name1;
				cout<<endl;
				cout<<"Enter name 2:"<<endl;
				cin>>name2;
				cout<<endl;
				uncommon=uncommon_letters(name1,name2);
				middle=middle_level(head,uncommon);
				cout<<"Relationship is-";
				print_relationship(middle);
				cout<<endl;
				break;
			case 2:
				create_list();
				cout<<"Enter name 1:"<<endl;
				cin>>name1;
				cout<<endl;
				cout<<"Enter name 2:"<<endl;
				cin>>name2;
				cout<<endl;
				uncommon=uncommon_letters(name1,name2);
				high=high_level(uncommon);
				cout<<"Relationship is-";
				print_relationship(high);
				cout<<endl<<endl;
				break;
			case 3:
				break;
		}
	}
}
