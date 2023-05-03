/*
 * @lc app=leetcode id=2248 lang=cpp
 *
 * [2248] Intersection of Multiple Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        if(n == 1){
            sort(nums[0].begin(), nums[0].end());
            return nums[0];
        }
        vector<int> res;
        // since they are present in all
        // we can check count of that
        map<int,int> mp;
        for(auto &vec: nums){
            for(auto x: vec){
                mp[x]++;
            }
        }

        // now that all combined freq is ther
        for(auto &it: mp){
            int key = it.first;
            // cout << key << " : " << mp[key] << endl;
            if(mp[key] == n){
                res.push_back(key);
            }
        }
        return res;
    }
};
// @lc code=end

