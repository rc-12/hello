#include <iostream>  
using namespace std;
int main()
{ 
    int MemoryBlock[10], Processes[10], numberOfMemoryBlocks, numberOfProc,
        flags[10], allocation[10];
    int i, j, smallest;
    for (i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }

    cout << "Please enter the number of Memory Partitions: ";
    cin >> numberOfMemoryBlocks; 
    for (i = 0; i < numberOfMemoryBlocks; i++)
    {
        cin >> MemoryBlock[i];
    } 

    cout << "\nPlease enter number of processes: ";
    cin >> numberOfProc; 
    cout << "\nPlease enter the size of each process: ";
    for (i = 0; i < numberOfProc; i++)
    {
        cin >> Processes[i];
    } 
    
    for (i = 0; i < numberOfProc; i++)
    {                  
        smallest = -1; 
        for (j = 0; j < numberOfMemoryBlocks; j++)
            if (flags[j] == 0 && MemoryBlock[j] >= Processes[i])
            {
                smallest = j;
                break;
            }
        for (j = 0; j < numberOfMemoryBlocks; j++)
        {
            if (flags[j] == 0 && MemoryBlock[j] >= Processes[i] &&
                MemoryBlock[j] < MemoryBlock[smallest])
                smallest = j;
        }
        if (smallest != -1)
        {
            allocation[smallest] = i;
            flags[smallest] = 1;
        }
    }

    
    cout << "\nPartition\tSize\tProcess No.\tSize";
    for (i = 0; i < numberOfMemoryBlocks; i++)
    {
        cout << "\n"
             << i + 1 << "\t\t" << MemoryBlock[i] << "\t";
        if (flags[i] == 1)
            cout << allocation[i] + 1 << "\t\t" << Processes[allocation[i]];
        else
            cout << "Not allocated";
    }
    cout << endl;
    return 0;
}
