#include <queue>
#include <set>

#include "graph.h"

// Criao?=o?=o da aresta src --> dst
void Graph::edge(int src, int dst, int w) {
	if (src < 0) throw std::runtime_error("Src invalido");
	if (dst < 0) throw std::runtime_error("Dst invalido");
	if (w   < 0) throw std::runtime_error("Distancia/peso invalido");
	
	adj[src].push_back({dst, w});

}


int Graph::degree(int src) const {
	if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");

	int Tamanho = adj[src].size();
	return Tamanho;

}

list<int> Graph::neighbors(int src) const {
	if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");
	
	list<int> vizinhos;
	for (const auto& par : adj[src]) {
		int vertice_vizinho = par.first;
		vizinhos.push_back(vertice_vizinho);
	}
	return vizinhos;
}

int Graph::weight(int src, int dst) const {
	if (src < 0 || src >= adj.size()) throw std::runtime_error("Src invalido");
	if (dst < 0 || dst >= adj.size()) throw std::runtime_error("Dst invalido");
	

	for (const auto& par : adj[src]) {
		if(dst == par.first)
		{
			return par.second;
		}
	}
	return -1;
}

void Graph::print() const {
	for (int i = 0; i < this->size(); i++) {
		int d = this->degree(i);
		cout << i << "(" << d << "): ";
		list<int> nei = this->neighbors(i);
		for (int dst : nei) {
			int w = this->weight(i, dst);
			cout << dst << "[" << w << "]; ";
		}
		cout << endl;
	}
}


bool Graph::isConnected() const {

	int n = adj.size();
	vector<int> grupo(n);


	for (int i = 0; i < n; i++) {
		grupo[i] = i;
	}

// propaga grupos até que nenhuma mudança ocorra
	bool mudou = true;
	while (mudou) {
		mudou = false;
		for (int v = 0; v < n; v++) {
			for (const auto& par : adj[v]) {
				int dst = par.first;
				int grupo_v = grupo[v];
				int grupo_dst = grupo[dst];

				// se os grupos forem diferentes, une-os
				if (grupo_dst != grupo_v) {
					for (int u = 0; u < n; u++) {
						if (grupo[u] == grupo_dst) {
							grupo[u] = grupo_v;
							mudou = true;
						}
					}
				}
			}
		}
	}

// verifica se todos os vértices estão no mesmo grupo
	int g = grupo[0];
	for (int i = 1; i < n; i++) {
		if (grupo[i] != g) return false;
	}

	return true;

}

void graph() {
	cout << endl << "*** Testando Grafo ***" << endl << endl;

	Graph graph1(6);		// Connected
	graph1.edge(0, 1, 4);
	graph1.edge(0, 2, 2);
	graph1.edge(1, 2, 5);
	graph1.edge(1, 3, 10);
	graph1.edge(2, 4, 3);
	graph1.edge(4, 3, 4);
	graph1.edge(3, 5, 11);
	graph1.edge(5, 1, 11);

	Graph graph2(9);		// Connected
	graph2.edge(0, 1, 4);
	graph2.edge(0, 7, 8);
	graph2.edge(1, 2, 8);
	graph2.edge(1, 7, 11);
	graph2.edge(2, 3, 7);
	graph2.edge(2, 5, 4);
	graph2.edge(2, 8, 2);
	graph2.edge(3, 4, 9);
	graph2.edge(3, 5, 14);
	graph2.edge(4, 5, 10);
	graph2.edge(5, 6, 2);
	graph2.edge(6, 7, 1);
	graph2.edge(6, 8, 6);
	graph2.edge(7, 8, 7);

	Graph graph3(6);		// Not connected
	graph3.edge(0, 1, 12);
	graph3.edge(0, 2, 2);
	graph3.edge(3, 4, 1);
	graph3.edge(4, 5, 10);

	// Pr?tica 08
	cout << "Graph1 is connected? " << (graph1.isConnected()?"YES":"NO") << endl; // YES
	graph1.print();
	cout << endl;

	cout << "Graph2 is connected? " << (graph2.isConnected()?"YES":"NO") << endl; // YES
	graph2.print();
	cout << endl;

	cout << "Graph3 is connected? " << (graph3.isConnected()?"YES":"NO") << endl; // NO
	graph3.print();
	cout << endl;

	
}

