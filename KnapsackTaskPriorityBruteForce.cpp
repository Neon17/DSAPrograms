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
// int totalPriority = 0;
// int totalHours = 0;

vector<Task> seed()
{
    tasks.clear(); // Clear any existing tasks

    // Test Case 1: Simple case - optimal should be tasks 2 and 3
    // Task 1: (id=1, priority=1, hours=1) ratio=1.0
    // Task 2: (id=2, priority=2, hours=2) ratio=1.0
    // Task 3: (id=3, priority=2, hours=1) ratio=2.0
    // With 3 hours: optimal = tasks 2+3 (priority=4) OR tasks 1+2+? (can't fit all)

    // Actually task 2+3 = priority 4, hours 3
    // Task 1+2+3 = priority 5 but hours 4 > 3, so not possible
    // Task 1+3 = priority 3, hours 2
    // So optimal is 2+3

    return {
        {1, 15, 7},  // 2.14
        {2, 12, 5},  // 2.4
        {3, 10, 4},  // 2.5
        {4, 8, 3},   // 2.67
        {5, 7, 2},   // 3.5
        {6, 5, 1},   // 5.0
        {7, 20, 9},  // 2.22 (big but high priority)
        {8, 6, 2}    // 3.0
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

int calculateTotalPriority(vector<Task> tasks1)
{
    int maxPriority = 0;
    for (int i = 0; i < tasks1.size(); i++)
    {
        maxPriority += tasks1[i].priority;
    }
    return maxPriority;
}

vector<Task> taskPriority(vector<Task> tasks1, int maxHours)
{
    vector<Task> temp;
    vector<Task> answer, tempa, considerthis;
    int tempPriority = 0;
    int tempHours = 0;
    int totalPriority = 0;
    int totalHours = 0;

    if (tasks1.size() == 0)
    {
        return answer;
    }

    if (tasks1.size() == 1)
    {
        if (tasks1[0].estimated_hours <= maxHours)
        {
            answer.push_back(tasks1[0]);
        }
        return answer;
    }

    for (int i = 0; i < tasks1.size(); i++)
    {
        // cout<<"Considering Task ID: " << tasks1[i].id << ", i = " << i << ", tasks1.size() = " << tasks1.size() << endl;
        temp.clear();
        considerthis.clear();
        temp.push_back({tasks1[i]});
        tempHours = tasks1[i].estimated_hours;
        if (tempHours > maxHours)
        {
            continue;
        }
        else if (tempHours == maxHours)
        {
            tempPriority = calculateTotalPriority(temp);
            if (tempPriority > totalPriority)
            {
                totalPriority = tempPriority;
                totalHours = tempHours;
                answer.clear();
                answer = temp;
            }
            continue;
        }

        considerthis.clear();
        for (int j = i+1; j < tasks1.size(); j++)
        {
            considerthis.push_back(tasks1[j]);
        }
        // cout<<"Calling taskPriority recursively with maxHours = " << maxHours-tempHours << endl;
        // cout<<"temp size before recursive call: " << considerthis.size() << endl;
        considerthis = taskPriority(considerthis, maxHours - tempHours);
        for (int k = 0; k < considerthis.size(); k++)
        {
            temp.push_back(considerthis[k]);
        }
        tempPriority = calculateTotalPriority(temp);

        // cout<<"tempHours = " << tempHours << ", tempPriority = " << tempPriority << endl;
        if (tempPriority > totalPriority)
        {
            totalPriority = tempPriority;
            totalHours = tempHours;
            answer.clear();
            answer = temp;
        }
        // cout<<"Current Best Answer: "<<endl;
        // printTask(answer);
    }

    return answer;
}

int main()
{
    cout << "=========================================" << endl;
    cout << "Knapsack Task Priority - Brute Force" << endl;
    cout << "=========================================" << endl;

    int maxHours = 10;
    tasks = seed();
    printTask(tasks);
    vector<Task> result = taskPriority(tasks, maxHours);
    cout << "Optimal Task Selection within " << maxHours << " hours:" << endl;
    printTask(result);
    cout << "Total Priority: " << calculateTotalPriority(result) << endl;
    cout << "=========================================" << endl;

    return 0;
}