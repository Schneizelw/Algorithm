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
