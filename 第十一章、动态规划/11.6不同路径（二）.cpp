// leetcode题号：63
// 题目：不同路径 II


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        dp[1][1] = 1;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(obstacleGrid[i-1][j-1] ==0) {
                    if(i==1 && j==1) continue;
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};


int main() {
    Solution sol=Solution();
    vector<vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    int result = sol.uniquePathsWithObstacles(obstacleGrid);
    cout << "Number of unique paths: " << result << endl; // Output: 2
    return 0;
}