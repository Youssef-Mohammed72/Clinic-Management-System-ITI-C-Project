/**************************************************************************/
/**************************************************************************/
/***************** Author: 	  Youssef Mohammed AbdelFattah ****************/
/***************** Topic :    Clinic Management System 	   ****************/
/***************** File: 	  func.c 			       	   ****************/
/***************** Date  :    Monday, 21/8/2023		       ****************/
/***************** Version:   1.0 						   ****************/
/**************************************************************************/
/**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "func.h"
#include "LinkedList.h"

#ifndef 	NULL  
#define 	NULL (void *)0	 // NULL Equal 0 as pointer to void
#endif

struct node  *first = NULL, *last = NULL;
struct slot  *prev = NULL, *next = NULL;

extern node* PatientList;
extern slot* slots;

void MainMenu(void){
	system("cls");
	printf("\t|====================================================================================|\n");
	printf("\t|                              Clinic Management System                              |\n");
	printf("\t|====================================================================================|\n");
	int selected_option = 0;
	printf("\n\t\tSelect one option: \n\n");
	printf("\t\t\t\t1) Admin\n");
	printf("\t\t\t\t2) User\n");
	printf("\n\t-------------------------------------------------------------------------------------\n\n");
	printf("\t\tEnter your choice: ");
	scanf("%d", &selected_option);
	if(selected_option == 1){
		Admin_Password();
	}
	else if(selected_option == 2){
		UserMenu();
	}
	else{
		printf("\n\t-------------------------------------------------------------------------------------\n");
		printf("\n\t\t\tInvalid choice, press any button to reselect..!\n");
		getch();
		fflush(stdin);
		MainMenu();
	}
}

void Admin_Password(void){
	char pass[5];
	int i ,j = 0;
	do{
		system("cls");
		printf("\t|====================================================================================|\n");
		printf("\t|                              Clinic Management System                              |\n");
		printf("\t|====================================================================================|\n");
		printf("\n\t\tEnter Password: ");
		for (i = 0; i < 4; i++) {
			pass[i] = getch();
			printf("*");
		}
		pass[i] = '\0';
		getch();
		/* You must use strcmp() function which exist in string.h to compare two string in c */
		if(strcmp(pass ,"1234") == 0){
			AdminMenu();
			break;
		}
		else{
			if(j < 2){
				printf("\n\n\t-------------------------------------------------------------------------------------\n\n");
				printf("\t\t\tIncorrect password, Press any button to reEnter password...\n");
				getch();
				fflush(stdin);
			}
			else if(j == 2){
				printf("\n\n\t======================================================================================\n\n");
				printf("\t\tYou can't access Admin page, press any character to return to the main page");
				getch();
				fflush(stdin);
				MainMenu();
			}
		}
		j++;
	}while(j < 3);	
}

void AdminMenu(void){
	system("cls");
	printf("\t|====================================================================================|\n");
	printf("\t|                              Clinic Management System                              |\n");
	printf("\t|====================================================================================|\n");
	int selected_option = 0;
	printf("\n\t\tSelect one option: \n\n");
	printf("\t\t\t\t1) Add new patient record.\n");
	printf("\t\t\t\t2) Edit patient record.\n");
	printf("\t\t\t\t3) Reserve a slot with the doctor.\n");
	printf("\t\t\t\t4) Cancel reservation.\n");
	printf("\t\t\t\t5) Return to main menu.\n");
	printf("\n\t-------------------------------------------------------------------------------------\n\n");
	printf("\t\tEnter your choice: ");
	scanf("%d", &selected_option);
	if(selected_option == 1){
		AddNewPatient();
	}
	else if(selected_option == 2){
		EditPatientRecord();
	}
	else if(selected_option == 3){
		reserveAslot();
	}
	else if(selected_option == 4){
		CancelReserve();
	}
	else if(selected_option == 5){
		MainMenu();
	}
}

