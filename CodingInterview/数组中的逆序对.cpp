/*
时间限制：1秒 空间限制：65536K 热度指数：143836
本题知识点： 数组
题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 
即输出P%1000000007
输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：

	对于%50的数据,size<=10^4

	对于%75的数据,size<=10^5

	对于%100的数据,size<=2*10^5

示例1
输入
1,2,3,4,5,6,7,0
输出
7
*/


class Solution {
public:
    int InversePairs(vector<int> data) {
        int sz = data.size();
        int P=0;
        sort(data,0,sz-1,P);
        return P;
    }
    void sort(vector<int>& data,int first,int last,int& P)
    {
        if(first<last){
            int mid = (first+last)/2;
            sort(data,first,mid,P);
            sort(data,mid+1,last,P);
            merge(data,first,last,P);
        }
    }
    void merge(vector<int>& data,int first,int last,int& P)
    {
        int mid = (first+last)/2;
        vector<int> vec1;
        vector<int> vec2;
        for(int i=first;i<=mid;++i){
            vec1.push_back(data[i]);
        }
        for(int j=mid+1;j<=last;++j){
            vec2.push_back(data[j]);
        }
        int sz1 = mid-first+1;
        int sz2 = last-mid;
        //int numbers = last-first+1;
        int i=0,j=0,k=first;
        while(i<sz1 && j<sz2){
            if(vec1[i]<vec2[j]){
                data[k++] = vec1[i++];
            }else{
                P = (P+sz1-i)%1000000007;
                data[k++] = vec2[j++];
            }
        }
        while(i<sz1){
            data[k++] = vec1[i++];
        }
        while(j<sz2){
            data[k++] = vec2[j++];
        }
    }
};
