// This is same code as KnapsackTaskPriority01BruteForce.cpp but with memoization to optimize overlapping subproblems.
// This is not optimal as there can be cases where optimal solution is not stored in memoization structure.
// But it still improves performance for larger inputs compared to pure brute force.
// Just for learning purpose.

#include <iostream>
#include <vector>
using namespace std;

struct Task
{
    int id;
    int priority;
    int estimated_hours;
};

vector<Task> tasks;
vector<std::pair<std::pair<int,int>, vector<Task>>> memo;

int calculateTotalPriority(vector<Task> tasks1)
{
    int maxPriority = 0;
    for (int i = 0; i < tasks1.size(); i++)
    {
        maxPriority += tasks1[i].priority;
    }
    return maxPriority;
}

int calculateTotalHours(vector<Task> tasks1)
{
    int maxHours = 0;
    for (int i = 0; i < tasks1.size(); i++)
    {
        maxHours += tasks1[i].estimated_hours;
    }
    return maxHours;
}

vector<Task> taskPriority(vector<Task> ans = {}, int hours = 0, int index = 0)
{
    if ((tasks.size() <= index))
        return ans;

    if (tasks[index].estimated_hours > hours)
        return taskPriority(ans, hours, index + 1);

    int tempPriority1, tempPriority2, tempHours1, tempHours2;
    vector<Task> tasks1, tasks2;
    vector<Task> ans1 = ans, ans2 = ans;

    ans1.push_back(tasks[index]);

    /*
    * Memoization Check
    * If we have already solved the subproblem with the same index and hours, return the stored result.
    * This is to avoid overlapping subproblems and improve performance.
    * But another problem is that there may not be optimal solution in memo
    */

    for (auto &entry: memo){
        if (entry.first.first == index && entry.first.second == hours){
            return entry.second;
        }
    }

    tasks1 = taskPriority(ans1, hours-tasks[index].estimated_hours, index + 1);
    tasks2 = taskPriority(ans2, hours, index + 1);
    tempPriority1 = calculateTotalPriority(tasks1);
    tempPriority2 = calculateTotalPriority(tasks2);

    /*
    * Store the result in memoization structure before returning.
    */

    memo.push_back({
        {index, hours},
        (tempPriority1 > tempPriority2) ? tasks1 :
            (tempPriority1 == tempPriority2 ?
                (calculateTotalHours(tasks1) <= calculateTotalHours(tasks2) ? tasks1 : tasks2)
                : tasks2)
    });

    if (tempPriority1 > tempPriority2)
        return tasks1;
    else if (tempPriority1 == tempPriority2)
    {
        tempHours1 = calculateTotalHours(tasks1);
        tempHours2 = calculateTotalHours(tasks2);

        if (tempHours1 <= tempHours2)
            return tasks1;
        return tasks2;
    }
    return tasks2;
}

vector<Task> seed()
{
    tasks.clear();

    return {
        {1, 15, 7}, // 2.14
        {2, 12, 5}, // 2.4
        {3, 10, 4}, // 2.5
        {4, 8, 3},  // 2.67
        {5, 7, 2},  // 3.5
        {6, 5, 1},  // 5.0
        {7, 20, 9}, // 2.22 (big but high priority)
        {8, 6, 2}   // 3.0
    };
}

void printTask(vector<Task> tasks1)
{
    cout << "Tasks" << endl;
    for (int i = 0; i < tasks1.size(); i++)
    {
        if (i == 0)
            cout << "ID Priority Estimated_Hours Ratio" << endl;
        double ratio = (double)tasks1[i].priority / tasks1[i].estimated_hours;
        cout << tasks1[i].id << "\t " << tasks1[i].priority << "\t "
             << tasks1[i].estimated_hours << "\t\t " << ratio << endl;
    }
    cout << "------------------" << endl;
}

int main()
{
    cout << "=========================================" << endl;
    cout << "Knapsack Task Priority - Brute Force" << endl;
    cout << "=========================================" << endl;

    int maxHours = 10;
    tasks = seed();
    printTask(tasks);
    vector<Task> result = taskPriority({}, maxHours);
    cout << "Optimal Task Selection within " << maxHours << " hours:" << endl;
    printTask(result);
    cout << "Total Priority: " << calculateTotalPriority(result) << endl;
    cout << "=========================================" << endl;

    return 0;
}
