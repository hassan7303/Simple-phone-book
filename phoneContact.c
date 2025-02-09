#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100  

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

struct Contact contacts[MAX_CONTACTS]; 

int contactCount = 0 ;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("The phone book is full!\n");
        return;
    }

    printf("contact name: ");
    scanf(" %[^\n]s", contacts[contactCount].name);

    printf("phone: ");
    scanf(" %[^\n]s", contacts[contactCount].phone);

    printf("email: ");
    scanf(" %[^\n]s", contacts[contactCount].email);

    contactCount++;
    printf("✅ Contact successfully added!\n");
}

void listContacts() {
    if(contactCount == 0){
        printf("⛔ No contacts registered!\n");
        return;
    }

    printf("\n📜 Contact list:\n");
    for(int i = 0;i < contactCount; i++){
        printf("%d.%s : %s -||- %s : %s -||- %s : %s \n",i + 1,"name",contacts[i].name ,"phone", contacts[i].phone ,"email", contacts[i].email);
    }
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
                default : printf("⛔ Invalid selection!\n"); return 1;   
            }

        }while(choice != 5);

    return 0;
}
