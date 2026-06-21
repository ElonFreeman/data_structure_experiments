#include<stdlib.h>

#include<malloc.h>

#include<stdio.h>



typedef struct Polynode  /*定义多项式结点类型*/

{ 

    int coef; 

    int exp;

    struct Polynode *next;

} Polynode, *Polylist;



Polylist polycreate()

{/*建立多项式*/

    Polynode *head, *rear, *s; int c,e;

    head=(Polynode *)malloc(sizeof(Polynode));  /*建立多项式的头结点*/

    rear = head;

    scanf("%d%d",&c,&e);/*键入多项式的系数和指数项*/

    while(c!=0) /*若 c=0，则代表多项式的输入结束*/

    {   s=(Polynode*)malloc(sizeof(Polynode));  /* 申请新结点*/

        s->coef=c ; s->exp=e ;

        rear->next=s ;  /*在当前表尾做插入*/

        rear=s;

        scanf("%d%d",&c,&e);

    }

    rear->next=NULL;    /*将表的最后一个结点的 next 置 NULL，以示表结束*/

    return head;

}



void polyadd(Polylist polya, Polylist polyb)

/*将两个多项式相加，然后将和多项式存放在多项式 polya 中，并将多项式ployb 删除*/

{

    Polynode * p, *q, *tail,*temp; int sum;

    p=polya->next ; /*令 p 和 q 分别指向 polya 和 polyb 多项式链表中的第一个结点*/

    q=polyb->next ;

    tail=polya; /* tail 指向和多项式的尾结点*/

    while(p!=NULL && q!=NULL) /*当两个多项式均未扫描结束时*/

    {

        if(p->exp< q->exp)

        {  

            /*规则⑴：如果 p 指向的多项式项的指数小于 q 的指数，将 p 结点加入到和多项式中*/

            /***********Begin1***********/
             
            tail->next=p;   tail =p;   p =p->next;       /*将 p 结点加入到“和多项式中”*/ 


            /************End1************/

               



        }  

        else if ( p->exp==q->exp) /*规则⑵：若指数相等，则相应的系数相加*/

            {  

                sum=p->coef + q->coef;

                if (sum!=0) /*若系数和非零，则系数和置入结点 p，释放结点 q，并将指针后移*/

                {  

                    /***********Begin2***********/
                    p->coef=sum;
                    tail->next=p;
                    tail=p;
                    p=p->next;
                    Polylist tmp=q;
                    q=q->next;
                    free(tmp);



                    /************End2************/

                }

                else

                {  

                    /*若系数和为零，则删除结点 p 与 q，并将指针指向下一个结点*/

                    /***********Begin3***********/
                    Polylist tmp1=p,tmp2=q;
                    p=p->next,q=q->next;
                    free(tmp1),free(tmp2);



                    /************End3************/              

                   

                   

                }              

             }

        else

        { tail ->next=q;  tail =q;  /*规则⑶：将 q 结点加入到“和多项式中”*/ q =q->next;    }

    }

    if(p!=NULL) /*多项式 A 中还有剩余，则将剩余的结点加入到和多项式*/

        tail ->next=p;

    else    /*否则，将 B 中的结点加入到和多项式中*/

        tail ->next=q;

}



void polyprint(Polylist head)

{/*输出多项式*/

    Polynode *p;

    p = head->next;

    while(p!=NULL)

    {   printf("%d,%d\n",p->coef,p->exp);

        p=p->next;

    }

}

int main()

{   Polylist pa,pb;

    pa=polycreate();

    pb=polycreate();

    polyadd(pa,pb);

    polyprint(pa);

    return 0;

}