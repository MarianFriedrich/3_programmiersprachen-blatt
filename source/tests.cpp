#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

/*
TEST_CASE("describe_rect_get_circumference","[rect_get_circumference]")
{
	Vec2 point{5.0f,5.0f};
	Color farbe{1.0,1.0,0.0};
	Rect test{point,farbe,5.0f,5.0f};

	REQUIRE(test.circumference() == Approx(20.0f));
}
*/
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
