#include<iostream>
using namespace std;

/*hanoi(int n,char source,char inter,char dest)
{
	if(n>=1)
	{
		hanoi(n-1,source,dest,inter);
		cout<<"Move disk "<<n<<" from "<<source<<" to "<<dest<<"."<<endl;
		hanoi(n-1,inter,source,dest);
	}
}*/

/*hanoi(int n,char source,char dest,char inter)
{
	if(n>=1)
	{
		hanoi(n-1,source,inter,dest);
		cout<<"Move disk "<<n<<" from "<<source<<" to "<<dest<<"."<<endl;
		hanoi(n-1,inter,dest,source);
	}
}*/

hanoi(int n,char inter, char dest,char source)
{
	if(n>=1)
	{
		hanoi(n-1,dest,inter,source);
		cout<<"Move disk "<<n<<" from "<<source<<" to "<<dest<<"."<<endl;
		hanoi(n-1,source,dest,inter);
	}
}


main()
{
	int n;
	cout<<"Enter no. of disks-";
	cin>>n;
	hanoi(n,'B','C','A');
}
