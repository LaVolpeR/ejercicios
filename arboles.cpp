/* Ejercicio 4: Encontrar de un árbol binario, de empleados (código, nombres, fechaNac, género) de una empresa donde el nodo 
raíz es el personal de género masculino y donde las personas de género femenino se ubiquen al lado izquierdo y los masculinos 
al lado derecho. Se ordenaran por edades calculados a partir de la fecha de nacimiento de izquierda a derecha de mayor a menor.*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
string nombre;
string codigo;
int fechaNac;
int edad;
int cont;
string genero;
Nodo *der;
Nodo *izq;
Nodo *padre;
};

Nodo *arbol = NULL;

void menu();
Nodo *crearNodo(string, string, int,int, int, string, Nodo *);
void insertarNodo(Nodo *&,string, string, int,int,int, string, Nodo *);
void mostrarArbol(Nodo *arbol, int cont);

int main(){
int opc , ind ,contador=0;
string nom, cod, gen;
int fech , eda,id;
insertarNodo(arbol,"empresa",cod,fech,0,1000,gen,NULL);
do{
menu();
cin>>opc;
switch(opc){
case 1: cout<<"Ingresar el nombre del trabajador: ";cin>>nom;
cout<<"Ingresar el codigo del trabajador: ";cin>>cod;
cout<<"Ingresar la fecha de nacimiento:   ";cin>>fech;
do{
cout<<"Ingresar (1) si es Mujer o (2) si es Hombre: ";cin>>ind;
switch(ind){
case 1: gen = "Mujer";
id = 2018-fech;
eda = 2018-fech;
break;
case 2: gen = "Hombre";
id = 2018 - fech + 1000;
eda = 2018-fech;
break;
}
}while(ind != 1 && ind != 2);
insertarNodo(arbol,nom,cod,fech,eda,id,gen,NULL);
break;
case 2: cout<<"\nMostrando el arbol completo: \n\n";
mostrarArbol(arbol,contador);
cout<<"\n"<<endl;
system("pause");
break;
}
system("cls");
}while(opc!=3);
getch();
return 0;
}

//void insertarNodo(Nodo *&,string, string, int,int,int, string, Nodo *);
void insertarNodo(Nodo *&arbol,string n,string m, int o,int p, int q, string r, Nodo *padre){
if(arbol==NULL){
Nodo *nuevo_nodo = crearNodo(n,m,o,p,q,r, padre);
arbol = nuevo_nodo;
}
else{
int valorRaiz = arbol->cont;
if(q<valorRaiz){
insertarNodo(arbol->izq,n,m,o,p,q,r, arbol);
}
else{
insertarNodo(arbol->der,n,m,o,p,q,r, arbol);
}
}
}

Nodo *crearNodo(string n,string m, int o,int p, int q, string r, Nodo *padre){
Nodo *nuevo_nodo = new Nodo();
nuevo_nodo->nombre = n;
nuevo_nodo->codigo = m;
nuevo_nodo->fechaNac = o;
nuevo_nodo->edad = p;
nuevo_nodo->cont = q;
nuevo_nodo->genero = r;
nuevo_nodo->der = NULL;
nuevo_nodo->izq = NULL;
nuevo_nodo->padre = padre;
return nuevo_nodo;
}

void mostrarArbol(Nodo *arbol, int cont){
if(arbol== NULL){ //Si el arbol esta vacio
return ;
}
else{
mostrarArbol(arbol->der,cont +1);
for(int i=0;i<cont;i++){
cout<<"\t";
}
cout<<"("<<arbol->nombre<<","<<arbol->edad<<")"<<endl;
mostrarArbol(arbol->izq,cont +1);
}
}

void menu(){
cout<<"\t\t.:Menu:."<<endl;
cout<<"\n1.insertar empleado"<<endl;
cout<<"2. Mostrar Arbol"<<endl;
cout<<"3. Salir"<<endl;
cout<<"Opcion: "<<endl;
}
