// This is 24 Game problem solver using backtracking
// Leetcode 679. 24 Game (Hard), target sum = 24

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

float sumIt(float a, char op, float b)
{
    switch (op)
    {
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if (b == 0)
            return 0;
        return a / b;
        break;
    default:
        return a + b;
        break;
    }
}

// each card consists of 1 and 9
bool backtrack(vector<float> cards)
{
    if (cards.size() == 0)
    {
        return false;
    }
    if (cards.size() == 1)
    {
        if (cards[0] >= 24.1 || cards[0] < 23.94)
        {
            return false;
        }
        if (round(cards[0]) == 24)
            return true;
        return false;
    }
    float total = 0;
    vector<float> temp = cards;
    vector<float> old = temp;
    bool a, b, c, d, e, f;
    for (float i = 0; i < cards.size() - 1; i++)
    {
        for (float j = i + 1; j < cards.size(); j++)
        {
            temp = old;
            temp.erase(temp.begin() + j);
            temp.erase(temp.begin() + i);

            float temp1 = cards[i], temp2 = cards[j];

            float total1 = sumIt(temp1, '+', temp2);
            float total2 = sumIt(temp1, '-', temp2);
            float total3 = sumIt(temp1, '*', temp2);
            float total5 = sumIt(temp2, '-', temp1);

            if (temp2 != 0)
            {
                float total4 = sumIt(temp1, '/', temp2);
                temp.insert(temp.begin(), total4);
                a = backtrack(temp);
                if (a)
                    return true;
                temp.erase(temp.begin());
            }
            if (temp1 != 0)
            {
                float total6 = sumIt(temp2, '/', temp1);
                temp.insert(temp.begin(), total6);
                b = backtrack(temp);
                if (b)
                    return true;
                temp.erase(temp.begin());
            }

            temp.insert(temp.begin(), total1);
            a = backtrack(temp);
            if (a)
                return true;
            temp.erase(temp.begin());

            temp.insert(temp.begin(), total2);
            b = backtrack(temp);
            if (b)
                return true;
            temp.erase(temp.begin());

            temp.insert(temp.begin(), total3);
            c = backtrack(temp);
            if (c)
                return true;
            temp.erase(temp.begin());

            temp.insert(temp.begin(), total5);
            e = backtrack(temp);
            if (e)
                return true;
            temp.erase(temp.begin());
        }
    }
    return false;
}

int main()
{
    // vector<float> cards = {1,9,1,2};
    // vector<float> cards = {8,1,6,6};
    // vector<float> cards = {3,3,8,8};
    // vector<float> cards = {4,1,8,7};
    // vector<float> cards = {1,2,1,2};
    vector<float> cards = {1,3,4,6};
    // vector<float> cards = {1, 1, 7, 7};
    // vector<float> cards = {3, 4, 6, 7};
    bool ans = backtrack(cards);
    if (ans)
    {
        cout << "Answer = true" << endl;
    }
    else
    {
        cout << "Answer = false" << endl;
    }
    return 0;
}
