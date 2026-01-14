// leetcode题号：70
// 题目：爬楼梯

#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(3);
        if(n==1||n==2){
            return n;
        }
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[0]=dp[1]+dp[2];
            dp[1]=dp[2];
            dp[2]=dp[0];
        }

        return dp[2];        
    }
};


int main(){
    Solution s=Solution();
    cout<<s.climbStairs(3)<<endl;
    return 0;    
}



