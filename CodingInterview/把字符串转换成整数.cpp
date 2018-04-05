/*
时间限制：1秒 空间限制：32768K 热度指数：89421
本题知识点： 字符串

题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
+2147483647
    1a33
输出
2147483647
    0
*/




class Solution {
public:
    int StrToInt(string str) {
        int i = 0;
        bool flag=true;
        if(str[i]=='+'){
            flag=true;
            ++i;
        }else if(str[i]=='-' ){
            flag=false;
            ++i;
        }else if(str[i]-'0'>=0 && str[i]-'0'<=9){
           flag = true;
        }else{
            return 0;
        }
        int res=0;
        for(;i<str.length();++i){
            int temp = str[i]-'0';
            if(temp<0 || temp>9){
                return 0;
            }
            res*=10;
            res += temp;
        }
        return (flag? res:-res);
        
    }
};