void AddNewPatient(void){
	int id ,age, selected_option = 0;
	char name[40] ,gender[7];
	system("cls");
	printf("\t|====================================================================================|\n");
	printf("\t|                              Clinic Management System                              |\n");
	printf("\t|====================================================================================|\n");
	printf("\n\t\t\tID: ");
	scanf("%d", &id);
	fflush(stdin);
	if(SearchID(id) != -1){
		printf("\n\t********************************************************************************\n");
		printf("\n\t\tThis ID already exist, press any button to enter another one...\n");
		printf("\n\t********************************************************************************\n");
		getch();
		fflush(stdin);
		AddNewPatient();
	}
	printf("\n\t\t\tName: ");
	scanf("%[^\n]%*c", &name);
	fflush(stdin);
	printf("\n\t\t\tAge: ");
	scanf("%d", &age);
	fflush(stdin);
	printf("\n\t\t\tGender: ");
	scanf("%s", &gender);
	InsertFirst(id ,name ,age ,gender);
	printf("\n\t-------------------------------------------------------------------------------------\n");
	printf("\n\t\tNew patient is added successfully!\n");
	printf("\n\t=====================================================================================\n");
	printf("\n\tDo you want to add other patients?\n\n");
	printf("\t\t\t\t\t1) YES\n");
	printf("\t\t\t\t\t2) NO\n");
	label:
		printf("\n\t-------------------------------------------------------------------------------------\n"); 
		printf("\t\tEnter your choice: ");
		scanf("%d", &selected_option);
		fflush(stdin);
	if(selected_option == 1){
		AddNewPatient();
	}
	else if(selected_option == 2){
		AdminMenu();
	}
	else{
		printf("\n\t\t\t\t   Invalid choice, please select Yes or No..!\n");
		goto label;
	}
}

void EditPatientRecord(void){
	int id ,selected_option = 0;
	system("cls");
	printf("\t|====================================================================================|\n");
	printf("\t|                              Clinic Management System                              |\n");
	printf("\t|====================================================================================|\n");
	printf("\n\t\t\tEnter patient id: ");
	scanf("%d", &id);
	fflush(stdin);
	printf("\n\t*************************************************************************************\n\n");
	if(SearchID(id) != -1){
		label2:
			selected_option = 0;
			system("cls");
			printf("\t|====================================================================================|\n");
			printf("\t|                              Clinic Management System                              |\n");
			printf("\t|====================================================================================|\n");
			printf("\t\tSelect one option: \n\n");
			printf("\t\t\t\t1) Edit Name.\n");
			printf("\t\t\t\t2) Edit Age.\n");
			printf("\t\t\t\t3) Edit Gender.\n");
			printf("\t\t\t\t4) Go Back.\n");
			printf("\n\t-------------------------------------------------------------------------------------\n\n");
			printf("\t\tEnter your choice: ");
			scanf("%d", &selected_option);
			fflush(stdin);
			printf("\n\t*************************************************************************************\n\n");
		if(selected_option == 1){
			system("cls");
			printf("\t|====================================================================================|\n");
			printf("\t|                              Clinic Management System                              |\n");
			printf("\t|====================================================================================|\n");
			char newName[40];
			printf("\n\t\tEnter new name: ");
			scanf("%[^\n]%*c", &newName);
			fflush(stdin);
			EditName(id ,newName);
			printf("\n\t*************************************************************************************\n\n");
			printf("\t\tName Edited successfully, press on any character to return back..!\n");
			getch();
			fflush(stdin);
			system("cls");
			printf("\t|====================================================================================|\n");
			printf("\t|                              Clinic Management System                              |\n");
			printf("\t|====================================================================================|\n");
			goto label2;
		}
		else if(selected_option == 2){
			system("cls");
			printf("\t|====================================================================================|\n");
			printf("\t|                              Clinic Management System                              |\n");
			printf("\t|====================================================================================|\n");
			int newAge;
			printf("\n\t\tEnter new age: ");
			scanf("%d", &newAge);
			fflush(stdin);
			EditAge(id ,newAge);
			printf("\n\t*************************************************************************************\n\n");
			printf("\t\tAge Edited successfully, press on any character to return back..!\n");
			getch();
			fflush(stdin);
			system("cls");
			printf("\t|====================================================================================|\n");
			printf("\t|                              Clinic Management System                              |\n");
			printf("\t|====================================================================================|\n");
			goto label2;
		}
		else if(selected_option == 3){
			system("cls");
			printf("\t|====================================================================================|\n");
			printf("\t|                              Clinic Management System                              |\n");
			printf("\t|====================================================================================|\n");
			char newGender[7];
			printf("\n\t\tEnter new gender: ");
			scanf("%d", &newGender);
			fflush(stdin);
			EditGender(id ,newGender);
			printf("\n\t*************************************************************************************\n\n");
			printf("\t\tGender Edited successfully, press on any character to return back..!\n");
			getch();
			fflush(stdin);
			system("cls");
			printf("\t|====================================================================================|\n");
			printf("\t|                              Clinic Management System                              |\n");
			printf("\t|====================================================================================|\n");
			goto label2;
		}
		else if(selected_option == 4){
			AdminMenu();
		}
		else{
			printf("\t\t\tInvalid choice, please enter valid choice..!\n");
			getch();
			fflush(stdin);
			goto label2;
		}
	}
	else{
		printf("\t\tIncorrect patient id...\n");
		printf("\n\t************************************************************************************\n");
		printf("\n\t\tSelect one option: \n\n");
		printf("\t\t\t\t1) ReEnter patient id.\n");
		printf("\t\t\t\t2) Go back.\n");
		label: 
			printf("\n\t------------------------------------------------------------------------------------\n\n");
			printf("\t\tEnter your choice: ");
			scanf("%d", &selected_option);
		if(selected_option == 1){
			EditPatientRecord();
		}
		else if(selected_option == 2){
			AdminMenu();
		}
		else{
			printf("\n\t\t\t\t   Invalid choice, please select valid option..!\n");
			goto label;
		}
	}
}

