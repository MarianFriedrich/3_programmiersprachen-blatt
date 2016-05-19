#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <vector>

bool is_even(int i);
bool is_odd(int i);
bool is_even(int i){return((i%2)==0);}
bool is_odd(int i){return((i%2)==1);}


// Filter
template <typename container, typename function>
container filter(container cont, function func)
{	
	cont.erase(std::remove_if(cont.begin(), cont.end(), func),cont.end());
 	return cont;
}

TEST_CASE("describe_filter","[filter]")
{
	std::vector<int> v1{1,2,3,4,5,6};
	std::vector<int> alleven = filter(v1, is_odd);
	REQUIRE(std::all_of(alleven.begin(),alleven.end(),is_even));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


