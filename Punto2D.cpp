/*! 
  \file Punto2D.cpp
  \brief fichero que contiene las funciones de Punto2D
*/

#include "Punto2D.hpp"
#include <cassert>
//! \name Funciones de la clase.

	/*! 
		\brief Comprueba si dos puntos son iguales
		\param Punto2D, compara el punto con este pasado.
	*/
bool Punto2D::sonIguales(Punto2D const &p) const{
	
	bool retVal = (getX() == p.getX() and getY() == p.getY());

	#ifndef NDEBUG
	if (retVal){
		assert (getX() == p.getX() and getY() == p.getY());
	}
	#endif

	return retVal;
}
