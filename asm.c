#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "string.h"
struct newContactField{
    char fieldName[100];
    char fieldValue[100];
}typedef newContactField;

struct contact {
    char firstName[100];
    char middleName[100];
    char lastName[100];
    char company[100];
    char phoneNumber[100];
    char email[100];
    char address[100];
    char birthday[100];
    char website[100];
    char note[100];
    bool isFavouriteContact;
    int fieldCurrentIndex;
    newContactField* fields;
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
int getIntNumber(char * title);
void getInput(char* title,char * errorContent,char * resource,int action);
int contactDetailSubmenu(contact* currentContact,int contactIndex );
void updateContact(contact* contacts , int contactIndex);
void addNewContactField(contact* contacts,int contactIndex);
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
    int action = 0;
    getInput(" First name : "," First name" ,newContact.firstName,action);
    getInput(" Middle name : "," Middle name",newContact.middleName,action);
    getInput(" Last name : "," Last name",newContact.lastName,action);
    // getInput(" Company : ","Company",newContact.company,action);
    // getInput(" Phone number : ","Phone number",newContact.phoneNumber,action);
    // getInput(" Email : ","Email",newContact.email,action);
    // getInput(" Address : ","Address",newContact.address,action);
    // getInput(" Birthdate : ","Birthdate",newContact.birthday,action);
    // getInput(" Website : ","Website",newContact.website,action);
    // getInput(" Note : ","Note",newContact.note,action);
    newContact.isFavouriteContact = false;
    newContact.fieldCurrentIndex = 0;
    printf(line);
    printf("Create contact complete!\n");
    enterToContinue();
    return newContact;
} 

void mainMenu(char *line){

    int choice;
    int currentContactIndex = 0;
    contact* contacts = malloc((1 * sizeof(contact))+ (1 * sizeof(newContactField)));
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
    char buffer[40];
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
            fgets( buffer,40, stdin );
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
    char buffer[40];
    do
        {
            
            if(!isCorrectDataType){
                printf("WRONG INPUT! PLEASE RE-ENTER.\n");
            }
            printf(title);
            fgets( buffer, 40, stdin );
            isCorrectDataType = false;
        } while (sscanf(buffer,"%d",&choice) != 1);
    // is correct data type
    return choice;
}

void getInput(char* title,char * errorContent,char * resource,int action){
    bool isValid = true;
    if(action == 0 /*is create*/){
        do
        {
            if(!isValid){
                printf(errorContent);
                printf(" is required.\n");
            }
            printf(title);
            fgets(resource,100,stdin);
            isValid = false;
        } while (resource[0] =='\n' || resource[0] == '\0');
    }

    else{
        printf(title);
        printf(" : ");
        fgets(resource,100,stdin);
    }
    if(resource[strlen(resource)- 1]== '\n'){
                    resource[strlen(resource)- 1] = '\0';
    }
    
}

void displayContactDetail(contact* contacts,int contactIndex){
    contact currentContact = *(contacts + (contactIndex - 1));
    int choice;
    while (true)
    {
        clearScreen();
        displayEqualCharacter();
        printf(" CONTACT DETAILS\n");
        displayEqualCharacter();
        printf(" First name:  %s\n",currentContact.firstName);
        printf(" Middle name: %s\n",currentContact.middleName);
        printf(" Last name:   %s\n",currentContact.lastName);
        printf(" Company:     %s\n",currentContact.company);
        printf(" Phone:       %s\n",currentContact.phoneNumber);
        printf(" Email:       %s\n",currentContact.email);
        printf(" Address:     %s\n",currentContact.address);
        printf(" Birthday:    %s\n",currentContact.birthday);
        printf(" Website:     %s\n",currentContact.website);
        printf(" Note:        %s\n",currentContact.note);
        displayEqualCharacter();
        choice = contactDetailSubmenu(contacts,contactIndex - 1);
        displayEqualCharacter();
        if(choice == 5){
            break;
        }
    }
    
}
int contactDetailSubmenu(contact* contacts,int contactIndex ){
    int choice ;
    bool isCorrectChoice = true;
    printf(" 1. ADD TO FAVOURRITES\n");
    printf(" 2. UPDATE\n");
    printf(" 3. DELETE\n");
    printf(" 4. ADD FIELD\n");
    printf(" 5. BACK TO MAIN MENU\n");
    do
    {
        if(!isCorrectChoice){
            printf(" ARE YOU KIDDING ME? PLEASE RE-ENTER.\n");
        }
        choice = getIntNumber(" # YOUR CHOICE : ");
        isCorrectChoice = false;
    } while (choice < 1 || choice > 5);
    switch (choice)
    {
    case 1:
        if(contacts[contactIndex].isFavouriteContact){
            printf("This contact was favourite contact!\n");
            enterToContinue(); 
            return choice;
        }
        contacts[contactIndex].isFavouriteContact = true;
        printf("Added this contact to favourite contacts!\n");
        enterToContinue(); 
        return choice;
    case 2:
        updateContact(contacts,contactIndex);
        break;
    case 3:
        // printf("%d",currentContact.isFavouriteContact);
        break;
    case 4:
        addNewContactField(contacts,contactIndex);
        break;
    case 5:
        return choice;
    default:
        break;
    }
    return choice;
}

