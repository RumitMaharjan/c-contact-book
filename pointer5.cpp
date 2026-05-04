#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    float grade;
} Student;


void setGrade(Student *s, float grade);
void printStudent(Student *s);
Student* topStudent(Student *arr, int size);
void curveGrades(Student *arr, int size, float bonus);

int main() {
    Student classroom[3] = {
        {"Alice", 85.5},
        {"Bob", 90.0},
        {"Charlie", 78.0}
    };
    int size = 3;

    printf("--- Original Records ---\n");
    for (int i = 0; i < size; i++) {
        printStudent(&classroom[i]);
    }
    
    curveGrades(classroom, size, 5.0f);
    printf("\n--- After 5.0 Point Curve ---\n");
    for (int i = 0; i < size; i++) {
        printStudent(&classroom[i]);
    }

    Student *best = topStudent(classroom, size);
    printf("\nTop Student: %s (%.2f)\n", best->name, best->grade);

    setGrade(&classroom[0], 99.9f);
    printf("\nUpdated Alice: ");
    printStudent(&classroom[0]);

    return 0;
}

void setGrade(Student *s, float grade) {
    if (s != NULL) {
        s->grade = grade;
    }
}

void printStudent(Student *s) {
    if (s != NULL) {
        printf("Student: %-10s | Grade: %.2f\n", s->name, s->grade);
    }
}

Student* topStudent(Student *arr, int size) {
    if (size <= 0) return NULL;
    
    Student *best = &arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i].grade > best->grade) {
            best = &arr[i];
        }
    }
    return best;
}

void curveGrades(Student *arr, int size, float bonus) {
    for (int i = 0; i < size; i++) {
        (arr+i)->grade += bonus;
    }
}

