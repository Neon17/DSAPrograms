#include <iostream>
#include <vector>
#include <random>
#include <unordered_map>
#include <thread>
using namespace std;

// We can even solve this problem by hashing and sorting but it takes O(nlogn) time
// Even though this code performs at O(n) time complexity due to more swaps, hashing and quickSorting is very fast due to fewer data

int partition(vector<pair<int, int>> &arr, int low, int high)
{
    if (low > high)
        throw invalid_argument("high can not be less than low, Error in partition function");
    else if (low == high)
        return low;
    int pivot = arr[(low + high) / 2].second;
    int i = low - 1, j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i].second > pivot);
        do
        {
            j--;
        } while (arr[j].second < pivot);

        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }

    return i;
}

void quickSelect(vector<pair<int, int>> &arr, int low, int high, int k)
{
    if (low >= high)
        return;

    int index = partition(arr, low, high);
    if (index - low + 1 == k)
        return;
    else if (index - low + 1 > k)
        quickSelect(arr, low, index, k);
    else
        quickSelect(arr, index + 1, high, k - index + low - 1);
}

vector<int> topKFrequency(vector<int> arr, int k = 5)
{
    // value count
    unordered_map<int, int> freq;
    vector<pair<int, int>> freqPairs;

    for (int i = 0; i < arr.size(); i++)
        freq[arr[i]]++;
    for (auto &[val, count] : freq)
        freqPairs.push_back({val, count});

    quickSelect(freqPairs, 0, freqPairs.size() - 1, k);

    vector<int> result;
    for (int i = 0; i < k; i++)
        result.push_back(freqPairs[i].first);
    return result;
}

void printVector(vector<int> arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << arr[i];
    }
    cout << "]" << endl;
}

void randomFill(vector<int> &arr, int size = 100, int startValue = 1, int endValue = 20)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(startValue, endValue);

    arr.clear();
    for (int i = 0; i < size; ++i)
    {
        arr.push_back(distrib(gen));
    }
}

int main()
{
    vector<int> arr, ans;
    randomFill(arr);

    auto start = std::chrono::high_resolution_clock::now();
    ans = topKFrequency(arr);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = end - start;

    printVector(ans);
    std::cout << "It took: "
              << std::chrono::duration_cast<std::chrono::microseconds>(duration).count()
              << " microseconds" << std::endl;

    return 0;
}
