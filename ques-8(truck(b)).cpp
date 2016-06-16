#include<iostream>
#define free 3
using namespace std;

struct node
{
	int id;
	int serv;
	node* next;
};

node* front=NULL;
node* rear=NULL;

void i_last(int i,int s)
{
    node* newnode;
    newnode=new node;
    newnode->id=i;
    newnode->serv=s;
    newnode->next=NULL;
    node* temp=front;
    if(front==NULL)
    {
		front=newnode;
		rear=front;
	}
    else
	{
		rear->next=newnode;
        newnode->next=NULL;
        rear=rear->next;
	}
}
d_first(int i)
{	
	if(i!=front->id)
		cout<<endl<<"Truck can't be moved"<<endl;
	else
	{
		if(front==NULL)
			cout<<"No trucks in the garage";
		else if(front->next==NULL)
		{
			delete front;
			front=NULL;
		}
		else
		{
			node* temp=front;
			front=temp->next;
			delete temp;
		}
	}
}


void display()
{
    node* temp;
    temp=front;
    if(front==NULL)
    {
    	cout<<endl<<endl<<"!..Empty garage..!"<<endl<<"No trucks to display"<<endl;
	}
	else
	{

		cout<<endl<<"Truck id-\tservice no.-"<<endl;
    	while(temp!=NULL)
    	{
    		if(temp->serv<=free)
				cout<<temp->id<<"\t\t"<<"FREE service"<<endl;
			else
				cout<<temp->id<<"\t\t"<<"PAID service"<<endl;
			temp=temp->next;
    	}
	}
}

int main()
{
	int ch,i=1,service,t_id,move_id;
	while(ch!=4)
	{
		cout<<endl<<"Enter your choice:"<<endl<<"1-Enter garage"<<endl<<"2-Exit garage"<<endl<<"3-Display trucks in garage"<<endl<<"4-Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<endl<<"Truck id:";
				cin>>t_id;
				cout<<"Service No.:";
				cin>>service;
				cout<<endl;
				i_last(t_id,service);
				break;
			case 2:
				if(front==NULL)
				{
					cout<<endl<<"Empty garage.."<<endl;
					break;
				}
				cout<<endl<<"Enter the truck id to be moved out-"<<endl;
				cin>>move_id;
				cout<<endl<<"Truck going out of the garage:"<<endl;
				if(front->serv>free)
				{
					cout<<endl<<"truck id-\tService-";
					cout<<endl<<front->id<<"\t\tPAID service"<<endl;
				}
				else
				{
					cout<<endl<<"truck id-\tService-";
					cout<<endl<<front->id<<"\t\tFREE service"<<endl;
				}
				d_first(move_id);
				break;
			case 3:
				display();
				break;
				
		}
	}
}
