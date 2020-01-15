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

    students[0].first_name = "Anna";
    students[0].last_name = "Musterfrau";
    students[0].martikel_number = 22222;
    students[0].address = "Am Schwarzberger-Campus 3";
    students[0].required_courses = 4;

    students[1].first_name = "Hans";
    students[1].last_name = "Peter";
    students[1].martikel_number = 44444;
    students[1].address = "Kasernenstrasse 12";
    students[1].required_courses = 2;

    students[2].first_name = "Lisa";
    students[2].last_name = "Lustig";
    students[2].martikel_number = 66666;
    students[2].address = "Denickestrasse 15";
    students[2].required_courses = 8;

    for (int i = 0; i < 3; i++)
    {
        print_student(students[i]);
    }

    printf("------------------------\n");

    student temp;

    temp.first_name = students[0].first_name;
    temp.last_name = students[0].last_name;
    temp.martikel_number = students[0].martikel_number;
    temp.address = students[0].address;
    temp.required_courses = students[0].required_courses;

    students[0].first_name = students[2].first_name;
    students[0].last_name = students[2].last_name;
    students[0].martikel_number = students[2].martikel_number;
    students[0].address = students[2].address;
    students[0].required_courses = students[2].required_courses;
    students[2].first_name = temp.first_name;
    students[2].last_name = temp.last_name;
    students[2].martikel_number = temp.martikel_number;
    students[2].address = temp.address;
    students[2].required_courses = temp.required_courses;

    for (int i = 0; i < 3; i++)
    {
        print_student(students[i]);
    }

    return 1;
}

