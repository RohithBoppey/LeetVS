/*
 * @lc app=leetcode id=319 lang=cpp
 *
 * [319] Bulb Switcher
 */

// @lc code=start
class Solution {
public:
    int numberOfFactors(int n, vector<int>& f){
        // checking for sqrt should be enough
        if(f[n] != -1){
            return f[n];
        }
        int fac = 0;
        for(int i = 1; i <= sqrt(n); i++){
            if(n % i == 0){
                if(n / i == i){
                    // i**2 == n
                    fac += 1;
                }else{
                    fac += 2;
                }
            }
        }
        return f[n] = fac;
    }

    int bulbSwitch(int n) {
        if(n == 0){
            // all are off
            return 0;
        }
        if(n == 1){
            // all bulbs are on in the first round
            return n;
        }

        int res = 0;
        // the idea is that each bulb changes for the number of factors it has
        // vector<int> f(n + 1, -1);
        // for(int i = 1; i <= n; i++){
        //     int fact = numberOfFactors(i, f);
        //     cout << fact << " ";
        //     if(fact % 2 != 0){
        //         // odd 
        //         // then it is lit
        //         res++;
        //     }
        // }

        // will only be turning on when there is a square

        return sqrt(n);
    }
};
// @lc code=end

