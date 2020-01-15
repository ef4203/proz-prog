#include <stdio.h>

typedef struct t_student
{
    char *first_name;
    char *last_name;
    int martikel_number;
    char *address;
    int required_courses;
} student;

void print_student(student s)
{
    printf("First Name: %s\n", s.first_name);
    printf("Last Name: %s\n", s.last_name);
    printf("Martikel Number: %d\n", s.martikel_number);
    printf("Address: %s\n", s.address);
    printf("Required Courses: %d\n", s.required_courses);
    printf("\n");
}

int main()
{
    student students[3];
    student anna = {"Anna", "Musterfrau", 22222, "Am Schwarzberg-Campus 3", 4};
    student hans = {"Hans", "Peter", 44444, "Kasernenstrasse 12", 2};
    student lisa = {"Lisa", "Lustig", 66666, "Denickestrasse 15", 8};
    students[0] = anna;
    students[1] = hans;
    students[2] = lisa;

    for (int i = 0; i < 3; i++)
    {
        print_student(students[i]);
    }

    printf("------------------------\n");

    student temp;
    temp = students[0];
    students[0] = students[2];
    students[2] = temp;

    for (int i = 0; i < 3; i++)
    {
        print_student(students[i]);
    }

    return 1;
}

