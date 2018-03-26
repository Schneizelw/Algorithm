/*
时间限制：1秒 空间限制：32768K 热度指数：177299
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int sz = sequence.size();
        if(sz==0) return false;  //默认长度为0不是二叉搜索树
        if(sz<=2) return true;   //1 2两个结点为二叉搜索树
        return judge(0,sz-1,sequence);
    }
    //判断sequence数组中的区间[first，last]是否为二叉搜索树
    bool judge(int first,int last,vector<int>& sequence){
        if(last-first+1<=2) return true;
        int key = sequence[last];//根节点
        //后往前遍历找出第一个比key小的元素，那么这个元素的后边为key的右孩子
        //这个元素的前面的每一个值都应该小于key，这些值为左孩子结点
        for(int i=last-1;i>=first;--i){
            if(sequence[i]<key){
                //此时i的前面的值都应该需要小于key
                for(int j=i-1;j>=0;--j){
                    if(sequence[j]>key) return false;
                }
                //递归判断
                return (judge(first,i,sequence) && judge(i+1,last-1,sequence));
            }
        }
        //特殊情况，该树没有左孩子
        return judge(first,last-1,sequence);
    }
};
