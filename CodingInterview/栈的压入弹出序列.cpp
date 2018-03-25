/*
时间限制：1秒 空间限制：32768K 热度指数：154725
本题知识点： 栈
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/



//解法1 使用map和一个vector标记 比较麻烦
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int sz = pushV.size();
        if(sz==0) return true;
        map<int,int> mp;
        for(int i=0;i<sz;++i){
            mp[pushV[i]] = i;
        }
        for(int i=0;i<sz;++i){
            if(mp.find(popV[i])==mp.end()) return false;
        }
        
        vector<bool> flagV(sz,false);
        flagV[mp[popV[0]]]= true;
        for(int i=0;i<sz-1;++i){
            int indexFirst = mp[popV[i]];
            int indexSecond = mp[popV[i+1]];
            //表示在压入顺序中popV[i+1]在popV[i]的前面，这时要检测
            if(indexFirst>indexSecond){
                for(int j=indexFirst-1;indexFirst>=0;--j){
                    if(flagV[j]==true) continue;
                    else if(popV[i+1]==pushV[j]){
                    //除了已经出栈的元素的 在压入序列中popV[i]的前一个元素是popV[i+1]
                        break;
                    }else{
                        return false;
                    }
                }
            }
            flagV[indexSecond] = true;
        }
        return true;
    }
};

//解法2 检测是否存在这种弹出的可能
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int sz = pushV.size();
        if(sz==0) return true;
        vector<int> sk;
        int indexV=0;
        for(int i=0;i<sz;++i){
            sk.push_back(pushV[i]);
            while(indexV<sz && sk.back()==popV[indexV]){
                sk.pop_back();
                indexV++;
            }
        }
        return sk.empty();
    }
};
