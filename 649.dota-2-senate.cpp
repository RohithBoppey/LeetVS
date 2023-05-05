/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        // contains R and D
        // R can disable D or D can disable R

        // need to maintian which comes first

        /*
            The idea is to maintian order
            and since there are multiple rounds,
            we need to add index
            and then traverse
        */

        queue<int> qr, qd;
        int n = senate.size();
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R'){
                qr.push(i);
            }else{
                qd.push(i);
            }
        }

        // once indices are pushed
        // we need to see which will be left
        while(!qr.empty() && !qd.empty()){
            int ri = qr.front();
            int di = qd.front();

            qr.pop();
            qd.pop();

            if(ri < di){
                // radiant comes first
                // can eliminate dire

                // to eliminate radiant
                // we need next round
                qr.push(ri + n);
            }else{
                // dire comes first
                // can eliminate radiant

                // to eliminate dire
                // we need next roun
                qd.push(di + n);
            }
        }


        return (!qr.empty() ? "Radiant" : "Dire");

    }
};
// @lc code=end

