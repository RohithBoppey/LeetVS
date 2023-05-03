/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp1, mp2;
        for(auto x: nums1){
            mp1[x]++;
        }
        for(auto x: nums2){
            mp2[x]++;
        }

        // once they are added, we need to compare and do
        // traverse the map
        for(auto it: mp1){
            int key = it.first;
            // cout << key << endl;
            if(mp2.find(key) != mp2.end()){
                // present in mp2 for like k number of times
                int k = min(mp1[key], mp2[key]);
                while(k != 0){
                    res.push_back(key);
                    k--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

