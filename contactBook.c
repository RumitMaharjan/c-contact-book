// What it does:
// 1. Add a contact (name + phone)
// 2. List all contacts
// 3. Search by name
// 4. Delete a contact
// 5. Quit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[15];
} Contact;

Contact *contacts = NULL;
int count = 0;
int capacity = 2;  // start small so realloc triggers fast

void addContact(char *name, char *phone) {
    if (count == capacity) {
        capacity *= 2;
        contacts = realloc(contacts, capacity * sizeof(Contact));
    }
    strcpy(contacts[count].name, name);
    strcpy(contacts[count].phone, phone);
    count++;
    printf("Contact added.\n");
}

void listContacts() {
    if (count == 0) { printf("No contacts.\n"); return; }
    printf("\n--- Contacts (%d) ---\n", count);
    for (int i = 0; i < count; i++) {
        printf("[%d] %-20s %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
    printf("--------------------\n\n");
}

void searchContact(char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("Found: %s — %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void deleteContact(char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            contacts[i] = contacts[count - 1];  // replace with last
            count--;
            printf("Deleted.\n");
            return;
        }
    }
    printf("Contact not found.\n");
}

int main() {
    contacts = malloc(capacity * sizeof(Contact));

    int choice;
    char name[50], phone[15];

    while (1) {
        printf("1. Add  2. List  3. Search  4. Delete  5. Quit\n> ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Name: "); scanf("%s", name);
            printf("Phone: "); scanf("%s", phone);
            addContact(name, phone);
        } else if (choice == 2) {
            listContacts();
        } else if (choice == 3) {
            printf("Search name: "); scanf("%s", name);
            searchContact(name);
        } else if (choice == 4) {
            printf("Delete name: "); scanf("%s", name);
            deleteContact(name);
        } else {
            free(contacts);
            printf("Bye.\n");
            break;
        }
    }
    return 0;
}
