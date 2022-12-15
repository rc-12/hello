#include <iostream>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

struct process_struct
{
    int pid;
    int at;
    int bt;
    int ct, wt, tat,  start_time;
} ps[10];

int main()
{

    int n;
    float bt_remaining[10];
    bool is_completed[10] = {false}, is_first_process = true;
    int current_time = 0;
    int completed = 0;
    float sum_tat = 0, sum_wt = 0;


    cout << fixed << setprecision(2);

    cout << "Enter total number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Process  Arrival Time: ";
        cin >> ps[i].at;
        ps[i].pid = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Process Burst Time: ";
        cin >> ps[i].bt;
        bt_remaining[i] = ps[i].bt;
    }

    while (completed != n)
    {
        // minimun burst time
        int min_index = -1;
        int minimum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (ps[i].at <= current_time && is_completed[i] == false)
            {
                if (bt_remaining[i] < minimum)
                {
                    minimum = bt_remaining[i];
                    
                    min_index = i;
                }
                if (bt_remaining[i] == minimum)
                {
                    if (ps[i].at < ps[min_index].at)
                    {
                        minimum = bt_remaining[i];
                        
                        min_index = i;
                    }
                }
            }
        }

        if (min_index == -1)
        {
            current_time++;
        }
        else
        {

            bt_remaining[min_index] -= 1;//total 4   4-1=3
            current_time++;

            if (bt_remaining[min_index] == 0)
            {
                ps[min_index].ct = current_time;
                ps[min_index].tat = ps[min_index].ct - ps[min_index].at;
                ps[min_index].wt = ps[min_index].tat - ps[min_index].bt;

                sum_tat += ps[min_index].tat;
                sum_wt += ps[min_index].wt;

                completed++;
                is_completed[min_index] = true;
            }
        }
    }

    // Output
    cout << "\nProcess No.\tAT\tCPU Burst Time\tTAT\tWT\t\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t\t" << ps[i].at << "\t" << ps[i].bt << "\t\t"
             << "\t" << ps[i].tat << "\t" << ps[i].wt << endl;
    cout << endl;

    cout << "\nAverage Turn Around time= " << (float)sum_tat / n;
    cout << "\nAverage Waiting Time= " << (float)sum_wt / n;

    return 0;
}