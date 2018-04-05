/*
时间限制：1秒 空间限制：32768K 热度指数：77188
本题知识点： 链表

题目描述
一个链表中包含环，请找出该链表的环的入口结点。
*/

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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        unordered_set<ListNode*> setPtr;
        ListNode* curPtr = pHead;
        while(curPtr)
        {
            if(setPtr.find(curPtr)==setPtr.end())
            {
                setPtr.insert(curPtr);
                curPtr = curPtr->next;
            }else{
                return curPtr;
            }
        }
        return nullptr;
        
    }
};



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
    ListNode* meetNode(ListNode* pHead)
    {
        if(!pHead) return nullptr;
        ListNode* pSlow = pHead->next;
        if(!pSlow) return nullptr;
        ListNode* pFast = pSlow->next;
        
        while(pFast)
        {
            if(pFast==pSlow)
                return pFast;
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast){
                pFast = pFast->next;
            }
        }
        return nullptr;
    }
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* pNode =  meetNode(pHead);
        if(!pNode) return nullptr;
        ListNode* curPtr =  pNode;
        int cnt = 1;
        while(curPtr->next!=pNode)
        {
            curPtr = curPtr->next;
            cnt++;
        }
        ListNode* p1=pHead,*p2=pHead;
        while(cnt--)
        {
            p2 = p2->next;
        }
        while(p1!=p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
        
    }
};
