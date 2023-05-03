/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:

    /*
        LOGIC:
            Also simple idea why digital root equals to mod 9 if we've got an ABCD number
            ABCD = 1000A+100B+10*C+D = (A + B + C + D) + 9 * (111 * A + 11 * B + C)
            this equals (mod 9) to A + B + C + D.
    
    */

    int addDigits(int num) {
        // if num is less than 10 we can return
        if(num < 10) return num;

        // if more, we need to add recursively
        if(num % 9 == 0){
            return 9;
        }

        return num % 9;
    }
};
// @lc code=end

