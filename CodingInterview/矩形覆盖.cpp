/*
时间限制：1秒 空间限制：32768K 热度指数：142187
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法?
*/
/*
f(n)=f(n-1)+f(n-2),f(1)=1,f(2)=2;
*/


class Solution {
public:
    int rectCover(int number) {
        vector<long> dp={0,1,2};
        if(number<0) return -1;
        if(number<=2) return dp[number];
        number-=2;
        int i=1,j=2;
        while(number--){
            dp.push_back(dp[i++]+dp[j++]);
        }
        return dp.back();
    }
};
