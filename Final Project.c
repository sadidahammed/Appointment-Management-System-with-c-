#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char appointment[10][10][100] = {

        {"1234", "Adnan Mahmud", "19","skin","10:00 AM","4137"},
        {"1245", "Khairul Islam", "18","skin","10:30 AM","4137"},
        {"1256", "Limon Miah", "26","Breath","11:00 AM","7895"}
    };
char medicine[100][100][100]=  {
    {"Sadid Ahammed","1234","Baclofen", "Bleomycin","Bortezomib","Cefaclor","Cefixime"},
    {"Sabbir","1234","Dapsone", "Diclofenac","Erlotinib","Etoposide","Foscarnet"}
    };

char doctor[100][100][100]={{"4137","Sadid Ahammed","Male","1234"},
                            {"7895","Akash Ahammed","Male","1234"}
                            };

char patient[100][100][100]={{"1234","Adnan Mahmud","Male","1234"},
                            {"1245","Khairul Islam","Male","1234"},
                            {"1256","Khairul Islam","Limon Miah","1234"}

};

int main(){

printf("|-------------------------------------------------------|\n");
printf("|      Welcome to Appointment management system         |\n");
printf("|-------------------------------------------------------|\n");
printf("|                  1. Sign In                           |\n");
printf("|                  2. Sign Up                           |\n");
printf("|-------------------------------------------------------|\n");
int option;
printf("                Enter your choice: ");
scanf("%d", &option);
if(option == 1){
        system("cls");
   signIn();
}else if(option == 2){
    system("cls");
signUp();
}else{
    system("cls");
main_menu();
}
}

void signUp(){

printf("|-------------------------------------------------------|\n");
printf("|           Sign Up to Appointment Management           |\n");
printf("|-------------------------------------------------------|\n\n");
printf("Enter your name: ");
char name[20];
scanf("%s", name);

printf("Enter your gender: ");
char gender[20];
scanf("%s", gender);


printf("Chose your are Doctor/Patient: ");
char idType[20];
scanf("%s", idType);



printf("Enter your password: ");
char password[20];
scanf("%s", password);


char id[5];
generateNumber(id);
if (strcmp(idType, "Doctor") == 0) {
        for (int i = 0; i < 100; i++) {
            if (doctor[i][0][0] == '\0') {
                strcpy(doctor[i][0], id);
                strcpy(doctor[i][1], name);
                strcpy(doctor[i][2], gender);
                strcpy(doctor[i][3], password);
                system("cls");
                printf("\n\nYour account has been created.\nYour id is: %s. \nPlease remember this id.\n\n",id);
                doctor_menu(id);
                break;
            }
        }
    } else if (strcmp(idType, "Patient") == 0) {

        for (int i = 0; i < 100; i++) {
            if (patient[i][0][0] == '\0') {
                strcpy(patient[i][0], id);
                strcpy(patient[i][1], name);
                strcpy(patient[i][2], gender);
                strcpy(patient[i][3], password);
                system("cls");
                printf("\n\nYour account has been created.\nYour id is: %s. \nPlease remember this id.\n\n",id);
                patient_menu(id);
                break;
            }
        }
    } else {
        printf("\nPlease choose either 'Doctor' or 'Patient'.\n");
        system("cls");
        signUp();
    }
}

