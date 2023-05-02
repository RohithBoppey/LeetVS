/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(auto x: nums){
            if(x < 0){
                neg++;
            }else if(x == 0){
//                 x = 0, product itself is 0
                return 0;
            }
        }
        
        return (neg % 2 == 0) ? 1 : -1;
    }
};
// @lc code=end

