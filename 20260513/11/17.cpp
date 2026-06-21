#include<stdio.h>
#include<string.h>
#define MAXSIZE 1000

int BF(char a[],char b[])
{//简单模式匹配算法,匹配成功返回1，否则返回0

    int L1=strlen(a),L2=strlen(b),re=0;    //病毒DNA序列长度L1,人的DNA序列长度L2

    /**************begin************/
    for(int i=0;i<=L2-L1;i++)//human
    {
        int j;
        for(j=0;j<L1;j++)//virus
        {
            if(a[j]!=b[i+j])
            {
                break;
            }
        }

        if(j==L1){return 1;}
    }

    return 0;
    /**************end************/
}

void Revolve(char a[])
{//字符串旋转,把病毒第一个字符变为最后一个字符

    int L1=strlen(a);
    char temp=a[0];    //首位元素暂存

    for(int i=0;i<L1-1;i++)   //后面逐个覆盖前一位
    {
      /**************begin************/
        a[i]=a[i+1];
      /**************end************/
    }

    a[L1-1]=temp;   //首位元素放在最后

}

int Judge(char a[],char b[])
{//判别病毒DNA环状序列是否在患者DNA序列中出现过，出现过返回1，否则返回0

    int L1=strlen(a);

    while(L1--)

    {

        int re=BF(a,b);

        if(re==1) return 1;

        Revolve(a);

    }

    return 0;

 }

int main()

{

    char a[MAXSIZE],b[MAXSIZE];//a存入病毒的DNA序列，b存入人的DNA序列

    scanf("%s",a);

    scanf("%s",b);

    int result=Judge(a,b);

    if(result)

         printf("YES");

    else

         printf("NO");

    return 0;

}