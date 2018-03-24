/*
时间限制：1秒 空间限制：32768K 热度指数：210001
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

*/
/*
dp问题: f(n) = f(n-1)+f(n-1),f(1)=1,f(2)=2。
*/
class Solution {
public:
    int jumpFloor(int number) {
        vector<int> dp = {0,1,2};
        if(number<=2)
            return dp[number];
        number-=2;
        int i=1,j=2;
        while(number--){
            dp.push_back(dp[i++]+dp[j++]);
        }
        return dp.back();     
    }
};
