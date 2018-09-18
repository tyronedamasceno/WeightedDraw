/**
*
* Baseado em https://medium.com/@peterkellyonline/weighted-random-selection-3ff222917eb6
*
*/


#include <bits/stdc++.h>

using namespace std;

struct Pizza
{
	string name;
	int weight;
	Pizza(string name_, int weight_) : name(name_), weight(weight_) {}
};

int sumWeight(vector<Pizza>& v) {
	int aux = 0;
	for (int i = 0; i < v.size(); i++) {
		aux += v[i].weight;
	}
	return aux;
}

string randomSelect(vector<Pizza>& v) {

	int totalWeight = sumWeight(v);
	int randKey = (rand() % totalWeight) + 1; // Valor aleatório entre 1 e totalWeight, inclusive

	for (int i = 0; i < v.size(); i++) {
		randKey -= v[i].weight;
		if (randKey <= 0) {
			return v[i].name;
		}
	}

	return "erro";
}

int main() {

	srand(time(NULL));

	cout << fixed << setprecision(3);

	vector <Pizza> pizzas;
	pizzas.push_back(Pizza("A", 1));
	pizzas.push_back(Pizza("B", 2));
	pizzas.push_back(Pizza("C", 3));
	pizzas.push_back(Pizza("D", 4));
	pizzas.push_back(Pizza("E", 5));
	pizzas.push_back(Pizza("F", 6));
	pizzas.push_back(Pizza("G", 7));
	pizzas.push_back(Pizza("H", 8));
	pizzas.push_back(Pizza("I", 9));
	pizzas.push_back(Pizza("J", 10));
	
	int total  = sumWeight(pizzas);
	for (int i = 0; i < pizzas.size(); i++) {
		cout << "Nome: " << pizzas[i].name << " // Nota: " << pizzas[i].weight << endl;
		cout << "Porcentagem estimada: " << ((double) pizzas[i].weight / total )*100.0 << "%" << endl << endl; 
	}


	int numeroDeTestes = 1000000;
	cout << " ========== Experimento ==========" << endl << endl;
	cout << "Testado " << numeroDeTestes << " vezes" << endl << endl;

	map<string, int> countmap;
	map<string, int>::iterator it;

	for (int i = 0; i < numeroDeTestes; i++) {
		string aux = randomSelect(pizzas);
		countmap[aux]++;
	}

	for (it = countmap.begin(); it != countmap.end(); it++) {
		cout << it->first << " " << it->second << " ~=> " << ((double) it->second / numeroDeTestes )*100.0 << "%" << endl;
		cout << endl;
	}

	return 0;
}