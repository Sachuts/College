#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *start = NULL;

void createlist() {
    if (start == NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        
        if (n != 0) {
            int data;
            struct node *newnode, *temp;
            
            start = malloc(sizeof(struct node));
            start->link = NULL;
            temp = start;
            
            printf("\nEnter number to be inserted: ");
            scanf("%d", &data);
            start->info = data;
            
            for (int i = 2; i <= n; i++) {
                newnode = malloc(sizeof(struct node));
                newnode->link = NULL;
                
                printf("\nEnter number to be inserted: ");
                scanf("%d", &data);
                newnode->info = data;
                
                temp->link = newnode;
                temp = temp->link;
            }
        }
        printf("\nThe list is created\n");
    } else {
        printf("\nThe list is already created\n");
    }
}

void traverse() {
    struct node *temp;
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("Data=%d\n", temp->info);
            temp = temp->link;
        }
    }
}

void insertAtFront() {
    int data;
    struct node *temp;
    
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    
    temp->info = data;
    temp->link = start;
    start = temp;
}

void insertAtEnd() {
    int data;
    struct node *temp, *head;
    
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    
    temp->info = data;
    temp->link = NULL;
    
    if (start == NULL) {
        start = temp;
    } else {
        head = start;
        while (head->link != NULL) {
            head = head->link;
        }
        head->link = temp;
    }
}

void insertAtPosition() {
    struct node *temp, *newnode;
    int pos, data, i = 1;
    
    newnode = malloc(sizeof(struct node));
    printf("\nEnter position and data: ");
    scanf("%d %d", &pos, &data);
    
    newnode->info = data;
    newnode->link = NULL;
    
    temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->link;
        i++;
    }
    if (temp == NULL) {
        printf("\nPosition not found\n");
    } else {
        newnode->link = temp->link;
        temp->link = newnode;
    }
}

void deleteFirst() {
    struct node *temp;
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = start;
        start = start->link;
        free(temp);
    }
}

void deleteEnd() {
    struct node *temp, *prevnode;
    if (start == NULL) {
        printf("\nList is Empty\n");
    } else {
        temp = start;
        while (temp->link != NULL) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = NULL;
    }
}

void deletePosition() {
    struct node *temp, *position;
    int pos, i = 1;
    
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        printf("\nEnter index: ");
        scanf("%d", &pos);
        
        temp = start;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->link;
            i++;
        }
        if (temp == NULL || temp->link == NULL) {
            printf("\nPosition not found\n");
        } else {
            position = temp->link;
            temp->link = position->link;
            free(position);
        }
    }
}

void search() {
    int found = 0;
    struct node *temp = start;
    
    if (start == NULL) {
        printf("Linked list is empty\n");
    } else {
        int key;
        printf("\nEnter the element you want to search: ");
        scanf("%d", &key);
        
        while (temp != NULL) {
            if (temp->info == key) {
                found = 1;
                break;
            }
            temp = temp->link;
        }
        
        if (found) {
            printf("Yes, %d is present in the linked list.\n", key);
        } else {
            printf("No, %d is not present in the linked list.\n", key);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n\t1 To see list\n");
        printf("\t2 For insertion at beginning\n");
        printf("\t3 For insertion at end\n");
        printf("\t4 For insertion at any position\n");
        printf("\t5 For deletion of first element\n");
        printf("\t6 For deletion of last element\n");
        printf("\t7 For deletion of element at any position\n");
        printf("\t8 Search an element in linked list\n");
        printf("\t9 To exit\n");
        
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                insertAtFront();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                deletePosition();
                break;
            case 8:
                search();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Incorrect Choice\n");
        }
    }
    
    return 0;
}