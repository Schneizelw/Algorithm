/*
时间限制：1秒 空间限制：32768K
本题知识点： 查找
题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

/*
思路：根据规律，从左下角开始，当target比左下角元素大时 右移，target比左下角元素小时上移。
*/


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows=array.size();
        if(rows==0) return false;
        int cols=array[0].size();
        
        int r=rows-1,c=0;
        while(r>=0 && c<cols){
            if(array[r][c]==target){
                return true;
            }else if(array[r][c]>target){
                r--;
            }else{
                c++;
            }
        }
        return false;
    }

};
