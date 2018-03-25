/*
时间限制：1秒 空间限制：32768K 热度指数：128684
本题知识点： 栈
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/

class Solution {
public:
    stack<int> minElem;
    stack<int> sk;
public:
    void push(int value) {
        if(!sk.empty()){
            sk.push(value);
            minElem.push(std::min(value,minElem.top()));
        }else{
            sk.push(value);
            minElem.push(value);
        }
       
    }
    void pop() {
        sk.pop();
        minElem.pop();
    }
    int top() {
        return sk.top();
    }
    int min() { 
         return minElem.top();
    }
};
