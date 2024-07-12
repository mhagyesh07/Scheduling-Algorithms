#include <iostream>
#include <vector>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    int i, j, temp = 0, size;
    double avg_wait_time = 0, avg_tat_time = 0;
    //Enter the number of processes: 
    cin >> size;

    vector<int> arrival_time(size), burst_time(size), priority(size), waiting_time(size), turn_around_time(size), process(size);
    //Enter the priority, arrival time, and burst time of the processes

    for (i = 0; i < size; i++) {
        cin >> process[i] >> priority[i] >> arrival_time[i] >> burst_time[i];
    }

    waiting_time[0] = avg_wait_time = 0;
    turn_around_time[0] = avg_tat_time = burst_time[0];

    for (i = 1; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if ((priority[i] > priority[j]) && (arrival_time[i] < arrival_time[j])) {
                swap(priority[i], priority[j]);
                swap(burst_time[i], burst_time[j]);
                swap(arrival_time[i], arrival_time[j]);
                swap(process[i], process[j]);
            }
        }
    }

    for (i = 1; i < size; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        turn_around_time[i] = turn_around_time[i - 1] + burst_time[i];
        avg_wait_time += waiting_time[i];
        avg_tat_time += turn_around_time[i];
    }
    for (i = 1; i < size; i++) {
        waiting_time[i] -= arrival_time[i];
    }

    cout << "\tPROCESS\t\tPRIORITY\t ARRIVAL TIME\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n";
    for (i = 0; i < size; i++) {
        cout << "\n\tP" << process[i] << "\t\t" << priority[i] << "\t\t" << arrival_time[i] << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << "\t\t" << turn_around_time[i];
    }

    cout << "\nAverage Waiting Time: " << avg_wait_time / size;
    cout << "\nAverage Turnaround Time: " << avg_tat_time / size;
    return 0;
}
