void Lappend(Lqueue *q,int x)

{

    Qnodetype *s;

    s=(Qnodetype *)malloc(sizeof(Qnodetype));

    s->data=x;

    s->next=NULL;

    q->next=s;
    
    q->rear->next = s;
  //【1】  /*将未完成的代码补全,提示:此处添加一条语句*/

    q->rear=s;

}