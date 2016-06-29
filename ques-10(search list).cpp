#include<iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* pre;
};


struct node* head=NULL;

void i_last(int val)
{
	node* n;
	node* temp=head;
	n=new node;
	n->data=val;
	n->next=n;
	n->pre=n;
	if(head==NULL)
		head=n;
	else
	{
		 while(temp->next!=head)
		 {
		 	temp=temp->next;
		 }
		 temp->next=n;
		 n->pre=temp;
		 n->next=head;
		 head->pre=n;
	}
}

void delete_any(int value)
{
	void display();
	int a=0;
	node* temp=head;
	while(temp->data!=value)
	{
		temp=temp->next;
		if(temp==head)
		{
			cout<<endl<<"Entered Record doesn't exist in the list.."<<endl<<endl;	
			a=1;
			break;
		}
	}

	if(a==0)
	{
		if(temp->next==temp)
		{
			cout<<"Deleted node is-"<<temp->data;
			cout<<endl<<"Now list is empty!"<<endl<<endl<<endl;
			delete(temp);
			head=NULL;
		}
		else
		{
			cout<<endl<<"Predecesor node of deleted node-"<<temp->pre->data<<endl;
			cout<<"Succesor node of deleted node-"<<temp->next->data<<endl;
			if(temp==head)
			{
				head=head->next;
			}
			temp->pre->next=temp->next;
			temp->next->pre=temp->pre;
			delete(temp);
			cout<<endl<<"List after deleting the record:"<<endl;
			display();
			cout<<endl<<endl;
		}
	}
}

void display()
{
        int q;
        node* temp;
        temp=head;
        while(temp->next!=head)
            {
                q=temp->data;
                temp=temp->next;
                cout<<q<<endl;
            }
        cout<<temp->data<<endl;
}

search(int val)
{
	node* temp=head;
	int count=0;
	while(temp->data!=val)
	{
		temp=temp->next;
		if(temp==head && count==1)
		{
			cout<<endl<<"Entered Record doesn't exist in the list.."<<endl<<endl;
			return 0;
		}
		count=1;
	}
		cout<<endl<<"Searched record is present in list.."<<endl<<endl;
		cout<<"Predecesor node of searched node-"<<temp->pre->data<<endl;
		cout<<"Succesor node of searched node-"<<temp->next->data<<endl<<endl;
}


main()
{
	int ch,i,no,data,rec,sch;
	while(ch!=4)
	{
		cout<<"Enter your choice:"<<endl<<"1-Insert record"<<endl<<"2-Search a record"<<endl;
		cout<<"3-Delete a record"<<endl<<"4-Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<endl<<"Enter no. of students-"<<endl;
				cin>>no;
				cout<<endl;
				for(i=1;i<=no;i++)
					{
						cout<<"Student "<<i<<"-";
						cin>>data;
						i_last(data);
					}
				cout<<endl<<"List of records:"<<endl;
				display();
				cout<<endl<<endl;
				break;
			case 2:
				if(head==NULL)
				{
					cout<<endl<<"Empty List.."<<endl<<endl;
					break;
				}
				cout<<endl<<"Enter record to be searched-"<<endl;
				cin>>sch;
				search(sch);
				break;
			case 3:
				if(head==NULL)
				{
					cout<<endl<<"Empty List.."<<endl<<endl;
					break;
				}
				cout<<endl<<"Enter record to be deleted-"<<endl;
				cin>>rec;
				delete_any(rec);
				break;
				
			case 4:
				break;
		}
	}
}
