#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

/* Student struct. */
struct student
{
    char Vorname[51];
    char Nachname[51];
    int MatNr;
    char Adresse[51];
    int Kurse;
    struct student *prev;
    struct student *next;
};

/* Prints a students element. */
void print_konsole(struct student *elem)
{
    printf("Vorname: %s\n", elem->Vorname);
    printf("Nachname: %s\n", elem->Nachname);
    printf("Mat-Nr.: %d\n", elem->MatNr);
    printf("Adresse: %s\n", elem->Adresse);
    printf("belegte Kurse: %d\n\n", elem->Kurse);
}

/* Deletes the element "elem" from a double linked list
 * and returns the head of the list. */
struct student *delete (struct student *start, struct student *elem)
{
    if (elem == start)
    {
        elem->next->prev = NULL;
        start = elem->next;
    }
    else if (elem->next == NULL)
    {
        elem->prev->next = NULL;
    }
    else
    {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
    }

    /* Prevent memory leak, by actually deleting. */
    free(elem);

    return start;
}

/* Returns the head of a double linked list, but reversed. */
struct student *reverse_list(struct student *list)
{
    struct student *tmp = NULL;
    while (list != NULL)
    {
        list->prev = list->next;
        list->next = tmp;
        tmp = list;
        list = list->prev;
    }
    return tmp;
}

struct student *swap_elements(struct student *list, struct student *a,
                              struct student *b)
{
    // TODO: Actually implement this.
}

struct student *sort_list(struct student *list)
{
    // TODO: Actually implement this.
}

int main()
{
    /* First element of the list. */
    struct student *studenten = NULL;

    /* Null pointer. */
    struct student *stud = NULL;

    // Erster Datensatz
    studenten = (struct student *)malloc(sizeof(struct student));
    stud = studenten;
    strcpy(stud->Vorname, "Anna");
    strcpy(stud->Nachname, "Musterfrau");
    stud->MatNr = 22222;
    strcpy(stud->Adresse, "Am Schwarzenberg-Campus 39");
    stud->Kurse = 4;
    stud->prev = NULL; // Listenanfang
    stud->next = (struct student *)malloc(sizeof(struct student));
    stud->next->prev = stud; // Mache Vorgaenger bekannt
    stud = stud->next;

    // Zweiter Datensatz
    strcpy(stud->Vorname, "Hans");
    strcpy(stud->Nachname, "Peter");
    stud->MatNr = 44444;
    strcpy(stud->Adresse, "Kasernenstrasse 12");
    stud->Kurse = 2;
    stud->next = (struct student *)malloc(sizeof(struct student));
    stud->next->prev = stud;
    stud = stud->next;

    // Dritter Datensatz
    strcpy(stud->Vorname, "Lisa");
    strcpy(stud->Nachname, "Lustig");
    stud->MatNr = 66666;
    strcpy(stud->Adresse, "Denickestrasse 15");
    stud->Kurse = 8;
    stud->next = (struct student *)malloc(sizeof(struct student));
    stud->next->prev = stud;
    stud = stud->next;

    // Vierter Datensatz
    strcpy(stud->Vorname, "Gabriele");
    strcpy(stud->Nachname, "Koenig");
    stud->MatNr = 12345;
    strcpy(stud->Adresse, "Waldstrasse 32");
    stud->Kurse = 3;
    stud->next = (struct student *)malloc(sizeof(struct student));
    stud->next->prev = stud;
    stud = stud->next;

    // Fuenfter Datensatz
    strcpy(stud->Vorname, "Otto");
    strcpy(stud->Nachname, "Mayer");
    stud->MatNr = 21545;
    strcpy(stud->Adresse, "Bahnhofstrasse 4");
    stud->Kurse = 5;
    stud->next = NULL; // Listenende

    // Gebe Datensaetze in der Konsole aus
    for (stud = studenten; stud != NULL; stud = stud->next)
    {
        print_konsole(stud);
    }

    // Loesche drittes Element (Lisa)
    studenten = delete (studenten, studenten->next->next);

    // Gebe Datensaetze in der Konsole aus
    printf("\n-------------------\n\n");
    for (stud = studenten; stud != NULL; stud = stud->next)
    {
        print_konsole(stud);
    }

    // Drehe Liste um
    studenten = reverse_list(studenten);

    // Gebe Datensaetze in der Konsole aus
    printf("\n-------------------\n\n");
    for (stud = studenten; stud != NULL; stud = stud->next)
    {
        print_konsole(stud);
    }

    return 0;
}
