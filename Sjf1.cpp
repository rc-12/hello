#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

struct sjf
{
    int pid, bt, at, tat, ct, start_time;
    int wt;

} sp[10];

int main()
{
    int n;
    bool is_completed[10] = {false}, is_first_process = true;
    int current_time = 0;
    int completed = 0;


    cout<< "Enter total number of processes" << endl;
    cin >> n;

    float sum_tat = 0, sum_wt = 0;
    float avtat, avwt;

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
    {
        cout << "enter the process arrival time" << endl;
        cin >> sp[i].at;
        sp[i].pid = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Process Burst time" << endl;
        cin >> sp[i].bt;
    }

    while(completed!=n){
 
    int min_index = -1;
    int minimum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (sp[i].at <= current_time && is_completed[i] == 0)
        {
            if (sp[i].bt < minimum)
            {
                minimum = sp[i].bt;
                min_index = i;
            }
            if (sp[i].bt == minimum)
            {
                if (sp[i].at < sp[min_index].at)
                {
                    minimum = sp[i].bt;
                    min_index = i;
                }
            }
        }
    }
        if (min_index == -1)
        {
            current_time++;  //idle
        }
        else
        {

            sp[min_index].start_time = current_time;
            sp[min_index].ct = sp[min_index].start_time + sp[min_index].bt;
            sp[min_index].tat = sp[min_index].ct - sp[min_index].at;
            sp[min_index].wt = sp[min_index].tat - sp[min_index].bt;

            sum_tat += sp[min_index].tat;

            sum_wt += sp[min_index].wt;

            avtat = sum_tat / n;
            avwt = sum_wt / n;

            completed++;
            is_completed[min_index] = true;
            current_time = sp[min_index].ct;
         
        }
    
}
cout << "processno.      at          bt            tat             wt  " << endl;

for (int j = 0; j < n; j++)
{

    cout << sp[j].pid << "  " << sp[j].at << "  " << sp[j].bt << "  " << sp[j].tat << "  " << sp[j].wt << endl;
}
cout << avtat << " " << avwt << "";

return 0;
}