#include "LINKEDLIST.h"

void insert_node(uint8 id, uint8 year, uint8 *subjects, uint8 *grades)
{
    new->ID = id;
    new->Year = year;
    for (int i = 0; i < 3; ++i)
    {
        new->subjects_id[i] = *(subjects++);
        new->subjects_grade[i] = *(grades++);
    }
    new->next = NULL;
}

bool SDB_AddEntry(uint8 id, uint8 year, uint8 *subjects, uint8 *grades)
{

    new = (SimpleDb *)malloc(sizeof(SimpleDb));

    if (start == NULL)
    {

        insert_node(id, year, subjects, grades);
        start = new;
        current = start;
    }
    else
    {
        insert_node(id, year, subjects, grades);
        current->next = new;
        current = new;
    }

    ++SDB_counter;

    return true;
}

void ask_for_detail(void)
{
    if (SDB_isFull() == 1)
    {
        puts("SDB Is Full");
        return;
    }
    uint8 id;
    uint8 year;
    uint8 all_grade[3];
    uint8 all_sub[3];
    char scaner[10];

    do
    {
        printf("Enter The Student ID.\n");
        scanf("%s", scaner);

    } while ((id = Int_checker(scaner)) == tester);

    do
    {
        printf("Enter The Student Year.\n");
        scanf("%s", scaner);

    } while ((year = Int_checker(scaner)) == tester);

    do
    {
        printf("Enter The Student First Subject Id.\n");
        scanf("%s", scaner);
    } while ((all_sub[0] = Int_checker(scaner)) == tester);

    do
    {

        printf("Enter The Student First Grade.\n");
        scanf("%s", scaner);

    } while (((all_grade[0] = Int_checker(scaner)) == tester) || ((all_grade[0] < 0) || (all_grade[0] > 100)));

    do
    {
        printf("Enter The Student Second Subject Id.\n");
        scanf("%s", scaner);
    } while ((all_sub[1] = Int_checker(scaner)) == tester);

    do
    {

        printf("Enter The Student Second Grade.\n");
        scanf("%s", scaner);
    } while (((all_grade[1] = Int_checker(scaner)) == tester) || ((all_grade[1] < 0) || (all_grade[1] > 100)));

    do
    {
        printf("Enter The Student Third Subject Id.\n");
        scanf("%s", scaner);
    } while ((all_sub[2] = Int_checker(scaner)) == tester);

    do
    {

        printf("Enter The Student Third Grade.\n");
        scanf("%s", scaner);
    } while (((all_grade[2] = Int_checker(scaner)) == tester) || ((all_grade[2] < 0) || (all_grade[2] > 100)));
    SDB_AddEntry(id, year, all_sub, all_grade);
}

void SDB_DeleteEntry(uint8 id)
{
    if (start == NULL)
    {
        puts("There are no students in the database yet.");
    }
    SimpleDb *cursor = start;
    SimpleDb *previous;

    if (cursor->ID == id)
    {
        start = cursor->next;
        free(cursor);
        --SDB_counter;
        return;
    }

    while (cursor->ID != id)
    {
        previous = cursor;
        cursor = cursor->next;
    }

    previous->next = cursor->next;

    free(cursor);

    current = start;
    while (current->next != NULL)
    {
        current = current->next;
    }

    --SDB_counter;
}