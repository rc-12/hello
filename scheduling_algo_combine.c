#include<iostream>
using namespace std;
class process
{
	public:
	int *p,*bt,*at,*pr,*wait,*turn;

};
#define MAX 9999
struct proc
{
    int no,at,bt,rt,ct,tat,wt,pri,temp;
};

class fcfs:public process
{
	int n;
	public:
	fcfs()
	{}	
	fcfs(int n)
	{
		this->n=n;
		p=new int[this->n];
		at=new int[this->n];
		bt=new int[this->n];
		wait=new int[this->n]();
		turn=new int[this->n]();
	}
	void data()
	{
		for(int i=0;i<n;i++)
		{
			p[i]=i+1;
		cout<<"Enter Arrival time\n";                    cin>>at[i];                 		  cout<<"Enter Burst time\n";                       cin>>bt[i];
		}
	}
	void sort()
	{
		int min;
		for(int i=0;i<n-1;i++)
		{	min=i;
			for(int j=i+1;j<n;j++)
		{
			if(at[min]>at[j]) min=j;
		}
			if(min!=i)
			{
			swap(bt[i],bt[min]);
			swap(at[i],at[min]);
			swap(p[i],p[min]);
			}
		}
	}
	void time()
	{
		wait[0]=0;int t=bt[0];
		turn[0]=bt[0];
		for(int i=1;i<n;i++)
		{
		     int j=i;
		while(j--)
		{
	//		turn[i]+=at[j]+bt[j];
			wait[i]+=bt[j];
			t+=bt[j];
		}
		if(t<=at[i])
		{
			wait[i]=0;
		turn[i]=bt[i];
		}
		else
		{
		turn[i]=wait[i]+bt[i]-at[i];
		wait[i]-=at[i];
		}
		}
	}
	void disp()
	{
	double sumw=0,sumt=0;                          cout<<"\nProcess"<<"\tAT"<<"\tBT"<<"\tWT"<<"\tTAT\n";                                                      for(int i=0;i<n;i++)                              {                                                 sumw+=wait[i];                                    sumt+=turn[i];                            cout<<"P"<<p[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wait[i]<<"\t"<<turn[i]<<endl;
	}	  	
	sumw/=n;sumt/=n;
	printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",sumt,sumw);  
}
	void sort1()
        {
                int min;                                          for(int i=0;i<n-1;i++)                            {       min=i;                                            for(int j=i+1;j<n;j++)                    {                                                         if(bt[min]>bt[j] || at[min]>at[j]) min=j;                  }                                                         if(min!=i)
                        {                                                 swap(bt[i],bt[min]);                              swap(at[i],at[min]);                              swap(p[i],p[min]);
                        }
                }
        }

	
};
struct proc read(int i)
{
    struct proc p;
    p.no=i;
    cout<<"Enter Arrival Time "<<endl;
    cin>>p.at;
    cout<<"Enter Burst Time "<<endl;
    cin>>p.bt;
    p.rt=p.bt;
    return p;
}
class rr:public process
{
	int *rt;
};
class prior:public process
{	public:
	int n;
	prior(int n)                                       {                                                         this->n=n;                                        p=new int[this->n];                               at=new int[this->n];                              bt=new int[this->n];                              wait=new int[this->n]();                          turn=new int[this->n](); 
		pr=new int[this->n];
	}

	void data()
        {	
                for(int i=0;i<n;i++)
                {                                                         p[i]=i+1;
	cout<<"Enter Arrival time\n";
			cin>>at[i]; 
		cout<<"Enter Burst time\n";
		cin>>bt[i];
		cout<<"Enter Priority\n";
			cin>>pr[i];
                }     
	}
	void sort()                                       {                                                         int min;                                       for(int i=0;i<n-1;i++)                            {       min=i;                                            for(int j=i+1;j<n;j++)                    {                                                   if(pr[min]>pr[j]||at[min]>at[j])min=j;                  }                                                         if(min!=i)                                   {                                                 swap(bt[i],bt[min]);
          swap(at[i],at[min]);                              swap(p[i],p[min]);  
	  swap(pr[i],pr[min]);
	}                                         }		                                    }
	void time()                                       {                                                         wait[0]=0;int t=0;                                turn[0]=bt[0];                                    for(int i=1;i<n;i++)                              {                                                      int j=i;                                     while(j--)                                        {                                                    turn[i]+=at[j]+bt[j];                             wait[i]+=bt[j];                                   t+=bt[j];                                 }                                                 if(t<=at[i])                                      {                                                         wait[i]=0;                                turn[i]=bt[i];                                    }                                                 else    
		{
		turn[i]=wait[i]+bt[i]-at[i];                         wait[i]-=at[i];                                       }     
	}
	}
void disp()                                       {                                                         double sumw=0,sumt=0;                          printf("\nProcess\tAT\tBT\tWT\tTAT\tPR\n");                                                   		 for(int i=0;i<n;i++)                              {                                                 sumw+=wait[i];                                    sumt+=turn[i];                                  cout<<"P"<<p[i]<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<wait[i]<<"\t"<<turn[i]<<"\t"<<pr[i]<<endl;           
}
	sumw/=n;sumt/=n;
	printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",sumt,sumw); 
}
};
struct proc readq(int i)
{
    struct proc p;
    printf("\nProcess No: %d\n",i);
    p.no=i;
    printf("Enter Arrival Time: ");
    scanf("%d",&p.at);
    printf("Enter Burst Time: ");
    scanf("%d",&p.bt);
    p.rt=p.bt;
    printf("Enter Priority: ");
    scanf("%d",&p.pri);
    p.temp=p.pri;
    return p;
}
class priorp
{
	public:
	int i,n,c,remaining,min_val,min_index;
    struct proc p[10],temp;
    float avgtat,avgwt;
	priorp(int n)
	{
		this->n=n;
		avgtat=0;
		avgwt=0;
	}
	void data()
		{
			for(int i=0;i<n;i++)                      p[i]=readq(i+1);
		}

