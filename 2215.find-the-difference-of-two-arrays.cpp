/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1;
        vector<int> v2;

        // processing starts here
        // first array - unique from first
        // second array - unique from second

        // need not be sorted also, array can be any order

        
        set<int> s1, s2;

        for(auto x: nums1){
            s1.insert(x);
        }
        for(auto x: nums2){
            s2.insert(x);
        }

        // using for loops to iterate and push
        for(auto x: s1){
            // check in mp2
            if(s2.find(x) == s2.end()){
                // not there so push
                // while(k != 0){
                    v1.push_back(x);
                // }
            }
        }

        for(auto x: s2){
            // check in mp2
            if(s1.find(x) == s1.end()){
                // not there so push
                // while(k != 0){
                    v2.push_back(x);
                // }
            }
        }
        
        vector<vector<int>> res = {v1, v2};
        return res;
    }
};
// @lc code=end

