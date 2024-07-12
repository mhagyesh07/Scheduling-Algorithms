#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Process {
    int id, burst_time, arrival_time, priority, remaining_time, wait_time, turn_around_time;
};

bool compareArrival(Process a, Process b) {
    return a.arrival_time < b.arrival_time;
}
bool priority()
{

}
void roundRobin(queue<Process>& q, int quantum, int& time) {
    while (!q.empty()) {
        Process p = q.front();
        q.pop();
        if (p.remaining_time > quantum) {
            time += quantum;
            p.remaining_time -= quantum;
            q.push(p);
        } else {
            time += p.remaining_time;
            p.remaining_time = 0;
            p.turn_around_time = time - p.arrival_time;
            p.wait_time = p.turn_around_time - p.burst_time;
            cout << "Process " << p.id << " completed with Turnaround Time: " << p.turn_around_time << " and Waiting Time: " << p.wait_time << endl;
        }
    }
}

void priorityScheduling(vector<Process>& q, int& time) {
    sort(q.begin(), q.end(), [](Process a, Process b) {
        return a.priority < b.priority;
    });
    for (auto& p : q) {
        time += p.burst_time;
        p.turn_around_time = time - p.arrival_time;
        p.wait_time = p.turn_around_time - p.burst_time;
        cout << "Process " << p.id << " completed with Turnaround Time: " << p.turn_around_time << " and Waiting Time: " << p.wait_time << endl;
    }
}

void fcfs(queue<Process>& q, int& time) {
    while (!q.empty()) {
        Process p = q.front();
        q.pop();
        time += p.burst_time;
        p.turn_around_time = time - p.arrival_time;
        p.wait_time = p.turn_around_time - p.burst_time;
        cout << "Process " << p.id << " completed with Turnaround Time: " << p.turn_around_time << " and Waiting Time: " << p.wait_time << endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n, quantum;
    cin >> n;//no. of processes
    //Enter the time quantum for Round Robin: 
    cin >> quantum;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        //Enter arrival time, burst time, and priority for process 
        cin >> processes[i].arrival_time >> processes[i].burst_time >> processes[i].priority;
        processes[i].remaining_time = processes[i].burst_time;
    }

    sort(processes.begin(), processes.end(), compareArrival);

    queue<Process> high_priority_queue;
    vector<Process> medium_priority_queue;
    queue<Process> low_priority_queue;

    for (auto& p : processes) {
        if (p.priority >= 7) {
            high_priority_queue.push(p);
        } else if (p.priority >= 4) {
            medium_priority_queue.push_back(p);
        } else {
            low_priority_queue.push(p);
        }
    }

    int time = 0;
    cout << "\nProcessing High Priority Queue (Round Robin):\n";
    roundRobin(high_priority_queue, quantum, time);

    cout << "\nProcessing Medium Priority Queue (Priority Scheduling):\n";
    priorityScheduling(medium_priority_queue, time);

    cout << "\nProcessing Low Priority Queue (FCFS):\n";
    fcfs(low_priority_queue, time);

    return 0;
}
