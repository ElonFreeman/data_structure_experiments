#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
    char identi[50];
    char name[50];
    char grade[20];
    char classes[20];
    
    struct info *next;
} info;

void initialization(info **head)
{
    *head = (info*)malloc(sizeof(info));
    (*head)->next = NULL;
}

void add(info *head)
{
    info *current = head;
    
    /* move to tail */
    while(current->next != NULL)
    {
        current = current->next;
    }
    
    /* set up a new node */
    info *node = (info*)malloc(sizeof(info));
    node->next = NULL;
    
    /* input data domain */
    printf("Input ID number:"); scanf("%s", node->identi);
    printf("Input Name:"); scanf("%s", node->name);
    printf("Input grade:"); scanf("%s", node->grade);
    printf("Input classes:"); scanf("%s", node->classes);
    
    /* link the new node onto tail */
    current->next = node;
}

void dele(info *head)
{
    /* check empty */
    if(head == NULL)
    {
        printf("Error!\n");
        return;
    }
    
    /* input the target to delete */
    char name[50];
    printf("Which student do you want to delete:(Input name)");
    scanf("%s", name);
    
    info *current = head;
    
    while(current->next != NULL)
    {
        /* check info */
        if(strcmp(current->next->name, name) == 0)
        {
            info *target = current->next;
            current->next = current->next->next;
            free(target);
            return;
        }
        /* move */
        current = current->next;
    }
    
    printf("Not found!\n");
}

void search(info *head)
{
    /* input the target to search */
    char name[50];
    printf("Which student do you want to search:(Input name)");
    scanf("%s", name);
    
    /* traverse and search */
    info *current = head;
    while(current->next != NULL)
    {
        current = current->next;
        if(strcmp(current->name, name) == 0)
        {
            printf("Got it!\n");
            printf("%s %s %s %s\n", current->identi, current->name, 
                   current->grade, current->classes);
            return;
        }
    }
    /* uncommon process */
    printf("No such person found!\n");
}

void print(info *head)
{
    info *current = head;
    while(current->next != NULL)
    {
        current = current->next;
        printf("%s %s %s %s\n", current->identi, current->name, 
               current->grade, current->classes);
    }
}

void insert(info *head)
{
    int position = 0;
    printf("Which position do you want to insert:(input a number)");
    scanf("%d", &position);
    
    info *current = head;
    
    int i = 1;
    while(current->next != NULL && i < position)
    {
        current = current->next;
        i++;
    }
    if(i < position)
    {
        printf("Illegal input!\n");
        return;
    }
    
    info *node = (info*)malloc(sizeof(info));
    
    /* insert link */
    node->next = current->next;
    current->next = node;
    
    /* input informations */
    printf("Input ID number:"); scanf("%s", node->identi);
    printf("Input Name:"); scanf("%s", node->name);
    printf("Input grade:"); scanf("%s", node->grade);
    printf("Input classes:"); scanf("%s", node->classes);
}

void cleanup(info *head)
{
    info *current = head;
    info *next;
    
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(void)
{
    info *head = NULL;
    initialization(&head);  /* set up an empty linked list */
    int whattodo = 0;
    
    do
    {
        printf("What do you want to do?\n");
        printf("(1.add,2.delete,3.search,4.print,5.insert,6.exit)\n");
        scanf("%d", &whattodo);
        if(whattodo == 6)
            break;
        
        switch(whattodo)
        {
            case 1: add(head); break;
            case 2: dele(head); break;
            case 3: search(head); break;
            case 4: print(head); break;
            case 5: insert(head); break;
            default: printf("Illegal input!\n");
        }
        
    } while(1);
    
    //cleanup(head);  /* free allocated memory */
    
    return 0;
}