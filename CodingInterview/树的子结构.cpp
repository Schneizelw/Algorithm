/*
时间限制：1秒 空间限制：32768K 热度指数：209520
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        //其中之一为空 则肯定为假
        if(!pRoot2 || !pRoot1) return false;
        //先检测根如果不行递归检测左右孩子
        return (judge(pRoot1,pRoot2)||
                HasSubtree(pRoot1->left,pRoot2)||
                HasSubtree(pRoot1->right,pRoot2) );   
    }
    //判断treeA是否包含treeB子结构
    bool judge(TreeNode* treeA, TreeNode* treeB)
    {
        //treeB为空则为真，此时tree不影响为真这个结果
        if(!treeB) return true;
        else if(!treeA) return false; //treeB不为空 treeA为空返回假
        else{
            //如果两个值相等检测 检测左子树和右子树
            if(treeA->val==treeB->val){
                return (judge(treeA->left,treeB->left)
                      && judge(treeA->right,treeB->right));
            }else{
                return false;
            }
        }
       
    }
};
