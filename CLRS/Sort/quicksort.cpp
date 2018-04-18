//!QUICKSORT(A,p,r)
/*
1   if p<r
2       q = PARTITION(A,p,r)
3       QUICKSORT(A,p,q-1)
4       QUICKSORT(A,q+1,r)
*/
//!partition(A,p,r)
/*
1   x = A[r]
2   i = p-1
3   for j = p to r-1
4       if A[j]<=x
5           i = i + 1
6           exchange A[i] with A[j]
7   exchange A[i+1] with A[r]
8   return i+1
*/
//!RANDOMIZED-PARTITION(A,p,r)
/*
1   i  = RANDOM(p,r)
2   exchange A[r] with A[i]
3   return PARTITION(A,p,r)
*/
//!RANDOMIZED-QUICKSORT(A,p,r)
/*
1   if p<r
2       q = RANDOMIZED-PARTITION(A,p,r)
3       RANDOMIZED-QUICKSORT(p,q-1)
4       RANDOMIZED-QUICKSORT(q+1,r)
*/
#include<vector>
#include<iostream>
#include<random>
#include<ctime>
using namespace std;

template<typename T>
int PARTITION(vector<T>& A,int p,int r)
{
    T x = A[r];
    int i = p-1;
    for(int j=p;j<r;++j){
        if(A[j]<=x){
            i += 1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}

template<typename T>
int RANDOMIZED_PARTITION(vector<T> &A,int p,int r)
{
    default_random_engine e(time(0));
    uniform_int_distribution<unsigned> u(p,r);
    int i = u(e);
    swap(A[i],A[r]);
    return PARTITION(A,p,r);
}

template<typename T>
void RANDOMIZED_QUICKSORT(vector<T> &A,int p,int r)
{
    if(p<r){
        int q = RANDOMIZED_PARTITION(A,p,r);
        RANDOMIZED_QUICKSORT(A,p,q-1);
        RANDOMIZED_QUICKSORT(A,q+1,r);
    }
}


template<typename T>
void QUICKSORT(vector<T> &A,int p,int r)
{
    if(p<r){
        int q = PARTITION(A,p,r);
        QUICKSORT(A,p,q-1);
        QUICKSORT(A,q+1,r);
    }
}

int main()
{
    vector<int> A = {48,6,1,5,3,1,86,13};
    //QUICKSORT(A,0,A.size()-1);
    RANDOMIZED_QUICKSORT(A,0,A.size()-1);
    for(int i=0;i<A.size();++i)
        cout << A[i] << ",";
}
