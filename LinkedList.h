/**************************************************************************/
/**************************************************************************/
/***************** Author: 	  Youssef Mohammed AbdelFattah ****************/
/***************** Topic :    Clinic Management System 	   ****************/
/***************** File: 	  LinkedList.h 			       ****************/
/***************** Date  :    Monday, 21/8/2023		       ****************/
/***************** Version:   1.0 						   ****************/
/**************************************************************************/
/**************************************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<stdbool.h>

struct node{
	int id;
	char name[40];
	int age;
	char gender[7];
	struct node  *prev , *next;
};
typedef struct node node;

// Structure to represent a time slot
struct slot {
	int id;
    char period[40];
    struct slot* prev;
    struct slot* next;
};
typedef struct slot slot;

/* Admin */
void InsertFirst(int id ,char name[40] ,int age ,char gender[7]);
int  GetSize();
void PrintFirstToLast();
int  SearchID(int id);
void DeleteList();
void EditName(int id ,char newName[40]);
void EditAge(int id ,int newAge);
void EditGender(int id ,char newGender[7]);
void InitializeSlots(slot** slots);
void DisplaySlots(slot* slots);
void ReserveSlot(slot* slots, int patientID, char period[40]);
void CancelReservation(slot* slots, int patientID);
/* User */
void PrintIDInformation(int id);
int  CheekTodayslots(slot *slots);
void PrintSlot(slot *slots);

#endif