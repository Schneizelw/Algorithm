/*
时间限制：1秒 空间限制：32768K 热度指数：151842
本题知识点： 数组
 算法知识视频讲解
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，
超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

/*
思路：一个数字抵消一个数字。
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int sz = numbers.size();
        if(sz==0) return 0 ;
        int cnt = 1;
        int result = numbers[0];
        for(int i=1;i<sz;++i){
            if(cnt==0) result = numbers[i];
            if(numbers[i]==result) cnt++;
            else cnt--;
        }
        cnt=0;
        for(int i=0;i<sz;++i){
            if(result==numbers[i]) 
                cnt++;
        }
        return (cnt>(sz/2))? result:0;
    }
};
