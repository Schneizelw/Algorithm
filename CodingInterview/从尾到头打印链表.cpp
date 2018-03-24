/*

时间限制：1秒 空间限制：32768K 热度指数：452655
本题知识点： 链表
题目描述
输入一个链表，从尾到头打印链表每个节点的值。
*/
/*
正序存入vector，然后使用reverse(vec.begin(),vec.end())函数。
*/



/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(!head) return vector<int>{};
        ListNode* temp = head;
        vector<int> res;
        while(temp){
            res.push_back(temp->val);
            temp=temp->next;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
