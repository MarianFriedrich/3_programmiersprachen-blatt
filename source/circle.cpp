#include "circle.hpp"
#include "color.hpp"
#include <math.h>

//constructor
Circle::Circle(Vec2 const& ctr, float r, Color const& clr)
  : center_(ctr), radius_(r), color_(clr)
{}
/*
 *	Getter
 */
//AREA
float Circle::area()const{
	Circle temp = *this;
	return temp.radius_ * temp.radius_ * M_PI;
}
//RADIUS
float Circle::radius()const{
	return this -> radius_;
}
//COLOR
Color Circle::color()const{
	return this -> color_;
}
//Center
Vec2 Circle::center()const{
	return this -> center_;
}

float Circle::circumference() const{
	Circle temp = *this;
	return 2 * temp.radius_ * M_PI;
}
/*
 * SETTER
 */
//RADIUS
void Circle::radius(float r){
	this -> radius_ = r;
}
//COLOR
void Circle::color(Color const& clr){
	this -> color_ = clr;
}
//Center
void Circle::center(Vec2 const& ctr){
	this -> center_ = ctr;
}
/*
 *	FUNCTIONS
 */

