#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef unsigned char uint8;

/*
 *Function: insert_node
 *
 * insert the student in the database linked list
 * 
 *uint8 id is the student id
 * uint8 year is the student year
 * uint8 *subject is pointer to the array that contain the 3 subjects IDs
 * uint8 *grades is pointer to the array that contain the 3 subject grades
 * 
 * return void
 */
void insert_node(uint8 id, uint8 year, uint8 *subjects, uint8 *grades);
/*
 *Function: SDB_AddEntry
 *
 *add anew entry to the database
 *
 * uint8 id is the student id
 * uint8 year is the student year
 * uint8 *subject is pointer to the array that contain the 3 subjects IDs
 * uint8 *grades is pointer to the array that contain the 3 subject grades
 * 
 * return 1 if the student succesfuly inserted
 * return 0 if the database full
 */
bool SDB_AddEntry(uint8 id, uint8 year, uint8 *subjects, uint8 *grades);
/**
 * Function: ask_for_detail
 * 
 * ask the user about the NEW_ENTRY student info
 * 
 * return void
*/
void ask_for_detail(void);

/*
 *Fnction: SBB_DeleterEntry
 *
 * delete the student with given id
 *
 * uint8 id is the id which will delete
 * 
 * return void
 */
void SDB_DeleteEntry(uint8 id);

#endif