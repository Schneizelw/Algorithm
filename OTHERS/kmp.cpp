#include<iostream>
#include<vector>
#include<cstring>

using namespace std;


void cal_next(char* str,int *next,int len)
{
    next[0] = -1;
    int k = -1;
    for(int q = 1;q <= len-1;q++)
    {
        while(k>-1 && str[k+1]!=str[q])
        {
            k = next[k];//回溯
        }
        if(str[k+1] == str[q])
        {
            k = k+1;
        }
        next[q] = k;
    }
}

int KMP(char* str,int slen,char *ptr,int plen)
{
    int *next = new int(plen);
    cal_next(ptr,next,plen);
    int k = -1;
    for(int i=0;i<slen;++i)
    {
        while(k>-1 && ptr[k+1]!=str[i]){
            k = next[k];
        }
        if(ptr[k+1] == str[i])
            k = k+1;
        if(k==plen-1)
        {
            return i-plen+1;
        }
    }
    return -1;
}

int main()
{
    char *str = "bacbababadababacambabacaddababacasdsd";
    char *ptr = "ababaca";
    //cout << sizeof(str) <<endl;
    //cout << strlen(str) <<endl;
    int a = KMP(str, 36, ptr, 7);
    cout << a;
    return 0;
}
