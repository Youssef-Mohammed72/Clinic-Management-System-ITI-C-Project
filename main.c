/**************************************************************************/
/**************************************************************************/
/***************** Author: 	  Youssef Mohammed AbdelFattah ****************/
/***************** Topic :    Clinic Management System 	   ****************/
/***************** File: 	  main.c 			       	   ****************/
/***************** Date  :    Monday, 21/8/2023		       ****************/
/***************** Version:   1.0 						   ****************/
/**************************************************************************/
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "func.h"
#include "LinkedList.h"

node *PatientList;
slot* slots;

int main(void){
	PatientList = (node*)calloc(1, sizeof(node));
	InitializeSlots(&slots);
	MainMenu();
	return 0;
}