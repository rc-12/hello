#include <iostream>
using namespace std;
int main()
{
	int blocks;
	int processes;
	
	cout<<"Enter the number of memory blocks: "<<endl;
	cin>>blocks;
	int memory[blocks];
	
	cout<<"Enter the size of each block: "<<endl;
	for(int i=0;i<blocks;i++)
	{
	cout<<"Block "<<i+1<<" : ";
	cin>>memory[i];
	cout<<endl;
	}
	
	cout<<"Enter the number of processes: "<<endl;
	cin>>processes;
	int p[processes];
	
	cout<<"Enter the size of each process: "<<endl;
	for(int i=0;i<processes;i++)
	{
	cout<<"Process "<<i+1<<" : ";
	cin>>p[i];
	cout<<endl;
	}
	for(int i=0;i<processes;i++)
	{
		int flag=0;
		for(int j=0;j<blocks;j++)
		{
	        if( p[i]<memory[j] )
			{
		       cout<<"Process "<<i+1<<" is allocated to block "<<j+1<<endl;
			   memory[j]=memory[j]-p[i];
			   int flag=1;
			   break;                    	    
			}	     	 
		}
		if(flag==0)
		{
			cout<<"The size of Process "<<i<<" is bigger than memory block"<<endl;
		}
	}
	return 0;
}
