//============================================================================
// Name        : archivos_secuenciales_indexados.cpp
// Author      : Marco
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdio>
#include <conio.h>

using namespace std;
	struct estudiante {
	int carnet;
 	char nombre[20];
	int edad;
	char carrera[30]; };

	struct index{
	int carnet;
 	int posicion;	};

int main(){
int opcion, bus;
estudiante alumno, auxi;
index indice, aux;
do{
    void clrscr(void);
ofstream dat("datos.txt", ios::binary | ios::app);
ofstream ind("index.txt", ios::binary | ios::app);
ifstream indic("index.txt", ios::binary);

cout<<"ES UN NUEVO DIA EN LA UNIVERSIDAD"<<endl<<endl;
cout<<"Base de Datos de la universidad:"<<endl<<endl;

cout<<"1. Ingresar un nuevo estudiante"<<endl;
cout<<"2. Buscar datos de un estudiante"<<endl;
cout<<"3. Borrar registros"<<endl;
cout<<"4. cerrar el programa"<<endl;
cout<<endl<<"elige el numero de la accion a realizar: ";
cin>>opcion;
cout<<endl;
if(opcion>0 && opcion<4){
	switch(opcion){

case 1:
	if(!dat && !ind){
	cout<<"Error al abrir archivo"<<endl;
	}else{
	cout<<"Ingrese carnet: ";
	cin>>alumno.carnet;
	cout<<endl;

	while(!indic.eof()){
indic.read((char*) &aux, sizeof(struct index));

if (alumno.carnet==aux.carnet){
	cout<<"El archivo ya existe, Posicion: "<<aux.posicion;
	cout<<endl;
	bus=10;
}}
indic.close();

if(bus!=10){
	cout<<"Ingrese el nombre: ";
	cin>>alumno.nombre;
	cout<<endl;
	cout<<"Ingrese la edad: ";
	cin>>alumno.edad;
	cout<<endl;
	cout<<"Ingrese la carrera: ";
	cin>>alumno.carrera;
	cout<<endl;

	dat.write((char*) &alumno, sizeof(struct estudiante));
	dat.seekp(0, ios::end);
	indice.carnet=alumno.carnet;
	indice.posicion=dat.tellp()/sizeof(struct estudiante);
	ind.write((char*) &indice, sizeof(struct index));
	cout<<"Guardado en la posicion: "<<"["<<indice.posicion<<"]"<<endl;
	dat.close();
	ind.close();	}
	return 0; break;
	}

case 2:
	int buscar;
	cout<<"Escriba el carnet del alumno para poder mostrar sus datos: ";
	cin>>buscar;
	while(!indic.eof()){
	indic.read((char*) &aux, sizeof(struct index));

	if (buscar==aux.carnet){
	cout<<endl<<"POSICION: "<<aux.posicion;
	cout<<endl<<endl;
	ifstream dato("datos.txt", ios::binary);
	bus=aux.posicion-1;
	dato.seekg(sizeof(struct estudiante)*bus, ios::beg);
	dato.read((char*) &auxi, sizeof(struct estudiante));

	cout<<"Carnet:  "<<auxi.carnet<<endl;
	cout<<"Nombre:  "<<auxi.nombre<<endl;
	cout<<"Edad:    "<<auxi.edad<<endl;
	cout<<"Carrera: "<<auxi.carrera<<endl;
	dato.close();
	return 0;
	}}
	indic.close();
break;

case 3:
	bus=0;
	if(bus==0){
		ifstream eliminar("datos.txt", ios::binary);
		ifstream elim_ind("index.txt", ios::binary);
		ofstream temporal("temp.txt", ios::binary | ios::out);
		ofstream temp_ind("tempi.txt", ios::binary | ios::out);
	if(!eliminar || !elim_ind){
		cout<<"Error al abrir el archivo"<<endl;
	}else{
		cout<<"Ingrese el numero de carnet del alumno que desea borrar: ";
		cin>>opcion;
	while(!eliminar.eof()){
	eliminar.read((char*) &auxi, sizeof(struct estudiante));
	if(auxi.carnet==opcion){
		cout<<"El archivo se ha eliminado de datos"<<endl;
	}else{
	temporal.write((char*) &auxi, sizeof(struct estudiante));
	}}
	while(!elim_ind.eof()){
	elim_ind.read((char*) &aux, sizeof(struct index));
	if(aux.carnet==opcion){
		cout<<"El archivo se ha eliminado de indice"<<endl;
	}else{
	temp_ind.write((char*) &aux, sizeof(struct index));
	}}}
	eliminar.close();
	temporal.close();
	elim_ind.close();
	temp_ind.close();
	 }
	remove("datos.txt");
	remove("index.txt");
	rename("temp.txt", "datos.txt");
	rename("tempi.txt", "index.txt");
	return 0;
	break;
default: break;
	}}
} while(opcion>0 && opcion!=4);
  return 0;}
