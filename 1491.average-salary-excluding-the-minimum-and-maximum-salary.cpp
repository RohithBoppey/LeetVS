/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
class Solution {
public:
    double average(vector<int>& salary) {
        // given all are unique ra unga
        // should leave the max and min
        int mn = INT_MAX, mx = 0;
        for(auto x: salary){
               mn = min(mn, x);
            mx = max(mx, x);
        }
        // min and max are founded
        // so should compare and find the average
        int sum = 0, n = 0;
        
        // cout << mx << " " << mn << endl; 
        for(auto x: salary){
            if(x != mx && x != mn){
                sum += x;
                n++;
            }
        }

        return (double) sum / n;
    }
};
// @lc code=end

