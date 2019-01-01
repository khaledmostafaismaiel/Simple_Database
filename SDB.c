#include "SDB.h"

bool SDB_isFull(void)
{
    if (start == NULL)
    {
        puts("There are no students in the database yet.");
    }
    if (SDB_counter == MAX_SIZE)
    {
        return true;
    }
    return false;
}
uint8 SDB_GetUsedSize(void)
{
    if (start == NULL)
    {
        puts("There are no students in the database yet.");
    }
    return SDB_counter;
}

bool SDB_ReadEntry(uint8 id, uint8 *year, uint8 *subjects, uint8 *grades)
{
    if (start == NULL)
    {
        return false;
    }
    SimpleDb *cursor = start;
    while (cursor != NULL)
    {
        if (cursor->ID == id)
        {
            year = &cursor->Year;
            subjects = cursor->subjects_id;
            grades = cursor->subjects_grade;
            /*
                printf("ID is %d\n", id);
                printf("Year is %d\n", year[0]);
                puts("subjects IDs: ");
                printf("1st %d, 2nd %d, 3rd %d\n", subjects[0], subjects[1], subjects[2]);
                puts("subjects Grades: ");
                printf("1st %d, 2nd %d, 3rd %d\n", grades[0], grades[1], grades[2]);
            */
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}
void SDB_GetidList(uint8 *count, uint8 *list)
{
    if (start == NULL)
    {
        puts("There are no students in the database yet.");
    }
    count = &SDB_counter;

    uint8 idlist[10];
    SimpleDb *cursor = start;
    for (uint8 i = 0; i < SDB_counter; ++i)
    {
        idlist[i] = cursor->ID;
        cursor = cursor->next;
        //printf("%d\n", i);
    }

    list = idlist;
}
bool SDB_IsIdExist(uint8 id)
{
    if (start == NULL)
    {
        puts("There are no students in the database yet.");
    }
    struct SimpleDb *cursor = start;
    while (cursor != NULL)
    {
        if (cursor->ID == id)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}
