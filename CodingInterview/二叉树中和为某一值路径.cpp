/*
时间限制：1秒 空间限制：32768K 热度指数：160479
题目描述
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if(!root) return res;
        int tot = root->val;//当前路径值的总和
        vector<int> temp = {tot};//存放路径值
        scan(res,temp,root,expectNumber,tot);
        return res;
        
    }
    void scan(vector<vector<int>>& res,vector<int>& temp,TreeNode* ptr,
             const int& expectNumber,int tot)
    {
        //走到叶子节点，且当前路径和等于expectNumber 放入res中。
        if(!ptr->left && !ptr->right && expectNumber==tot){
            res.push_back(temp);
            return ;
        }
        if(ptr->left){
            //存入左孩子的值
            temp.push_back(ptr->left->val);
            scan(res,temp,ptr->left,expectNumber,tot + ptr->left->val);
            //回溯
            temp.pop_back();
        }
        if(ptr->right){
            //存入右孩子的值
            temp.push_back(ptr->right->val);
            scan(res,temp,ptr->right,expectNumber,tot + ptr->right->val);
            //回溯
            temp.pop_back();
        }  
    }
};
