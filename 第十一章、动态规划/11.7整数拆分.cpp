//leetcode题号：343
//题目：整数拆分
#include<iostream>
#include<vector>
using namespace std;


//方法一：动态规划
// class Solution {
// public:
//     int integerBreak(int n) {
//         if(n<=3) return n-1;
//         vector<int> dp(n+1,0);
//         dp[1]=1;
//         dp[2]=1;
//         dp[3]=2;
//         for(int i=4;i<=n;i++){
//             for(int j=1;j<i;j++){
//                 dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
//             }
//         }
//         return dp[n];
        
//     }
// };





//方法二：贪心算法
class Solution {
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        int product=1;
        while(n>4){
            n-=3;
            product*=3;
        }
        if(n>0){
            product*=n;
        }
        return product;
    }
};

int main() {
    Solution sol=Solution();
    int n = 10;
    int result = sol.integerBreak(n);
    cout << "Maximum product for integer " << n << " is: " << result << endl; // Output: 36
    return 0;
}