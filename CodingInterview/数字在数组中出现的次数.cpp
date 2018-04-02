/*
时间限制：1秒 空间限制：32768K 热度指数：105676
本题知识点： 数组
题目描述
统计一个数字在排序数组中出现的次数。
*/
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int cnt = 0;
        auto iter = lower_bound(data.begin(),data.end(),k);
        while(iter!=data.end() && *iter==k){
            cnt++;
            iter++;
        }
        return cnt;
    }
};
