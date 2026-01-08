// I am solving Leetcode 127. Word Ladder (Medium), transforming beginWord to endWord by changing one letter at a time using words from wordList.
// The topics are: Array, Breadth-First Search, String, Hash Table

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

bool diffOne(string a, string b)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            count++;
    }
    if (count == 1)
        return true;
    return false;
}

int minLadderLength(string beginWord, string endWord, vector<string> &wordlist)
{
    int status = 0;
    for (int i = 0; i < wordlist.size(); i++)
    {
        if (endWord == wordlist[i])
            status = 1;
    }
    if (status != 1)
        return 0;
    if (beginWord == endWord)
        return 2;

    queue<string> q;
    unordered_set<string> visited;

    int level = 0, size = 0;
    q.push(beginWord);
    string temp;
    bool stop = false;
    while (!q.empty())
    {
        size = q.size();
        level++;

        cout<<endl<<endl<<"level = "<<level<<endl;
        for (int i = 0; i < size; i++)
        {
            temp = q.front();
            q.pop();
            visited.insert(temp);

            if (temp == endWord)
            {
                stop = true;
                break;
            }

            int j = 0;
            cout<<endl;
            cout<<"wordlist.size() = "<<wordlist.size()<<endl;
            cout<<"value = "<<temp<<endl;
            while (j < wordlist.size())
            {
                if (visited.count(wordlist[j])){
                    j++; 
                    continue;
                }
                if (diffOne(temp, wordlist[j]))
                {
                    cout<<"string with one difference = "<<wordlist[j]<<endl;
                    q.push(wordlist[j]);
                    wordlist.erase(wordlist.begin() + j);
                    j = j-1;
                }
                j++;
            }
        }
        if (stop)
            break;
    }
    if (!stop) return 0;
    return level;
}

int main()
{
    string beginWord, endWord;
    vector<string> wordList;

    // beginWord = "hit"; endWord = "cog";
    // beginWord = "a"; endWord = "c";
    // beginWord = "leet"; endWord = "code";
    beginWord = "hot"; endWord = "dog";

    // wordList = {"hot","dot","dog","lot","log","cog"};
    // wordList = {"hot","dot","dog","lot","log"};
    // wordList = {"a", "b", "c"};
    // wordList = {"lest","leet","lose","code","lode","robe","lost"};
    wordList = {"hot", "dog"};

    cout << "Min Ladder Length = " << minLadderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
