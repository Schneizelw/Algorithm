/*
时间限制：1秒 空间限制：32768K 热度指数：67159
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        //1 存在右结点
        if(pNode->right){
            pNode = pNode->right;
            while(pNode->left){
                pNode = pNode->left;
            }
            return pNode;
        }
        //2 是父节点的右孩子
        while(pNode->next &&  pNode == pNode->next->right)
        {
            pNode =  pNode->next;
        }
        //3 是父节点的左孩子
        if(pNode->next && pNode == pNode->next->left){
            return pNode->next;
        }
        return nullptr;
    }
};
