#include <iostream>
#include "Swap.h"

// 字符串的排列
// 输入abc
// 输出所有排列abc,acb,bac,bca,cab,cba

void Permutation(char* pStr,char* pBegin)
{
    
    if (*pBegin == '\0') 
    {
        printf("%s\n",pStr);
    }
    else
    {
        for(char *pChar = pBegin; *pChar != '\0'; pChar++)
        {
            std::swap(*pBegin,*pChar);
            Permutation(pStr,pBegin+1);
            std::swap(*pBegin,*pChar);
        }
    }
}

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

int __tmain( )
{
     char str[] = "abc";
	Permutation(str,str);
    getchar();
    return 0;
}