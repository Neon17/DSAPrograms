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

 /**
  * This is totally my solution
  */

 #include<iostream>
 #include<vector>
 #include<stack>
 #include<unordered_map>
 #include<unordered_set>
 using namespace std;

 class Solution {
public:
    struct node {
        int first = 0;
        int second = 0;
        int index = 0;
    };

    int trap(vector<int>& height) {
        int area = 0;
        stack<node> st;
        int size = height.size();
        int dp[size];
        for (int i=0;i<size;i++) dp[i]=0;
        int right = 0;

        st.push({height[0], height[0]});

        for (right = 1; right < size; right++){
            if (height[right] == 0) continue;
            
            if (height[right] < st.top().first){
                struct node top = st.top();
                top.second -= height[right];
                st.pop();
                st.push(top);
                int sep = right - st.top().index - 1;
                dp[right] = height[right] * sep;
                st.push({height[right], height[right], right});
                continue;
            }

            int tempSecond = height[right];
            while (!st.empty() && st.top().first <= height[right]){
                int sep = right - st.top().index - 1;
                dp[right] += st.top().second * sep;
                tempSecond = st.top().first;
                st.pop();
            }

            if (!st.empty()){
                st.top().second = st.top().first - height[right];
                dp[right] += (height[right] - tempSecond) * (right - st.top().index - 1);
            }
            st.push({height[right], height[right], right});
        }

        area = 0;
        for (int i=0;i<size;i++) area += dp[i];
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

      [4, 2, 3]
      [5, 0, 1, 0, 3]
      [6, 0, 2, 0, 5]
      [10, 0, 1, 0, 2, 0, 3]

      [3, 1, 2, 1, 3]
      [5, 0, 1, 0, 4]

      [4,0,3,0,2,0,5]
      [8,3,1,2,1,4,1,6]
      [0,3,0,1,0,2,0,5,0]
      [2,6,3,5,2,8,1,4,2,2,5,3,2]
    */
   
   Solution s; 
   vector<int> height;
   
//    height = {0,1,0,2,1,0,1,3,2,1,2,1};
//    cout<<s.trap(height)<<endl;

   // height = {4,2,0,3,2,5};
   // cout<<s.trap(height)<<endl;

   // height = {0,1,0};
   // cout<<s.trap(height)<<endl;

   // height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
   // cout<<s.trap(height)<<endl;

//    height = {0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3};
//    cout<<s.trap(height)<<endl;

   // height = {3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1};
   // cout<<s.trap(height)<<endl;

//    height = {0, 0, 1, 0, 1, 2, 1, 0, 0, 1, 0, 0};
//    cout<<s.trap(height)<<endl;

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

   // height = {3, 1, 2, 1, 3};
   // cout<<s.trap(height)<<endl;

   // height = {5, 0, 1, 0, 4};
   // cout<<s.trap(height)<<endl;

   // height = {4,0,3,0,2,0,5};
   // cout<<s.trap(height)<<endl;

   // height = {8,3,1,2,1,4,1,6};
   // cout<<s.trap(height)<<endl;

//    height = {0,3,0,1,0,2,0,5,0};
//    cout<<s.trap(height)<<endl;

//    height = {2,6,3,5,2,8,1,4,2,2,5,3,2,3};
//    cout<<s.trap(height)<<endl;

    // height = {2,6,3,5,2,8,1,4};
    // cout<<s.trap(height)<<endl;

    // height = {5, 4, 3, 2, 1, 2, 3, 4, 5};
    // cout<<s.trap(height)<<endl;

    height = {5, 4, 5, 4, 5};
    cout<<s.trap(height)<<endl;

   return 0;
 }

