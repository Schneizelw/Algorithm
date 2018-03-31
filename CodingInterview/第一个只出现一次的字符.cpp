/*
时间限制：1秒 空间限制：32768K 热度指数：129925
本题知识点： 字符串
题目描述
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        
        map<char,int> mp1,mp2;
        int len = str.length();
        for(int i=0;i<len;++i){
              mp1[str[i]]++;
        }
        for(int firstIndex = 0;firstIndex<len;++firstIndex ){
             if(mp1[str[firstIndex]]==1) 
                 return firstIndex;
        }
        return -1;
    }
};
