/**
 * 42. Trapping Rain Water
 * Given n non-negative integers representing an elevation map where the width of each bar is 1
 * compute how much water it can trap after raining.
 * 
 * Example 1:
 * Input: height = [0,1,0,2,1,0,1
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]
 * 
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 * Explanation: The above elevation map (black section) is represented by array [4,2,0,3,2,5]
 * 
 * 
 * Topics: Array, Two Pointers, Stack, Dynamic Programming, Monotonic Stack
 * Difficulty: Hard
 * Acceptance: 67.0%
 */

 #include<iostream>
 #include<vector>
 #include<stack>
 #include<unordered_map>
 #include<unordered_set>
 using namespace std;

 class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> increase;
        stack<int> decrease;
        int size = height.size();
        int left = 0, area = 0, start = 0, right = 0;
        int level = 0, distance = 0, i=0;


      //   cout<<"[";
        for (i=0;i<size;i++){
            if (height[i] != 0){
                increase.push(height[i]);
                // cout<<height[i]<<", ";
                break;
            }
        }
        start = i; left = i;
        bool trend = true; // increasing or decreasing

        while (left < right || right == 0){
            trend = true;

            for (right = left+1; right < size; right++){
                if (trend){
                    if (increase.empty() || increase.top() <= height[right]){
                        increase.push(height[right]);
                        left++;
                        // cout<<height[right]<<", ";
                        continue;
                    } else{
                        trend = false;
                        // cout<<endl;
                    }
                } 
               //  cout<<height[right]<<",";
                decrease.push(height[right]);
                if (height[right] >= height[left] ){
                    distance = right - left - 1;
                    level = min(height[left], height[right]);
                    area += level * distance;
                    
                    left++;
                    while (left < right){
                        area -= height[left++];
                    }
                    while (!increase.empty()) increase.pop();
                    increase.push(height[right]);
                    while (!decrease.empty()) decrease.pop();
                    trend = true;
                    // cout<<"]"<<endl;
                    // cout<<"area = "<<area<<endl;
                    // cout<<"["<<increase.top()<<", ";
                }
            }
            
            right--; left++;
            // cout<<"left = "<<left<<endl;
            // cout<<"right = "<<right<<endl;
            if (left >= right) break;
            while (!increase.empty()) increase.pop();
            increase.push(height[left]);
            // cout<<"["<<increase.top();
            while (!decrease.empty()) decrease.pop();
        }

        return area;        
    }
};

int main() {

   /**
    * [0,1,0,2,1,0,1,3,2,1,2,1]
      [4,2,0,3,2,5]
      [0,1,0]
      [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
      [0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3]
      [3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1]
      [0, 0, 1, 0, 1, 2, 1, 0, 0, 1, 0, 0]

      [1, 2, 3, 4]
      [4, 3, 2, 1]
      [2, 0, 2]
      [3, 0, 0, 2, 0, 4]
      [5, 4, 1, 2, 3, 5]
    */
   
   Solution s; 
   vector<int> height;
   
   height = {0,1,0,2,1,0,1,3,2,1,2,1};
   cout<<s.trap(height)<<endl;

   height = {4,2,0,3,2,5};
   cout<<s.trap(height)<<endl;

   height = {0,1,0};
   cout<<s.trap(height)<<endl;

   height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
   cout<<s.trap(height)<<endl;

   height = {0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3};
   cout<<s.trap(height)<<endl;

   height = {3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1};
   cout<<s.trap(height)<<endl;

   height = {0, 0, 1, 0, 1, 2, 1, 0, 0, 1, 0, 0};
   cout<<s.trap(height)<<endl;

   // height = {1, 2, 3, 4};
   // cout<<s.trap(height)<<endl;

   // height = {4, 3, 2, 1};
   // cout<<s.trap(height)<<endl;

   // height = {2, 0, 2};
   // cout<<s.trap(height)<<endl;

   // height = {3, 0, 0, 2, 0, 4};
   // cout<<s.trap(height)<<endl;

   // height = {5, 4, 1, 2, 3, 5};
   // cout<<s.trap(height)<<endl;

   return 0;
 }

