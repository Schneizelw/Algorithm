/*
时间限制：3秒 空间限制：32768K 热度指数：271192
本题知识点： 查找
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

/*
利用二分查找的来找出最小值。
有下列几种情况：
4 5 6 7 1 2 3   (first)1 < (mid)7 > (last)3 最小值在mid右边
7 6 (first)7  == (mid)7 > (last)6 最小值在mid右边

6 7 1 2 3 4 5   (first)6 > (mid)2 < (last)5 最小值在mid左边
5 6 7 1 2 3 4   (first)5 > (mid)1 < (last)4  且mid(1)<mid-1(7) 最小值mid指向的元素
*/


class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int sz = rotateArray.size();
        if(sz==0) return 0;
        if(sz==1) return rotateArray[0];
        int first = 0,last = sz-1;
        while(first<=last){
            int mid = (first+last)/2;
            if(rotateArray[first]<=rotateArray[mid] &&
              rotateArray[mid]<=rotateArray[last]){
                return rotateArray[first];
            }else if(rotateArray[first]<=rotateArray[mid] &&
              rotateArray[mid]>rotateArray[last]){
                first = mid+1;
            }else{
                if(mid-1>=0 && rotateArray[mid]<rotateArray[mid-1])
                    return rotateArray[mid];
                last = mid-1;
            }
        }
        return 0; 
    }
};
