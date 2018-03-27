/*
时间限制：1秒 空间限制：32768K 热度指数：108074
本题知识点： 数组
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
*/


class Solution {
public:
    static bool compare(const string& str1,const string& str2)
    {
        string s1 = str1+str2;
        string s2 = str2+str1;
        return s1<s2;
    }
    string PrintMinNumber(vector<int> numbers) {
        int sz = numbers.size();
        if(sz==0) return string();
        if(sz==1) return to_string(numbers[0]);
        vector<string> vec;
        for(int i=0;i<sz ;++i){
            vec.push_back(to_string(numbers[i]));
        }
        sort(vec.begin(),vec.end(),compare);
        string res;
        for(int i=0;i<sz;++i){
            res += vec[i];
        }
        return res;
    }
};
