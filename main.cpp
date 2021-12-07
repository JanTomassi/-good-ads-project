#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

struct node
{
public:
    //? forse è meglio un pointer ad un nodo
    vector<int> v;
};

void erdos(vector<node> G, node r, int distance[])
{
    queue<node> Q;
    Q.push(r);
    for (int i = 0; i < G.size(); i++)
    {
        cout << G[i].v.front() << endl;
    }
}

int main(int argc, char const *argv[])
{
    auto start = high_resolution_clock::now();
    /*Read file*/
    ifstream in = ifstream("./mario/input/input0.txt");
    ofstream out = ofstream("./mario/test/input0.txt");

    /*Ottenere i parametri base
        N=numero di nodi
        M=numero di archi
        P=Power-up da consegnare
    */
    int N, M, P;
    in >> N >> M >> P;

    /*Inizializazione del grafo come lista concatenata*/
    vector<node> G(N);

    /*Definizione del grafo orientato con conesisoni in entrabi i versi*/
    for (int i = 0, u, v; i < M; i++)
    {
        in >> u >> v;
        G[u].v.push_back(v);
        G[v].v.push_back(u);
    }
    auto end = high_resolution_clock::now();

    /*Print del Grafo*/
    for (int i = 0; i < G.size(); i++)
    {
        cout << i << ": ";
        for (int j = 0; j < G[i].v.size(); j++)
        {
            cout << G[i].v[j] << ' ';
        }
        cout << endl;
    }

    duration<double, milli> ms_double = end - start;

    cout << ms_double.count() << "ms\n";
    

    return 0;
}
