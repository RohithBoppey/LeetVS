/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
    void solve(int start, int target, vector<int>& curr, vector<vector<int>>& graph, vector<vector<int>>& res){
        if(start == target){
            curr.push_back(start);
            res.push_back(curr);
            curr.pop_back();
            return;
        }

        // using dfs
        curr.push_back(start);
        for(auto x: graph[start]){
            // traverse all connecting edges
            solve(x, target, curr, graph, res);
        }
        curr.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        // so I am having n number of nodes
        // find path from 0 to n - 1

        // we can use bfs or dfs to do this
        // already given is adjList
        vector<vector<int>> res;
        vector<int> curr;
        solve(0, n - 1, curr, graph, res);
        return res;
    }
};
// @lc code=end

