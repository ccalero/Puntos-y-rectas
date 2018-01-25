/*! 
  \file Punto2D.hpp
  \brief Declaracion de un punto (Punto2D)
*/

#ifndef PUNTO2D_H_
#define PUNTO2D_H_

#include <cassert>
 
class Punto2D {

//! \name Variables privadas del Punto
private:
	int _x;
	int _y;

public:
//! \name Constructor clase.
	/*! 
		\brief Crea un punto con los datos pasados, x e y.
		\param coordenada x, entero
		\param coordenada y, entero
	*/
	Punto2D(int const &x, int const &y) : _x(x), _y(y){};
//! \name Funciones de la clase.
	/*! 
		\brief Devuelve el valor de x.
	*/
	int getX() const {return _x;}
	/*! 
		\brief Asigna un valor de x.
	*/
	void setX(int const &x) {_x = x;}
	/*! 
		\brief Devuelve el valor de y.
	*/
	int getY() const {return _y;}
	/*! 
		\brief Asigna un valor de y.
	*/
	void setY(int const &y) {_y = y;}
	/*! 
		\brief Comprueba si dos puntos son iguales
		\param Punto2D, compara el punto con este pasado.
	*/
	bool sonIguales(const Punto2D &p) const;

};

#endif /* PUNTO2D_H_ */
