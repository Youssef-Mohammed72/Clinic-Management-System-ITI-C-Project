/**************************************************************************/
/**************************************************************************/
/***************** Author: 	  Youssef Mohammed AbdelFattah ****************/
/***************** Topic :    Clinic Management System 	   ****************/
/***************** File: 	  LinkedList.c 			       ****************/
/***************** Date  :    Monday, 21/8/2023		       ****************/
/***************** Version:   1.0 						   ****************/
/**************************************************************************/
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LinkedList.h"

extern node  *first, *last;
extern slot  *prev , *next;

void InsertFirst(int id ,char name[40] ,int age ,char gender[7]){
	node *temp = (node *)malloc(sizeof(node));
	temp->id = id;
	strcpy(temp->name, name);
	temp->age = age;
	strcpy(temp->gender, gender);
	temp->prev = NULL;
	temp->next = first;
	if(first != NULL){
		first->prev = temp;
	}
	first = temp;
	if(last == NULL){
		last = temp;
	}
}
	
void InsertLast(int id ,char name[40] ,int age ,char gender[7]){
	if(first == NULL){
        InsertFirst(id ,name ,age ,gender);
        return;
    }
	node *temp = (node *)malloc(sizeof(node));
	temp->id = id;
	strcpy(temp->name, name);
	temp->age = age;
	strcpy(temp->gender, gender);
	temp->prev = last;
	temp->next = NULL;
	last->next = temp;
	last = temp;
}

int GetSize(){
	node *temp;
	int counter = 0 ;
	for(temp = first ; temp != NULL ; temp = temp->next)
		counter++;
	return counter ;
}

int SearchID(int id){
	node *temp;
	int k , size , index;
	size = GetSize();
	temp = first;
	index = -1 ;
	k = 1;
	for(temp = first ; temp != NULL ; temp = temp->next){
		if(temp->id == id){
            index = k;
            break;
        }
		else{
			k++;
		}    
	}
	if(index == -1){
		//printf("ID: %d couldn't be found\n", ID);
        return -1;
    }
	else{
		//printf("ID: %d is found at index: %d", ID ,index);
        return index ;
    }
}

void PrintFirstToLast(){
	node *temp;
	for(temp = first ; temp != NULL ; temp = temp->next){
		printf("ID: %d\n", temp->id);
		printf("Name: %s\n", temp->name);
		printf("Age: %d\n", temp->age);
		printf("gender: %s\n", temp->gender);
	}
}

void DeleteList(){
	node *temp;
	for(temp = first ; temp != NULL ; temp = temp->next){
		first = temp->next;
		free(temp);
	}
}
void EditName(int id ,char newName[40]){
	node *temp;
	temp = first;
	for(temp = first ; temp != NULL ; temp = temp->next){
		if(temp->id == id){
			strcpy(temp->name, newName);
            break;
        } 
	}
}

void EditAge(int id ,int newAge){
	node *temp;
	temp = first;
	for(temp = first ; temp != NULL ; temp = temp->next){
		if(temp->id == id){
			temp->age = newAge;
            break;
        } 
	}
}

void EditGender(int id ,char newGender[7]){
	node *temp;
	temp = first;
	for(temp = first ; temp != NULL ; temp = temp->next){
		if(temp->id == id){
			strcpy(temp->gender, newGender);
            break;
        } 
	}
}

void InitializeSlots(slot** slots){
    slot* slot1 = (slot*)malloc(sizeof(slot));
    slot* slot2 = (slot*)malloc(sizeof(slot));
    slot* slot3 = (slot*)malloc(sizeof(slot));
    slot* slot4 = (slot*)malloc(sizeof(slot));
    slot* slot5 = (slot*)malloc(sizeof(slot));
	
	slot1->id = 0;
	strcpy(slot1->period ,"2pm to 2:30pm");
    slot1->prev = NULL;
    slot1->next = slot2;

	slot2->id = 0;
	strcpy(slot2->period ,"2:30pm to 3pm");
    slot2->prev = slot1;
    slot2->next = slot3;

	slot3->id = 0;
    strcpy(slot3->period ,"3pm to 3:30pm");
    slot3->prev = slot2;
    slot3->next = slot4;

	slot4->id = 0;
    strcpy(slot4->period ,"4pm to 4:30pm");
    slot4->prev = slot3;
    slot4->next = slot5;

	slot5->id = 0;
    strcpy(slot5->period ,"4:30pm to 5pm");
    slot5->prev = slot4;
    slot5->next = NULL;

    *slots = slot1;
}

void DisplaySlots(slot* slots){
    slot* current = slots;
    while (current != NULL) {
		if(current->id == 0){
			printf("\t\t\t\t%s\n", current->period);
		}
		else{
		}
        current = current->next;
    }
}

void ReserveSlot(slot* slots, int patientID, char period[40]){
    slot* current = slots;
    while (current != NULL){
        if(strcmp(current->period ,period) == 0) {
            // Reserve the slot
			current->id = patientID;
            printf("\n\t\t   Your Reserved slot: %s has been enrolled successfully..!\n", current->period);
			printf("\n\t**************************************************************************************\n\n");
			return;
        }
        current = current->next;
    }
    printf("\n\t\t Ohhh..you entered Invalid slot..!\n");
	printf("\n\t**************************************************************************************\n");
}

void CancelReservation(slot* slots, int patientID){
    slot* current = slots;
    while (current != NULL) {
        if(current->id == patientID){
			current->id = 0;
			printf("\n\t--------------------------------------------------------------------------------------\n");
            printf("\n\t   Patient has this Reservation: %s which has been cancelled successfully..!\n", current->period);
            return;
        }
		else{
			printf("\n\t--------------------------------------------------------------------------------------\n");
			printf("\n\t\tThis patient id has no Reservation yet..!\n", current->period);
            return;
		}
        current = current->next;
    }
	printf("\n\t======================================================================================\n");
    printf("\n\t\t Invalid Id!\n");
}

void PrintIDInformation(int id){
	node *temp = first;
	while(temp != NULL){
		if(temp->id == id){
			printf("\n\t\t\tID: %d\n\n", temp->id);
			printf("\t\t\tName: %s\n\n", temp->name);
			printf("\t\t\tAge: %d\n\n", temp->age);
			printf("\t\t\tgender: %s\n", temp->gender);
		}
		temp = temp->next;
	}
}

int CheekTodayslots(slot *slots){
	int flag = 0;
	slot *current = slots;
	while (current != NULL){
		if(current->id != 0){
			flag = 1;
			break;
		}
		else{
		}
        current = current->next;
    }
	return flag;
}

void PrintSlot(slot *slots){
	slot *current = slots;
	while (current != NULL){
		if(current->id != 0){
			printf("\t\t\t\t%d        %s\n\n", current->id ,current->period);
		}
		else{
		}
        current = current->next;
    }
}