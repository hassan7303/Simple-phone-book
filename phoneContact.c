#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact {
    char name[50];
    char phone[20];
    char email[50];
};

// struct Contacts contactCount[MAX_CONTACTS];

int contactCount = 0 ;

void addContact() {}

void listContacts() {}

void searchContact() {}

void deleteContact() {}

void saveContacts() {}

void loadContacts() {}

int main() {
    loadContacts();
    int choice;

        printf("1. Add contact \n");
        printf("2. Display contact list \n");
        printf("3. Contact search \n");
        printf("4. Delete contact \n");
        printf("5. Save and exit \n");
        printf("Your choice:");
        scanf("%d",&choice);

    return 0;
}
