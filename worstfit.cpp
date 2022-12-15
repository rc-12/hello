#include <iostream>  
using namespace std; 

int main()
{ 

    int NumberOfBlock, NumberOfProcess, MemoryBlock[20], Processes[20];

    cout << " Please enter the number of Memory Blocks: ";
    cin >> NumberOfBlock; 

    cout << " Please enter the number of processes: ";
    cin >> NumberOfProcess; 

    cout << " Please enter the size of " << NumberOfBlock << " blocks: ";
    for (int i = 0; i < NumberOfBlock; i++)
    {
        cin >> MemoryBlock[i];
    } 

    cout << " Please enter the size of " << NumberOfProcess << " processes: ";
    for (int i = 0; i < NumberOfProcess; i++)
    {
        cin >> Processes[i];
    } 

    
    for (int i = 0; i < NumberOfProcess; i++)
    {
    	
        int max = MemoryBlock[0];
        int pos = 0;
        for (int j = 0; j < NumberOfBlock; j++)
            if (max < MemoryBlock[j])
            {
                max = MemoryBlock[j];
                pos = j;
            }
        
        if (max >= Processes[i])
        {
            cout << "\nProcess " << i + 1 << " is allocated to block "
                 << pos + 1;
            MemoryBlock[pos] = MemoryBlock[pos] - Processes[i];
        }
        else
        {
            cout << "\nProcess " << i + 1 << " can't be allocated!";
        }
    }
    cout << endl;
    return 0;
}
