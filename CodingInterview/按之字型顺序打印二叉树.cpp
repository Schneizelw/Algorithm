/*
时间限制：1秒 空间限制：32768K 热度指数：72298
题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

*/


//递归
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
    void recur( vector<vector<int>>& res,int& maxDepth,int curDepth,TreeNode* pNode)
    {
        if(pNode->left){
            if(curDepth+1>maxDepth){
                maxDepth++;
                res.push_back(vector<int>());
            }
            recur(res,maxDepth,curDepth+1,pNode->left);
        }
        
        if(curDepth%2==1)
            res[curDepth].insert(res[curDepth].begin(),pNode->val);
        else 
            res[curDepth].push_back(pNode->val);
        
        if(pNode->right){
            if(curDepth+1>maxDepth){
                maxDepth++;
                res.push_back(vector<int>());
            }
            recur(res,maxDepth,curDepth+1,pNode->right);
        }
        
    }
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        int maxDepth = 0;
        if(!pRoot) return res;
        res.push_back(vector<int>());   
        recur(res,maxDepth,0,pRoot);
        return res;
    }
    
};

//队列
class Solution {
public:
    
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(!pRoot) return res;
        queue<TreeNode*> que;
        que.push(pRoot);
        bool even = false;
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
            if(even){
                reverse(temp.begin(),temp.end());
            }
            even = !even;
            res.push_back(temp);
            
        }
        return res;
    }
    
};
