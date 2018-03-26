/*
时间限制：1秒 空间限制：32768K 热度指数：110754
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
/*

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree) return nullptr;
        TreeNode* prePtr = nullptr,*curPtr=pRootOfTree;
        makeList(curPtr,prePtr);
        TreeNode* pHead=pRootOfTree;
        while(pHead->left){
            pHead = pHead->left;
        }
        return pHead;

    }
    //中序遍历
    void makeList(TreeNode* curPtr,TreeNode*& prePtr)
    {
        if(curPtr->left){
            makeList(curPtr->left,prePtr);
        }
        //对于当前结点curPtr的left指向上一节点
        //而上一节点的right指向当前结点。
        //也就是说当前结点的right现在还没更新
        if(prePtr) prePtr->right = curPtr;
        curPtr->left = prePtr;
        prePtr = curPtr;
        if(curPtr->right){
            makeList(curPtr->right,prePtr);
        }
    }
};
