#include <stdio.h>

struct t_student
{
    char *first_name;
    char *last_name;
    int martikel_number;
    char *address;
    int required_courses;
};

int main()
{
    struct t_student list_of_students[3];

    list_of_students[0].first_name = "Anna";
    list_of_students[0].last_name = "Musterfrau";
    list_of_students[0].martikel_number = 22222;
    list_of_students[0].address = "Am Schwarzberger-Campus 3";
    list_of_students[0].required_courses = 4;

    list_of_students[1].first_name = "Hans";
    list_of_students[1].last_name = "Peter";
    list_of_students[1].martikel_number = 44444;
    list_of_students[1].address = "Kasernenstrasse 12";
    list_of_students[1].required_courses = 2;

    list_of_students[2].first_name = "Lisa";
    list_of_students[2].last_name = "Lustig";
    list_of_students[2].martikel_number = 66666;
    list_of_students[2].address = "Denickestrasse 15";
    list_of_students[2].required_courses = 8;

    for (int i = 0; i < 3; i++)
    {
        printf("First Name: %s\n", list_of_students[i].first_name);
        printf("Last Name: %s\n", list_of_students[i].last_name);
        printf("Martikel Number: %d\n", list_of_students[i].martikel_number);
        printf("Address: %s\n", list_of_students[i].address);
        printf("Required Courses: %d\n", list_of_students[i].required_courses);
        printf("\n");
    }

    return 1;
}

