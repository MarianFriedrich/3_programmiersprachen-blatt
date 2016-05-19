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
	return radius_ * radius_ * M_PI;
}
//RADIUS
float Circle::radius()const{
	return radius_;
}
//COLOR
Color Circle::color()const{
	return color_;
}
//Center
Vec2 Circle::center()const{
	return center_;
}

float Circle::circumference() const{
	return 2 * radius_ * M_PI;
}
/*
 * SETTER
 */
//RADIUS
void Circle::radius(float r){
	radius_ = r;
}
//COLOR
void Circle::color(Color const& clr){
	color_ = clr;
}
//Center
void Circle::center(Vec2 const& ctr){
	center_ = ctr;
}
/*
 *	FUNCTIONS
 */
bool operator<(Circle const& circle1, Circle const& circle2){
	return circle1.radius_ < circle2.radius_;
}
bool operator>(Circle const& circle1, Circle const& circle2){
	return circle1.radius_ > circle2.radius_;
}
bool operator==(Circle const& circle1, Circle const& circle2){
	return circle1.radius_ == circle2.radius_;
}
