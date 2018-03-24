/*
时间限制：1秒 空间限制：32768K 热度指数：199418
本题知识点： 队列 栈
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
/*
使用两个栈stack1，和stack2。
当push的时候直接放入stack1.
当pop的时候，如果stack2中位空则，
    stack1的最底部元素就是队列的第一个元素，所以将stack1中的元素全部放到stack2中。
    也就是stack1中的top元素到了stack2中就是down元素。然后返回stack2中的top元素就可以了，然后再pop掉。
否则
    直接返回stack2的top元素再pop掉。
*/

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty() && stack1.empty())
            return -1;
        
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = stack2.top();
        stack2.pop();
        return res;
        
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
