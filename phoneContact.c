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

void search(int searchBy){
    char searchInput[50];

    switch(searchBy){
        case 1:
            printf("🔍 Enter the contact name:\n");
            break;

        case 2:
            printf("🔍 Enter the contact phone :\n");
            break;

        case 3:
            printf("🔍 Enter the contact email :\n");
            break;
    }
    
    scanf("%s", &searchInput);
    
    for (int i = 0; i < contactCount; i++) {
        if ((searchBy == 1 && strcmp(contacts[i].name, searchInput) == 0) ||
            (searchBy == 2 && strcmp(contacts[i].phone, searchInput) == 0) ||
            (searchBy == 3 && strcmp(contacts[i].email, searchInput) == 0)) {
            
            printf("✅ Found Contact:\n");
            printf("%d. Name: %s | Phone: %s | Email: %s\n", 
                   i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
            return;
        }
    }

    printf("⛔ Contact not found!\n");return;
}

void searchContact() {
    if (contactCount == 0) {
        printf("⛔ No contacts registered!\n");
        return;
    }

    int choice;
    printf("Search by?\n");
    printf("1. Contact name\n");
    printf("2. Contact phone\n");
    printf("3. Contact email\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3) {
        search(choice);
    } else {
        printf("⛔ Invalid selection!\n");
    }
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
