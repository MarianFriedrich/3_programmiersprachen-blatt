# include <cstdlib> 	//std::rand()
# include <vector> 		//std::vector <>
# include <list>   		//std::list <>
# include <iostream> 	//std::cout
# include <iterator> 	//std::ostream_iterator <>
# include <algorithm> 	//std::reverse , std::generate

int main()
{
	//Vektor der größe 10 wird erstellt
	std::vector<int> v0 (10);
	//Vektor wird mit zufallszahlen befüllt
	for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); ++ it) {
		*it = std::rand();
	}
	
	//Vectorinhalt wird mit Copyiterator ausgegeben
	auto outiter = std::ostream_iterator<int>(std::cout,"\n");
	std::copy(std::begin(v0),std::end(v0), outiter);

	//Liste wird mit gleicher größe wie obiger Vektor erstellt
	std::list <int> l0 (v0.size());
	//Vektorinhalt wird in Liste kopiert
	std::copy(std::begin(v0),std::end(v0),std::begin(l0));

	//Neue Liste mit gleicher größe wie alte Liste wird erstellt
	std::list <int> l1(std::begin(l0),std::end(l0));
	//Inhalt der neuen Liste wird umgedreht
	std::reverse(std::begin(l1), std::end(l1));
	//Inhalt der Liste wird wieder ausgegeben
	std::copy(std::begin(l1), std::end(l1), std::ostream_iterator<int>(std::cout,"\n"));

	//Liste die umgekehrt war wird wieder sortiert
	l1.sort();
	//Liste wird wieder ausgegeben
	std::copy(l1.begin(), l1.end(), std::ostream_iterator<int>(std::cout,"\n"));

	//Vector v0 wird nochmals durchrandomisiert
	std::generate(std::begin(v0), std::end(v0), std::rand);
	// ... und wieder ausgegeben
	std::copy(v0.rbegin(), v0.rend(), std::ostream_iterator<int>(std::cout,"\n"));

	return 0;
}