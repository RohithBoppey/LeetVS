/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
public:
    void printVector(vector<int> &v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }

// can contain inf elements - INT_MAX
    vector<int> s;
    SmallestInfiniteSet() {
        // using iota to initialize a pattern
        s.resize(1000, 0);
        iota(s.begin(), s.end(), 1);
        // printVector(s);
        // starting from 1 to N
        // worst case 1 to INT_MAX
    }
    
    int popSmallest() {
        int res = INT_MAX;;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != INT_MAX){
                res = s[i];
                s[i] = INT_MAX;
                // marking as visited
                return res;
            }
        }
        return res;
    }
    
    void addBack(int num) {
        s[num-1] = num;
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

