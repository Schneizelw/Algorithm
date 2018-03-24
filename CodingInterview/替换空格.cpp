/*
时间限制：1秒 空间限制：32768K 热度指数：516143
本题知识点： 字符串
题目描述
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
/*
思路
传入的length表示的是str字符串的长度，但是str指向的空间大于length，但是题目没给出这个意思。。。

有上述条件后就是向前统计空格，确定新的长度，然后向后替换字符了。
*/


class Solution {
public:
	void replaceSpace(char *str,int length) {
        int new_size = length-1;
        for(int i=0;i<length;++i){
            if(str[i]==' '){
                new_size+=2;
            }
        }
        if(new_size==length-1) return;
        for(int i=length-1,j=new_size;i>=0;--i){
            if(str[i] != ' '){
                str[j--]=str[i];
            }else{
                str[j--]='0';
                str[j--]='2';
                str[j--]='%';
            }
        }
        str[new_size] = '/0';
	}
};
