#include <iostream>
#include <vector>
using namespace std;

int min(const vector<int>& burstTime, const vector<int>& arrivalTime, const vector<int>& priority, int current) {
    int min = 0;
    for (int i = 1; i < burstTime.size(); i++) {
        if (burstTime[min] == 0)
            min = i;
        if (priority[i] < priority[min] && current >= arrivalTime[i] && burstTime[i] != 0)
            min = i;
    }
    return min;
}

void incWaitTime(int index, int current, vector<int>& waitTime, const vector<int>& arrivalTime, const vector<int>& burstTime) {
    for (int i = 0; i < burstTime.size(); i++) {
        if (i != index && current >= arrivalTime[i] && burstTime[i] > 0)
            waitTime[i]++;
    }
}

void display(const vector<int>& burstTime, const vector<int>& arrivalTime, const vector<int>& waitTime, const vector<int>& turnaroundTime, const vector<int>& priority) {
    cout << "PID\tPriority\tBurst Time\tArrival Time\tWait Time\tTurnaround Time\n";
    for (int i = 0; i < burstTime.size(); i++)
        cout << "P" << i << "\t" << priority[i] << "\t\t" << burstTime[i] << "\t\t" << arrivalTime[i] << "\t\t" << waitTime[i] << "\t\t" << turnaroundTime[i] << '\n';
}

void prioritySched(vector<int>& burstTime, vector<int>& waitTime, const vector<int>& arrivalTime, vector<int>& turnaroundTime, const vector<int>& priority, int totalBurst) {
    int index;
    vector<int> tempBurstTime = burstTime;
    index = min(tempBurstTime, arrivalTime, priority, 0);
    for (int i = 0; i <= totalBurst; i++) {
        if (tempBurstTime[index] == 0)
            index = min(tempBurstTime, arrivalTime, priority, i);
        tempBurstTime[index]--;
        incWaitTime(index, i, waitTime, arrivalTime, tempBurstTime);
    }
    for (int i = 0; i < burstTime.size(); i++)
        turnaroundTime[i] = waitTime[i] + burstTime[i];
    display(burstTime, arrivalTime, waitTime, turnaroundTime, priority);
}

int main() {

	#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif


    vector<int> burstTime, arrivalTime, waitTime, turnaroundTime, priority;
    int totalBurst = 0, n;
    //Enter the number of processes
    cin >> n;
    burstTime.resize(n);
    arrivalTime.resize(n);
    waitTime.resize(n, 0);
    turnaroundTime.resize(n);
    priority.resize(n);
    //Enter burst times, arrival times, and priorities of the processes
    for (int i = 0; i < n; i++) {
        cin >> burstTime[i] >> arrivalTime[i] >> priority[i];
        totalBurst += burstTime[i];
    }
    prioritySched(burstTime, waitTime, arrivalTime, turnaroundTime, priority, totalBurst);
    return 0;
}
