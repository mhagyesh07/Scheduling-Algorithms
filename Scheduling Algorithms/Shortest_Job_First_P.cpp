#include <iostream>
#include <vector>
using namespace std;

int main() {

    
    int i, n, smallest, count = 0, time;
    double avg_wait_time = 0, avg_turn_around_time = 0, end;
    //Enter the number of processes
    cin >> n;
    vector<int> burst_time(n), arrival_time(n), temp_burst_time(n);
    //Enter the arrival and burst times of the processes
    for (i = 0; i < n; i++) {
        cin >> arrival_time[i] >> burst_time[i];
        temp_burst_time[i] = burst_time[i];
    }
    burst_time.push_back(9999); // Adding a large value at the end for comparison
    for (time = 0; count != n; time++) {
        smallest = n; // Index of the large value
        for (i = 0; i < n; i++) {
            if (arrival_time[i] <= time && burst_time[i] < burst_time[smallest] && burst_time[i] > 0) {
                smallest = i;
            }
        }
        burst_time[smallest]--;
        if (burst_time[smallest] == 0) {
            count++;
            end = time + 1;
            avg_wait_time += end - arrival_time[smallest] - temp_burst_time[smallest];
            avg_turn_around_time += end - arrival_time[smallest];
        }
    }

    cout << "\n\nAverage Waiting Time: " << avg_wait_time / n;
    cout << "\n\nAverage Turnaround Time: " << avg_turn_around_time / n;

    return 0;
}
