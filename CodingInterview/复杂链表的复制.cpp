/*
时间限制：1秒 空间限制：32768K 热度指数：153989
本题知识点： 链表
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/


/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* newHead;
        if(!pHead) return newHead;
        //map保存旧链表和新链表的每一个结点对应关系
        map<RandomListNode*,RandomListNode*> mp;
        newHead = new RandomListNode(pHead->label);
        mp[pHead] = newHead;
        RandomListNode* ptr1=pHead,* ptr2=newHead;
        while(ptr1->next){
            ptr1=ptr1->next;
            ptr2->next = new RandomListNode(ptr1->label);
            mp[ptr1] = ptr2->next;
            ptr2 = ptr2->next;
        }
        ptr1=pHead,ptr2=newHead;
        while(ptr1){
            ptr2->random = mp[ptr1->random];
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return newHead;
    }
};
