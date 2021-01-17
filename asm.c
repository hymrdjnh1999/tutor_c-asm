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
    bool isFavouriteContact;
} typedef contact;


const int lineWidth = 50;

int enterSelect();
void mainMenu();
void displayContacts(contact* contact,int contactLength);
void displayWhiteSpace(int length);
void displayThroughLine();
void clearScreen();
void enterToContinue();
void enterToViewDetail(int contactLength,contact *contacts);
void displayContactDetail(contact* contacts,int contactIndex);
void displayEqualCharacter();
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
    system("cls");
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
    newContact.isFavouriteContact = false;
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

void displayFavouriteContacts(contact * contacts,int contactLength){
    clearScreen();
    
}
void displayContacts(contact* contacts,int contactLength){
    clearScreen();
    displayThroughLine(lineWidth);
    printf("| %-4s | %-41s |\n","No","Full Name");
    displayThroughLine(lineWidth);
    for (int index = 0;  index< contactLength;  index++)
    {
        int rank = index + 1;
        char* firstName = contacts[index].firstName;
        char* middleName= contacts[index].middleName;
        char* lastName= contacts[index].lastName;
        int fullNameLength = strlen(firstName) + strlen(middleName) + strlen(lastName);
        int restLength = 50 - fullNameLength;
        char * message = "| %-4d | %s %s %s";
        printf(message,rank,firstName,middleName,lastName);
        displayWhiteSpace(restLength - 10);
        printf("|\n");
    }
    displayThroughLine(lineWidth);
    
    enterToViewDetail(contactLength,contacts);

}
void displayWhiteSpace(int length){
    
    for (int i = 0; i < length; i++)
    {
        printf(" ");
    }
}
void displayThroughLine(){
    printf("+");
    for (int i = 0; i < lineWidth; i++)
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

void enterToViewDetail(int contactLength,contact* contacts){
    int choice;
    char buffer[200];
    bool isCorrectDataType = true;
    bool isCorrectRange = true;
    if(contactLength == 0){
        printf("NOTHING TO SHOW!\n");
        enterToContinue();
        return;
    }
    do
    {
        if(!isCorrectRange){
                isCorrectDataType = true;
                printf("DONT HAVE THIS CHOICE!\n");
            }
        do
        {
            
            if(!isCorrectDataType){
                isCorrectRange = true;
                printf("WRONG INPUT! PLEASE RE-ENTER.\n");
            }
            printf("ENTER NO TO VIEW DETAIL OR ENTER 0 TO BACK MAIN MENU : ");
            fgets( buffer, sizeof(buffer), stdin );
            isCorrectDataType = false;
        } while (sscanf(buffer,"%d",&choice) != 1);
        isCorrectRange = false;
    } while (choice < 0 || choice > contactLength );
    if(choice == 0){
        return;
    }
    displayContactDetail(contacts,choice);
}

void displayContactDetail(contact* contacts,int contactIndex){
    contact currentContact = *(contacts + (contactIndex - 1));
    clearScreen();
    displayEqualCharacter();
    printf(" CONTACT DETAILS\n");
    displayEqualCharacter();
    printf(" First name: %s\n",currentContact.firstName);
    printf(" Middle name: %s\n",currentContact.firstName);
    printf(" Last name: %s\n",currentContact.firstName);
    printf(" Company: %s\n",currentContact.firstName);
    printf(" Phone: %s\n",currentContact.firstName);
    printf(" Email: %s\n",currentContact.firstName);
    printf(" Address: %s\n",currentContact.firstName);
    printf(" Birthday: %s\n",currentContact.firstName);
    printf(" Website: %s\n",currentContact.firstName);
    printf(" Note: %s\n",currentContact.firstName);
    displayThroughLine(lineWidth);
    char* firstName = contacts[contactIndex].firstName;
    char* middleName= contacts[contactIndex].middleName;
    char* lastName= contacts[contactIndex].lastName;
    int fullNameLength = strlen(firstName) + strlen(middleName) + strlen(lastName);
    int restLength = 50 - fullNameLength;
    displayWhiteSpace(restLength - 10);
    printf("|\n");
    displayThroughLine(lineWidth);
    enterToContinue();
}


void displayEqualCharacter(){
    for (int i = 0; i < lineWidth; i++)
    {
        printf("=");
    }
    printf("\n");
}