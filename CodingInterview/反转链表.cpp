/*
时间限制：1秒 空间限制：32768K 热度指数：225387
本题知识点： 链表
题目描述
输入一个链表，反转链表后，输出链表的所有元素。
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
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead) 
            return nullptr;
        ListNode* ptr = new ListNode(pHead->val);
        ListNode* temp = pHead;
        temp = temp->next;
        while(temp){
            ListNode* node = new ListNode(temp->val);
            node->next = ptr;
            ptr=node;
            temp = temp->next;
            
        }
        return ptr;
    }
};
