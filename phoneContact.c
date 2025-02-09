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

void addContact() {
    printf("addContact\n");
}

void listContacts() {
    printf("listContacts\n");
}

void searchContact() {
    printf("searchContact\n");
}

void deleteContact() {
    printf("deleteContact\n");
}

void saveContacts() {
    printf("saveContacts\n");
}

void loadContacts() {}

int main() {
    loadContacts();
    int choice;

        do{
            printf("\n📞 **Contact Management** 📞\n");
            printf("1. Add contact\n");
            printf("2. Display contact list\n");
            printf("3. Contact search\n");
            printf("4. Delete contact\n");
            printf("5. Save and exit\n");
            printf("Your choice:");
            scanf("%d", &choice);

            switch(choice)
            {
                case 1: addContact(); break;       
                case 2: listContacts(); break;     
                case 3: searchContact(); break;    
                case 4: deleteContact(); break;         
                case 5: saveContacts(); printf("👋 Goodbye!\n"); break;   
                default : printf("⛔ Invalid selection!\n"); break;   
            }

        }while(choice != 5);

    return 0;
}
