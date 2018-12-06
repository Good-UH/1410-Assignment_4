/*COSC 1410, Assignment 4
Tuesday, October 7, 2014
Write a program that keeps track of the social security numbers (SSN) of customers of a bank.
Assume that SSN is a four-digit number (ex. 1234 not 0123). Record SSNs in an array of 32 elements.
Use two functions: one to validate the SSN to check if its been recorded or not and another function
to list the records of SSN to show the user all the SSNs recorded in the program.
Assume that the user will always enter proper type of value (integer).*/
#include <iostream>
using namespace std;

const int MAX_NUM_RECORDS = 32; //Using a defined/named constant for array size of 32
int records[MAX_NUM_RECORDS]; //Init an array of integers called records of size 32

bool isValid(int ssn); //bool function to verify if the SSN is valid or not (not a 4-digit number)
bool isExist(int ssn, int records[], int numberOfRecords); //bool function to verify if the SSN has already been entered or not in the array
void listRecords(int records[], int); //void function to list(print) all the SSNs in the array 
int getSSN(); //int function to ask the user for SSN 
int ssn; //ssn to hold the ssn values from the user
int numberOfRecords = 0; //counter to count SSNs in the array

int main() 
{
	for (int i = 0; i < MAX_NUM_RECORDS; i++) //for loop to make space for SSNs in the array
	{
		ssn = getSSN(); //call the getSSN function to get the ssn for the array
		isExist(ssn, records, MAX_NUM_RECORDS); //call the function isExist to check if the ssn entered is already in the array

		if (isExist(ssn, records, MAX_NUM_RECORDS) == false) //if the ssn is not in the array record the entry
		{
			records[i] = ssn;
			numberOfRecords++; //count how many SSNs are in the array
			cout << records[i] << " is recorded.\n";  //show the entry to the user
		}
		else if (isExist(ssn, records, MAX_NUM_RECORDS) == true) //if the ssn is in the array void the entry (do not record it) and notify the user
		{
			cout << "This SSN is already in the system.\n"; //notify user
			i--; //reuse the space in the array (do nothing in the array)
		}
	}
	listRecords(records, numberOfRecords); //list(print) all SSNs in the array

	system("pause");
	return 0;
}

bool isValid(int ssn) //function to verify ssn is a valid input and a 4-digit number
{
	if (ssn > 999 && ssn < 10000) //return true if it is a 4-digit number
	{
		return true;
	}
	else //return false if it is not a 4-digit number
	{
		return false;
	}
}

bool isExist(int ssn, int records[], int numberOfRecords) //function to check if an ssn entry is already in the array
{
	for (int i = 0; i < numberOfRecords; i++)  //for loop to check all entries in the array
	{
		if (records[i] == ssn) //if the ssn entry is already in the array it Exist
		{
			return true;
		}
	}
	return false; //otherwise return false for the ssn entry not being in the array
}

void listRecords(int records[], int) //print the SSNs in the array the user inputted
{
	for (int i = 0; i < numberOfRecords; i++) //for loop to print all the entries and values in the array
	{
		cout << "record[" << i << "] is equal to " << records[i] << endl;
	}
}

int getSSN() //function to ask for the ssn
{
	do //ask the user for a 4-digit SSN number or 0 to exit
	{
		cout << "Please enter a 4 digit SSN number to record, or enter 0 to finish: ";
		cin >> ssn;

		if (ssn == 0) //if the user enters 0 then display all the SSNs in the array
		{
			listRecords(records, MAX_NUM_RECORDS);
			system("pause");
			exit(0);
		}
	} while (isValid(ssn) == false); //ignore input if its not a 4-digit number 
	return ssn; //return the ssn
}