void updateContact(contact* contacts , int contactIndex){
    contact newContact = contacts[contactIndex];
    int currentFieldKey = newContact.fieldCurrentIndex;
    getInput(" Press Enter to not update,enter data to update\n First name","",newContact.firstName,1);
    getInput(" Press Enter to not update,enter data to update\n Middle name","",newContact.middleName,1);
    getInput(" Press Enter to not update,enter data to update\n Last name","",newContact.lastName,1);
    // update field name
    for (int count = 0; count <= currentFieldKey; count++)
    {
        printf(" Press Enter to not update,enter data to update\n");
        getInput(newContact.fields[count].fieldName,"",newContact.fields[count].fieldValue,1);
    }
    // 1
    if(strlen(newContact.firstName)){
        strcpy(contacts[contactIndex].firstName,newContact.firstName);
    }
    if(strlen(newContact.middleName)){
        strcpy(contacts[contactIndex].middleName,newContact.middleName);
    }    
    if(strlen(newContact.lastName)){
        strcpy(contacts[contactIndex].lastName,newContact.lastName);
    }    
    if(strlen(newContact.company)){
        strcpy(contacts[contactIndex].company,newContact.company);
    }    
    // 5
    if(strlen(newContact.phoneNumber)){
        strcpy(contacts[contactIndex].phoneNumber,newContact.phoneNumber);
    }    
    if(strlen(newContact.email)){
        strcpy(contacts[contactIndex].email,newContact.email);
    }    
    if(strlen(newContact.birthday)){
        strcpy(contacts[contactIndex].birthday,newContact.birthday);
    }  
    if(strlen(newContact.website)){
        strcpy(contacts[contactIndex].website,newContact.website);
    }    
    if(strlen(newContact.address)){
        strcpy(contacts[contactIndex].address,newContact.address);
    }   
    if(strlen(newContact.note)){
        strcpy(contacts[contactIndex].note,newContact.note);
    }     
    // printf("value 363|%s|",contacts[contactIndex].firstName );
    printf("Complete update contact information!\n");
    enterToContinue();
}

void displayEqualCharacter(){
    for (int i = 0; i < lineWidth; i++)
    {
        printf("=");
    }
    printf("\n");
}
void addNewContactField(contact* contacts,int contactIndex){
    int fieldCurrentIndex = contacts[contactIndex].fieldCurrentIndex;
    char value[100];
    newContactField newContactField;
        // getInput(" Field Name : "," Field name",newContactField.fieldValue,0);
        getInput(" Field Value : "," Field value",contacts[contactIndex].fields[fieldCurrentIndex].fieldValue,0);
        printf("fieldValue: %s|\n",contacts[contactIndex].fields[fieldCurrentIndex].fieldValue);
        // printf("fieldName : %d|\n",strlen(newContactField.fieldName));
        getInput(" Field Name : "," Field name",value,0);
        strcpy(newContactField.fieldName,value);
        printf("value: %s\n",newContactField.fieldName);
        enterToContinue();
        printf("Do you want to add a new field?( y:yes - any:n): \n");
        // fgets( buffer,1, stdin);
        // sscanf(buffer,"%c",choice);

    
}
