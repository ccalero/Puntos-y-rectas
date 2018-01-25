/*! 
  \file Recta2D.cpp
  \brief fichero que contiene las funciones de Recta2D
*/

#include "Recta2D.hpp"
#include "Punto2D.hpp"
#include <cmath> //pow y sqrt
#include <stdlib.h> //abs
//! \name Constructor clase.
	/*! 
		\brief Crea una recta a partir de dos puntos
		\param Punto p,
		\param Punto q,
		\pre Los dos puntos no sean iguales
	*/
Recta2D::Recta2D(Punto2D p, Punto2D q){
	if(!p.sonIguales(q)){
		_a= q.getY() - p.getY();
		_b= p.getX() - q.getX();
		_c= (q.getX() * p.getY()) - (p.getX() * q.getY());
	}
}
//! \name Funciones de la clase.

	/*! 
		\brief Calcula la distancia de un punto con la recta.
		\param Punto2D.
	*/
double Recta2D::distancia(Punto2D const &p) const{	//calcula la mínima distancia del punto a la recta
		return abs( _a*p.getX() + _b*p.getY() + _c ) / sqrt(pow(_a,2) + pow(_b,2));
}
