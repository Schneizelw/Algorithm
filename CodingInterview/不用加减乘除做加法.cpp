/*
时间限制：1秒 空间限制：32768K 热度指数：50919
题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/


class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2){
            int sum = num1^num2;//求和不算进位
            int carry = (num1&num2) << 1;//得出进位
            num1 = sum;
            num2 = carry;
        }
        return num1;
    }
};
