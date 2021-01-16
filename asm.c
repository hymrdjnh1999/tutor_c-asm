#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"
struct contact {
    char firstName[20];
    char middleName[20];
    char lastName[20];
    char company[40];
    char phoneNumber[20];
    char address[40];
    char birthday[20];
    char website[40];
    char note[80];
} typedef contact;



int enterSelect();
void mainMenu();
void displayContacts(contact* contact,int contactLength);
void displayThroughLine(int width);
void clearScreen();
void enterToContinue();
int main(int argc,char const *argv[])
{
    char line[] = "==========================================\n";
    mainMenu(line);
    return 0;
}

// int enterSelect(char *line){
    
//     return choice;
// }

void enterData(char* title,char * content,char *input){
    char output [100];
    int length = 0;
    int count = 0;
    do
    {
        if(count != 0){
            printf(content);
            printf(" must at least 6 characters!\n");
        }
        printf(title);
        fflush(stdin);
        scanf("%[^\n]s",input);
        fflush(stdin);
        count+=1;
    } while (!strlen(input));
    // return output;
}

contact addContact(char *line ){
    contact newContact;
    // system("cls");
    printf(line);
    printf(" CREATE NEW CONTACT\n");
    printf(line);
    enterData(" First name : ","First name" ,newContact.firstName);
    enterData(" Middle name : ","Middle name",newContact.middleName);
    enterData(" Last name : ","Middle name",newContact.lastName);
    // enterData(" Company : ","Company",newContact.company);
    // enterData(" Phone number : ","Phone number",newContact.phoneNumber);
    // enterData(" Address : ","Address",newContact.address);
    // enterData(" Birthdate : ","Birthdate",newContact.birthday);
    // enterData(" Website : ","Website",newContact.website);
    // enterData(" Note : ","Note",newContact.note);
    printf(line);
    printf("Create contact complete!\n");
    enterToContinue();
    
    return newContact;
} 

void mainMenu(char *line){

    int choice;
    int currentContactIndex = 0;
    contact* contacts = malloc(1* sizeof(contact));
    do
    {
    system("cls");
    contact newContact;
    printf(line);
    printf("  --- VTC ACADEMY CONTACT MANAGEMENT --- \n");
    printf(line);
    printf("1. SEARCH YOUR CONTACT\n");
    printf("2. ADD CONTACT\n");
    printf("3. DISPLAY FAVOURITE CONTACT\n");
    printf("4. DISPLAY ALL CONTACT\n");
    printf("5. EXIT APPLICATION\n");
    printf(line);
    printf(" #YOUR CHOICE: ");
    int test;
    if(scanf("%d",&choice)){
        fflush(stdin);
        if(choice< 1 || choice > 5){
            system("cls");
            printf("Please enter in range from 1 to 5!\n");
        }
    }
    else{
        fflush(stdin);
        system("cls");
        printf("Wrong input. Please re-enter!\n");
    }
    switch (choice)
    {
        case 1:
            break;
        case 2:
        newContact = addContact(line);
        contacts[currentContactIndex] = newContact;
        ++currentContactIndex;
        contacts =(contact*) realloc(contacts,(currentContactIndex + 1) * sizeof(contact));
            break;
        case 3:
            break;
        case 4:
            displayContacts(contacts,currentContactIndex);
            break;
        case 5:
            exit(1);
            break;
    }
    
    } while ( true );

}


void displayContacts(contact* contacts,int contactLength){
    clearScreen();
    int lineWidth = 50;
    displayThroughLine(lineWidth);
    printf("| %-4s | %-41s |\n","No","Full Name");
    displayThroughLine(lineWidth);
    for (int index = 0;  index< contactLength;  index++)
    {
        char *fullName = strcat(contacts[index].firstName," ");
        fullName = strcat(fullName,contacts[index].middleName);
        fullName = strcat(fullName," ");
        fullName = strcat(fullName,contacts[index].lastName);
        int rank = index + 1;
        printf("| %-4d | %-41s |\n",rank,fullName);
    }
    
    enterToContinue();

}
void displayThroughLine(int width){
    printf("+");
    for (int i = 0; i < width; i++)
    {   
        printf("-");
    }
    printf("+\n");
    
}
void clearScreen(){
    system("cls");
}
void enterToContinue(){
    printf("Enter any key to continue...");
    getchar();
    fflush(stdin);
}