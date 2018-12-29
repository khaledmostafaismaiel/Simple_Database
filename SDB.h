#ifndef _SDB_H_
#define _SDB_H_

typedef unsigned char uint8;

/**
 *Function: SDB_isFull
 *
 * check if the database if full or ont
 * 
 * return 1 if the database is full
 * return 0 if the database not full
 **/
bool SDB_isFull(void);
/**
 * Function: SDB_GetUsedSize
 * 
 * Get the number of the entires from the database using a global uint8 counter
 * 
 * return the used size
*/
uint8 SDB_GetUsedSize(void);
/**
 *Function:  SDB_ReadEntry
 *
 * read an entry that match the provided ID
 * 
 *uint8 id is the student id
 * uint8 *year is pointer to the array that contain the database years
 * uint8 *subject is pointer to the array that contain the 3 subjects IDs
 * uint8 *grades is pointer to the array that contain the 3 subject grades
 * 
 * return 1 if the entry exist
 * return 0 if the entrt not exist
*/

bool SDB_ReadEntry(uint8 id, uint8 *year, uint8 *subjects, uint8 *grades);
/**
 *Function: SDB_GetidList
 *
 *get the list of the IDs of the student
 *
 * uint8 *count is pointer to counter that contain the database size
 * uint8 *list is pointer to the list of IDs
 * 
 * return void
*/
void SDB_GetidList(uint8 *count, uint8 *list);
/*
 * Function: SDB_IsIdExist
 * 
 * Check if the id is exist or not
 * 
 * return 1 if the id exist
 * return 0 if the id is not exist
*/
bool SDB_IsIdExist(uint8 id);

/**
 * Function : print
 * 
 * used to pring all database students information
 * 
 * return void 
*/
void print(void);

#endif