void reserveAslot(void){
	int id ,selected_option = 0;
	char appontment[40];
	system("cls");
	printf("\t|====================================================================================|\n");
	printf("\t|                              Clinic Management System                              |\n");
	printf("\t|====================================================================================|\n");
	printf("\t\tAvailable Slots: \n\n");
	DisplaySlots(slots);
	printf("\n\t*************************************************************************************\n\n");
	printf("\t\tEnter patient id: ");
	scanf("%d", &id);
	fflush(stdin);
	printf("\n\t-------------------------------------------------------------------------------------\n\n");
	if(SearchID(id) != -1){
		printf("\t\tSelect your available slot: ");
		scanf("%[^\n]%*c", &appontment);
		fflush(stdin);
		printf("\n\t**************************************************************************************\n");
		ReserveSlot(slots, id, appontment);
		printf("\t\tpress on any character to return back..!\n");
		getch();
		fflush(stdin);
		AdminMenu();
	}
	else{
		printf("\t\t\tNo patient with this entered id..!\n");
		printf("\n\t************************************************************************************\n");
		printf("\n\t\tSelect one option: \n\n");
		printf("\t\t\t\t1) ReEnter patient id.\n");
		printf("\t\t\t\t2) Go back.\n");
		label: 
			printf("\n\t------------------------------------------------------------------------------------\n\n");
			printf("\t\tEnter your choice: ");
			scanf("%d", &selected_option);
		if(selected_option == 1){
			reserveAslot();
		}
		else if(selected_option == 2){
			AdminMenu();
		}
		else{
			printf("\n\t\t\t\t   Invalid choice, please select valid option..!\n");
			goto label;
		}
	}
}

