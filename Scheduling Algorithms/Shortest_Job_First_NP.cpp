#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
	
    int i, n, min, k = 1, btime = 0;
    vector<int> p = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> burst_time(10), arrival_time(10), wait_time(10), turn_around_time(10);
    int temp, j, ta = 0, sum = 0;
    float total_tat_time = 0, total_wait_time = 0;
    cout << " -------Shortest Job First Scheduling ( NP )-------\n";
    cin >> n; // no. of processes

    for(i = 0; i < n; i++) {
        
        cin >> burst_time[i]; // burst time 
        cin >> arrival_time[i];// arrival time
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(arrival_time[i] < arrival_time[j]) {
                swap(p[j], p[i]);
                swap(arrival_time[j], arrival_time[i]);
                swap(burst_time[j], burst_time[i]);
            }
        }
    }

    for(j = 0; j < n; j++) {
        btime += burst_time[j];
        min = burst_time[k];
        for(i = k; i < n; i++) {
            if (btime >= arrival_time[i] && burst_time[i] < min) {
                swap(p[k], p[i]);
                swap(arrival_time[k], arrival_time[i]);
                swap(burst_time[k], burst_time[i]);
            }
        }
        k++;
    }

    wait_time[0] = 0;
    for(i = 1; i < n; i++) {
        sum += burst_time[i - 1];
        wait_time[i] = sum - arrival_time[i];
        total_wait_time += wait_time[i];
    }

    for(i = 0; i < n; i++) {
        ta += burst_time[i];
        turn_around_time[i] = ta - arrival_time[i];
        total_tat_time += turn_around_time[i];
    }

    cout << "\tPROCESS\t ARRIVAL TIME\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n";
    for(i = 0; i < n; i++) {
        cout << "\n\tP" << p[i] << "\t\t" << arrival_time[i] << "\t\t" << burst_time[i] << "\t\t" << wait_time[i] << "\t\t" << turn_around_time[i];
    }
    cout << "\nAverage Waiting Time: " << total_wait_time / n;
    cout << "\nAverage Turnaround Time: " << total_tat_time / n;
    return 0;
}
