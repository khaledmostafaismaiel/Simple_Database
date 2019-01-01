#include "HELPERFUNCS.h"
#define MAX_SIZE 10
uint8 tester = -1;

void menuIndentation(int num)
{
    for (int i = 0; i < num; ++i)
    {
        printf("\t");
    }
}

uint8 stringToint(char string[])
{
    uint8 intnum;
    int num;
    sscanf(string, "%d", &num);
    if ((num >= 0) && (num <= 255))
    {
        intnum = num;
        return intnum;
    }
    puts("Your integer numbers range is (0<= num >=255).");

    return -1;
}

uint8 Int_checker(char string[])
{
    for (int i = 0; string[i] != '\0';)
    {
        if ((string[i] >= '0') && (string[i] <= '9'))
        {
            ++i;
        }
        else
        {
            puts("Enter integer numbers only.");
            return -1;
        }
    }

    return stringToint(string);
}

uint8 menu(void)
{
    char choise[10];
    uint8 int_choise;
    do
    {
        menuIndentation(7);
        printf("Dear AMIT's C Project Tester.\n");
        menuIndentation(5);
        printf("1 / SDB_IsFull.\n");
        menuIndentation(5);
        printf("2 / SDB_GetUsedSize.\n");
        menuIndentation(5);
        printf("3 / SDB_AddEntry.\n");
        menuIndentation(5);
        printf("4 / SDB_DeleteEntry.\n");
        menuIndentation(5);
        printf("5 / SDB_READEntry.\n");
        menuIndentation(5);
        printf("6 / SDB_GetIdList.\n");
        menuIndentation(5);
        printf("7 / SDB_IsIdExist.\n");
        menuIndentation(5);
        printf("8 / PRint.\n");
        menuIndentation(5);
        printf("9 / Exist.\n");

        scanf("%s", choise);

        int_choise = Int_checker(choise);

    } while ((int_choise < 0) || (int_choise > 9));

    return int_choise;
}

void print(void)
{
    SimpleDb *cursor = start;
    puts("ID\tYEAr Subject1ID Subject2ID Subject3ID Grade1 Grade2 Grade3.");
    while (cursor != NULL)
    {
        printf("%hhu\t%hhu\t%hhu\t%hhu\t%hhu\t%hhu\t%hhu\t%hhu\t\n", cursor->ID, cursor->Year, cursor->subjects_id[0], cursor->subjects_id[1], cursor->subjects_id[2], cursor->subjects_grade[0], cursor->subjects_grade[1], cursor->subjects_grade[2]);
        cursor = cursor->next;
    }
}