#include <bits/stdc++.h>
using namespace std;
struct pe
{
    int pid, bt, at, tat, ct,  pt;
    int wt;

} ps[10];

int main()
{
    int bt_remaining[10];
    int n;
    bool is_completed[100] = {false};
    int current_time = 0;
    int completed = 0;
    cout << "Enter total number of processes" << endl;
    cin >> n;

    float sum_tat = 0, sum_wt = 0;
    float avtat = 0, avwt = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "enter the process arrival time" << endl;
        cin >> ps[i].at;
        ps[i].pid = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Enter Process Burst time" << endl;
        cin >> ps[i].bt;
        bt_remaining[i] = ps[i].bt;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Process Priority" << endl;
        cin >> ps[i].pt;
    }

    while (completed != n)
    {

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
            current_time++;  //idle
        }
        else
        {

            bt_remaining[max_index] -= 1;
            current_time++;

            if (bt_remaining[max_index] == 0)
            {
                ps[max_index].ct = current_time;
                ps[max_index].tat = ps[max_index].ct - ps[max_index].at;
                ps[max_index].wt = ps[max_index].tat - ps[max_index].bt;

                sum_tat += ps[max_index].tat;
                sum_wt += ps[max_index].wt;

                completed++;
                is_completed[max_index] = true;
            }
        }
    }
    cout << fixed << setprecision(5);
    cout << "processno.   at   bt  pt  tat   wt  " << endl;

    for (int j = 0; j < n; j++)
    {

        cout << ps[j].pid << "       " << ps[j].at << "      " << ps[j].bt << "      " << ps[j].pt << "     " << ps[j].tat << "     " << ps[j].wt << endl;
    }

    cout << "\nAverage Turn Around time= " << (float)sum_tat / n;
    cout << "\nAverage Waiting Time= " << (float)sum_wt / n;
    return 0;
}
