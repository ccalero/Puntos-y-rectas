/*! 
  \file Recta2D.hpp
  \brief Declaracion de una (Recta2D)
*/

#ifndef RECTA2D_H_
#define RECTA2D_H_

#include <cassert>
#include "Punto2D.hpp"

class Recta2D {
//! \name Variables privadas de la Recta
private:
	int _a;
	int _b;
	int _c;

public:
//! \name Constructor clase.
	/*! 
		\brief Crea una recta con los datos pasados, a, b y c.
		\param coordenada a, entero
		\param coordenada b, entero
		\param coordenada c, entero
	*/
	Recta2D(int a, int b, int c): _a(a), _b(b), _c(c){};
	/*! 
		\brief Crea una recta a partir de dos puntos
		\param Punto p,
		\param Punto q,
		\pre Los dos puntos no sean iguales
	*/
	Recta2D(Punto2D p, Punto2D q);
//! \name Funciones de la clase.
	/*! 
		\brief Devuelve el valor de a.
	*/
	int getA() const {return _a;}
	/*! 
		\brief Asigna un valor de a.
	*/
	void setA(int a) {_a = a;}
	/*! 
		\brief Devuelve el valor de b.
	*/
	int getB() const {return _b;}
	/*! 
		\brief Asigna un valor de b.
	*/
	void setB(int b) {_b = b;}
	/*! 
		\brief Devuelve el valor de c.
	*/
	int getC() const {return _c;}
	/*! 
		\brief Asigna un valor de c.
	*/
	void setC(int c) {_c = c;}
	/*! 
		\brief Calcula la distancia de un punto con la recta.
		\param Punto2D.
	*/
	double distancia(Punto2D const &p) const;
};

#endif /* RECTA2D_H_ */
