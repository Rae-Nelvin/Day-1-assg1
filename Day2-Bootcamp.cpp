#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
    char name[255];
    int score;
    Node *next; // menunjuk ke node selanjutnya
} *head, *tail; // global variabelnya, head dan tail
// head : node pertama dalam linked list
// tail : node terakhir dalam linked list

// char *name == char name[], const char untuk menghilangkan warning vscode

Node *createNode(const char *name, int score)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL; // untuk memastikan next tidak menunjuk ke garbage value
    return newNode;
}

// Push head, push tail
void pushHead(const char *name, int score)
{ 
    Node *temp = createNode(name, score); // 1. Buat dulu nodenya
    // 2. Cek kondisi
    if(!head) //  Jika tidak ada head, maka nodenya akan menjadi head dan tail
    {
        head = tail = temp;
    }

    else //  Jika ada head, node akan menjadi head baru dan node->next = head lama
    {
        temp->next = head; // node menunjuk ke head yang lama
        head = temp; // node akan menjadi head yang baru
    }
}

void pushTail(const char *name, int score)
{ 
    Node *temp = createNode(name, score); // 1. Buat dulu nodenya
    // 2. Cek kondisi
    if(!head) //  Jika tidak ada head, maka nodenya akan menjadi head dan tail
    {
        head = tail = temp;
    }

    else //  Jika ada tail
    {
        tail->next = temp; // node menunjuk ke tail yang lama
        tail = temp; // node akan menjadi tail yang baru
    }
}

void popHead()
{
    if(!head) // Jika tidak ada head
    {
        return; // Langsung return aja
    }
    else if(head == tail) // Kalau node cuman ada 1
    {
        free(head);
        head = tail = NULL;
    }
    else // Misal 53 (head) -> 70 -> 40 -> 25
    {
        Node *temp = head->next; // 53 (head) -> 70 (temp) -> 40 -> 25
        head->next = NULL; // 53 (head) -> NULL || 70 (temp) -> 40 -> 25
        free(head);
        head = temp; // 70 (head, temp) -> 40 -> 25
    }
     // karna temp itu local,  70 (head) -> 40 -> 25
}

void popTail()
{
    if(!head) // Jika tidak ada head
    {
        return; // Langsung return aja
    }
    else if(head == tail) // Kalau node cuman ada 1
    {
        free(head);
        head = tail = NULL;
    }
    else // Misal 53 (head) -> 70 -> 40 -> 25 (tail)
    {
        Node *temp = head; // 53 (head, temp) -> 70 -> 40 -> 25 -> NULL
        while(temp->next != tail)
        {
            temp = temp->next;
        }
        // 53 (head, temp) -> 70 -> 40 (temp) -> 25 (tail) -> NULL
        temp->next = NULL; // 53 (head) -> 70 -> 40 (temp) NULL || -> 25 (tail)
        free(tail);
        tail = temp; // 53 (head) -> 70 -> 40 (temp, tail) -> NULL
    }
     // karna temp itu local,  70 (head) -> 40 -> 25
}

void printList() 
{
    Node *curr = head;

    while(curr) 
    {
        printf("%s %d\n", curr->name, curr->score);
        curr = curr->next;
    }
}

int main()
{
    pushHead("Budi", 100); // Budi (head, tail) -> N
    pushTail("Ani", 90); // Budi (head) -> Ani (tail) -> N
    pushTail("Cynthia", 95); // Budi (head) -> Ani -> Cynthia (tail) -> N
    printList();
    return 0;
}