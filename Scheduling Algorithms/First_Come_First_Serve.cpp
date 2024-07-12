#include <iostream>
#include <vector>
using namespace std;

int main() {

    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    double avg_wait_time = 0, avg_tat_time = 0;
    cin >> n; //no. of processes

    vector<int> burst_time(n), wait_time(n), turn_around_time(n);
    
   
    for (int i = 0; i < n; i++) {
        cin >> burst_time[i]; //burst time
    }
    
    wait_time[0] = 0;
    turn_around_time[0] = burst_time[0];
    
    for (int i = 1; i < n; i++) {
        wait_time[i] = wait_time[i - 1] + burst_time[i - 1];
        turn_around_time[i] = turn_around_time[i - 1] + burst_time[i];
        avg_wait_time += wait_time[i];
        avg_tat_time += turn_around_time[i];
    }
    
    cout << "\tPROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n";
    for (int i = 0; i < n; i++) {
        cout << "\n\tP" << i << "\t\t" << burst_time[i] << "\t\t" << wait_time[i] << "\t\t" << turn_around_time[i];
    }
    
    cout << "\nAverage Waiting Time: " << avg_wait_time / n;
    cout << "\nAverage Turnaround Time: " << avg_tat_time / n;
    
    return 0;
}
