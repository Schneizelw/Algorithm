/*
时间限制：1秒 空间限制：32768K 热度指数：120243
本题知识点： 数组
题目描述
把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，
但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。
求按从小到大的顺序的第N个丑数。
*/


class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        long uglyNum = 1;
        set<long> s;
        if(index<=0) return 0;
        while(--index){
            s.insert(uglyNum*2);
            s.insert(uglyNum*3);
            s.insert(uglyNum*5);
            uglyNum = *s.begin();
            s.erase(s.begin());
        }
        return uglyNum;
    }
};
