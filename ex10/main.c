#include <stdio.h>
#include <stdlib.h>

struct t_student
{
    char *first_name;
    char *last_name;
    int martikel_number;
    char *address;
    int required_courses;
    struct t_student *next;
};

int main()
{
    struct t_student *head;

    head = (struct t_student *)malloc(sizeof(struct t_student));

    head->first_name = "Anna";
    head->last_name = "Musterfrau";
    head->martikel_number = 22222;
    head->address = "Am Schwarzberger-Campus 3";
    head->required_courses = 4;

    head->next = (struct t_student *)malloc(sizeof(struct t_student));

    head->next->first_name = "Hans";
    head->next->last_name = "Peter";
    head->next->martikel_number = 44444;
    head->next->address = "Kasernenstrasse 12";
    head->next->required_courses = 2;

    head->next->next = (struct t_student *)malloc(sizeof(struct t_student));

    head->next->next->first_name = "Lisa";
    head->next->next->last_name = "Lustig";
    head->next->next->martikel_number = 66666;
    head->next->next->address = "Denickestrasse 15";
    head->next->next->required_courses = 8;

    head->next->next->next = NULL;

    /*
            for (int i = 0; i < 3; i++)
            {
                printf("First Name: %s\n", list_of_students[i].first_name);
                printf("Last Name: %s\n", list_of_students[i].last_name);
                printf("Martikel Number: %d\n",
           list_of_students[i].martikel_number); printf("Address: %s\n",
           list_of_students[i].address); printf("Required Courses: %d\n",
           list_of_students[i].required_courses); printf("\n");
            }
            */
    return 1;
}

