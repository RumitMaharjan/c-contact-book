#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[50];
	char phone[15];
}Contact;

Contact *contacts = NULL;
int count = 0;
int capacity = 2;

void addContact(char *name, char *phone){
	Contact *temp;
	if(count==capacity){
		capacity *= 2;
		temp = realloc(contacts, capacity*sizeof(Contact));
		if (temp == NULL){
		printf("Memory allocation failed.\n");
		free(contacts);
		exit(1);
		}
		contacts = temp;
	}
	
	strcpy(contacts[count].name, name);
	strcpy(contacts[count].phone, phone);
	printf("Contact is added!\n");
	count++;
}

void listContact(){
	if(count == 0){
		printf("No Contacts!\n");
		return;
	}
	for (int i = 0; i<count; i++){
		printf("[%d] Name: %-20s Phone: %s\n",i+1,contacts[i].name, contacts[i].phone);
	}
}

void searchContact(char *name){
	for (int i = 0; i<count; i++){
		if(strcmp(contacts[i].name, name)==0){
			printf("Contact Found!\n");
			printf("Name: %-20s Phone: %s\n", name, contacts[i].phone);
			return;
		}
	}
	printf("Contact With Name %s Not Found!\n",name);
}

void deleteContact(char *name){
	for (int i = 0; i<count; i++){
		if(strcmp(contacts[i].name, name)==0){
			contacts[i] = contacts[count-1];
			count--;
			printf("Contact %s Deleted\n",name);
			return;
		}
	}
	printf("Contact With Name %s Not Found!\n",name);
}

int main(){
	contacts = malloc(capacity*sizeof(Contact));
	if(contacts == NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	int choice=0;
	
	char name[50], phone[15];
	
	
	while(choice!=5){
		printf("-----------------------------\n");
		printf("1: Add Contact\n");
		printf("2: List Contact\n");
		printf("3: Search Contact\n");
		printf("4: Delete Contact\n");
		printf("5: Exit\n");
		printf("-----------------------------\n");
		printf("Enter your choice (1-5): ");
		scanf("%d", &choice);
		printf("-----------------------------\n");
		switch(choice){
			case 1:{
				printf("Enter name: ");
				scanf(" %49[^\n]", name);
				printf("Enter phone: ");
				scanf("%s", phone);
				addContact(name,phone);
				break;
			}
			case 2:{
				printf("Contact List: \n");
				listContact();
				break;
			}
			case 3:{
				printf("Search Contact\n");
				printf("Enter contact name: ");
				scanf(" %49[^\n]", name);
				printf("-----------------------------\n");
				searchContact(name);
				break;
			}
			case 4:{
				printf("Delete Contact\n");
				printf("Enter contact name: ");
				scanf(" %49[^\n]", name);
				printf("-----------------------------\n");
				deleteContact(name);
				break;
			}
			case 5:{
				free(contacts);
				printf("Thank You!\n");
				printf("-----------------------------\n");
				break;
			}
			default:{
				printf("Please Choose Between 1-5!\n");
				break;
			}
		}
	}
	return 0;
}
