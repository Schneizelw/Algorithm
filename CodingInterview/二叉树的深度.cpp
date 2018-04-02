/*
时间限制：1秒 空间限制：32768K 热度指数：72323
题目描述
输入一棵二叉树，求该树的深度。
从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

*/


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
    int TreeDepth(TreeNode* pRoot)
    {
        int depth = 0,max_depth=0;
        recur(pRoot,depth,max_depth);
        return max_depth;
    }
    void recur(TreeNode* node,int depth,int& max_depth)
    {
        if(!node) return;
        ++depth;
        if(depth>max_depth)
            max_depth = depth;
        recur(node->left,depth,max_depth);
        recur(node->right,depth,max_depth);
    }
};
