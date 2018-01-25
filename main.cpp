/*!
  \file main.cpp
  \brief Programa principal que usa los Objetos Punto y Recta.
*/

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>	// std::cout
#include <vector>
#include <string>
#include <fstream>      // std::ifstream

#include "Punto2D.hpp"
#include "Recta2D.hpp"

/*!
   \brief Espacio de nombres para la asignatura Estructura de datos.
*/
using namespace std;

/*! 
	\brief Carga el fichero abrelatas.txt (contorno)
	\param Vector de Punto2D, contorno
	\param Nombre de fichero, contorno (abrelatas.txt)
	\pre El vector definido y que el fichero exista.
*/
void cargarContorno(vector<Punto2D> &contorno, char *fContorno);

/*! 
	\brief Carga el fichero aproximacion.txt (contorno)
	\param Vector de enteros, aproximacionPoligonal
	\param Nombre de fichero, aproximacionPoligonal (aproximacion.txt)
	\pre El vector definido y que el fichero exista.
*/
void cargarAproximacionPoligonal(vector<int> &aproximacionPoligonal, char *fAproximacionPoligonal);

/*! 
	\brief Calcula el error
	\param Vector de Punto2D, contorno
	\param Vector de enteros, aproximacionPoligonal
	\pre El vector contorno y vector aproximacionPoligonal tienen que estar cargados.
*/
double calucularError(const vector<Punto2D> &contorno, const vector<int> aproximacionPoligonal);

/*! 
	\brief Programa principal
	\param argc, numeros de parametros introducidos
	\param argv, nombres de parametros introducidos
*/
int main(int argc, char** argv) {

	char cont[20] = "abrelatas.txt";
	char aprox[20] = "aproximacion.txt";
	
    	vector<Punto2D> contorno;
    	vector<int> aproximacion;

	cargarContorno(contorno,cont);  

	cargarAproximacionPoligonal(aproximacion,aprox); 

	cout << "Error: " << calucularError(contorno, aproximacion) << endl;

    return 0;
}

//Carga el fichero abrelatas.txt en contorno
void cargarContorno(vector<Punto2D> &contorno, char *fContorno){

	contorno.clear();

	ifstream f(fContorno);
	int x, y;
	if(f){
		while(f >> x >> y){
			Punto2D p(x,y);
			contorno.push_back(p);
		}
		f.close();
	} else {
		cout << "Problema abrir fichero contorno" << endl;
		exit(-1);
	}
}
//Carga el fichero aproximacion.txt en contorno
void cargarAproximacionPoligonal(vector<int> &aproximacionPoligonal, char *fAproximacionPoligonal){
	
	aproximacionPoligonal.clear();

	ifstream f(fAproximacionPoligonal);
	int x;
	if(f){
		while(f >> x){
			aproximacionPoligonal.push_back(x);
		}
		f.close();
	} else {
		cout << "Problema abrir fichero aproximacion" << endl;
		exit(-1);
	}
	

}
//contorno -> abrelatas.txt | aproximacionPoligonal -> aproximación.txt
double calucularError(const vector<Punto2D> &contorno, const vector<int> aproximacionPoligonal){

	double error = 0.0;
	int actual;
	int siguiente;
	
	//Recorremos el archvio aproximacion
	for(int i=0; i < aproximacionPoligonal.size()-1; i++){
		
		//Guardamos en actual punto en el que estamos
		actual = aproximacionPoligonal[i];
		//Siguiente el que le sigue al actual para formar la recta
		siguiente = aproximacionPoligonal[i+1];
	
		//Formamos la recta con actual y siguiente
		Recta2D r(contorno[actual], contorno[siguiente]);
	
		//Cuando el actual es mas pequeño que el siguiente.
		if(actual < siguiente){
			//Suma el error de cada punto en la recta, hasta llegar al siguiente.
			for(int j = actual+1; j< siguiente; j++)
				error += pow(r.distancia(contorno[j]),2);

		}
		//Cuando siguiente es mas pequeño que el actual (Ultimo caso)
		else {
			//Suma el error desde el actual, hasta el final.
			for(int j = actual+1; j <  contorno.size(); j++)
				error += pow(r.distancia(contorno[j]),2);
			//Suma el error desde el principio, hasta el siguiente.
			for(int j = 0; j < siguiente; j++)
				error += pow(r.distancia(contorno[j]),2);	
		}
	}
	return error;

}
