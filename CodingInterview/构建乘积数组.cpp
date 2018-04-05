/*
时间限制：1秒 空间限制：32768K 热度指数：51362
本题知识点： 数组
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/


class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B;
        int sz = A.size();
        if(sz<=1) return B;
      
        vector<int> temp1;
        vector<int> temp2;
        temp1.push_back(1);
        temp2.push_back(1);
        int val1 = 1,val2 = 1;
        for(int i=0,j=sz-1;i<sz-1;++i,--j){
            val1 *= A[i];
            temp1.push_back(val1);
            val2 *= A[j];
            temp2.push_back(val2);
        }

        for(int i=0,j=sz-1;i<sz;++i,--j){
            B.push_back(temp1[i]*temp2[j]);
        }
        return B;      
    }
};
