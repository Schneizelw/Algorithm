/*
时间限制：1秒 空间限制：32768K 热度指数：298558
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/
/*
在前序遍历中的每一个元素，在中序遍历中，在该元素的左边为该元素的左孩子，在该元素的右边为该元素的右孩子。
如果上述例子，1在中序遍历中4,7,2都是1的左孩子5,3,8,6都是1的右孩子。利用该特点递归实现。
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int nodeNumber = pre.size();
        if(nodeNumber==0) return nullptr;
        TreeNode* root = new TreeNode(pre[0]);
        if(nodeNumber==1) return root;
        int keyIndex=0;
        int rootIndex = find(vin.begin(),vin.end(),pre[keyIndex])-vin.begin();
        return buildTree(pre,vin,0,rootIndex,nodeNumber-1,++keyIndex,root);
    }
    
    TreeNode* buildTree(vector<int>& pre,vector<int>& vin,
                        int first,int mid,int last,int& keyIndex,TreeNode* node)
    {                                               //^^^^^^^^^^^ 一定得是引用
         //构造左孩子
        int key = pre[keyIndex];
        for(int i=first;i<mid;++i){
            if(vin[i]==key){
                node->left = new TreeNode(key);
                buildTree(pre,vin,first,i,mid-1,++keyIndex,node->left);
                break;
            }
        }
        //构造右孩子
        key = pre[keyIndex];//更新key
        for(int j=mid+1;j<=last;++j){
            if(vin[j]==key){
                node->right = new TreeNode(key);
                buildTree(pre,vin,mid+1,j,last,++keyIndex,node->right);
                break;
            }
        }
        return node; 
    }
};
