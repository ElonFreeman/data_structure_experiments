#include<stdio.h> 

int max(int a,int b,int c)
{   
    if(a > b)
    {    
        if(a > c) 
            return a;
        else 
            return c;
    }
    else  // 添加 b >= a 的情况
    {   
        if(b > c) 
            return b;
        else 
            return c;
    }
} 

int main()
{ 
    int a,b,c,m;
    scanf("%d%d%d",&a,&b,&c);
    m = max(a,b,c); 
    printf("%d",m);
    return 0;
}