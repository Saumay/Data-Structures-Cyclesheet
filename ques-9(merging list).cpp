#include<iostream>
using namespace std;

struct node
{
int data;
node* next;
};

struct node* head1=NULL;
struct node* head2=NULL;

void i_last1(int val)
{
        node* newnode;
        newnode=new node;
        newnode->data=val;
        newnode->next=NULL;
        node* temp=head1;
        if(head1==NULL)
        	head1=newnode;
        else
			{
			while(temp->next!='\0')
        		{
                temp=temp->next;
        		}
 			temp->next=newnode;
        	newnode->next=NULL;
			}
}

void i_last2(int val)
{
	node* newnode;
    newnode=new node;
    newnode->data=val;
    newnode->next=NULL;
    node* temp=head2;
    if(head2==NULL)
        head2=newnode;
    else
		{
			while(temp->next!='\0')
        		{
                temp=temp->next;
        		}
 			temp->next=newnode;
        	newnode->next=NULL;
		}
}

void swap_nodes(node* temp1,node* temp2)
{
	int temp;
	temp=temp1->data;
	temp1->data=temp2->data;
	temp2->data=temp;
}

void display(node* head)
{
        int q;
        node* temp;
        temp=head;
        while(temp->next!=0)
            {
                q=temp->data;
                temp=temp->next;
                cout<<q<<endl;
            }
        cout<<temp->data<<endl;
}

void list_sort(node* head,int n)      //bubble sort
{
	int i,j,flag;
	for(i=n-2;i>=0;i--)
	{
		node* temp=head;
		flag=0;
		for(j=0;j<=i;j++)
		{
			node* temp1;
			temp1=temp->next;
			if((temp->data)>(temp1->data))
			{
				swap_nodes(temp,temp1);
            	flag=1;
        	}
        	temp=temp->next;
		}
		if(flag==0)
			break;
	}
	cout<<endl<<"Sorted list-"<<endl;
	display(head);
}

void merge_lists(node* head1,node* head2)
{
	node* temp=head1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head2;
	head2=head1;
}

int main()
{
	int i,no1,no2,roll,ch;
	char name[20];
	while(ch!=7)
	{
		cout<<endl<<"Enter your choice-"<<endl<<"1-Enter data in List 1"<<endl<<"2-Sort list 1 elements"<<endl<<"3-Enter data in list 2"<<endl<<"4-Sort list 2 elements"<<endl<<"5-Merge both the lists"<<endl<<"6-Sorted merged list"<<endl<<"7-Exit"<<endl;
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
				cout<<"Enter no. of students for list 1-"<<endl;
				cin>>no1;
				cout<<endl;
				for(i=1;i<=no1;i++)
				{
					cout<<"Student "<<i<<"-"<<endl;
					//cout<<"Roll no:";
					cin>>roll;
					/*cout<<"Name:";
					cin>>name;
					cout<<endl;*/
					i_last1(roll);
				}
				cout<<endl<<"Elements in the list 1-"<<endl;
				display(head1);
				break;
			case 2:
				list_sort(head1,no1);
				break;
			case 3:
				cout<<endl<<"Enter no. of students for list 2-"<<endl;
				cin>>no2;
				for(i=1;i<=no2;i++)
				{
					cout<<"Student "<<i<<"-";
					cin>>roll;
					i_last2(roll);
				}
				cout<<endl<<"Elements in the list 2-"<<endl;
				display(head2);
				break;
			case 4:
				list_sort(head2,no2);
				break;
			case 5:
				merge_lists(head1,head2);
				cout<<endl<<"Elements in the merged list-"<<endl;
				display(head1);
				break;
			case 6:
				list_sort(head1,no1+no2);
				break;
			case 7:
				break;
		}	
	}
}
