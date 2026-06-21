#include <bits/stdc++.h>
using namespace std;
#define N 8

typedef struct alist
{
    int data;
    struct alist *next;
} SLIST;

void fun(SLIST *h, int x)
{
    SLIST *p, *q, *s;
    s = (SLIST *)malloc(sizeof(SLIST));
    /********** Begin **********/
    s->data = x;
    /********** End **********/
    q = h;
    p = h->next;

    while (p != NULL && x > p->data)
    {
        /********** Begin **********/
        q = q->next;
        /********** End **********/
        p = p->next;
    }

    s->next = p;
    /********** Begin **********/

    q->next = s;

    /********** End **********/
}

SLIST *creatlist(int *a)
{
    SLIST *h, *p, *q;
    int i;
    h = p = (SLIST *)malloc(sizeof(SLIST));
    for (i = 0; i < N; i++)
    {
        q = (SLIST *)malloc(sizeof(SLIST));
        q->data = a[i];
        p->next = q;
        p = q;
    }
    p->next = 0;
    return h;
}

void outlist(SLIST *h)
{
    SLIST *p;
    p = h->next;
    if (p == NULL)
        printf("\nThe  list  is  NULL!\n");
    else
    {
        printf("Head");
        do
        {
            printf(" %d", p->data);
            p = p->next;

        } while (p != NULL);
        printf(" End");
    }
}

int main()
{
    SLIST *head;

    int x;
    int a[N] = {11, 12, 15, 18, 19, 22, 25, 29};
    head = creatlist(a);
    scanf("%d", &x);
    fun(head, x);
    outlist(head);
    return 0;
}