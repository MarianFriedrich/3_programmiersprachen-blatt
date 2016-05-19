#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <list>
#include <cstdlib>
#include "circle.hpp"

// Swap
template <typename T>
void swap(T& x, T& y)
{	
 	T temp = x;
	x = y;
 	y = temp;
}	
TEST_CASE("describe_swap","[swap]")
{
	
	Circle circle1 = Circle{{0.0,0.0},5.0,{0.0,0.0,0.0}};
	Circle circle2 = Circle{{0.0,0.0},10.0,{0.0,0.0,0.0}};

	swap(circle1, circle2);
	REQUIRE(circle2.radius() == 5.0);
	REQUIRE(circle1.radius() == 10.0);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
