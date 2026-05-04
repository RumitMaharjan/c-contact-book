#include <stdio.h>
#include<string.h>

typedef struct {
    char name[50];
    int age;
} Person;

void birthday(Person *p) {
    p->age++;  // arrow operator: dereference + access field
}

void printPerson(Person *p) {
    printf("%s is %d years old\n", p->name, p->age);
}


void rename(Person *p, char *newName){

	strcpy(p->name, newName);
}

int main() {
	char newName[50];
    Person rumit = {"Rumit", 20};

    printPerson(&rumit);
    birthday(&rumit);
    printPerson(&rumit);
    
    printf("Write new name: ");
	scanf("%s", newName);
	
	rename(&rumit, newName);
	
	printf("New name is: %s",rumit.name);

    return 0;
}

