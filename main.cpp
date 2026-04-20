#include <bits/stdc++.h>
using namespace std;

// This structure represents a task
struct Task {
    string name;   // Task name (T1, T2, etc.)
    int start;     // Start time
    int end;       // End time
    int priority;  // Higher number = higher priority
};

// Function to print tasks nicely
void printTasks(const vector<Task>& tasks) {
    for (auto t : tasks) {
        cout << t.name << " (" << t.start << "-" << t.end 
             << ", Priority: " << t.priority << ")\n";
    }
}

// This function combines two halves and removes conflicts
vector<Task> mergeSchedule(vector<Task>& left, vector<Task>& right) {

    vector<Task> combined;

    // Step 1: Combine both halves into one list
    combined.insert(combined.end(), left.begin(), left.end());
    combined.insert(combined.end(), right.begin(), right.end());

    // Step 2: Sort tasks
    // First by end time (earlier finishing first)
    // If same end time, higher priority first
    sort(combined.begin(), combined.end(), [](Task a, Task b) {
        if (a.end == b.end)
            return a.priority > b.priority; // higher priority first
        return a.end < b.end; // earlier end first
    });

    vector<Task> result;

    int lastEnd = -1; // Keeps track of last selected task's end time

    // Step 3: Select non-overlapping tasks
    for (auto task : combined) {

        // If current task starts after previous one ends → no conflict
        if (task.start >= lastEnd) {
            result.push_back(task); // select it
            lastEnd = task.end;     // update last end time
        }
    }

    return result;
}

// Main Divide & Conquer function
vector<Task> divideAndConquer(vector<Task>& tasks, int left, int right) {

    // Base case: only one task → return it
    if (left == right) {
        return {tasks[left]};
    }

    // Step 1: Divide into two halves
    int mid = (left + right) / 2;

    // Solve left half
    vector<Task> leftPart = divideAndConquer(tasks, left, mid);

    // Solve right half
    vector<Task> rightPart = divideAndConquer(tasks, mid + 1, right);

    // Step 2: Merge both halves
    return mergeSchedule(leftPart, rightPart);
}

int main() {

    // Sample tasks
    vector<Task> tasks = {
        {"T1", 1, 4, 2},
        {"T2", 3, 5, 1},
        {"T3", 0, 6, 3},
        {"T4", 5, 7, 2},
        {"T5", 8, 9, 1},
        {"T6", 5, 9, 2}
    };

    cout << "Input Tasks:\n";
    printTasks(tasks);

    // Call Divide & Conquer
    vector<Task> result = divideAndConquer(tasks, 0, tasks.size() - 1);

    cout << "\nFinal Scheduled Tasks:\n";
    printTasks(result);

    return 0;
}