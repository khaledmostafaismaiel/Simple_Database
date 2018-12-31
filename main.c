//THIS PROGRAM IS A STUDENTS DATABASE
//I HAD FINSHED THIS PRIGRAM AS A PROJECT IN AMIT C PROGRAMMING COURSE
//THIS PROJRAM CONTAIN THE BASIC FUNCTION FOR ANY SOFTWARE DATABASE THAT CAN READ and INSERT ,DELETE ,SEARCH BY ID ,
//PRINT ALL DATABASE INFO AND READ INFORMATIONS FROM A SPACEFIC STUDENT
//AUTHOR : KHALED MOSTAFA
//IN 28/12/25018

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "HELPERFUNCS.c"
#include "SDB.c"
#include "LINKEDLIST.c"

int main()
{
    char input[10];
    uint8 choise = 0, year[1], subjects[3], grades[3], count[10], list[10];
    int checker;

    do
    {
        choise = menu();

        switch (choise)
        {
            uint8 id;

        case 1:

            switch (SDB_isFull())
            {
            case 1:

                puts("SDB Is Full");
                break;

            case 0:

                puts("SDB Is Not Full");
                break;
            }
            break;

        case 2:

            printf("The Used Size is %d.\n", SDB_GetUsedSize());
            break;

        case 3:

            ask_for_detail();
            break;

        case 4:

            do
            {
                puts("Enter The Student ID to Delete.");
                scanf("%s", input);
            } while ((id = Int_checker(input)) == tester);

            if (SDB_IsIdExist(id) == 1)
            {
                SDB_DeleteEntry(id);
                puts("Deleteing Succesfully.");
            }
            else
            {
                puts("The Student ID is Not in The Database.");
            }
            break;

        case 5:

            do
            {
                puts("Enter The Student ID.");
                scanf("%s", input);
            } while ((id = Int_checker(input)) == tester);

            checker = SDB_ReadEntry(id, year, subjects, grades);
            //printf("%d\n", checker);

            break;

        case 6:

            SDB_GetidList(count, list);
            break;

        case 7:

            do
            {
                puts("Enter The Student ID to Found.");
                scanf("%s", input);
            } while ((id = Int_checker(input)) == tester);

            switch (SDB_IsIdExist(id))
            {
            case 1:

                printf("The Student ID is in The Database.\n");
                break;

            case 0:

                printf("The Student ID is Not in The Database.\n");
                break;
            }
            break;

        case 8:

            print();
            break;
        }
    } while (choise != 9);

    menuIndentation(7);
    printf("Thanks AMIT's C Project Tester.\n");

    return 0;
}
