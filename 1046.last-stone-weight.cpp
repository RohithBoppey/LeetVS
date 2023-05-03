/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:
    void insert(vector<int>& v, int k){
        int n = v.size();
        if(n == 0){
            v.push_back(k);
            return;
        }
        if(v[n-1] <= k){
            v.push_back(k);
            return;
        }
        // last element is greater than k
        int t = v[n-1];
        v.pop_back();
        insert(v, k);
        v.push_back(t);
    }

    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 1){
            return stones[0];
        }
        sort(stones.begin(), stones.end());
        // using some sort of insertion sort
        while(stones.size() != 1){
            // combine last 2
            n = stones.size();
            int diff = stones[n-1] - stones[n-2];
            stones.pop_back();
            stones.pop_back();
            if(diff == 0){
                // remove last 2 and done
                if(stones.size() == 0){
                    return 0;
                }
            }else if(diff > 0){
                // x is destroyed and insert diff at right pos
                insert(stones, diff);
            }
        }
        return stones[0];
    }
};

// @lc code=end

