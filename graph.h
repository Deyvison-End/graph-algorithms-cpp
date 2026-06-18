#include <iostream>
#include <list>
#include <vector>

using namespace std;


class Graph {
private:
    // ATENCAO:
    // Esse codigo assume que todos os vertices de 0 ateh (adj.size() - 1) existem no grafo.
    // Isto eh, nao pode haver uma grafo com vertices 0, 1 e 3, 4.
    // O vertice 2 eh assumido que existe tambem nesse caso.
    // Isso tem impacto, por exemplo, em determinar se o grafo eh conexo.
	 vector<list<pair<int, int>>> adj;

public:
    explicit Graph(int size) : adj(size) {}
	~Graph() = default;

	int size() const { return static_cast<int>(adj.size()); }	


	void edge(int src, int dst, int w);		// Cria src -> dst com peso w
	int degree(int vtx) const;              // retorna grau de um vétice
    list<int> neighbors(int vtx) const;	    // retorna lista de vertices ligados a src
    int weight(int src, int dst) const;	    // retorna peso da aresta de src para dst
	bool isConnected() const;

	
	list<int> dfs(int src); 
	list<int> bfs(int src); 
	list<int> spf(int src, int dst); 

    bool has_cycle() const;
    bool has_cycle(int src) const;

    bool reacheable(int src, int dst) const;

	void print() const; // Exibe o grafo


	
};



