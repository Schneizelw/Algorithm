
/*
时间限制：1秒 空间限制：32768K 热度指数：162462
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if(!root) return vector<int>{};
        queue<TreeNode*> que;
        vector<int> res;
        que.push(root);
        while(!que.empty()){
            TreeNode* ptr = que.front();
            if(ptr->left) que.push(ptr->left);
            if(ptr->right) que.push(ptr->right);
            res.push_back(ptr->val);
            que.pop();
        }
        return res;
    }
};
