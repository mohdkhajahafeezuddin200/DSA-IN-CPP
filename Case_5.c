
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    int patient_id;
    char name[50];
    int age;
    char gender;
    char disease[50];
    char doctor[50];
    char department[30];
    char treatment[100];
};

struct Patient patients[MAX];
int count = 0;

// Function declarations
void registerPatient();
void displayPatients();
void searchPatient();
void assignDoctor();
void updatePatient();
void deletePatient();
void saveToFile();
void sortPatients();

// Find patient by ID
int findPatient(int id) {
    for (int i = 0; i < count; i++) {
        if (patients[i].patient_id == id)
            return i;
    }
    return -1;
}

// Register a new patient
void registerPatient() {
    if (count >= MAX) {
        printf("\nPatient records are full!\n");
        return;
    }

    struct Patient p;

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.patient_id);

    if (findPatient(p.patient_id) != -1) {
        printf("\nPatient ID already exists!\n");
        return;
    }

    printf("Enter Patient Name: ");
    scanf(" %49[^\n]", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    if (p.age < 0 || p.age > 120) {
        printf("\nInvalid age!\n");
        return;
    }

    printf("Enter Gender (M/F/O): ");
    scanf(" %c", &p.gender);

    printf("Enter Disease/Diagnosis: ");
    scanf(" %49[^\n]", p.disease);

    strcpy(p.doctor, "Not Assigned");
    strcpy(p.department, "Not Assigned");
    strcpy(p.treatment, "Not Recorded");

    patients[count++] = p;

    saveToFile();

    printf("\nPatient registered successfully!\n");
}

// Display all patients
void displayPatients() {
    if (count == 0) {
        printf("\nNo patient records available!\n");
        return;
    }

    printf("\n========== PATIENT RECORDS ==========\n");

    for (int i = 0; i < count; i++) {
        printf("\nPatient ID : %d", patients[i].patient_id);
        printf("\nName       : %s", patients[i].name);
        printf("\nAge        : %d", patients[i].age);
        printf("\nGender     : %c", patients[i].gender);
        printf("\nDiagnosis  : %s", patients[i].disease);
        printf("\nDoctor     : %s", patients[i].doctor);
        printf("\nDepartment : %s", patients[i].department);
        printf("\nTreatment  : %s\n", patients[i].treatment);
    }
}

// Search patient by ID or name
void searchPatient() {
    int choice, id, found = 0;
    char name[50];

    printf("\n1. Search by Patient ID");
    printf("\n2. Search by Patient Name");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Patient ID: ");
        scanf("%d", &id);

        int index = findPatient(id);

        if (index != -1) {
            int i = index;
            printf("\nPatient Found!\n");
            printf("ID: %d\nName: %s\nAge: %d\n",
                   patients[i].patient_id,
                   patients[i].name,
                   patients[i].age);
            printf("Diagnosis: %s\nDoctor: %s\nDepartment: %s\n",
                   patients[i].disease,
                   patients[i].doctor,
                   patients[i].department);
            printf("Treatment: %s\n", patients[i].treatment);
            found = 1;
        }
    }
    else if (choice == 2) {
        printf("Enter Patient Name: ");
        scanf(" %49[^\n]", name);

        for (int i = 0; i < count; i++) {
            if (strcmp(patients[i].name, name) == 0) {
                printf("\nPatient Found!\n");
                printf("ID: %d\nName: %s\nAge: %d\n",
                       patients[i].patient_id,
                       patients[i].name,
                       patients[i].age);
                printf("Diagnosis: %s\nDoctor: %s\nDepartment: %s\n",
                       patients[i].disease,
                       patients[i].doctor,
                       patients[i].department);
                printf("Treatment: %s\n", patients[i].treatment);
                found = 1;
            }
        }
    }
    else {
        printf("\nInvalid choice!\n");
        return;
    }

    if (!found)
        printf("\nPatient not found!\n");
}

// Assign doctor and department
void assignDoctor() {
    int id, index;

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);

    index = findPatient(id);

    if (index == -1) {
        printf("\nPatient not found!\n");
        return;
    }

    printf("Enter Doctor Name: ");
    scanf(" %49[^\n]", patients[index].doctor);

    printf("Enter Department: ");
    scanf(" %29[^\n]", patients[index].department);

    saveToFile();

    printf("\nDoctor assigned successfully!\n");
}

// Update diagnosis and treatment
void updatePatient() {
    int id, index;

    printf("\nEnter Patient ID: ");
    scanf("%d", &id);

    index = findPatient(id);

    if (index == -1) {
        printf("\nPatient not found!\n");
        return;
    }

    printf("Enter Updated Diagnosis: ");
    scanf(" %49[^\n]", patients[index].disease);

    printf("Enter Treatment Details: ");
    scanf(" %99[^\n]", patients[index].treatment);

    saveToFile();

    printf("\nPatient record updated successfully!\n");
}

// Delete patient record
void deletePatient() {
    int id, index;

    printf("\nEnter Patient ID to delete: ");
    scanf("%d", &id);

    index = findPatient(id);

    if (index == -1) {
        printf("\nPatient not found!\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        patients[i] = patients[i + 1];
    }

    count--;

    saveToFile();

    printf("\nPatient record deleted successfully!\n");
}

// Sort patients
void sortPatients() {
    int choice;
    struct Patient temp;

    printf("\n1. Sort by Name");
    printf("\n2. Sort by Age");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("\nInvalid choice!\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int swap = 0;

            if (choice == 1 &&
                strcmp(patients[j].name,
                       patients[j + 1].name) > 0) {
                swap = 1;
            }

            if (choice == 2 &&
                patients[j].age > patients[j + 1].age) {
                swap = 1;
            }

            if (swap) {
                temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }

    saveToFile();

    printf("\nPatients sorted successfully!\n");
    displayPatients();
}

// Save records to binary file
void saveToFile() {
    FILE *fp = fopen("patients.dat", "wb");

    if (fp == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(patients, sizeof(struct Patient), count, fp);

    fclose(fp);
}

// Load records from binary file
void loadFromFile() {
    FILE *fp = fopen("patients.dat", "rb");

    if (fp == NULL)
        return;

    if (fread(&count, sizeof(int), 1, fp) != 1 ||
        count < 0 || count > MAX) {
        count = 0;
        fclose(fp);
        return;
    }

    if (fread(patients, sizeof(struct Patient), count, fp)
        != (size_t)count) {
        count = 0;
    }

    fclose(fp);
}

// Main function
int main() {
    int choice;

    loadFromFile();

    do {
        printf("\n\n===== HOSPITAL PATIENT RECORD SYSTEM =====\n");
        printf("1. Register Patient\n");
        printf("2. Display Patients\n");
        printf("3. Search Patient\n");
        printf("4. Assign Doctor\n");
        printf("5. Update Patient\n");
        printf("6. Delete Patient\n");
        printf("7. Sort Patients\n");
        printf("8. Save Records\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerPatient();
                break;

            case 2:
                displayPatients();
                break;

            case 3:
                searchPatient();
                break;

            case 4:
                assignDoctor();
                break;

            case 5:
                updatePatient();
                break;

            case 6:
                deletePatient();
                break;

            case 7:
                sortPatients();
                break;

            case 8:
                saveToFile();
                printf("\nRecords saved successfully!\n");
                break;

            case 9:
                saveToFile();
                printf("\nExiting system. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 9);

    return 0;
}
