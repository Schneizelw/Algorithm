/*
时间限制：1秒 空间限制：32768K 热度指数：316383
本题知识点： 链表
题目描述
输入一个链表，输出该链表中倒数第k个结点。
*/

/*
链表的长度为len，则倒数k个结点即为正数的第len-k+1个结点。
求len-k+1有一个前提就是 k不能大于len否则代码错误。
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {  
        ListNode* ptr = pListHead;
        int len=0;
        while(ptr){
            len++;
            ptr=ptr->next;
        }
        ptr = pListHead;
        if(k>len) 
            return nullptr;
        len = len-k+1;
        while(--len){
            ptr=ptr->next;
        }
        return ptr;
    }
};

//解法2
/*
使用两个指针ptr1和ptr2初始化为指向head，让ptr2先走k-1步，也就是指向了正数第k个元素。
然后同时移动两个指针，当ptr2指向最后一个元素的时候，ptr1指向的即为倒数第k个元素。
*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {  
        if(!pListHead || k==0 ) 
            return nullptr;
        ListNode* ptr1 = pListHead;
        ListNode* ptr2 = pListHead;
        for(unsigned int i=1;i<k;++i)
        {
            ptr2 = ptr2->next;
            if(ptr2==nullptr) 
                return nullptr; 
        }
        
        while(ptr2->next){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr1; 
    }
};
