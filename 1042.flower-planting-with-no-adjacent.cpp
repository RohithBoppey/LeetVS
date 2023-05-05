/*
 * @lc app=leetcode id=1042 lang=cpp
 *
 * [1042] Flower Planting With No Adjacent
 */

// @lc code=start
class Solution {
public:
    bool dfs(int start, int color, vector<vector<int>>& adjList, vector<int>& res){
        if(res[start] == color){
            // color matched
            return false;
        }

        for(auto node: adjList[start]){
            // checking for path
            if(res[node] == color){
                return false;
            }
        }

        return true;
    }


    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // should generate adjList
        vector<vector<int>> adjList(n + 1);

        // n denotes number of gardens 
        // paths means the connection

        for(auto &x: paths){
            adjList[x[0]].push_back(x[1]);
            adjList[x[1]].push_back(x[0]);
        }

        // adjList is created
        
        vector<int> res(n + 1, -1);
        // we need to find the flower we are planting in the garden i + 1

        // mark all of the flowers used and use the first one
        
        // to color all gardens
        for(int i = 1; i <= n; i++){
            if(res[i] == -1){
                // not coloured yet
                // find the valid colour
            for(int j = 1; j <= 4; j++)
                // checking for all colours
                // IF PATH CONTAINS THE COLOUR, DONT USE
                if(dfs(i, j, adjList, res)){
                    res[i] = j; 
                }
            }
        }
    
        res.erase(res.begin());
        return res;
    }
};
// @lc code=end

