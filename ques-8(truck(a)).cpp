#include<iostream>
#define free 3

using namespace std;

struct node
{
	int id;
	int time;
	int serv;
	node* next;
};

node* top=NULL;

void i_first(int i,int t,int s)
{
    node* newnode;
    newnode=new node;
    newnode->id=i;
    newnode->time=t;
    newnode->serv=s;
    newnode->next=NULL;
    if(top==NULL)
        top=newnode;
    else
    {
        newnode->next=top;
        top=newnode;
    }
}

void i_last(int i,int t,int s)
{
    node* newnode;
    newnode=new node;
    newnode->id=i;
    newnode->time=t;
    newnode->serv=s;
    newnode->next=NULL;
    node* temp=top;
    if(top==NULL)
       	top=newnode;
    else
		{
			while(temp->next!=NULL)
        	{
            	temp=temp->next;
        	}
 			temp->next=newnode;
        	newnode->next=NULL;
		}
}

d_first(int move_id)
{	
	if(move_id!=top->id)
	{
		cout<<endl<<"Truck can't be moved out"<<endl;
	}
	else
	{
		if(top==NULL)
			cout<<"No trucks in the garage";
		else if(top->next==NULL)
		{
			delete top;
			top=NULL;
		}
		else
		{
			node* temp=top;
			top=temp->next;
			delete temp;
		}
	}
}

void display()
{
    node* temp;
    temp=top;
    if(top==NULL)
    {
    	cout<<endl<<endl<<"!..Empty garage..!"<<endl<<"No trucks to display"<<endl;
	}
	else
	{
		cout<<endl<<"Truck id-\ttime taken-\tService-"<<endl;
    	while(temp!=NULL)
    	{
    		if(temp->serv<=free)
				cout<<temp->id<<"\t\t"<<temp->time<<"\t\t"<<"FREE service"<<endl;
			else
				cout<<temp->id<<"\t\t"<<temp->time<<"\t\t"<<"PAID service"<<endl;
			temp=temp->next;
    	}
	}
}

int main()
{
	int ch,t_id,time,service,move_id;
	while(ch!=4)
	{
		cout<<endl<<"Enter your choice:"<<endl<<"1-Enter garage"<<endl<<"2-Exit garage"<<endl<<"3-Display trucks in garage"<<endl<<"4-Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<endl<<"Truck "<<":"<<endl;
				cout<<"Truck id-";
				cin>>t_id;
				cout<<"Time taken-";
				cin>>time;
				cout<<"Service No.-";
				cin>>service;
				cout<<endl;
				if(top==NULL || time<=top->time)
				{
					i_first(t_id,time,service);
				}
				else if(time>top->time)
				{
					i_last(t_id,time,service);
				}
				break;
			case 2:
				if(top==NULL)
				{
					cout<<endl<<"Empty garage.."<<endl;
					break;
				}
				cout<<endl<<"Enter the truck id to be moved out-"<<endl;
				cin>>move_id;
				
				if(top->serv>free)
				{
					cout<<endl<<"truck id-\tService-";
					cout<<endl<<top->id<<"\t\tPAID service"<<endl;
				}
				else
				{
					cout<<endl<<"truck id-\tService-";
					cout<<endl<<top->id<<"\t\tFREE service"<<endl;
				}
				d_first(move_id);
				break;
			case 3:
				display();
				break;
		}
	}
}

