#include <iostream>
#include "tsp.h"
#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <fstream>
using namespace std;

int main()
{
	srand(time(NULL)); // random numbers

					   
	vector<int> essential_nodes;
	vector<int> graph3_nodes;
	bool essential;
	bool essential2;




	//reading of file from csv

	ifstream ip("book1.csv");
	vector <pair< string, int >> shoppinglist;

	if (!ip.is_open()) {
		std::cout << "ERROR: File Open" << '\n';
	}
	else {
		string prodname;
		string prodprice;
		int priceprod;

		while (ip.good()) {

			getline(ip, prodname, ';');
			getline(ip, prodprice, '\n');

			priceprod = stoi(prodprice);

			shoppinglist.push_back(make_pair(prodname, priceprod));
		}

		ip.close();
		
		// Printing shopping List
		for (int i = 0; i < shoppinglist.size() ; ++i) {
			printf("Shopping list[%d] ", i);
			cout << "\nProduct Name: " << shoppinglist[i].first << ". Product price: " << shoppinglist[i].second;
			//printing Products as pair.
			printf("\n");
		}
		
	}



	ifstream ip3("Book2.csv");
	vector<int>vendorlist;
	vector<list<pair< string, int>>> vprices(10);
	
	if (!ip3.is_open()) {
		std::cout << "ERROR: File Open" << '\n';
	}
	else {
		string shopnum;
		string shopprod;
		string shopprice;
		int priceshop;
		int numshop;


		while (ip3.good()) {

			getline(ip3, shopnum, ';');
			getline(ip3, shopprod, ';');
			getline(ip3, shopprice, '\n');

			numshop = stoi(shopnum);
			priceshop = stoi(shopprice);
			
			cout << "\nShop Num: " << numshop << "\n Product: " << shopprod << "\n Price:" << priceshop << "\n";


			vprices[numshop].push_back(make_pair(shopprod, priceshop));

			
			if (find(vendorlist.begin(), vendorlist.end(), numshop) != vendorlist.end()) {
			}
			else {
				vendorlist.push_back(numshop);
			}
			
		}

		ip3.close();
		
		
		// Printing vendor list
		for (int i = 0; i < vprices.size() ; ++i) {
			printf("\nVendor's product list[%d] ", i);

			list< pair<string, int> >::iterator itr = vprices[i].begin();

			while (itr != vprices[i].end()) {
				cout << "\n Product name:  " << (*itr).first << ", Price: " << (*itr).second; 

				++itr;
			}
			printf("\n");
		}

		//printing essential nodes

		for (int i = 0; i < vendorlist.size(); ++i) {
			cout << "\n" << vendorlist[i] << endl;
		}
		
		
	}

	

	Shop * shop1 = new Shop(1);
	shop1->addprods("patola", 20);
	shop1->addprods("giniling", 30);
	shop1->showprods();

	std::cout << "\nprice of patola: " << shop1->getprice("patola") << "\n";

	// Adjacency List is a vector of list.
	// Where each element is a pair<int, int>
	// pair.first -> the edge's destination
	// pair.second -> edge's weight


	vector< list< pair<int, int> > > adjacencyList(5);

	adjacencyList[0].push_back(make_pair(1, 10));
	adjacencyList[0].push_back(make_pair(2, 15));
	adjacencyList[0].push_back(make_pair(3, 20));
	adjacencyList[0].push_back(make_pair(4, 35));
	adjacencyList[1].push_back(make_pair(3, 25));
	adjacencyList[1].push_back(make_pair(0, 10));
	adjacencyList[1].push_back(make_pair(2, 35));
	adjacencyList[1].push_back(make_pair(4, 30));
	adjacencyList[2].push_back(make_pair(1, 35));
	adjacencyList[2].push_back(make_pair(0, 15));
	adjacencyList[2].push_back(make_pair(3, 30));
	adjacencyList[2].push_back(make_pair(4, 25));
	adjacencyList[3].push_back(make_pair(0, 20));
	adjacencyList[3].push_back(make_pair(2, 30));
	adjacencyList[3].push_back(make_pair(1, 25));
	adjacencyList[3].push_back(make_pair(4, 27));
	adjacencyList[4].push_back(make_pair(0, 35));
	adjacencyList[4].push_back(make_pair(1, 30));
	adjacencyList[4].push_back(make_pair(2, 25));
	adjacencyList[4].push_back(make_pair(3, 27));


	cout << "\n";

	// Printing Adjacency List
	for (int i = 0; i < adjacencyList.size(); ++i) {
		printf("adjacencyList[%d] ", i);

		list< pair<int, int> >::iterator itr = adjacencyList[i].begin();

		while (itr != adjacencyList[i].end()) {
			cout << "\n -> " << (*itr).first << ", weight: " << (*itr).second;

			++itr;
		}
		printf("\n");
	}



	essential_nodes = { 0 , 1 , 2 , 4 };
	int enodesize = essential_nodes.size();


	int i, j;
	//creates new graph from essential nodes
	Graph * inputgraph = new Graph(enodesize, 0);
	//filling graph with essential nodes
	for (j = 0; j < enodesize; ++j) {
		essential = false;

		for (i = 0; i < enodesize; i++) {

			//checking if src node is essential to graph

			if (std::find(essential_nodes.begin(), essential_nodes.end(), i) != essential_nodes.end()) {

				list< pair<int, int> >::iterator itr = adjacencyList[i].begin();
				//adding the edge between essential nodes.

				while (itr != adjacencyList[i].end()) {

					if (std::find(essential_nodes.begin(), essential_nodes.end(), (*itr).first) != essential_nodes.end()) {
						essential2 = true;
					}
					else {
						essential2 = false;
					}
					//checks to see if destination is essential node as well
					if (essential2) {

						//checks to see if edge already exists
						if (inputgraph->existsEdge(i, (*itr).first) == -1) {
							cout << "\nNew edge\n Src: " << i << " Dest:" << (*itr).first << " Weight:" << (*itr).second;
							cout << "\nNew edge\n Src: " << (*itr).first << " Dest:" << i << " Weight:" << (*itr).second;
							inputgraph->addEdge(i, (*itr).first, (*itr).second);
							inputgraph->addEdge((*itr).first, i, (*itr).second);
						}
					}
					++itr;
				}


			}
		}
	}

	cout << "\n";
	inputgraph->showInfoGraph();
	inputgraph->showGraph();


	// parameters: the graph, population size, generations and mutation rate
	// optional parameters: show_population
	Genetic genetic(inputgraph, 10, 1000, 5, essential_nodes, true);

	const clock_t begin_time = clock(); // gets time
	genetic.run(); // runs the genetic algorithm
	cout << "\n\nTime for to run the genetic algorithm: " << float(clock() - begin_time) / CLOCKS_PER_SEC << " seconds."; // shows time in seconds
	cin.get();

	return 0;
}
