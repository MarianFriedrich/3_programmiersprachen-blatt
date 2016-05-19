#include <cstdlib> 		//std::rand()
#include <vector> 		//std::vector<>
#include <list>   		//std::list<>
#include <iostream> 	//std::cout
#include <iterator> 	//std::ostream_iterator<>
#include <set>
#include <map>
int main()
{
	// Liste mit zufälligen Zahlen füllen
	std::list <unsigned int> liste (100);
	for(std::list<unsigned int>::iterator it = liste.begin();it != liste.end(); ++ it){
		*it = std::rand() % 100 + 1;
	}

	// Liste in Vector kopieren und ausgeben
	std::vector<unsigned int> vec(liste.size());
	std::copy(std::begin(liste),std::end(liste),std::begin(vec));
	std::cout << "\n" << "Zufaellige Elemente im Vector:" << "\n" << "\n";
	std::copy(std::begin(vec),std::end(vec),std::ostream_iterator<unsigned int>(std::cout,"\n"));

	// Wie viele Emlemente unterschiedlich
	std::set <unsigned int> sett(std::begin(liste),std::end(liste));
	int counter = 0;
	for(unsigned int i = 0;i <= 100; ++ i){
		if(sett.count(i)>=1){
			counter ++;
		}
	}
	// Welche Elemente nicht in Liste
	std::vector <unsigned int> not_in_list;
	for(unsigned int i = 0;i <= 100; ++ i){
		if(sett.count(i)==0){
			not_in_list.push_back(i);
		}
	}

	// Ausgabe
	std::cout << "Es sind " << 100 - counter << " unterschiedliche Elemente in der liste" << "\n";
	std::cout << "Folgende Elemente sind nicht in der liste" << "\n";
	std::copy(std::begin(not_in_list),std::end(not_in_list),std::ostream_iterator<unsigned int>(std::cout,"\n"));

	// Anzahl der einzelnen Elemente 
	std::map <unsigned int, int> mappe;
	for(unsigned int i = 0; i <= 100 ; ++ i){
		int count = 0;
		for(unsigned int j = 0; j <= vec.size() ; ++ j){
			if(vec[j]==i){
				count ++;
			}
		}
		mappe.insert(std::make_pair(i, count));
	}
	std::cout << "Anzahl der Elemente in der Liste: " << "\n";
	for(auto it = mappe.begin(); it != mappe.end(); ++ it){
		if(it -> second > 0){
			std::cout << it -> first << " => " << it -> second << "\n";
		}
	}
	return 0;
}