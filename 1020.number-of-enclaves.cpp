/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
public:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};

    void dfs(int row, int col, vector<vector<int>>& visited,
     vector<vector<int>>& grid, int& count, 
     bool& reachBoundary){

        // cout << row << " " << col << endl;

        int rows = grid.size();
        int cols = grid[0].size();

        visited[row][col] = 1;

        // first check boundary
        if(row == rows - 1 || col == cols - 1 || row == 0 || col == 0){
            // is a boundary
            // cout << "Boundary!" << endl;
            reachBoundary = true;
        } 

        // continue the regular DFS
        for(int i = 0; i < 4; i++){
            int mrow = row + drow[i];
            int mcol = col + dcol[i];

            // check if the updated boundary is safe
            if(mcol >= 0 && mcol < cols && mrow >= 0 && mrow < rows){
                // is safe
                // int mcount = count + 1;
                // bool reach = reachBoundary;
                if(grid[mrow][mcol] == 1 && !visited[mrow][mcol]){
                    dfs(mrow, mcol, visited, grid, count = count + 1, reachBoundary);
                }
            }
        }

    }


    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        int totalCount = 0;
        
        // using count for each DFS call
        // using bool to show whether boundary or not
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    bool reachBoundary = false;
                    int count = 1;
                    dfs(i, j, visited, grid, count, reachBoundary);
                    if(reachBoundary == false){
                        // indicating cannot reach boundary
                        // cout << "Count: " << count << endl;
                        totalCount += count;
                    }
                }
            }
        }

        return totalCount;

    }
};
// @lc code=end

