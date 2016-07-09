#include<iostream>
#include<string>
using namespace std;

struct node
{
	int no;
	string A;
	node* next;
	node* pre;
};



node* head=NULL;
node* last=NULL;

i_last(string a,int index)
{
	node* n;
	n=new node;
	n->A=a;
	n->no=index;
	n->next=NULL;
	n->pre=NULL;
	if(head==NULL)
	{
		head=n;
		last=n;
	}
	else
	{
		node* temp=head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=n;
		n->pre=temp;
		last=n;
	}
}

void quick_sort(node* left,node* right)
{
	string temp;
	node* pivot=left;
	if((left->no)>=(right->no))
		return;
	node* l=left;
	node* r=right;
	while((l->no)<(r->no))
	{
		while((r->A)>(pivot->A))
			r=r->pre;
		while((l->A)<=(pivot->A))
			l=l->next;
		if((l->no)<(r->no))
		{
			temp=l->A;
			l->A=r->A;
			r->A=temp;
		}
	}
	temp=pivot->A;
	pivot->A=r->A;
	r->A=temp;
	quick_sort(left,r->pre);
	quick_sort(r->next,right);
}



display()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->A<<endl;
		temp=temp->next;
	}
}

main()
{
	int i,n;
	string Q;
	cout<<"Enter number of elements-"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"Enter string";
		cin>>Q;
		i_last(Q,i);
	}
	node* left=head;
	node* right=last;
	quick_sort(left,right);
	display();
}
		
