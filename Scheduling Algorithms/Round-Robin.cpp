#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int i, j, n, max, t_slice;
    //Enter the number of processes
    cin >> n;
    vector<int> burst_time(n), wait_time(n), turn_around_time(n), c_t(n);
    float avg_tat_time = 0, avg_wait_time = 0, temp = 0;
    //Enter the time slice
    cin >> t_slice;
    //Enter the burst times
    for (i = 0; i < n; i++) {
        cin >> burst_time[i];
        c_t[i] = burst_time[i];
    }
    max = burst_time[0];
    for (i = 1; i < n; i++) {
        if (max < burst_time[i])
            max = burst_time[i];
    }
    for (j = 0; j < (max / t_slice) + 1; j++) {
        for (i = 0; i < n; i++) {
            if (burst_time[i] != 0) {
                if (burst_time[i] <= t_slice) {
                    turn_around_time[i] = temp + burst_time[i];
                    temp = temp + burst_time[i];
                    burst_time[i] = 0;
                } else {
                    burst_time[i] -= t_slice;
                    temp += t_slice;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        wait_time[i] = turn_around_time[i] - c_t[i];
        avg_tat_time += turn_around_time[i];
        avg_wait_time += wait_time[i];
    }
    cout << "\tPROCESS\tBURST TIME\t WAITING TIME\t TURNAROUND TIME\n";
    for (i = 0; i < n; i++) {
        cout << "\n\tP" << i << "\t\t" << c_t[i] << "\t\t" << wait_time[i] << "\t\t" << turn_around_time[i];
    }
    cout << "\nAverage Waiting Time: " << avg_wait_time / n;
    cout << "\nAverage Turnaround Time: " << avg_tat_time / n;
    return 0;
}
