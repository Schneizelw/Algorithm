/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode* p1=pHead,*p2=pHead;
      
        if(!p1) return nullptr;
        
        while(p1)
        {
            if(p1->next && p1->next->val==p1->val){
                ListNode* tempHead = p1;
                
                
                p1 = p1->next;
                while(p1->next && p1->next->val==p1->val){
                    p1 = p1->next;
                }
                p1 = p1->next;
                
                if(tempHead==pHead)
                {
                    pHead = p1;
                    p2 = pHead;
                }else{
                    p2->next = p1;
                }
                
                //删除重复元素
                while(tempHead!=p1){
                    ListNode* temp = tempHead;
                    tempHead = tempHead->next;
                    delete(temp);
                }
                
            }else{
                p2 = p1;
                p1 = p1->next;
            }
        }
        return pHead;
    }
};
