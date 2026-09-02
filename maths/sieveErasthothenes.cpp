// Mathematical Sieve of Eratosthenes implementation in C++17
// This program finds all prime numbers up to a given limit n using the Sieve of Eratosthenes algorithm.
// It has time complexity of O(n log log n) and space complexity of O(n).

#include <iostream>
#include <vector>
using namespace std;

int main(){
    // we say n = 30, then we have blackbox up to 30, and we want to find all prime numbers up to 30
    // if black box value is 1, then it is prime, if it is 0, then it is not prime
    // we can count all prime numbers from 1 to n by this
    int n, count = 0;
    n = 30; //say for now

    if (n < 2) {
        cout << "No primes.\n";
        return 0;
    }

    vector<int> prime(n+1, 1);
    prime[0] = 0; prime[1] = 0;

    for (int i = 2; i*i <= n;i++){
        if (prime[i] == 0) continue;
        for (int j = i*i; j <= n; j+=i) prime[j] = 0;
    }
    for (int i=2;i<=n;i++){
        if (prime[i]) {
            count++;
            cout<<i<<" ";
        }
    }
    cout<<endl;
    cout<<"Number of primes = "<<count<<endl;

    // Super optimal solution, using Sieve of Eratosthenes
    // just checking odd number and vector<bool> is slow as it uses bit mask and shifting
    // to pass on leetcode

        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);

        // if (n <= 2) return 0;
        // int count = 1;
        // vector<char> prime(n, 1);
        // prime[0] = false; prime[1] = false;

        // for (long long i=3; i < n ;i+=2){
        //     if (!prime[i]) continue;
        //     count++;
        //     if (i*i >= n) continue;
        //     for (long long j=i*i;j<n;j+=2*i) prime[j] = 0;
        // }
        // return count;

    return 0;
}

