/*
时间限制：1秒 空间限制：32768K 热度指数：107195
本题知识点： 数组
题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:
在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？(子向量的长度至少是1)
*/

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sz = array.size();
        if(sz<=0) return 0;
        int greatTot=INT_MIN,tempTot=0;
        for(int i=0;i<sz;++i){
            tempTot += array[i];
            if(tempTot>greatTot) 
                greatTot = tempTot;
            if(tempTot<0){
                tempTot=0;
            }
        }
        return greatTot;
        
    }
};
