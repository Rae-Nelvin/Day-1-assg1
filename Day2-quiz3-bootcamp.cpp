#include<stdio.h>
#include<stdlib.h>


struct node 
{
    int value;
    node* next;
}*head, * tail;

node* createnode(int value) 
{
    node* temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
}

void pushHead(int value) 
{
    node* temp = createnode(value);
    if (!head) 
    {
        head = tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void pushTail(int value) 
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

void pushMid(int value) 
{
    node* temp = createnode(value);
    if (!head) 
    {
        head = tail = temp;
    }
    else if (value > head->value) 
    {
        pushHead(value);
    }
    else if (value <= tail->value) 
    {
        pushTail(value);
    }
    else 
    {
        node* curr = head;
        while (curr->next && curr->next->value > value) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print() 
{
    if (head == NULL) 
    {
        return;
    }
    node* temp = head;
    while (temp) 
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    puts("");
}

void find() 
{
    int panjang = 1;
    node* temp = head;
    if (!head) 
    {
        return;
    }
    while (temp->next) 
    {
        panjang++;
        temp = temp->next;
    }
    panjang = (panjang) / 2;
    node* temp2 = head;
    while (panjang > 0) 
    {
        temp2 = temp2->next;
        panjang--;
    }
    printf("Nilai dari Node Tengah adalah : %d\n", temp2->value);
}

int main() 
{
    pushHead(10);
    pushHead(20);
    pushHead(30);
    pushHead(40);
    pushHead(50);
    print();
    find();


    return 0;
}