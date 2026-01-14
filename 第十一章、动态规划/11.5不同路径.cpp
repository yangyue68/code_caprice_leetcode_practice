//leetcode题号：62
//题目：不同路径

#include<iostream>
#include<vector>
using namespace std;



//方法一：动态规划
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         for(int i=0;i<m;i++){
//             dp[i][0]=1;
//         }
//         for(int j=0;j<n;j++){
//             dp[0][j]=1;
//         }
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };



//方法二：空间优化后的动态规划
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<int> dp(n, 1);
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 dp[j]=dp[j]+dp[j-1];
//             }
//         }
//         return dp[n-1];
//     }
// };




//方法三：深度优先遍历
// class Solution {
// private:
//     int dfs(int i,int j,int m,int n){
//         if(i==m&&j==n){
//             return 1;
//         }
//         if(i>m||j>n){
//             return 0;
//         }
//         return dfs(i+1,j,m,n)+dfs(i,j+1,m,n);//向下走和向右走
//     }
// public:
//     int uniquePaths(int m, int n) {
//         return dfs(1,1,m,n);
//     }
// };



//方法四：组合数学,时间复杂度O(min(m,n)),空间复杂度O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long numerator=1;
        int t=m+n-2;
        int count=min(m-1,n-1);
         int denominator=count;
        while(count--){
            numerator*=t;
            t--;
            while(denominator!=0 && numerator%denominator==0){
                numerator/=denominator;
                denominator--;
            }
        }
        return (int)(numerator);
    }
};

int main(){
    Solution s=Solution();
    cout<<s.uniquePaths(3,7)<<endl;
    return 0;    
}