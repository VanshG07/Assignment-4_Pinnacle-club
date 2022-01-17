#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void display();
void add_member();
void insert_secretory();
void remove_member();
void count_members();

struct Node
{
    int roll,prn;
    char name[20];
    struct Node *next;
};


int main()
{
    struct Node* head=(struct Node*) malloc(sizeof(struct Node));
    printf("\n\nEnter Roll No, Prn No and Name of President: ");
    scanf("%d %d",&(head->roll),&(head->prn));
    scanf("%s",(head->name));
    head->next=NULL;


    while(1)
    {
        printf("\n*********Menu*********");
        printf("\n\tPress 1 to Add Member\n\tPress 2 to Remove Member\n\tPress 3 to Display Member\n\tPress 4 to Add Secretory\n\tPress 5 to Count Members\n\tPress 0 to Exit\n");
        printf(" Press: ");
        int x;
        scanf("%d",&x);
        switch (x)
        {
        case 1:
            add_member(head);
            break;
        case 2:
            remove_member(&head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            insert_secretory(head);
            break;
        case 5:
            count_members(head);
            break;
        case 0:
            break;
        }
        if(x==0)
            break;

    }
}

void add_member(struct Node* head)
{
    struct Node* new =(struct Node*) malloc(sizeof(struct Node));

    printf("\n\nEnter Roll No, Prn No and Name of New member: ");
    scanf("%d %d",&(new->roll),&(new->prn));
    scanf("%s",new->name);
    new->next = head->next;
    head->next=new;
}

void display(struct Node* head)
{
    printf("\n\nRoll No\tPRN\tName\n");
    while (head!=NULL)
    {
        printf("%d\t%d\t%s\n",head->roll,head->prn,head->name);
        head = head->next;
    }
    printf("\nPress Enter to continue......");
    getchar();
    getchar();
}

void insert_secretory(struct Node* head)
{
    struct Node* new=(struct Node*) malloc(sizeof(struct Node));
    printf("Enter Roll No, Prn No and Name of Secretory: ");
    scanf("%d %d",&(new->roll),&(new->prn));
    scanf("%s",(new->name));
 
    new->next = NULL;
    while(head->next!=NULL)
    {
        head=head->next;
    }
    head->next=new;
}

void remove_member(struct Node** head)
{
    struct Node *temp = *head, *prev;
    char key[10];
    printf("\nEnter Name of Member: \n");
    scanf("%s",key);

    if (temp != NULL && strcmp(temp->name,key)==0) {
        *head = temp->next;
        free(temp);
        return;
    }


    while (temp != NULL && strcmp(temp->name,key)!=0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
    printf("\nMember '%s' is removed....\n",key);
    printf("\nPress Enter to continue......\n");
    getchar();
    getchar();
}

void count_members(struct Node* head)
{
    int count=0;
    while (head!=NULL)
    {
        head = head->next;
        count++;
    }

    printf("\nNumber of Members: %d\n",count);
    printf("\nPress Enter to continue......");
    getchar();
    getchar();
}