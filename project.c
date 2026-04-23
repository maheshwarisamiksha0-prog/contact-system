#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Contact
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
    struct Contact* next;
};

struct Contact* head = NULL;

// Add Contact
void addContact() {
    struct Contact* newContact = (struct Contact*)malloc(sizeof(struct Contact));

    printf("Enter Name: ");
    scanf(" %[^\n]", newContact->name);

    printf("Enter Phone: ");
    scanf("%s", newContact->phone);

    printf("Enter Email: ");
    scanf("%s", newContact->email);

    newContact->next = head;
    head = newContact;

    printf("Contact Added Successfully!\n");
}

// Display Contacts
void displayContacts() {
    struct Contact* temp = head;

    if (temp == NULL) {
        printf("No contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("Email: %s\n\n", temp->email);
        temp = temp->next;
    }
}

// Search Contact
void searchContact() {
    char name[50];
    printf("Enter Name to Search: ");
    scanf(" %[^\n]", name);

    struct Contact* temp = head;
    int found = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Contact Found!\n");
            printf("Name: %s\nPhone: %s\nEmail: %s\n",
                   temp->name, temp->phone, temp->email);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found)
        printf("Contact Not Found.\n");
}

// Delete Contact
void deleteContact() {
    char name[50];
    printf("Enter Name to Delete: ");
    scanf(" %[^\n]", name);

    struct Contact *temp = head, *prev = NULL;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact Not Found.\n");
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Contact Deleted Successfully!\n");
}

// Main Menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }

    return 0;
}