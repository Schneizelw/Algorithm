//!MAX-HEAPIFY(A,i)
/* 保持最大堆的性质不变 使i的位置的元素放到适合的位置
1   l = LEFT(i)
2   r = RIGHT(i)
3   if l <= A.heap_size and A[l]>A[i]
4       largest = l
5   else largest = i
6   if r <= A.heap_size and A[r] > A[largest]
7       largest = r
8   if largest != i
9       exchange A[i] with A[largest]
10      MAX-HEAPIFY(A,largest)
*/
//!MIN-HEAPIFY(A,i)
/* 保持最小堆的性质不变 使i的位置的元素放到适合的位置
1   l = LEFT(i)
2   r = RIGHT(i)
3   if l <= A.heap_size and A[l]<A[i]
4       largest = l
5   else largest = i
6   if r <= A.heap_size and A[r]<A[largest]
7       largest = r
8   if largest != i
9       exchange A[i] with A[largest]
10      MIN-HEAPIFY(A,largest)
*/
//!MAX-HEAPIFY(A,i) //while
/* 循环版本(最大堆)
0   while(i!=largest)
1       l = LEFT(i)
2       r = RIGHT(i)
3       if l <= A.heap_size and A[l]<A[i]
4           largest = l
5       else largest = i
6       if r <= A.heap_size and A[r]<A[largest]
7           largest = r
8       if largest != i
9           exchange A[i] with A[largest]
10          i = largest
11      else break
*/
//!BUILD-MAX-HEAP(A)
/* 建立一个最大堆
1   A.heap_size = A.length
2   for i = floor(A.length/2) down to 1
3       MAX-HEAPIFY(A,i)
*/
//!HEAPSORT(A)
/* 堆排序
1   for i=A.length down to 2
2       exchange A[1] with A[i]
3       A.heap_size = A.heap_size - 1
4       MAX-HEAPIFY(A,1)
*/
//!HEAP-MAXIMUM(S)
/* 返回S中的最大键字
1   return S[1]
*/
//!HEAP-EXTRACT-MAX(S)
/* 去掉并返回S中的最大键字
1   if S.heap_size < 1
2       error "heap underflow"
3   max = S[1]
4   S[1] = S[S.heap_size]
5   A.heap_size = A.heap_size - 1
6   MAX-HEAPIFY(A,1)
7   return max
*/
//!HEAP-INCRESE-KEY(S,i,key)
/* 将元素i的关键字值增加到k 这里假设k的值不小于S[i]
1   if key<S[i]
2       error "new key is smaller than current key"
3   S[i] = key
4   while i > 1 and S[i] > S[PARENT(i)]
5       exchange A[i] with A[PARENT(i)]
6       i = PARENT(i)
*/
//!MAX-HEAP-INSERT(A,key)
/* 将元素key插入到集合S中
1   A.heap_size = A.heap_size + 1
2   A[A.heap_size] = -∞
3   HEAP-INCRESE-KEY(S,S.heap_size,key)
*/
//!MAX-HEAP-DELET(A,i)
/*
1   if A[A.heap_size] > A[i]
2       HEAP-INCRESE-KEY(A,i,A[A.heap_size])
3       A.heap_size = A.heap_size - 1
4   else
5      A[i] = A[A.heap_size]
6      A.heap_size = A.heap_size -1
7      MAX-HEAPIFY(A,i)
*/
//!HEAP-MINIMUN(S)
/*
1   return S[1]
*/
//!HEAP-EXTRACT-MIN(S)
/*
1   if S.heap_size < 1
2       error "underflow"
3   min = S[1]
4   S[1] = S[S.heap_size]
5   S.heap_size = S.heap_size - 1
6   MIN-HEAPIFY(S,1)
7   return min
*/
//!HEAP-DECREASE-KEY(S,i,key)
/*
1   if(key > S[i])
2       error "new key is bigger than current key"
3   S[i] = key
4   while( i>1 && S[i]<S[PARENT(i)] )
5       exchange S[i] with S[PARENT(i)]
6       i = PARENT(i)
*/
//!MIN-HEAP-INSERT(S,key)
/*
1   S.heap_size = S.heap_size + 1
2   S[S.heap_size] = +∞
3   HEAP-DECREASE-KEY(S,S.heap_size,key)
*/
#include<vector>
#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;

//template<typename T> void swap(T elem1,T elem2);
template<typename T>
class Heap{
public:
    //friend void swap<T>(T elem1,T elem2);
    Heap(int i=0):heap_size(i){}
    Heap(vector<T> V):A(V),heap_size(V.size()){}
                    //!    ^^^^^^^^^^^^^^^^^^ must initialize the raw type
    void push_back(T elem){  //!add elem into vector
        A.push_back(elem);
        ++heap_size;
    }
    void print(){  //!print vector's element
        for(auto biter=A.begin()+1,eiter=A.end(); biter!=eiter ;++biter)
            cout << *biter << ",";
    }
    int size(){return heap_size;}           //!return heap_size
    void decrese(){--heap_size;}            //!decrese the heap_size
    void set(int length){heap_size=length;} //!reset the heap_size
    //const T operator[](int index) const;
    T &operator[](int index){return A[index];}

private:
    vector<T> A;
    int heap_size;
};


template<typename T>
void MAX_HEAPIFY(Heap<T> &A,int rootIndex)
{
    int leftChildIndex = rootIndex*2;
    int rightChildIndex = rootIndex*2+1;
    //!                 ^^^^^^^^^^^^^^^^ it means you can't deal with 0th element
    int largestIndex = rootIndex;
    if(leftChildIndex <= A.size()&&A[leftChildIndex] > A[rootIndex])
        largestIndex = leftChildIndex;
    if(rightChildIndex <= A.size()&&A[rightChildIndex] > A[largestIndex])
        largestIndex = rightChildIndex;
    if(largestIndex!=rootIndex){
        swap(A[rootIndex],A[largestIndex]);
        MAX_HEAPIFY(A,largestIndex);
    }
}

template<typename T>
void BUILD_MAX_HEAP(Heap<T> &A)
{
    for(int i=A.size()/2 ; i>=1 ; --i){
        MAX_HEAPIFY(A,i);
    }
}

template<typename T>
void HEAPSORT(Heap<T> &A)
{
    BUILD_MAX_HEAP(A);
    int tempSize = A.size();
    for(int i=A.size();i>=2;--i){
        swap(A[1],A[i]);
        A.decrese();
        MAX_HEAPIFY(A,1);
    }
    A.set(tempSize);
}
template<typename T>
T HEAP_EXTRACT_MAX(Heap<T> &A)
{
    if(A.size()<1)
        cerr << "heap underflow\n";
    T &retmax = A[1];
    T ret = retmax;
    A[1] = A[A.size()];
    A.decrese();
    MAX_HEAPIFY(A,1);
    return ret;
}
int main()
{
    vector<int> S = {0,84,6,5,3,4,699,81,4564,13,45,65,8};
    Heap<int> A(S);
    HEAPSORT(A);
    A.print();
    int ret = HEAP_EXTRACT_MAX(A);
    cout << ret << endl;
}
/*
函数如果返回的是引用的话 在内部不能够创建一个临时引用变量返回
 warning：reference to local variable "xxx" return
*/


