/*
时间限制：1秒 空间限制：32768K 热度指数：54625
本题知识点： 字符串
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/

class Solution
{
public:
    string s;
    char hash[256] = {0};
  //Insert one char from stringstream
    void Insert(char ch)
    {
        s += ch;
        hash[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i=0;i<s.length();++i)
        {
            if(hash[s[i]]==1) 
                return s[i];
        }
        return '#';
    }

};
