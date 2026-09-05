/*
    Leetcode Medium 165. Compare Version Numbers

    Given two version strings, version1 and version2, compare them. 
    A version string consists of revisions separated by dots '.'. 
    The value of the revision is its integer conversion ignoring leading zeros.

    To compare version strings, compare their revision values in left-to-right order. 
    If one of the version strings has fewer revisions, treat the missing revision values as 0.

    Return the following:
        If version1 < version2, return -1.
        If version1 > version2, return 1.
        Otherwise, return 0.

    Constraints:
        1 <= version1.length, version2.length <= 500
        version1 and version2 only contain digits and '.'.
        version1 and version2 are valid version numbers.
        All the given revisions in version1 and version2 can be stored in a 32-bit integer.
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int left1 = 0, left2 = 0, right1 = 0, right2 = 0;
        int a = version1.size(), b = version2.size();

        while (left1 < a || left2 < b) {

            while (right1 < a && version1[right1] != '.'){
                if (left1 < a && version1[left1] == '0') left1++;
                right1++;
            }

            while (right2 < b && version2[right2] != '.'){
                if (left2 < b && version2[left2] == '0') left2++;
                right2++;
            }

            if (right1 - left1 > right2 - left2) return 1;
            else if (right2 - left2 > right1 - left1) return -1;

            while (left1 < right1 && left2 < right2) {
                if (version1[left1] > version2[left2]) return 1;
                else if (version1[left1] < version2[left2]) return -1;
                left1++; left2++;
            }
            if (left1 < a) left1 = ++right1;
            if (left2 < b) left2 = ++right2;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    string version1, version2;

    version1 = "00001.00002"; version2 = "1.10";
    cout<<solution.compareVersion(version1, version2)<<endl; // Output: -1

    version1 = "1.01"; version2 = "1.001";
    cout<<solution.compareVersion(version1, version2)<<endl; // Output: 0

    version1 = "1.0"; version2 = "1.0.0.3";
    cout<<solution.compareVersion(version1, version2)<<endl; // Output: -1

    version1 = "1.2"; version2 = "1.3";
    cout<<solution.compareVersion(version1, version2)<<endl; // Output: -1

    return 0;
}
