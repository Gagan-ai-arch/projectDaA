"# projectDAA 
Project Documentation

Title: Optimized Task Scheduling using Divide and Conquer with Greedy Conflict Resolution

1. Introduction

Task scheduling is a fundamental problem in computer science where a set of tasks must be arranged in a way that avoids conflicts and optimizes certain criteria. In this project, we address the scheduling of tasks defined by start time, end time, and priority.

The proposed solution uses a combination of the Divide and Conquer paradigm and a Greedy strategy. Divide and Conquer is used to break the problem into smaller subproblems, while the Greedy method is applied during the merge phase to select the optimal set of non-overlapping tasks.

2. Problem Statement

Given a list of tasks, where each task has:

A start time
An end time
A priority value

The objective is to:

Select a subset of tasks such that no two tasks overlap
Maximize the number of scheduled tasks
Prefer tasks with higher priority when conflicts arise
3. Approach
3.1 Divide and Conquer Strategy

The task list is recursively divided into two halves until each subproblem contains only one task. Each subproblem is solved independently.

3.2 Merge Strategy (Greedy)

During the merge phase:

Combine tasks from both halves
Sort tasks based on:
Earliest finishing time
Higher priority (in case of tie)
Select tasks sequentially such that:
A task is chosen only if its start time is greater than or equal to the end time of the last selected task

This ensures that the final schedule contains non-overlapping tasks.

4. Algorithm
Divide and Conquer Function
If only one task is present, return it
Otherwise:
Divide the task list into two halves
Recursively solve each half
Merge the results using the greedy selection process
Merge Function
Combine both task lists
Sort tasks by end time and priority
Iterate through sorted tasks and select non-overlapping ones
5. Implementation Details
Data Structure

A structure named Task is used with the following attributes:

name (string): Identifier of the task
start (int): Start time
end (int): End time
priority (int): Priority level
Key Functions
divideAndConquer: Recursively divides the task list and merges results
mergeSchedule: Combines two lists and selects non-overlapping tasks
printTasks: Displays tasks in a readable format
6. Time Complexity
Divide step: O(log n) levels of recursion
Merge step: O(n log n) due to sorting at each level

Overall Time Complexity:
O(n log² n)

7. Space Complexity
Recursive stack: O(log n)
Auxiliary space for merging: O(n)
8. Sample Input

T1 (1, 4, 2)
T2 (3, 5, 1)
T3 (0, 6, 3)
T4 (5, 7, 2)
T5 (8, 9, 1)
T6 (5, 9, 2)

9. Sample Output

T1 (1–4, Priority: 2)
T4 (5–7, Priority: 2)
T5 (8–9, Priority: 1)

10. Advantages
Modular and scalable design
Suitable for parallel execution
Handles large datasets effectively
Clear separation between problem decomposition and solution construction
11. Limitations
Higher computational overhead compared to pure greedy algorithms
Not optimal for all scheduling scenarios
Repeated sorting increases time complexity
12. Applications
CPU scheduling in operating systems
Cloud task distribution
Job scheduling in distributed systems
Workflow management systems
13. Conclusion

This project demonstrates how Divide and Conquer can be combined with a Greedy strategy to solve a scheduling problem. While not the most optimal approach in terms of time complexity, it provides a structured and scalable method that is useful in distributed and parallel environments. The hybrid nature of the algorithm highlights the practical integration of multiple design techniques in solving real-world problems.