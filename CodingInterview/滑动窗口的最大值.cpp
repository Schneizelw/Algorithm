/*
时间限制：1秒 空间限制：32768K 热度指数：74122
题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
{2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        deque<int> dq;
        int sz = num.size();
        if(size==0) return vector<int>();
        if(size==1) return num;
        for(int i=0;i<sz;++i){
            while(!dq.empty() && num[i]>num[dq.back()])
                dq.pop_back();
            if(!dq.empty() && i-dq.front()+1>size)
                dq.pop_front();
            dq.push_back(i);
            if(i+1>=size)
                res.push_back(num[dq.front()]);
        }
        return res;
    }
};
