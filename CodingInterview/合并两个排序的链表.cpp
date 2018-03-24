/*
时间限制：1秒 空间限制：32768K 热度指数：212836
本题知识点： 链表
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/


/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1) return pHead2;
        if(!pHead2) return pHead1;
        ListNode* ptr1=pHead1,*ptr2=pHead2;
        ListNode* pHead3;
        //选择较小值为第一个结点
        if(ptr1->val>ptr2->val){
            pHead3 = ptr2;
            ptr2 = ptr2->next;
        }else{
            pHead3 = ptr1;
            ptr1 = ptr1->next;
        }
        //cur指向新链表的最后一个位置
        ListNode* cur = pHead3;
        //将小的结点值接到cur的后面，更新cur
        while(ptr1 && ptr2){
            if(ptr1->val>ptr2->val){
                cur->next = ptr2;
                ptr2 = ptr2->next;
            }else{
                cur->next = ptr1;
                ptr1 = ptr1->next;
            }
            cur = cur->next;
        }
        //将剩余的补上
        cur->next = ptr1?ptr1:ptr2;
        return pHead3; 
    }
};
