#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Data {
    int num;
    char lastName[20], firstName[20];
    char middleName[20], job[20], position[20];
    char phoneNumbers[5][12], mails[5][20], sociaMedias[5][20], messengers[5][20];
} Data;
void clearData (struct Data contacts[20], int numOfContact) {
    contacts[numOfContact].num=0;
    strcpy(contacts[numOfContact].lastName, "");
    strcpy(contacts[numOfContact].firstName, "");
    strcpy(contacts[numOfContact].middleName, "");
    strcpy(contacts[numOfContact].job, "");
    strcpy(contacts[numOfContact].position, "");
    for(int k = 0; k < 5; k++) {
        strcpy(contacts[numOfContact].phoneNumbers[k], "");
        strcpy(contacts[numOfContact].mails[k], "");
        strcpy(contacts[numOfContact].sociaMedias[k], "");
        strcpy(contacts[numOfContact].messengers[k], "");
    }
}
void changeData (struct Data contacts[20], int numOfContact, char newLastName[20], char newFirstName[20],
 char newMiddleName[20], char newJob[20], char newPosition[20], char newPhoneNumbers[5][12],
 char newMails[5][20], char newSociaMedias[5][20], char newMessengers[5][20]) {
    contacts[numOfContact].num = numOfContact+1;
    strcpy(contacts[numOfContact].lastName, newLastName);
    strcpy(contacts[numOfContact].firstName, newFirstName);
    strcpy(contacts[numOfContact].middleName, newMiddleName);
    strcpy(contacts[numOfContact].job, newJob);
    strcpy(contacts[numOfContact].position, newPosition);
    for(int k = 0; k < 5; k++) {
        strcpy(contacts[numOfContact].phoneNumbers[k], newPhoneNumbers[k]);
        strcpy(contacts[numOfContact].mails[k], newMails[k]);
        strcpy(contacts[numOfContact].sociaMedias[k], newSociaMedias[k]);
        strcpy(contacts[numOfContact].messengers[k], newMessengers[k]);
    }
}
int main(int argc, char *argv[]) {
    char varLastName[5][20]={"Petrova","Sidorova","Ruka","Lipova","Chrahmalova"};
    char varFirstName[5][20]={"Antonina","Albina","Argentina","Karina","Marina"};
    struct Data contacts[20];
    for (int i=0;i<5;i++){
        clearData(contacts,i);
        contacts[i].num=i+1;
        strcpy(contacts[i].lastName, varLastName[rand()%4]);
        strcpy(contacts[i].firstName, varFirstName[rand()%4]);
    }
    char menuCommand = '4';
    char newLastName[20], newFirstName[20];
    char newMiddleName[20], newJob[20], newPosition[20];
    char newPhoneNumbers[5][12], newMails[5][20], newSociaMedias[5][20], newMessengers[5][20];
    int howMuch;
    char yesNo;
    int i = 5;
    int numOfContact, numOfParam;
    while (menuCommand!='0') {
        printf("1-add\n2-edit\n3-delete\n4-print\n0-exit\nEnter command:\n");
        scanf("%c", &menuCommand);
        switch (menuCommand) {
            case '1':
                printf("Enter last name:\n");
                scanf("%s", newLastName);
                printf("Enter first name:\n");
                scanf("%s", newFirstName);
                printf("Wanna enter middle name?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter middle name:\n");
                    scanf("%s", newMiddleName);
                }
                printf("Wanna enter job?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter job\n");
                    scanf("%s", newJob);
                }
                printf("Wanna enter position?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter position:\n");
                    scanf("%s", newPosition);
                }
                printf("Wanna enter phone numbers?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("How much phone numbers you want to enter? (max 5)\n");
                    while (getchar()!='\n') continue;
                    scanf("%d", &howMuch);
                    for (int j = 0; j < howMuch; j++){ 
                        printf("Enter phone number:\n");
                        scanf("%s", newPhoneNumbers[j]);
                    }
                }
                printf("Wanna enter mails?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("How much mails you want to enter? (max 5)\n");
                    while (getchar()!='\n') continue;
                    scanf("%d", &howMuch);
                    for (int j = 0; j < howMuch; j++){ 
                        printf("Enter mail:\n");
                        scanf("%s", newMails[j]);
                    }
                }
                printf("Wanna enter social medias?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("How much social medias you want to enter? (max 5)\n");
                    while (getchar()!='\n') continue;
                    scanf("%d", &howMuch);
                    for (int j = 0; j < howMuch; j++){ 
                        printf("Enter social media:\n");
                        scanf("%s", newSociaMedias[j]);
                    }
                }
                printf("Wanna enter messengers?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("How much messengers you want to enter? (max 5)\n");
                    while (getchar()!='\n') continue;
                    scanf("%d", &howMuch);
                    for (int j = 0; j < howMuch; j++){ 
                        printf("Enter messenger:\n");
                        scanf("%s", newMessengers[j]);
                    }
                }
                changeData(contacts,i,newLastName,newFirstName,newMiddleName,newJob,newPosition,
                newPhoneNumbers,newMails,newSociaMedias,newMessengers);
                i++;
                break;
            case '2':
                printf("Enter num of contact:\n");
                scanf("%d", &numOfContact);
                printf("Wanna change last name?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter new last name:\n");
                    scanf("%s", newLastName);
                } else strcpy(newLastName, contacts[numOfContact-1].lastName);
                printf("Wanna change first name?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter new first name:\n");
                    scanf("%s", newFirstName);
                } else strcpy(newFirstName, contacts[numOfContact-1].firstName);
                printf("Wanna change middle name?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter new middle name:\n");
                    scanf("%s", newMiddleName);
                } else strcpy(newMiddleName, contacts[numOfContact-1].middleName);
                printf("Wanna change job?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter new job\n");
                    scanf("%s", newJob);
                } else strcpy(newJob, contacts[numOfContact-1].job);
                printf("Wanna change position?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                if (yesNo=='1') {
                    printf("Enter new position:\n");
                    scanf("%s", newPosition);
                } else strcpy(newPosition, contacts[numOfContact-1].position);
                printf("Wanna enter new phone numbers?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                for(int k = 0; k < 5; k++) strcpy (newPhoneNumbers[k], contacts[numOfContact-1].phoneNumbers[k]);
                if (yesNo=='1') {
                    printf("How much phone numbers you want to change? (max 5)\n");
                    while (getchar()!='\n') continue;
                    scanf("%d", &howMuch);
                    for (int j = 0; j < howMuch; j++){
                        printf("What phone number you want to change? (1-5)\n");
                        while (getchar()!='\n') continue;
                        scanf("%d", &numOfParam);
                        printf("Enter new phone number:\n");
                        scanf("%s", newPhoneNumbers[numOfParam-1]);
                    }
                }
                printf("Wanna enter new mails?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                for(int k = 0; k < 5; k++) strcpy (newMails[k], contacts[numOfContact-1].mails[k]);
                if (yesNo=='1') {
                    printf("How much mails you want to change? (max 5)\n");
                    while (getchar()!='\n') continue;
                    scanf("%d", &howMuch);
                    for (int j = 0; j < howMuch; j++){
                        printf("What mail you want to change? (1-5)\n");
                        while (getchar()!='\n') continue;
                        scanf("%d", &numOfParam);
                        printf("Enter new mail:\n");
                        scanf("%s", newMails[numOfParam-1]);
                    }
                }
                printf("Wanna enter new social medias?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                for(int k = 0; k < 5; k++) strcpy (newSociaMedias[k], contacts[numOfContact-1].sociaMedias[k]);
                if (yesNo=='1') {
                    printf("How much social medias you want to change? (max 5)\n");
                    while (getchar()!='\n') continue;
                    scanf("%d", &howMuch);
                    for (int j = 0; j < howMuch; j++){
                        printf("What social media you want to change? (1-5)\n");
                        while (getchar()!='\n') continue;
                        scanf("%d", &numOfParam);
                        printf("Enter new social media:\n");
                        scanf("%s", newSociaMedias[numOfParam-1]);
                    }
                }
                printf("Wanna enter new messengers?\n0-no\n1-yes\n");
                while (getchar()!='\n') continue;
                scanf("%c",&yesNo);
                for(int k = 0; k < 5; k++) strcpy (newMessengers[k], contacts[numOfContact-1].messengers[k]);
                if (yesNo=='1') {
                    printf("How much messengers you want to change? (max 5)\n");
                    while (getchar()!='\n') continue;
                    scanf("%d", &howMuch);
                    for (int j = 0; j < howMuch; j++){
                        printf("What messenger you want to change? (1-5)\n");
                        while (getchar()!='\n') continue;
                        scanf("%d", &numOfParam);
                        printf("Enter new messenger:\n");
                        scanf("%s", newMessengers[numOfParam-1]);
                    }
                }
                changeData(contacts,numOfContact-1,newLastName,newFirstName,newMiddleName,newJob,newPosition,
                newPhoneNumbers,newMails,newSociaMedias,newMessengers);
                break;
            case '3':
                printf("Enter num of contact:\n");
                scanf("%d", &numOfContact);
                clearData(contacts,numOfContact-1);
                break;
            case '4':
                for (int j = 0; j < i; j++) {
                    if (contacts[j].num != 0) {
                        printf ("\n");
                        printf("Num: %d\n", contacts[j].num);
                        printf("Last name: %s\n", contacts[j].lastName);
                        printf("First name: %s\n", contacts[j].firstName);
                        if (strlen(contacts[j].middleName) != 0) printf("Middle name: %s\n", contacts[j].middleName);
                        if (strlen(contacts[j].job) != 0) printf("Job: %s\n", contacts[j].job);
                        if (strlen(contacts[j].position) != 0) printf("Position: %s\n", contacts[j].position);
                        for(int k = 0; k < 5; k++) 
                            if (strlen(contacts[j].phoneNumbers[k]) != 0) printf("Phone %d: %s\n", k+1, contacts[j].phoneNumbers[k]);
                        for(int k = 0; k < 5; k++)     
                            if (strlen(contacts[j].mails[k]) != 0) printf("Mail %d: %s\n", k+1, contacts[j].mails[k]);
                        for(int k = 0; k < 5; k++) 
                            if (strlen(contacts[j].sociaMedias[k]) != 0) printf("Social media %d: %s\n", k+1, contacts[j].sociaMedias[k]);
                        for(int k = 0; k < 5; k++) 
                            if (strlen(contacts[j].messengers[k]) != 0) printf("Messenger %d: %s\n", k+1, contacts[j].messengers[k]);
                        }
                }
                printf ("\n");
                break;
            default:
                break;
        }
        while (getchar()!='\n')
            continue;
    }
}