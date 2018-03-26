/*
时间限制：1秒 空间限制：32768K 热度指数：173269
本题知识点： 字符串
题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

/*
回溯法：
对于abcd
a的位置可以和后面的交换(也可以和自己)
确定了第1个位置的字母之后 递归：
        b的位置可以和后面的交换
        确定了第2个位置的字母之后 递归：
              c的位置可以和后面的交换
              确定了第3个位置的字母之后 递归：
                    d的位置可以和后面的交换
                    确定了第4个位置的字母之后 递归：
                          结束递归条件当start==str.size()时候，将(string)tmp存入result中 回溯(str和tmp都要回溯)
...

*/

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        int sz = str.size();
        if(sz==0) return vector<string>{};
        //sort(str.begin(),str.end());
        string tmp;
        recur(str,res,0,tmp);
        sort(res.begin(),res.end());
        return res;
    }
    void recur(string& str,vector<string>& res,int start,string& tmp)
    {
        if(start==str.size()){
            res.push_back(tmp);
        }
        for(int i=start;i<str.size();++i){
            if(i!=start&&str[i]==str[start]) 
                continue;
            swap(str[i],str[start]);
            tmp.push_back(str[start]);
            recur(str,res,start+1,tmp);
            tmp.pop_back();
            swap(str[i],str[start]);
        }
    }
};
