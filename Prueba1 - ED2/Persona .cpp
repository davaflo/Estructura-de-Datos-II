#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>

#include "Persona.h"
#pragma warning(disable : 4996)
using namespace std;

Persona::Persona()
{
	LastName[0] = 0;
	FirstName[0] = 0;
	Address[0] = 0;
	City[0] = 0;
	State[0] = 0;
	ZipCode[0] = 0;
}

void Persona::Print() {
	ifstream iFilePersons;
	iFilePersons.open("Persons.dat", ios::in);

	if (!iFilePersons) {
		cout << "Error opening file..." << endl;
		return;
	}
	string s;

	cout << "First Name: " << setw(8) << "Last Name:" << setw(8)
		<< "Address:" << setw(8)
		<< "City:" << setw(8)
		<< "State: " << setw(8)
		<< "Zip Code:" "\n";


	while (getline(iFilePersons, s, '0')) {

		cout << s << setw(12);
	}


	
}

void Persona::PrintAll()
{
	ifstream fileEn;

	string data;
	fileEn.open("Personas.dat");
	getline(fileEn, data);

	cout << data;


	file.close();
}

void Persona::writeFile()
{
	
	int quantity;

	cout << "Enter amount of Persons: ";
	cin >> quantity;

	for (size_t i = 0; i < quantity; i++)
	{
		cout << endl << "First Name: ";
		cin >> FirstName;
		cout << endl << "Last Name:";
		cin >> LastName;
		cout << endl << "Address: ";
		cin >> Address;
		cout << endl << "City: ";
		cin >> City;
		cout << endl << "State: ";
		cin >> State;
		cout << endl << "Zip Code: ";
		cin >> ZipCode;
		cout << endl << endl;


		Pack();

	}

}

void Persona::leerArch() {
	char archivo[20];

	cout << "Nombre del archivo: " << endl;
	cin >> archivo;

	ifstream file;
	file.open(archivo);
	file.seekg(0, ios_base::end);
	int size = file.tellg();
	char * buffer = new char[size +1];
	file.seekg(0, ios_base::beg);
	file.read((char*)&buffer, sizeof(buffer));
	file.close();
	unPack(buffer);


}

void Persona::unPack(const char* buffer)
{

	char value[2];
	int val;
	int valorCampo;
	memcpy(value, buffer, 2);
	val = atoi(value);
	memcpy(LastName, buffer += 2, val);
	valorCampo = strlen(LastName);
	memcpy(value, buffer += valorCampo, 2);
	val = atoi(value);
	memcpy(FirstName, buffer += 2, val);
	valorCampo = strlen(FirstName);
	memcpy(value, buffer += valorCampo, 2);
	val = atoi(value);
	memcpy(Address, buffer += 2, val);
	valorCampo = strlen(Address);
	memcpy(value, buffer += valorCampo, 2);
	val = atoi(value);
	memcpy(City, buffer += 2, val);
	valorCampo = strlen(City);
	memcpy(value, buffer += valorCampo, 2);
	val = atoi(value);
	memcpy(State, buffer += 2, val);
	valorCampo = strlen(State);
	memcpy(value, buffer += valorCampo, 2);
	val = atoi(value);
	memcpy(ZipCode, buffer += 2, val);
	valorCampo = strlen(ZipCode);



}



void Persona::Pack()
{
	char buffer[99];
	char value[3];
	if (strlen(LastName) <= 9) {
		value[0] = '0';
		sprintf(&value[1], "%d", strlen(LastName));
	}
	else
	{
		sprintf(value, "%d", strlen(LastName));

	}
	strcpy(buffer, value);
	strcat(buffer, LastName);
	value[0] = 0;
	if (strlen(FirstName) <= 9) {
		value[0] = '0';
		sprintf(&value[1], "%d", strlen(FirstName));
	}
	else
	{
		sprintf(value, "%d", strlen(FirstName));

	}
	strcat(buffer, value);
	strcat(buffer, FirstName);
	value[0] = 0;

	if (strlen(Address) <= 9) {
		value[0] = '0';
		sprintf(&value[1], "%d", strlen(Address));
	}
	else
	{
		sprintf(value, "%d", strlen(Address));

	}
	strcat(buffer, value);
	strcat(buffer, Address);
	value[0] = 0;
	if (strlen(City) <= 9) {
		value[0] = '0';
		sprintf(&value[1], "%d", strlen(City));
	}
	else
	{
		sprintf(value, "%d", strlen(City));

	}
	strcat(buffer, value);
	strcat(buffer, City);
	value[0] = 0;
	if (strlen(State) <= 9) {
		value[0] = '0';
		sprintf(&value[1], "%d", strlen(State));
	}
	else
	{
		sprintf(value, "%d", strlen(State));

	}
	strcat(buffer, value);
	strcat(buffer, State);
	value[0] = 0;
	if (strlen(ZipCode) <= 9) {
		value[0] = '0';
		sprintf(&value[1], "%d", strlen(ZipCode));
	}
	else
	{
		sprintf(value, "%d", strlen(ZipCode));

	}
	strcat(buffer, value);
	strcat(buffer, ZipCode);
	value[0] = 0;

	strcat(buffer, "|");

	ofstream file;
	file.open("Persons.dat", ios::app | ios::out);
	file << buffer;
	file.close();

}
