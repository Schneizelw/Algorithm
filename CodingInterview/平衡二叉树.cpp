/*
时间限制：1秒 空间限制：32768K 热度指数：87833
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/
//这里并没有判断是否是搜索树
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        bool result = true;
        getDepth(pRoot,result);
        return result;
    }
    
    int getDepth(TreeNode* node,bool& result)
    {
        if(!node) return 0;
        int left = getDepth(node->left,result);
        //if(left==-1) return -1;
        int right = getDepth(node->right,result);
        //if(right==-1) return -1;
        if(abs(left-right)>1){ 
            result=false;
            return -1;
        }
        return right>left ? right+1:left+1;
    }
};
