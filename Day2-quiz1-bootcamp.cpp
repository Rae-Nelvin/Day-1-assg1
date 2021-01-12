#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int score;
    node* next;
}*head, * tail;

node* createnode(int value) 
{
    node* temp = (node*)malloc(sizeof(node));
    temp->score = value;
    temp->next = NULL;
    return temp;
}

void push(int value, node** curr_node) 
{
    node* temp = createnode(value);
    temp->next = *curr_node;
    *curr_node = temp;
}

void pushtail(int value) 
{
    node* temp = createnode(value);
    if (!tail) 
    {
        head = tail = temp;
    }
    else 
    {
        tail->next = temp;
        tail = temp;
    }
}

void swap(node* a, node* b) 
{
    if (head) 
    {
        node* hapus = head;
        while (hapus) {
            hapus = head->next;
            head->next = NULL;
            free(head);
            head = hapus;
        }
    }
    node* temp1 = a, * temp2 = b;
    while (temp1 && temp2) 
    {
        if (temp1->score > temp2->score) {
            pushtail(temp2->score);
            temp2 = temp2->next;
        }
        else {
            pushtail(temp1->score);
            temp1 = temp1->next;
        }
    }
    while (temp1) 
    {
        pushtail(temp1->score);
        temp1 = temp1->next;
    }
    while (temp2) 
    {
        pushtail(temp2->score);
        temp2 = temp2->next;
    }
}

void print(node* curr_node) 
{
    while (curr_node) 
    {
        if (curr_node->next == NULL) {
            printf("%d\n", curr_node->score);
            curr_node = curr_node->next;
        }
        else 
        {
            printf("%d -> ", curr_node->score);
            curr_node = curr_node->next;
        }
    }
}

int main() 
{
    node* a = NULL;
    node* b = NULL;
    int n, m, num;
    printf("Masukkan banyak angka yang diinginkan: ");
    scanf("%d", &n);
    printf("Masukkan angka - angka tersebut dari terbesar ke terkecil\n");
    for (int i = 0;i < n;i++) 
    {
        scanf("%d", &num);
        push(num, &a);
    }
    print(a);
    printf("Masukkan banyak angka yang diinginkan: ");
    scanf("%d", &m);
    printf("Masukkan angka - angka tersebut dari terbesar ke terkecil\n");
    for (int i = 0;i < n;i++) 
    {
        scanf("%d", &num);
        push(num, &b);
    }
    swap(b, a);
    print(head);

    return 0;
}