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
int totalPriority = 0;
int totalHours = 0;

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
        {1, 1, 1}, // Low priority, low hours
        {2, 2, 2}, // Medium priority, medium hours
        {3, 2, 1}  // High priority per hour (ratio=2)
    };
}

vector<Task> seed2()
{
    // Test Case 2: High value small task vs medium tasks
    // Task 1: (1, 10, 1) ratio=10
    // Task 2: (2, 8, 2) ratio=4
    // Task 3: (3, 7, 3) ratio=2.33
    // With 3 hours: optimal = task 1+2 (priority=18)
    // Could also do task 3 alone (priority=7) or 1+? (can't fit 1+3)

    return {
        {1, 10, 1}, // Very high value per hour
        {2, 8, 2},  // Good value
        {3, 7, 3}   // Lower ratio
    };
}

vector<Task> seed3()
{
    // Test Case 3: All tasks same hours but different priorities
    // Task 1: (1, 1, 2) ratio=0.5
    // Task 2: (2, 2, 2) ratio=1.0
    // Task 3: (3, 3, 2) ratio=1.5
    // With 3 hours: can't take all 3 (would need 6 hours)
    // Best is task 3 alone (priority=3) OR tasks 1+2 (priority=3)

    return {
        {1, 1, 2},
        {2, 2, 2},
        {3, 3, 2}};
}

vector<Task> seed4()
{
    // Test Case 4: One task dominates others (higher priority in fewer hours)
    // Task 1: (1, 5, 1) ratio=5
    // Task 2: (2, 3, 2) ratio=1.5
    // Task 3: (3, 2, 2) ratio=1.0
    // With 3 hours: optimal = task 1+2 (priority=8)

    return {
        {1, 5, 1}, // Best individual task
        {2, 3, 2}, // Good complement
        {3, 2, 2}  // Worst option
    };
}

vector<Task> seed5()
{
    // Test Case 5: Edge case - one very long task
    // Task 1: (1, 10, 10) ratio=1.0
    // Task 2: (2, 5, 1) ratio=5.0
    // Task 3: (3, 5, 1) ratio=5.0
    // With 3 hours: can't take task 1 (needs 10 hours)
    // Best is tasks 2+3 (priority=10)

    return {
        {1, 10, 10}, // Too long but high priority
        {2, 5, 1},
        {3, 5, 1}};
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

    if (tasks1.size() == 0)
    {
        return answer;
    }

    if (tasks1.size() == 1)
    {
        return tasks1;
    }

    if (tasks1.size() == 2)
    {
        // cout<<"reached size 2 base case"<<endl;
        temp.push_back(tasks1[0]);
        temp.push_back(tasks1[1]);

        int tempha = tasks1[0].estimated_hours;
        int temphb = tasks1[1].estimated_hours;

        int temppa = tasks1[0].priority;
        int temppb = tasks1[1].priority;

        if (maxHours >= (tempha + temphb))
        {
            tempHours = tempha + temphb;
            tempPriority = temppa + temppb;
            answer = temp;
        }
        else if (maxHours >= tempha && maxHours >= temphb)
        {
            // Both fit individually - take the higher priority one
            if (temppa >= temppb)
            {
                tempHours = tempha;
                tempPriority = temppa;
                answer = {tasks1[0]};
            }
            else
            {
                tempHours = temphb;
                tempPriority = temppb;
                answer = {tasks1[1]};
            }
        }
        else if (maxHours >= tempha)
        {
            tempHours = tempha;
            tempPriority = temppa;
            answer = {tasks1[0]};
        }
        else if (maxHours >= temphb)
        {
            tempHours = temphb;
            tempPriority = temppb;
            answer = {tasks1[1]};
        }
        else
        {
            tempHours = 0;
            tempPriority = 0;
            answer.clear();
            return answer;
        }

        // cout<<"tempHours = " << tempHours << ", tempPriority = " << tempPriority << endl;
        // cout<<"answer = ";
        // printTask(answer);
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
        for (int j = 0; j < tasks1.size(); j++)
        {
            if (i != j)
            {
                considerthis.push_back(tasks1[j]);
            }
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

    // Run all test cases
    vector<vector<Task> (*)()> testCases = {seed, seed2, seed3, seed4, seed5};
    vector<int> hourLimits = {1, 2, 3, 4, 5};
    vector<string> testNames = {
        "Test 1: Mixed priorities/hours",
        "Test 2: High value small task",
        "Test 3: Same hours, diff priorities",
        "Test 4: One dominant task",
        "Test 5: One very long task"};

    for (int testIdx = 0; testIdx < testCases.size(); testIdx++)
    {
        cout << "\n\n************************************************" << endl;
        cout << testNames[testIdx] << endl;
        cout << "************************************************" << endl;

        vector<Task> tasks = testCases[testIdx]();
        printTask(tasks);

        for (int hours : hourLimits)
        {
            cout << "\n--- Testing with " << hours << " hours available ---" << endl;

            // Reset global variables for each test
            totalPriority = 0;
            totalHours = 0;

            vector<Task> answer = taskPriority(tasks, hours);

            if (answer.empty())
            {
                cout << "No tasks can be selected within " << hours << " hours" << endl;
            }
            else
            {
                cout << "Optimal selection:" << endl;
                printTask(answer);
                int finalPriority = calculateTotalPriority(answer);
                int finalHours = 0;
                for (Task t : answer)
                {
                    finalHours += t.estimated_hours;
                }
                cout << "Total Priority: " << finalPriority << endl;
                cout << "Total Hours Used: " << finalHours << " out of " << hours << endl;
            }
        }
    }

    cout << "\n=========================================" << endl;
    cout << "All tests completed!" << endl;
    cout << "=========================================" << endl;

    return 0;
}