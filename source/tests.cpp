#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <list>
#include <cstdlib>
#include "circle.hpp"


// Circle Operatoren
TEST_CASE("describe_circle_operator_same","[circle_operator_same]")
{
	Circle test1{{0,0},5,{0.0,0.0,0.0}};
	Circle test2{{0,0},5,{0.0,0.0,0.0}};
	REQUIRE(test1 == test2);
}
TEST_CASE("describe_circle_operator_smaller","[circle_operator_smaller]")
{
	Circle test1{{0,0},5,{0.0,0.0,0.0}};
	Circle test2{{0,0},10,{0.0,0.0,0.0}};
	REQUIRE(test1 < test2);
}
TEST_CASE("describe_circle_operator_bigger","[circle_operator_bigger]")
{
	Circle test1{{0,0},10,{0.0,0.0,0.0}};
	Circle test2{{0,0},5,{0.0,0.0,0.0}};
	REQUIRE(test1 > test2);
}
// Circle sortieren in Liste
TEST_CASE("describe_circle_sort","[circle_sort]")
{
	std::list <Circle> liste;
	for(unsigned int i = 0; i < 100; ++i){
		liste.push_back(Circle{{0.0,0.0},(std::rand() % 100 + 1.0f),{0.0,0.0,0.0}});
	}
	liste.sort();
	REQUIRE(std::is_sorted(liste.begin(), liste.end()));
}

// Sort with lamda
TEST_CASE("describe_lamda_sort","[lambda_sort]")
{
	std::vector <Circle> vec;
	for(unsigned int i = 0; i < 100; ++i){
		vec.push_back(Circle{{0.0,0.0},(std::rand() % 100 + 1.0f),{0.0,0.0,0.0}});
	}
	auto comp = [](const Circle& c1,const Circle& c2) -> bool{return c1 < c2;};
	std::sort(vec.begin(),vec.end(),comp);
	REQUIRE(std::is_sorted(vec.begin(), vec.end()));
}
// Elementweises aufaddieren
TEST_CASE("describe_addieren","[addieren]")
{
	std::vector<int> v1{1,2,3,4,5,6,7,8,9};
	std::vector<int> v2{9,8,7,6,5,4,3,2,1};
	std::vector<int> v3(9);
	//cpp-reference(td::plus)
	std::transform (v1.begin(), v1.end(), v2.begin(), v3.begin(), std::plus<int>());
	//cpp-reference(std::all_of)
	REQUIRE(std::all_of(v3.begin(), v3.end(), [](int i){return i==10;}));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
