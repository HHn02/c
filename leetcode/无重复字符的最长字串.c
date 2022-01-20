#include"stdio.h"
#include"stdlib.h"
int main()
{
    char s[10]="awwawck";
    lengthOfLongestSubstring(s);
}

int lengthOfLongestSubstring(char * s)
{
    int i;  
    int index[128];
    for(i=0;i<128;i++){
        index[i]=-1;
    }
    int left =-1;                        //left 是窗口左边界的前一个位置
    int len =strlen(s);
    if (len ==1) return 1;
    int count =0; 
    for(i=0;i<len;i++){
        if(index[s[i]]>left){            //若 index[s[i]] > left 成立，说明之前出现过的字符在窗口内
            left = index[s[i]];
        }
        if(count<i-left) count= i-left;
        index[s[i]]=i;
    }
    return count;
}

