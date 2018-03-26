/*
时间限制：1秒 空间限制：32768K 热度指数：192226
本题知识点： 数组
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/


//排序 O(nlog(n))
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size()==0||input.size()<k||k<0) return vector<int>{};
        sort(input.begin(),input.end());
        return vector<int>(input.begin(),input.begin()+k);
    }
};

//红黑树：O(nlong(k))。必须用greater<int>，用最less<int>要在红黑树中插入n个元素 算法复杂度变为O((nlog(n))
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size()==0||input.size()<k) return vector<int>{};
        multiset<int,greater<int>> muls;
        auto maxIter = muls.begin();
        for(auto curIter=input.begin();curIter!=input.end();++curIter)
        {
            if(muls.size()<k){
                muls.insert(*curIter);
                continue;
            }
            maxIter = muls.begin(); 
            if( *curIter < *maxIter ){
                muls.erase(maxIter);
                muls.insert(*curIter);
            }
        }
        return vector<int>(muls.begin(),muls.end());
    }
};

//partition思想实现 O(n)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int sz = input.size();
        if(sz<=0||k>sz||k<=0) return vector<int>();
        int first=0,last=sz-1;
        int reIndex=partition(input,first,last);
        while(reIndex+1!=k){
            if(reIndex+1<k){
                first = reIndex+1;
                reIndex=partition(input,first,last);
            }else{
                last = reIndex-1;
                reIndex=partition(input,first,last);
            }
        }
        
        return vector<int>(input.begin(),input.begin()+k);
        
    }
    
    int partition(vector<int>& input,int first,int last)
    {
        int firstBig;
        //是要等于
        if(first<=last){
            int key = input[first];
            firstBig = first+1;
            for(int i=first+1;i<=last;++i){
                if(input[i]<key){
                    swap(input[i],input[firstBig++]);
                }
            }
        }
        swap(input[--firstBig],input[first]);
        return firstBig;
    }
};
