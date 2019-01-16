#include <stdio.h>
#include <stdlib.h>

struct t_student
{
    char *first_name;
    char *last_name;
    int martikel_number;
    char *address;
    int required_courses;
    struct t_student *prev;
    struct t_student *next;
};

void swap(struct t_student *a, struct t_student *b)
{
    struct t_student *tmp;
    tmp = (struct t_student *)malloc(sizeof(struct t_student));
    *tmp = *b;

    b->first_name = a->first_name;
    b->last_name = a->last_name;
    b->martikel_number = a->martikel_number;
    b->address = a->address;
    b->required_courses = a->required_courses;

    a->first_name = tmp->first_name;
    a->last_name = tmp->last_name;
    a->martikel_number = tmp->martikel_number;
    a->address = tmp->address;
    a->required_courses = tmp->required_courses;

    /*b->prev = a->prev;
    b->prev->next = a;
    b->next = a->next;
    b->next->prev = a;

    a->prev = tmp->prev;
    a->prev->next = tmp;
    a->next = tmp->next;
    a->next->prev = tmp;*/
}

void print_linked_list(struct t_student *l)
{
    struct t_student *a = l;

    while (a != NULL)
    {
        printf("%s ", a->first_name);
        printf("%s \n", a->last_name);
        a = a->next;
    }
}

int list_count(struct t_student *l)
{
    struct t_student *a = l;

    int i = 0;
    while (a != NULL)
    {
        i++;
        a = a->next;
    }

    return i;
}
int main()
{
    struct t_student *head;

    head = (struct t_student *)malloc(sizeof(struct t_student));

    head->first_name = "Anna";
    head->last_name = "Musterfrau";
    head->martikel_number = 22222;
    head->address = "Am Schwarzberger-Campus 3";
    head->required_courses = 4;

    head->prev = NULL;
    head->next = (struct t_student *)malloc(sizeof(struct t_student));

    head->next->first_name = "Hans";
    head->next->last_name = "Peter";
    head->next->martikel_number = 44444;
    head->next->address = "Kasernenstrasse 12";
    head->next->required_courses = 2;

    head->next->prev = head;
    head->next->next = (struct t_student *)malloc(sizeof(struct t_student));

    head->next->next->first_name = "Lisa";
    head->next->next->last_name = "Lustig";
    head->next->next->martikel_number = 66666;
    head->next->next->address = "Denickestrasse 15";
    head->next->next->required_courses = 8;

    head->next->next->prev = head->next;
    head->next->next->next = NULL;

    print_linked_list(head);

    printf("--------------\n");

    swap(head->next, head->next->next);

    print_linked_list(head);

    return 1;
}

