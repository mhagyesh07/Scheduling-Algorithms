#include <iostream>
#include <vector>
using namespace std;

int main() {   
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int i = 0, j = 0, k = 0, n, m, count = 0, choice;
           
    cin >> n; //no. of processes

    cin >> m;        //count of blocks                         

    vector<int> blockSize(m), processSize(n), temp(n, -1);
  
    for(i = 0; i < n; i++)
        cin >> processSize[i]; //sizes of processes
   
    for(j = 0; j < m; j++)
        cin >> blockSize[j]; //sizes of blocks

    // Enter choice:  1.First Fit   2.Best Fit   3.Worst Fit";
    cin >> choice;

    switch(choice) {
        case 1: 
            for(i = 0; i < n; i++) {
                for(j = 0; j < m; j++) {
                    if(processSize[i] <= blockSize[j] && blockSize[j] != 0) {
                        temp[i] = j;
                        blockSize[j] -= processSize[i];
                        break;
                    }
                }
            }    
            break;
        case 2: 
            for(i = 0; i < n; i++) {
                int diff = 9999;
                for(j = 0; j < m; j++) {
                    if(processSize[i] <= blockSize[j] && blockSize[j] != 0 && (blockSize[j] - processSize[i]) < diff) {
                        diff = blockSize[j] - processSize[i];
                        count = j;
                    }
                }
                if(diff != 0) {
                    blockSize[count] -= processSize[i];
                    temp[i] = count;
                }                                                   
            }   
            break;
        case 3: 
            for(i = 0; i < n; i++) {
                int diff = 0;
                for(j = 0; j < m; j++) {
                    if(processSize[i] <= blockSize[j] && blockSize[j] != 0 && (blockSize[j] - processSize[i]) > diff) {
                        diff = blockSize[j] - processSize[i];
                        count = j;
                    }
                }
                if(diff != 0) {
                    blockSize[count] -= processSize[i];
                    temp[i] = count;
                }
            }    
            break;
        default: 
            cout << "Wrong choice\n";    
    }

    cout << "\nProcess No.\t Process Size\tBlock no.\n";
    for(i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if(temp[i] != -1)
            cout << temp[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;    
    }
    
    return 0;
}
