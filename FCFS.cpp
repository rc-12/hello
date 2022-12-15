#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
struct fcfs
{
    int pid;
    int at;
    int bt;
    int ct, wt, tat, start_time;
} fp[20];



bool compare(struct fcfs a,struct fcfs b){
int x=a.at;
int y=b.at;
return x<y;

}
   
int main()
{
    int n;
    cout << "Enter total number of processes" << endl;
    cin >> n;

    float sum_tat = 0, sum_wt = 0;
    float avtat,avwt;


    for (int i = 0; i < n; i++)
    {
        cout << "enter the process arrival time" << endl;
        cin >> fp[i].at;
        fp[i].pid = i+1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Process Burst time" << endl;
        cin >> fp[i].bt;
       
    }

sort(fp,fp+n,compare);

    for (int i = 0; i < n; i++)
    {
        fp[i].start_time = (i == 0) ? fp[i].at : max(fp[i].at, fp[i - 1].ct);
        fp[i].ct = fp[i].start_time + fp[i].bt;
        fp[i].tat = fp[i].ct - fp[i].at;
        fp[i].wt = fp[i].tat - fp[i].bt;

        sum_tat += fp[i].tat;
        
        sum_wt += fp[i].wt;
      
  avtat=sum_tat/n;
  avwt=sum_wt/n;
    }
    cout << "processno.  at  bt   tat    Twt  " << endl;
sort(fp,fp+n,compare);
    for (int j = 0; j < n; j++)
    {

        cout  << fp[j].pid<<"  "<< fp[j].at <<"  "<< fp[j].bt <<"  "<< fp[j].tat<< "  "<<fp[j].wt<<endl;
    }
cout<<avtat<<" "<<avwt<<"";
    return 0;
} 