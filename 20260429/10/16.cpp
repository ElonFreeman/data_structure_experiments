ElemType Ldelete(Lqueue *q)

{

    Qnodetype *p;

    ElemType x;

    if(q->front==q->rear)

    {

        printf("队列为空!\n");

        return 0;

    }

    else

    {

        p=q->front->next;

       //【1】  /*将未完成的代码补全,提示:此处添加一条语句*/
        q->front->next = p->next;

        if(p->next==NULL)

            q->rear=q->front;

        x=p->data;

        free(p);

    }

    printf("出链队列元素:%d\n",x);

    return(x);

}

