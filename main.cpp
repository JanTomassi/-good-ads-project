#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
public:
    //? forse è meglio un pointer ad un nodo
    vector<int> v;
};

struct destination
{
public:
    unsigned int from;
    unsigned int to;
    destination(unsigned int from, unsigned int to){
        destination::from = from;
        destination::to = to;
    }
};


void erdosSeachArchRemove(vector<node> G, int r, int to, vector<unsigned int> &distance)
{
    queue<int> Q;
    Q.push(r);

    distance.assign(distance.size(), -1);
    distance[r] = 0;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int j = 0; j < G[u].v.size(); j++)
        {
            if (distance[G[u].v[j]] == -1)
            {
                distance[G[u].v[j]] = distance[u] + 1;
                Q.push(G[u].v[j]);
                if (G[u].v[j] == to)
                {
                    return;   
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
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
    vector<unsigned int> distance(N, -1);

    /*Definizione del grafo orientato con conesisoni in entrabi i versi*/
    for (int i = 0, u, v; i < M; i++)
    {
        in >> u >> v;
        G[u].v.push_back(v);
        G[v].v.push_back(u);
    }

    /*Inizializazione dei Power-up*/
    vector<destination> powerUpTrape;

    /*Definizione dei power-up da trasportare presi dal file*/
    for (int i = 0, u, v; i < P; i++)
    {
        in >> u >> v;
        powerUpTrape.push_back(destination(u,v));
    }
    
    for (int i = 0; i < P; i++)
    {
        cout << powerUpTrape[i].from << ' ' << powerUpTrape[i].to << endl;
    }
    

    erdosSeachArchRemove(G, 0, 2, distance);

    // for (int i = 0; i < N; i++)
    // {
    //     cout << distance[i] << ' ';
    // }
    // cout << endl;

    /*Print del Grafo*/
    // for (int i = 0; i < G.size(); i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < G[i].v.size(); j++)
    //     {
    //         cout << G[i].v[j] << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}
