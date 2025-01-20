#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Employee structure
typedef struct Employee {
    char SSN[20];
    char name[50];
    char dept[50];
    char designation[50];
    float salary;
    char phone[15];
} Employee;

// Node structure
typedef struct Node {
    Employee data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(Employee emp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = emp;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at the end of the DLL
void insertAtEnd(Node** head, Employee emp) {
    Node* newNode = createNode(emp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Display the DLL and count nodes
void displayDLL(Node* head) {
    Node* temp = head;
    int count = 0;
    if (head == NULL) {
        printf("Doubly Linked List is empty.\n");
        return;
    }
    printf("DLL Status:\n");
    while (temp != NULL) {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, Phone: %s\n",
               temp->data.SSN, temp->data.name, temp->data.dept,
               temp->data.designation, temp->data.salary, temp->data.phone);
        count++;
        temp = temp->next;
    }
    printf("Total number of nodes: %d\n", count);
}

// Insert at the front of the DLL
void insertAtFront(Node** head, Employee emp) {
    Node* newNode = createNode(emp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Delete from the end of the DLL
void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("DLL is empty, nothing to delete.\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

// Delete from the front of the DLL
void deleteAtFront(Node** head) {
    if (*head == NULL) {
        printf("DLL is empty, nothing to delete.\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Menu-driven program
int main() {
    Node* head = NULL;
    int choice, n, i;
    Employee emp;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Create DLL of N Employees using End Insertion\n");
        printf("2. Display DLL and Count Nodes\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front\n");
        printf("6. Delete at Front\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of employees: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter details for employee %d (SSN, Name, Dept, Designation, Salary, Phone):\n", i + 1);
                    scanf("%s %s %s %s %f %s", emp.SSN, emp.name, emp.dept, emp.designation, &emp.salary, emp.phone);
                    insertAtEnd(&head, emp);
                }
                break;

            case 2:
                displayDLL(head);
                break;

            case 3:
                printf("Enter details for the employee to insert at end (SSN, Name, Dept, Designation, Salary, Phone):\n");
                scanf("%s %s %s %s %f %s", emp.SSN, emp.name, emp.dept, emp.designation, &emp.salary, emp.phone);
                insertAtEnd(&head, emp);
                break;

            case 4:
                deleteAtEnd(&head);
                break;

            case 5:
                printf("Enter details for the employee to insert at front (SSN, Name, Dept, Designation, Salary, Phone):\n");
                scanf("%s %s %s %s %f %s", emp.SSN, emp.name, emp.dept, emp.designation, &emp.salary, emp.phone);
                insertAtFront(&head, emp);
                break;

            case 6:
                deleteAtFront(&head);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
