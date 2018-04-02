/*
时间限制：1秒 空间限制：32768K 热度指数：93102
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        map<int,int> mp;
        int sz = array.size();
        vector<int> result;
        if(sz<2) return result;
        for(int i=0;i<sz;++i){
            int num = sum - array[i];
            if(mp.find(array[i])!=mp.end()){
                if(result.empty()){
                    result.push_back(mp[array[i]]);
                    result.push_back(array[i]);
                }else{
                    if(array[i]*mp[array[i]]<result[0]*result[1]){
                        result[0] = mp[array[i]];
                        result[1] = array[i];
                    }
                }
            }else{
                mp[num] = array[i];
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
