#include <bits/stdc++.h>
using namespace std;
struct pne
{
    int pid, bt, at, tat, ct, start_time, pt;
    int wt;

} ps[10];



int main()
{
    int n;
    bool is_completed[100] = {false};
    int current_time = 0;
    int completed = 0;
    cout << "Enter total number of processes" << endl;
    cin >> n;

    float sum_tat = 0, sum_wt = 0, sum_rt = 0;
    float avtat, avwt;

    for (int i = 0; i < n; i++)
    {
        cout << "enter the process arrival time" << endl;
        cin >> ps[i].at;
        ps[i].pid = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Process Burst timre" << endl;
        cin >> ps[i].bt;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Process Priority" << endl;
        cin >> ps[i].pt;
    }
    while (completed != n)
    {
        // find process with min. burst time in ready queue at current time
        int max_index = -1;
        int maximum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (ps[i].at <= current_time && is_completed[i] == 0)
            {
                if (ps[i].pt > maximum)
                {
                    maximum = ps[i].pt;
                    max_index = i;
                }
                if (ps[i].pt == maximum)
                {
                    if (ps[i].at < ps[max_index].at)
                    {
                        maximum = ps[i].pt;
                        max_index = i;
                    }
                }
            }
        }

        if (max_index == -1)
        {
            current_time++;
        }
        else
        {
            ps[max_index].start_time = current_time;
            ps[max_index].ct = ps[max_index].start_time + ps[max_index].bt;
            ps[max_index].tat = ps[max_index].ct - ps[max_index].at;
            ps[max_index].wt = ps[max_index].tat - ps[max_index].bt;


            sum_tat += ps[max_index].tat;
            sum_wt += ps[max_index].wt;

            completed++;
            is_completed[max_index] = true;
            current_time = ps[max_index].ct;
 
        }
                avtat = sum_tat / n;
            avwt = sum_wt / n;
    }
    cout << fixed << setprecision(5);
    cout << "processno.   at   bt  pt  tat   wt  " << endl;

    for (int j = 0; j < n; j++)
    {

        cout << ps[j].pid << "  " << ps[j].at << "  " << ps[j].bt << "  " << ps[j].pt << "  " << ps[j].tat << "  " << ps[j].wt << endl;
    }
    cout << avtat << " " << avwt << "";
    return 0;
}
