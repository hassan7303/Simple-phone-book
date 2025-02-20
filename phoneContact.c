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

int getChoice() {
    int choice;

    printf("Search by?\n");
    printf("1. Contact name\n");
    printf("2. Contact phone\n");
    printf("3. Contact email\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("⛔ Invalid selection!\n");
        return -1;
    }

    return choice;
}


int search(){
    int choice = getChoice();
    if (choice == -1) return -1;

    char searchInput[50];
    printf("🔍 Enter the contact %s:\n", choice == 1 ? "name" : (choice == 2 ? "phone" : "email"));
    scanf(" %[^\n]s", searchInput);

    for (int i = 0; i < contactCount; i++) {
        if ((choice == 1 && strcmp(contacts[i].name, searchInput) == 0) ||
            (choice == 2 && strcmp(contacts[i].phone, searchInput) == 0) ||
            (choice == 3 && strcmp(contacts[i].email, searchInput) == 0)) {
            
            printf("✅ Found Contact:\n");
            printf("%d. Name: %s | Phone: %s | Email: %s\n", i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
            return 0; 
        }
    }

    printf("⛔ Contact not found!\n");
    return -1;
}


void deleteContact() {
    if (contactCount == 0) {
        printf("⛔ No contacts registered!\n");
        return;
    }
    char deleteInput[50];
    int choice = getChoice();
    if (choice == -1) return;

    printf("🗑 Enter the contact %s to delete:\n", choice == 1 ? "name" : (choice == 2 ? "phone" : "email"));
    scanf(" %[^\n]s", deleteInput);

    int found = 0;
    for (int i = 0; i < contactCount; i++) {
        if ((choice == 1 && strcasecmp(contacts[i].name, deleteInput) == 0) ||
            (choice == 2 && strcmp(contacts[i].phone, deleteInput) == 0) ||
            (choice == 3 && strcasecmp(contacts[i].email, deleteInput) == 0)) {
            
            found = 1;
            for (int j = i; j < contactCount - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contactCount--;
        }
    }

    if (!found) {
        printf("⛔ Contact not found!\n");
        return;
    }

    printf("✅ Contact successfully deleted!\n");
    return;
}

void saveContacts() {
    printf("saveContacts\n");
}

void addTestContact(const char* name, const char* phone, const char* email) {
    if (contactCount < MAX_CONTACTS) {
        strcpy(contacts[contactCount].name, name);
        strcpy(contacts[contactCount].phone, phone);
        strcpy(contacts[contactCount].email, email);
        contactCount++;
    }
}

void loadContacts() {}

int main() {
    loadContacts();

    addTestContact("Ali", "09123456789", "ali@example.com");
    addTestContact("Reza", "09223334455", "reza@example.com");
    
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
                case 3: search(); break;    
                case 4: deleteContact(); break;         
                case 5: saveContacts(); printf("👋 Goodbye!\n"); break;   
                default : printf("⛔ Invalid selection!\n"); return 1;   
            }

        }while(choice != 5);

    return 0;
}
