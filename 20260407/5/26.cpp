#include <stdio.h>
#include <stdlib.h>
#define  N  8

struct  slist
{   
    double  s;
    struct slist *next;
};

typedef  struct slist  STREC;

double  fun( STREC *h )
{
    int max=h->s;
    slist *current=h;

    while (current->next!=nullptr)
    {
        current=current->next;
        if((current->s)>max)
        {
            max=current->s;
        }
    }
    
    return max;
}

STREC *creat( double *s)
{
    STREC *h,*p,*q; 
    int  i=0;
    h=p=(STREC*)malloc(sizeof(STREC));
    p->s=0;
    while(i<N)
    {
        q=(STREC*)malloc(sizeof(STREC));
        q->s=s[i];
        i++; 
        p->next=q; 
        p=q;
    }
    p->next=0;
    return  h;
}

void outlist(STREC *h)
{
    STREC  *p;
    p=h->next; 
    printf("head");

    do
    {
        printf("->%2.0f",p->s);
        p=p->next;

    }while(p!=0);
    printf("\n");
}

int main()
{   
    double  s[N]={85,76,69,85,91,72,64,87}, max;
    STREC  *h;
    h=creat(s);
    outlist(h);
    max=fun(h);
    printf("max=%.1f",max);
    return 0;
}