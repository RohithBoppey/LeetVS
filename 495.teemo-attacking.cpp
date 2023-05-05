/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int time = 0;
        // should find the amount of time poisoned
        int n = timeSeries.size();
        for(int i = 0; i < n - 1; i++){
            int curr = timeSeries[i];
            int next = timeSeries[i + 1];

            int new_t = curr + duration - 1;

            if(new_t < next){
                time += duration;
            }else{
                time += next - curr;
            }
        }
        
        time += duration;

        return time;
    }
};
// @lc code=end

