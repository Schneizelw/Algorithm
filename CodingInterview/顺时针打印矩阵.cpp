/*
时间限制：1秒 空间限制：32768K 热度指数：216254
本题知识点： 数组
 算法知识视频讲解
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/


class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int left=0,top=0;
        int down=matrix.size()-1;
        if(down==-1) return vector<int>{};
        if(down==0) return matrix[0];
        int right=matrix[0].size()-1;
        vector<int> res;
        while(1){
            for(int i=left;i<=right;++i) res.push_back(matrix[top][i]);
            top++;
            if(top>down) return res;
            
            for(int i=top;i<=down;++i) res.push_back(matrix[i][right]);
            right--;
            if(left>right) return res;
            
            for(int i=right;i>=left;--i) res.push_back(matrix[down][i]);
            down--;
            if(top>down) return res;
            
            for(int i=down;i>=top;--i) res.push_back(matrix[i][left]);
            left++;
            if(left>right) return res;
        }
    }
};
