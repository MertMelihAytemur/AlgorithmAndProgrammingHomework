/*
 * This program sets up the internship information about SE and CS students.
 * Firstly, user enter a specific file name for student internship information without spaces. Ex :  mertmelihaytemur,asafvarol etc.
 * Program automatically add .txt extension to you file name to create a text file.
 * After that, user enters information about student and company.
 * When all information filled, program saved these infos into the text file that user set up at first.
 * At the end, program asks if user would like to read entered information. ->
 * The program flow continues according to the answer chosen by the user.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date {
    int da_day,
            da_mon,
            da_year;
};
struct InternInfo {
    int student_id;
    char                                //Student Informations
    student_name_and_surname[50],
            student_cellphone_number[20],
            student_email[100],
            student_home_address[100],
            student_city[10];
    char                                //Company Informations
    company_name[50],
            company_full_address[100],
            company_city_district[20],
            company_phone_number[20],
            company_email[100];
    struct Date intern_beginning_date;
    struct Date intern_ending_date;
    int intern_total_work_day;
};

void setInternInformation(char file_name[]);

void saveInternInformation(struct InternInfo intern_info, char file_name[]);

void getInternInformation(char file_name[]);

int main() {
    char file_name[100];
    char stay_or_exit = 'y';
    while (stay_or_exit == 'y') {
        printf("\nChoose a file name without spaces('E' for exit.) : ");
        scanf("%s", file_name);
        getchar();

        if(strcmp(file_name,"E") == 0){
            printf("PROGRAM WAS ENDED.");
            exit(1);
        }

        strcat(file_name, ".txt");
        setInternInformation(file_name);

        printf("\nWould you like to read your file ? (y/n)");
        scanf("%c", &stay_or_exit);
        switch (stay_or_exit) {
            case 'y' :
                getInternInformation(file_name);
                break;
            case 'n':
                printf("PROGRAM WAS ENDED.");
                exit(1);
        }
    }
    return 0;
}

void setInternInformation(char file_name[]) {
    struct InternInfo intern_info;
    printf("*****Enter Student Information*****\n");

    printf("Enter student id : ");
    scanf("%d", &intern_info.student_id);
    getchar();

    printf("\nEnter student name and surname : ");
    fgets(intern_info.student_name_and_surname, sizeof(intern_info.student_name_and_surname), stdin);

    printf("\nEnter student cellphone number : ");
    fgets(intern_info.student_cellphone_number, sizeof(intern_info.student_cellphone_number), stdin);

    printf("\nEnter student email : ");
    fgets(intern_info.student_email, sizeof(intern_info.student_email), stdin);

    printf("\nEnter student home address : ");
    fgets(intern_info.student_home_address, sizeof(intern_info.student_home_address), stdin);

    printf("\nEnter student city : ");
    fgets(intern_info.student_city, sizeof(intern_info.student_city), stdin);

    printf("\n*****Enter Company Information*****");

    printf("\nEnter company name : ");
    fgets(intern_info.company_name, sizeof(intern_info.company_name), stdin);

    printf("\nEnter company full address : ");
    fgets(intern_info.company_full_address, sizeof(intern_info.company_full_address), stdin);

    printf("\nEnter company city/district : ");
    fgets(intern_info.company_city_district, sizeof(intern_info.company_city_district), stdin);

    printf("\nEnter company phone number : ");
    fgets(intern_info.company_phone_number, sizeof(intern_info.company_phone_number), stdin);

    printf("\nEnter company email : ");
    fgets(intern_info.company_email, sizeof(intern_info.company_email), stdin);

    printf("\nEnter intern beginning date(like 11 11 2021) : ");  // input should be like 01 01 2021
    scanf("%d %d %d", &intern_info.intern_beginning_date.da_day,
          &intern_info.intern_beginning_date.da_mon,
          &intern_info.intern_beginning_date.da_year);
    getchar();

    printf("\nEnter intern ending date(like 11 11 2021) : ");
    scanf("%d %d %d", &intern_info.intern_ending_date.da_day,
          &intern_info.intern_ending_date.da_mon,
          &intern_info.intern_ending_date.da_year);
    getchar();

    printf("\nEnter intern total work day : ");
    scanf("%d", &intern_info.intern_total_work_day);
    getchar();

    saveInternInformation(intern_info, file_name);
}

void saveInternInformation(struct InternInfo intern_info, char file_name[]) {
    FILE *file_pointer;
    printf("\nFile name is : %s\n", file_name);
    file_pointer = fopen(file_name, "w");
    if (file_pointer == NULL) {
        fprintf(stderr, "\nError to open the file saveStudentInfo()\n");
        exit(1);
    }
    fprintf(file_pointer, "Student id : %d\n"
                          "Student name and surname :%s"
                          "Student phone number : %s"
                          "Student email : %s"
                          "Student home address : %s"
                          "Student city : %s"
                          "Company name : %s"
                          "Company full address : %s"
                          "Company city/district : %s"
                          "Company phone number : %s"
                          "Company email : %s"
                          "Intern beginning date : %d/%d/%d\n"
                          "Intern ending date : %d/%d/%d\n"
                          "Intern total work day : %d\n",intern_info.student_id,
            intern_info.student_name_and_surname,
            intern_info.student_cellphone_number,
            intern_info.student_email,
            intern_info.student_home_address,
            intern_info.student_city,
            intern_info.company_name,
            intern_info.company_full_address,
            intern_info.company_city_district,
            intern_info.company_phone_number,
            intern_info.company_email,
            intern_info.intern_beginning_date.da_day, intern_info.intern_beginning_date.da_mon,
            intern_info.intern_beginning_date.da_year,
            intern_info.intern_ending_date.da_day, intern_info.intern_ending_date.da_mon,
            intern_info.intern_ending_date.da_year,
            intern_info.intern_total_work_day);

    printf("Contents to file written successfully !\n");
    fclose(file_pointer);
}

void getInternInformation(char file_name[]) {
    printf("\n**********INTERN INFORMATION**********\n");
    char ch;
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");
    if (file_pointer == NULL) {
        printf("%s file failed to open.", file_name);
    } else
        printf("%s File opened successfully.\n", file_name);

    while ((ch = fgetc(file_pointer)) != EOF) {
        printf("%c", ch);
    }
    fclose(file_pointer);
}
