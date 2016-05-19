#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <iostream>

bool is_odd(unsigned int i);
bool is_even(unsigned int i);

TEST_CASE("describe_factorial","[aufgabe3]")
{
	//Vector erstellen und mit Zufallszahlen füllen
	std::vector <unsigned int> rand_vec (100);
	for(auto it = rand_vec.begin(); it != rand_vec.end(); ++ it){
		*it = std::rand() % 100 + 1;
	}

	//Neuer Vector bei dem die ungeraden Zahlen gelöscht werden
	std::vector <unsigned int> even = rand_vec;
	even.erase(std::remove_if(even.begin(), even.end(), is_odd),even.end());

	//Ausgabe
	std::cout << "\nVector with all numbers:" << std::endl;
	std::copy(std::begin(rand_vec),std::end(rand_vec),std::ostream_iterator<unsigned int>(std::cout,","));
	std::cout << "\n\n" << "Vector with odd numbers deleted:" << std::endl;
	std::copy(std::begin(even),std::end(even),std::ostream_iterator<unsigned int>(std::cout,","));
	std::cout << "\n\n";
	//Test
	REQUIRE(std::all_of(even.begin(),even.end(),is_even));
}


int main(int argc, char *argv[]){
  	return Catch::Session().run(argc, argv);
}


bool is_odd(unsigned int i){return((i%2)==1);}
bool is_even(unsigned int i){return((i%2)==0);}