	void time()
	{
remaining=n;
	for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)    
            if(p[j].at>p[j+1].at)
            {
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            }
    min_val=p[0].temp,min_index=0;
	for(int j=0;j<n&&p[j].at<=p[0].at;j++)
		if(p[j].temp<min_val)
			min_val=p[j].temp,min_index=j;
	i=min_index;
	c=p[i].ct=p[i].at+1;
	p[i].rt--;
	if(p[i].rt==0)
	{
		p[i].temp=MAX;
		remaining--;
	}
	while(remaining>0)
	{
		min_val=p[0].temp,min_index=0;
    	for(int j=0;j<n&&p[j].at<=c;j++)
    		if(p[j].temp<min_val)
    			min_val=p[j].temp,min_index=j;
    	i=min_index;
		p[i].ct=c=c+1;
		p[i].rt--;
		if(p[i].rt==0)
		{
		    p[i].temp=MAX;
		    remaining--;
		}
	}	
		printf("\nProcessNo\tAT\tBT\tPri\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        p[i].tat=p[i].ct-p[i].at;
        avgtat+=p[i].tat;
        p[i].wt=p[i].tat-p[i].bt;
        avgwt+=p[i].wt;
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[i].no,p[i].at,p[i].bt,p[i].pri,p[i].tat,p[i].wt);
    }
    avgtat/=n,avgwt/=n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgtat,avgwt);
}
};



class robin
{

	public:
		                                           int n,tq,ct,flag,remaining;
	struct proc p[10],tmp;
	float avgtat,avgwt;			
	robin(int n)                                       {                                                         this->n=n;  
  		  avgtat=0;
  		  avgwt=0;
  		  ct=0;
   		 flag=0;					   }
	void data()
	{
		cout<<"Enter time quantum\n";
		cin>>tq;
	}
	void time()
	{
		  for(int i=0;i<n;i++)
        p[i]=read(i+1);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].at>p[j+1].at)
            {
            tmp=p[j];
            p[j]=p[j+1];
            p[j+1]=tmp;
            }
	remaining=n;
    printf("\nProcessNo\tAT\tBT\tTAT\tWT\n");
    for(int i=0;remaining!=0;)
    {
        if(p[i].rt<=tq&&p[i].rt>0)
        {
			ct+=p[i].rt;
			p[i].rt=0;
			flag=1;
        }
        else if(p[i].rt>0)
        {
			p[i].rt-=tq;
			ct+=tq;
        }
        if(p[i].rt==0&&flag==1)
        {
		flag = 0;
		remaining--;
		p[i].ct=ct;
		p[i].tat=p[i].ct-p[i].at;
		avgtat+=p[i].tat;
            p[i].wt=p[i].tat-p[i].bt;
            avgwt+=p[i].wt;
	    printf("P%d\t\t%d\t%d\t%d\t%d\n",p[i].no,p[i].at,p[i].bt,p[i].tat,p[i].wt);
        }
        if(i!=n-1&&p[i+1].at<=ct)
			i++;
       		 else
			i=0;
    }
    avgtat/=n,avgwt/=n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgtat,avgwt);
    }
};

int main()
{	int n;int ch;
	cout<<"Enter no. of Processes\n";                 cin>>n;
	do
	{
	cout<<"Enter choice \n1.FCFS \n2.SJF \n3.SRTF \n4.PRIORITY(PREEMPTIVE) \n5.PRIORITY(NON) \n6.ROUND ROBIN \n7.Exit\n";
	cin>>ch;
	switch(ch)
	{
		case 1: {
				fcfs f(n);
				f.data();
				f.sort();
				f.time();
				f.disp();
			}break;
		case 2: {
				fcfs f(n);
				f.data();
				f.sort1();
				f.time();
				f.disp();
			}
			break;
		case 3:{
			  struct proc p[10],temp;
    float avgtat=0,avgwt=0;
    int s,remain=0,time;
    for(int i=0;i<n;i++)
        p[i]=read(i+1);
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].at>p[j+1].at)
            {
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            }
    printf("\nProcess\t\tAT\tBT\tCT\tTAT\tWT\n");
    p[9].rt=MAX;
    for(time=0;remain!=n;time++)
    {
        s=9;
        for(int i=0;i<n;i++)
            if(p[i].at<=time&&p[i].rt<p[s].rt&&p[i].rt>0)
                s=i;
        p[s].rt--;
        if(p[s].rt==0)
        {
            remain++;
            p[s].ct=time+1;
            p[s].tat=p[s].ct-p[s].at;
            avgtat+=p[s].tat;
            p[s].wt=p[s].tat-p[s].bt;
            avgwt+=p[s].wt;
            printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",p[s].no,p[s].at,p[s].bt,p[s].ct,p[s].tat,p[s].wt);
        }
    }
    avgtat/=n,avgwt/=n;
    printf("\nAverage TurnAroundTime=%f\nAverage WaitingTime=%f",avgtat,avgwt);
}break;
case 4: {
		prior p(n);
		p.data();
		p.sort();
		p.time();
		p.disp();
		break;
	}
case 5:{
	       priorp pn(n);
	       pn.data();
	       pn.time();
       }
	break;
case 6: {
		robin r(n);
		r.data();
		r.time();
	}
	break;
case 7: exit(0);
deafault: break;
}
cout<<"\n----------------------------------"<<endl;
}
while(true);
	return 0;
}

		  


