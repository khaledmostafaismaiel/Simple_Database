#ifndef _HELPERFUNCS_H_
#define _HELPERFUNCS_H_


typedef unsigned char uint8;
/**
 * Struct SimpleDB
 * 
 * is structure for students database that contain
 * uint8 ID
 * uint8 Year
 * uint8 subjects_id[3] that hold the 3 subjects IDs
 *uint8 subjects_grade[3] that hold 3 the subject grades
*/
typedef struct SimpleDb
{
    uint8 ID;
    uint8 Year;
    uint8 subjects_id[3];
    uint8 subjects_grade[3];

    struct SimpleDb *next;
} SimpleDb;

SimpleDb *start = NULL;
SimpleDb *new = NULL;
SimpleDb *current = NULL;
SimpleDb *prev = NULL;

uint8 SDB_counter = 0;

/**
 * Function: menuIndentation
 * 
 * used for indentation the menu
 * 
 * return void
*/
void menuIndentation(int);
/**
 * Function: menu
 * 
 * ask user for select a statment
 * 
 * return void
*/
uint8 menu(void);
/**
 *Function: Int_checker
 * 
 *check every char in the string and compare it with alph bet letters
 *
 * char string[] is the var which will be checked
 * 
 * return 0 if the string not pure int      // 0114_KHALED_3325016
 * return 1 if the string is pure int       // 01143325016
*/
uint8 Int_checker(char string[]);

/**
 * Function: stringToint
 * 
 * convert the string to int
 * 
 * char string[] is the array of chars that will convert into int num
 * 
 * return the number after convertion
*/
uint8 stringToint(char string[]);

#endif