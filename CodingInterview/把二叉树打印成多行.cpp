/*
时间限制：1秒 空间限制：32768K 热度指数：61358
题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
*/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if(!pRoot) return res;
            queue<TreeNode*> que;
            que.push(pRoot);
            while(!que.empty()){
                vector<int> temp;
                int sz = que.size();
                for(int i=0;i<sz;++i){
                    TreeNode* ptr = que.front();
                    temp.push_back(ptr->val);
                    que.pop();
                    if(ptr->left) que.push(ptr->left);
                    if(ptr->right) que.push(ptr->right);
                }
                res.push_back(temp);

            }
            return res;
        }
    
};