void CancelReserve(void){
	int id ,selected_option = 0;
	system("cls");
	printf("\t|====================================================================================|\n");
	printf("\t|                              Clinic Management System                              |\n");
	printf("\t|====================================================================================|\n");
	printf("\n\t\tEnter patient id: ");
	scanf("%d", &id);
	fflush(stdin);
	if(SearchID(id) != -1){
		CancelReservation(slots, id);
		printf("\n\t**************************************************************************************\n");
		printf("\n\t\t\tpress on any key to return back..!\n");
		getch();
		fflush(stdin);
		AdminMenu();
	}
	else{
		printf("\n\t************************************************************************************\n");
		printf("\n\t\t\tNo patient with this entered id..!\n");
		printf("\n\t************************************************************************************\n");
		printf("\n\t\tSelect one option: \n\n");
		printf("\t\t\t\t1) ReEnter patient id.\n");
		printf("\t\t\t\t2) Go back.\n");
		label: 
			printf("\n\t------------------------------------------------------------------------------------\n\n");
			printf("\t\tEnter your choice: ");
			scanf("%d", &selected_option);
		if(selected_option == 1){
			EditPatientRecord();
		}
		else if(selected_option == 2){
			AdminMenu();
		}
		else{
			printf("\n\t\t\t\t   Invalid choice, please select valid option..!\n");
			goto label;
		}
	}
}

void UserMenu(void){
	system("cls");
	printf("\t|====================================================================================|\n");
	printf("\t|                              Clinic Management System                              |\n");
	printf("\t|====================================================================================|\n");
	int selected_option = 0;
	printf("\n\t\tSelect one option: \n\n");
	printf("\t\t\t\t1) View patient record.\n");
	printf("\t\t\t\t2) View today reservations.\n");
	printf("\t\t\t\t3) Return to main menu.\n");
	printf("\n\t-------------------------------------------------------------------------------------\n\n");
	printf("\t\tEnter your choice: ");
	scanf("%d", &selected_option);
	if(selected_option == 1){
		ViewPatientRecord();
	}
	else if(selected_option == 2){
		//ViewTodayReservations();
		system("cls");
		printf("\t|====================================================================================|\n");
		printf("\t|                              Clinic Management System                              |\n");
		printf("\t|====================================================================================|\n");
		if(CheekTodayslots(slots) == 1){
			printf("\n\t\tToday Resevations: \n");
			printf("\n\t\t\t\t ID             Slot\n\n");
			PrintSlot(slots);
			printf("\t-------------------------------------------------------------------------------------\n");
		}
		else{
			printf("\n\t\t\tThere is no any reservations today..!\n");
			printf("\n\t-------------------------------------------------------------------------------------\n");
		}
		printf("\n\t\tpress on any key to return back..!\n");
		getch();
		fflush(stdin);
		UserMenu();
	}
	else if(selected_option == 3){
		MainMenu();
	}
}

void ViewPatientRecord(void){
	int id ,selected_option = 0;
	system("cls");
	printf("\t|====================================================================================|\n");
	printf("\t|                              Clinic Management System                              |\n");
	printf("\t|====================================================================================|\n");
	printf("\n\t\tEnter patient id: ");
	scanf("%d", &id);
	fflush(stdin);
	if(SearchID(id) != -1){
		printf("\n\t**************************************************************************************\n");
		PrintIDInformation(id);
		printf("\n\t**************************************************************************************\n");
		printf("\n\t\tpress on any key to return back..!\n");
		getch();
		fflush(stdin);
		UserMenu();
	}
	else{
		printf("\n\t************************************************************************************\n");
		printf("\n\t\t\tNo patient with this entered id..!\n");
		printf("\n\t************************************************************************************\n");
		printf("\n\t\tSelect one option: \n\n");
		printf("\t\t\t\t1) ReEnter patient id.\n");
		printf("\t\t\t\t2) Go back.\n");
		label: 
			printf("\n\t------------------------------------------------------------------------------------\n\n");
			printf("\t\tEnter your choice: ");
			scanf("%d", &selected_option);
		if(selected_option == 1){
			ViewPatientRecord();
		}
		else if(selected_option == 2){
			UserMenu();
		}
		else{
			printf("\n\t\t\t\t   Invalid choice, please select valid option..!\n");
			goto label;
		}
	}
}