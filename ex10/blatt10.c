#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3

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

void print_student(struct student *elem)
{
    printf("[%s %s]\n", elem->Vorname, elem->Nachname);
}

int main()
{
    struct student* root = NULL;

    // Erster Datensatz
    struct student* stud = malloc(sizeof(struct student));
    strcpy(stud->Vorname, "Anna");
    strcpy(stud->Nachname, "Musterfrau");
    stud->MatNr = 22222;
    strcpy(stud->Adresse, "Am Schwarzenberg-Campus 39");
    stud->Kurse = 4;
    stud->prev = root;
    root = stud;

    // Zweiter Datensatz
    stud = malloc(sizeof(struct student));
    strcpy(stud->Vorname, "Hans");
    strcpy(stud->Nachname, "Peter");
    stud->MatNr = 44444;
    strcpy(stud->Adresse, "Kasernenstrasse 12");
    stud->Kurse = 2;
    stud->prev = root;
    root->next = stud;
    root = stud;

    // Dritter Datensatz
    stud = malloc(sizeof(struct student));
    strcpy(stud->Vorname, "Lisa");
    strcpy(stud->Nachname, "Lustig");
    stud->MatNr = 66666;
    strcpy(stud->Adresse, "Denickestrasse 15");
    stud->Kurse = 8;
    stud->prev = root;
    root->next = stud;
    root = stud;

    while (root)
    {
        print_student(root);
        root = root->prev;
    }

  return 0;
}
