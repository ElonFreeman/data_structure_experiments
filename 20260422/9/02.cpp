#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} SeqStack;

void Push(SeqStack *s, char x) {
    if (s->top == MAX_SIZE - 1) {
        printf("栈满\n");
        return;
    }
    s->top++;
    s->data[s->top] = x;
}

char Pop(SeqStack *s) {
    if (s->top == -1) {
        printf("栈空\n");
        return -1;
    }
    char x = s->data[s->top];
    s->top--;
    return x;
}

char GetTop(SeqStack *s) {
    if (s->top != -1)
        return s->data[s->top];
    return -1;
}

int Empty(SeqStack *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

int BracketMatch(char *str) {
    SeqStack stack;
    stack.top = -1;
    int i; 
    char ch;
    for (i = 0; i < strlen(str); i++) {
        ch = str[i];
        switch(ch) {
            case '(':
            case '[':
            case '{':
                /***********Begin***********/
                Push(&stack, ch);
                /************End************/
                break;
            case ')':
                /************Begin************/
                if (Empty(&stack) || GetTop(&stack) != '(')
                    return 0;
                else
                    Pop(&stack);
                /************End************/
                break;
            case ']':
                /***********Begin***********/
                if (Empty(&stack) || GetTop(&stack) != '[')
                    return 0;
                else
                    Pop(&stack);
              /************End************/
                break;
            case '}':
                /***********Begin***********/
                if (Empty(&stack) || GetTop(&stack) != '{')
                    return 0;
                else
                    Pop(&stack);
                /************End************/
                break;
            default:
                break;
        }
    }
    if (Empty(&stack))
        return 1;
    else
        return 0;
}

int main() {
    char str[MAX_SIZE];
    fgets(str, MAX_SIZE, stdin);
    if (BracketMatch(str))
        printf("true\n");
    else
        printf("false\n");
    return 0;
}