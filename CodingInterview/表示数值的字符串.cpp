/*
时间限制：1秒 空间限制：32768K 热度指数：59140
本题知识点： 字符串
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

*/

class Solution {
public:
    
    bool scanUnsignedInt(string& str,int& curIndex)
    {
        int beforeIndex = curIndex;
        int len = str.length();
        while(curIndex<len && str[curIndex]-'0'>=0 &&
            str[curIndex]-'9'<=9 )
        {
            ++curIndex;
        }
        return curIndex>beforeIndex;
    }
    
    bool scanInt(string& str,int& curIndex)
    {
        if(str[curIndex]=='+' || str[curIndex]=='-')
        {
            curIndex++;
        }
        return scanUnsignedInt(str,curIndex);
    }
    
    bool isNumeric(char* string)
    {
        //A[.[B]][e|EC] 或者 .B[e|EC]
        std::string str(string);
        int len = str.length();
        if(len==0) return false;
        int curIndex=0;
        bool numeric = scanInt(str,curIndex);
        if(curIndex<len && str[curIndex]=='.')
        {
            ++curIndex;
            //如.123 -> 0.123
            //如233. -> 233.0
            //如233.666
            numeric = (scanUnsignedInt(str,curIndex)||numeric);
        }
        if(curIndex<len && (str[curIndex]=='e' || str[curIndex]=='E'))
        {
            ++curIndex;
            //e的前面后面都必须有数字
            numeric = (scanInt(str,curIndex) && numeric);
        }
        return (numeric && curIndex==len);
        
    }

};