void signIn(){


printf("|-------------------------------------------------------|\n");
printf("|           Sign In to Appointment Management           |\n");
printf("|-------------------------------------------------------|\n\n");

printf("Enter your ID: ");
char id[20];
scanf("%s", id);

printf("Enter your password: ");
char password[20];
scanf("%s", password);

int n = strlen(doctor);
int m = strlen(patient);

    for (int i = 0; i < n; i++) {
        if (strcmp(id, doctor[i][0]) == 0) {
            if (strcmp(password, doctor[i][3]) == 0) {
                doctor_menu(id);
                return;
            } else {
                system("cls");
                printf("Password does not match. Try again.\n");
                signIn();
                return;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (strcmp(id, patient[i][0]) == 0) {
            if (strcmp(password, patient[i][3]) == 0) {
                patient_menu(id);
                return;
            } else {
                system("cls");
                printf("Password does not match. Try again.\n");
                signIn();
                return;
            }
        }
    }
    system("cls");
    printf("ID not found. Try again.\n");
    signIn();

}
void main_menu(){
printf("|-------------------------------------------------------|\n");
printf("|      Welcome to Appointment management system         |\n");
printf("|-------------------------------------------------------|\n");
printf("|                  1. Sign In                           |\n");
printf("|                  2. Sign Up                           |\n");
printf("|-------------------------------------------------------|\n");
int option;
printf("                Enter your choice: ");
scanf("%d", &option);
if(option == 1){
        system("cls");
   signIn();
}else if(option == 2){
    system("cls");
signUp();
}else{
    system("cls");
main_menu();
}
}

void patient_menu(const char *id){
printf("|-------------------------------------------------------|\n");
printf("|              Select what you want to do.              |\n");
printf("|-------------------------------------------------------|\n");
printf("|               1. Take Appointment                     |\n");
printf("|               2. Check Doctor Free Time               |\n");
printf("|               3. Medicine List                        |\n");
printf("|               4. Log Out                              |\n");
printf("|-------------------------------------------------------|\n");
int option;
printf("                Enter your chose: ");
scanf("%d", &option);
if(option == 1){
    system("cls");
    Take_Appointment(id);
}else if(option == 3){
    system("cls");
    Medicine_List(id);
}else if(option == 2){
    system("cls");
    Check_Doctor_Free_Time();
}else if (option == 4){
    system("cls");
    main_menu();
}
}

void Take_Appointment(const char *id) {
    printf("|-------------------------------------------------------|\n");
    printf("|                   Take Appointment.                   |\n");
    printf("|-------------------------------------------------------|\n\n");

    char Docid[10];
    printf("\nEnter doctor id: ");
    scanf("%9s", Docid); // Prevent buffer overflow

    int numRowsDoctor = 10; // Or the actual number of entries in the doctor array
    char name[20] = {0}; // Initialize the name array
    for (int i = 0; i < numRowsDoctor; i++) {
        if (strcmp(Docid, doctor[i][0]) == 0) {
            strcpy(name, doctor[i][1]);
            break; // Stop the loop once the doctor is found
        }
    }

    int numRowsPatient = 10; // Or the actual number of entries in the patient array
    char name1[20] = {0}; // Initialize the name1 array
    for (int i = 0; i < numRowsPatient; i++) {
        if (strcmp(id, patient[i][0]) == 0) {
            strcpy(name1, patient[i][1]);
            break; // Stop the loop once the patient is found
        }
    }
    printf("You are taking appointment of Dr. %s\n", name);

    printf("Enter your age: ");
    char age[3];
    scanf("%2s", age); // Prevent buffer overflow

    printf("Enter your problem, why you want to take appointment: ");
    char prblm[50];
    scanf(" %49[^\n]", prblm); // Read until newline

    int numRowsAppointment = 10; // Or the actual number of entries in the appointment array
    strcpy(appointment[numRowsAppointment][0], id);
    strcpy(appointment[numRowsAppointment][1], name1);
    strcpy(appointment[numRowsAppointment][2], age);
    strcpy(appointment[numRowsAppointment][3], prblm);
    strcpy(appointment[numRowsAppointment][4], "12:00 PM");
    strcpy(appointment[numRowsAppointment][5], Docid);

    printf("\nYour appointment is fixed at 12:00 PM");

    int option;
    printf("\nEnter any number to return. ");
    scanf("%d", &option);

    // Clear the screen based on the platform
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    patient_menu(id);
}

void Check_Doctor_Free_Time(const char *id1){
    printf("|-------------------------------------------------------|\n");
    printf("|              Check Doctor Free Time.                  |\n");
    printf("|-------------------------------------------------------|\n\n");


char id[10];
printf("\nEnter doctor id: ");
scanf("%s", id);

int numRows = strlen(doctor);
char name[20];
for (int i = 0; i < numRows-1; i++) {
    if (strcmp(id, doctor[i][0]) == 0) {
            strcpy(name, doctor[i][1]);
    }
}
int numRows1 = strlen(appointment);
printf("\nDoctor %s already taken appointment times are: \n\n", name);
printf("Launch break is 1:00 PM to 2:30 PM\n");
printf("Patient visit starts from 10 AM and End 4:00 PM\n");
for (int i = 0; i < numRows1-1; i++) {
    if (strcmp(id, appointment[i][5]) == 0) {
            printf("Time: %s\n", appointment[i][4]);
    }
}
int option;
printf("\nEnter any number to return. ");
    scanf("%d", &option);

    if(option == 0){
        system("cls");
        Check_Doctor_Free_Time(id1);
    }else{
        system("cls");
        patient_menu(id1);
    }

}

void Medicine_List(const char *id){

printf("|-------------------------------------------------------|\n");
printf("|                    Medicine List.                     |\n");
printf("|-------------------------------------------------------|\n\n");

    int cancelSuccess = 0, option, n;


    int medicineSize = strlen(medicine);

    for (int i = 0; i < medicineSize; i++) {

        if (strcmp(id, medicine[i][1]) == 0) {
            cancelSuccess = 1;

            printf("|-------------------------------------------------|\n");
            printf("|                    Medicine List                |\n");
            printf("|-------------------------------------------------|\n");
            printf("|     Doctor name: %s \n",medicine[i][0]);
            printf("|     Patient ID : %s \n\n",medicine[i][1]);
            n = findColumnsLength(medicine,0);
            for(int j = 2; j < n ; j++){
                printf("|     Medicine %d : %s\n",j-1,medicine[i][j]);
            }
            printf("|-------------------------------------------------|\n");
            }
    }
    if (!cancelSuccess) {
        printf("Your doctor doesn't give you any medicine.\n");
    }

    printf("\nEnter any number to return. ");
    scanf("%d", &option);

    if(option == 0){
        system("cls");
        doctor_menu(id);
    }else{
        system("cls");
        doctor_menu(id);
    }
}

int findColumnsLength(char array[100][100][100], int row) {
        int count = 0;
        while (strlen(array[row][count]) > 0) {
            count++;
        }
        return count;
}

void generateNumber(char *buffer) {

    int randomNum = (rand() % 9000) + 1000;
    sprintf(buffer, "%d", randomNum);
}

void doctor_menu(const char *id){

int numRows = strlen(doctor);
char name[20];
for (int i = 0; i < numRows-1; i++) {
    if (strcmp(id, doctor[i][0]) == 0) {
            strcpy(name, doctor[i][1]);
    }
}

printf("|-------------------------------------------------------|\n");
printf("|              Select what you want to do.              |\n");
printf("|-------------------------------------------------------|\n");
printf("|               1. Check Appointment List               |\n");
printf("|               2. Cancel Appointment                   |\n");
printf("|               3. Update Appointment Time              |\n");
printf("|               4. Medicine Recommendation              |\n");
printf("|               5. Log Out                              |\n");
printf("|-------------------------------------------------------|\n");

int option;
printf("                Enter your chose: ");
scanf("%d", &option);

if(option == 1){
    system("cls");
    appointment_List(id);
}else if(option == 2){
    system("cls");
    cancel_appointment(id);
}else if(option == 3){
    system("cls");
    update_appointment_time(id);
}else if(option == 4){
    system("cls");
    Medicine_Recommendation(name , id);
}else if(option == 0){
    system("cls");
    main();
}else if(option == 5){
    system("cls");
    main_menu();
}else{
    system("cls");
    printf("You chose the wrong option.\n\n");
    doctor_menu(id);
}}

void Medicine_Recommendation(const char *name, const char *id1){
printf("|-------------------------------------------------------|\n");
printf("|              Medicine Recommendation.                 |\n");
printf("|-------------------------------------------------------|\n\n");

    char id[10], medi[100];
    int cancelSuccess = 0, option, n;

    printf("Enter your patient ID: ");
    scanf("%9s", &id);

    int numRows = strlen(appointment);
    int medicineSize = strlen(medicine);


    for (int i = 0; i < numRows; i++) {

        if (strcmp(id, appointment[i][0]) == 0) {
            cancelSuccess = 1;
            printf("\nYour Patient Name is: %s\n", appointment[i][1]);
            printf("\nEnter how many medicines you want to give: ");
            scanf("%d", &n);

            strcpy(medicine[medicineSize][0], name);
            strcpy(medicine[medicineSize][1], id);

            for(int j = 2; j < n + 2; j++){
                printf("Enter medicine name %d: ", j - 1);
                scanf("%s", medi);
                strcpy(medicine[medicineSize][j], medi);
            }
            system("cls");
            printf("\n           Medicines recorded successfully.\n");
            break;
        }
    }
    if (!cancelSuccess) {
        printf("Patient ID not found.\n");
    }else{
    printf("|-------------------------------------------------|\n");
    printf("|         Updated Medicine Recommendations        |\n");
    printf("|-------------------------------------------------|\n");
    printf("|     Doctor name: %s: \n",medicine[medicineSize][0]);
    printf("|     Patient ID : %s: \n",medicine[medicineSize][1]);
        for(int j = 2; j < n + 2; j++){
            printf("|     Medicine %d : %s\n",j-1,medicine[medicineSize][j]);
        }
    printf("|-------------------------------------------------|\n");
    }
    printf("\nEnter any number to return. ");
    scanf("%d", &option);

    if(option == 0){
        system("cls");
        doctor_menu(id1);
    }else{
        system("cls");
        doctor_menu(id1);
    }
}

void cancel_appointment(const char *id1){
printf("|-------------------------------------------------------|\n");
printf("|                Cancel Appointment.                    |\n");
printf("|-------------------------------------------------------|\n\n");

char id[10];
int cancelSuccess = 0, option;
printf("Enter your patient ID: ");
scanf("%s", id);

int numRows = strlen(appointment);
for (int i = 0; i < numRows; i++) {
        if (strcmp(id, appointment[i][0]) == 0) {

            strcpy(appointment[i][4], "Cancel");
            system("cls");
            printf("\nAppointment cancel successful.\n\n");
            printf("|---------------------------------|\n");
            printf("|         Patient Information     |\n");
            printf("|---------------------------------|\n");

            printf("|  Patient ID: %s\n|  Appointment Time: %s\n|  Patient Age: %s\n|  Patient Name: %s\n|  Patient Problem: %s\n", appointment[i][0],appointment[i][4],appointment[i][2],appointment[i][1],appointment[i][3]);
            printf("|---------------------------------|\n");
            cancelSuccess = 1;
            break;
        }
    }
    if (!cancelSuccess) {
        printf("Patient ID not found.\n");
    }
    printf("\nEnter any number to return. ");
    scanf("%d", &option);

    if(option == 0){
        system("cls");
        doctor_menu(id1);
    }else{
        system("cls");
        doctor_menu(id1);
    }
}

void update_appointment_time(const char *id1){
printf("|-------------------------------------------------------|\n");
printf("|            Update Appointment Time.                   |\n");
printf("|-------------------------------------------------------|\n\n");

char id[10], newTime[10];
int updateSuccess = 0, option;
printf("Enter your patient ID: ");
scanf("%s", id);

int numRows = strlen(appointment);
for (int i = 0; i < numRows; i++) {
        if (strcmp(id, appointment[i][0]) == 0) {

            printf("Enter your update time: ");
            scanf("%s", newTime);

            strcpy(appointment[i][4], newTime);
            system("cls");
            printf("\nTime update successful.\n\n");
            printf("|---------------------------------|\n");
            printf("|         Patient Information     |\n");
            printf("|---------------------------------|\n");

            printf("|  Patient ID: %s\n|  Appointment Time: %s\n|  Patient Age: %s\n|  Patient Name: %s\n|  Patient Problem: %s\n",
                    appointment[i][0],appointment[i][4],appointment[i][2],appointment[i][1],appointment[i][3]);
            printf("|---------------------------------|\n");
            updateSuccess = 1;
            break;
        }
    }
    if (!updateSuccess) {
        printf("Patient ID not found.\n");
    }
    printf("\nEnter any number to return. ");
    scanf("%d", &option);

    if(option == 0){
        system("cls");
        doctor_menu(id1);
    }else{
        system("cls");
        doctor_menu(id1);
    }
}

void appointment_List(const char *id){
int numRows = strlen(appointment);
int option;
printf("|------------------------------------------------------------|\n");
printf("|                       Appointment List                     |\n");
printf("|------------------------------------------------------------|\n");
printf("| ID        Time        Age         Name             Problem |\n");
printf("|------------------------------------------------------------|\n");
    for (int i = 0; i < numRows-1; i++) {

        if (strcmp(id, appointment[i][5]) == 0) {
        printf("|%s     %s      %s      %s          %s", appointment[i][0],appointment[i][4],appointment[i][2],appointment[i][1],appointment[i][3]);
        printf("\n"); }
    }
    printf("|------------------------------------------------------------|\n");
    printf("\nEnter 0 to return. ");
    scanf("%d", &option);
    if(option == 0){
        system("cls");
        return doctor_menu(id);
    }else{
        system("cls");
        printf("You chose the wrong option.\n\n");
        appointment_List(id);
    }
}
