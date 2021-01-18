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
    char email[100];
    char address[40];
    char birthday[20];
    char website[40];
    char note[80];
    bool isFavouriteContact;
    newContactField* fields;
} typedef contact;

struct newContactField{
    char fieldName[100];
    char fieldValue[100];
}typedef newContactField;


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
int getIntNumber(char * title);
void getInput(char* title,char * errorContent,char * resource);
void contactDetailSubmenu(contact currentContact);
// main
int main(int argc,char const *argv[])
{
    char line[] = "==========================================\n";
    mainMenu(line);
    return 0;
}

contact addContact(char *line ){
    contact newContact;
    system("cls");
    printf(line);
    printf(" CREATE NEW CONTACT\n");
    printf(line);
    getInput(" First name : "," First name" ,newContact.firstName);
    getInput(" Middle name : "," Middle name",newContact.middleName);
    getInput(" Last name : "," Last name",newContact.lastName);
    // enterData(" Company : ","Company",newContact.company);
    // enterData(" Phone number : ","Phone number",newContact.phoneNumber);
    // enterData(" Email : ","Email",newContact.email);
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
    choice = getIntNumber(" #YOUR CHOICE: ");
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
int getIntNumber(char * title){
    int choice ;
    bool isCorrectDataType = true;
    char buffer[200];
    do
        {
            
            if(!isCorrectDataType){
                printf("WRONG INPUT! PLEASE RE-ENTER.\n");
            }
            printf(title);
            fgets( buffer, sizeof(buffer), stdin );
            isCorrectDataType = false;
        } while (sscanf(buffer,"%d",&choice) != 1);
    // is correct data type
    return choice;
}

void getInput(char* title,char * errorContent,char * resource){
    bool isValid = true;
    do
    {
        if(!isValid){
            printf(errorContent);
            printf(" is required.\n");
        }
        printf(title);
        fgets(resource,sizeof(resource),stdin);
        isValid = false;
    } while (resource[0] =='\n' || resource[0] == '\0');
    fflush(stdin);
    if(resource[strlen(resource)- 1]== '\n'){
        resource[strlen(resource)- 1] = '\0';
    }
}

void displayContactDetail(contact* contacts,int contactIndex){
    contact currentContact = *(contacts + (contactIndex - 1));
    clearScreen();
    displayEqualCharacter();
    printf(" CONTACT DETAILS\n");
    displayEqualCharacter();
    printf(" First name: %s\n",currentContact.firstName);
    printf(" Middle name: %s\n",currentContact.middleName);
    printf(" Last name: %s\n",currentContact.lastName);
    printf(" Company: %s\n",currentContact.company);
    printf(" Phone: %s\n",currentContact.phoneNumber);
    printf(" Email: %s\n",currentContact.email);
    printf(" Address: %s\n",currentContact.address);
    printf(" Birthday: %s\n",currentContact.birthday);
    printf(" Website: %s\n",currentContact.website);
    printf(" Note: %s\n",currentContact.note);
    displayEqualCharacter();
    contactDetailSubmenu(currentContact);
    displayEqualCharacter();
    enterToContinue();
}
void contactDetailSubmenu(contact currentContact){
    int choice ;
    bool isCorrectChoice = true;
    printf("1. ADD TO FAVOURRITES");
    printf("2. UPDATE");
    printf("3. DELETE");
    printf("4. ADD FIELD");
    do
    {
        if(!isCorrectChoice){
            printf("ARE YOU KIDDING ME? PLEASE RE-ENTER.\n");
        }
        choice = getIntNumber(" # YOUR CHOICE : ");
        isCorrectChoice = false;
    } while (choice < 1 || choice > 5);

}

void handleDetailContactChoice(int choice){

}
void displayEqualCharacter(){
    for (int i = 0; i < lineWidth; i++)
    {
        printf("=");
    }
    printf("\n");
}