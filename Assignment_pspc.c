
#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUBJECTS 6

struct Marksheet {
    int roll_no;
    char name[50];
    float marks[6];
    float total;
    float percentage;
    char grade;
    char result[10];
};

struct Marksheet students[MAX];
int count = 0;

// Function declarations
void enterStudentDetails();
void calculateMarks(struct Marksheet *s);
void calculateGrade(struct Marksheet *s);
void generateMarksheet(struct Marksheet s);
void searchStudent();
void sortStudents();
void saveMarksheet();

// Enter student details
void enterStudentDetails() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[count].roll_no);

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", students[count].name);

    printf("\nEnter marks for 6 subjects (out of 100):\n");

    for (int i = 0; i < SUBJECTS; i++) {
        do {
            printf("Subject %d: ", i + 1);
            scanf("%f", &students[count].marks[i]);

            if (students[count].marks[i] < 0 ||
                students[count].marks[i] > 100) {
                printf("Enter marks between 0 and 100.\n");
            }
        } while (students[count].marks[i] < 0 ||
                 students[count].marks[i] > 100);
    }

    calculateMarks(&students[count]);
    calculateGrade(&students[count]);

    count++;

    printf("\nStudent details added successfully!\n");
}

// Calculate total and percentage
void calculateMarks(struct Marksheet *s) {
    s->total = 0;

    for (int i = 0; i < SUBJECTS; i++) {
        s->total += s->marks[i];
    }

    s->percentage = s->total / SUBJECTS;
}

// Calculate grade and result
void calculateGrade(struct Marksheet *s) {
    int pass = 1;

    for (int i = 0; i < SUBJECTS; i++) {
        if (s->marks[i] < 35) {
            pass = 0;
            break;
        }
    }

    if (!pass) {
        strcpy(s->result, "FAIL");
        s->grade = 'F';
    }
    else {
        strcpy(s->result, "PASS");

        if (s->percentage >= 90)
            s->grade = 'A';
        else if (s->percentage >= 80)
            s->grade = 'B';
        else if (s->percentage >= 70)
            s->grade = 'C';
        else if (s->percentage >= 60)
            s->grade = 'D';
        else
            s->grade = 'E';
    }
}

// Generate marksheet
void generateMarksheet(struct Marksheet s) {
    printf("\n========== STUDENT MARKSHEET ==========\n");

    printf("Roll Number : %d\n", s.roll_no);
    printf("Name        : %s\n", s.name);

    printf("\nSubject Marks:\n");

    for (int i = 0; i < SUBJECTS; i++) {
        printf("Subject %d   : %.2f\n",
               i + 1, s.marks[i]);
    }

    printf("\nTotal       : %.2f / 600\n", s.total);
    printf("Percentage  : %.2f%%\n", s.percentage);
    printf("Grade       : %c\n", s.grade);
    printf("Result      : %s\n", s.result);

    printf("=======================================\n");
}

// Search student by roll number
void searchStudent() {
    int roll, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll) {
            generateMarksheet(students[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent not found!\n");
    }
}

// Sort students by percentage
void sortStudents() {
    struct Marksheet temp;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            if (students[j].percentage <
                students[j + 1].percentage) {

                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted by percentage (Highest to Lowest).\n");

    for (int i = 0; i < count; i++) {
        printf("\nRoll No: %d | Name: %s | Percentage: %.2f%%",
               students[i].roll_no,
               students[i].name,
               students[i].percentage);
    }
}

// Save marksheets to file
void saveMarksheet() {
    FILE *fp;

    fp = fopen("marksheets.txt", "w");

    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "\n========== STUDENT MARKSHEET ==========\n");

        fprintf(fp, "Roll Number : %d\n",
                students[i].roll_no);

        fprintf(fp, "Name        : %s\n",
                students[i].name);

        for (int j = 0; j < SUBJECTS; j++) {
            fprintf(fp, "Subject %d   : %.2f\n",
                    j + 1, students[i].marks[j]);
        }

        fprintf(fp, "Total       : %.2f / 600\n",
                students[i].total);

        fprintf(fp, "Percentage  : %.2f%%\n",
                students[i].percentage);

        fprintf(fp, "Grade       : %c\n",
                students[i].grade);

        fprintf(fp, "Result      : %s\n",
                students[i].result);

        fprintf(fp, "=======================================\n");
    }

    fclose(fp);

    printf("\nMarksheets saved successfully in marksheets.txt!\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n\n===== STUDENT MARKSHEET GENERATOR =====\n");
        printf("1. Enter Student Details\n");
        printf("2. Generate All Marksheets\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Sort Students by Percentage\n");
        printf("5. Save Marksheets to File\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enterStudentDetails();
                break;

            case 2:
                for (int i = 0; i < count; i++) {
                    generateMarksheet(students[i]);
                }
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                sortStudents();
                break;

            case 5:
                saveMarksheet();
                break;

            case 6:
                printf("\nThank you!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
