#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node
{
public:
    //? forse è meglio un pointer ad un nodo
    vector<int> v;
};

struct destination
{
    unsigned int from;
    unsigned int to;
    destination(unsigned int from, unsigned int to)
    {
        destination::from = from;
        destination::to = to;
    }
};

bool BFSSeach(vector<node> G, int r, int to, vector<unsigned int> &distance, vector<unsigned int> &parent)
{
    queue<int> Q;
    Q.push(r);

    distance.assign(distance.size(), -1);
    distance[r] = 0;

    parent[r] = -1;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int j = 0; j < G[u].v.size(); j++)
        {
            if (distance[G[u].v[j]] == -1)
            {
                distance[G[u].v[j]] = distance[u] + 1;
                parent[G[u].v[j]] = u;
                Q.push(G[u].v[j]);

                if (G[u].v[j] == to)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool printPath(unsigned int r, unsigned int s, const vector<unsigned int> parent, vector<unsigned int> &res, bool &ret)
{
    if (r == s)
    {
        res.push_back(r);
    }
    else if (parent[s] == -1)
    {
        ret = false;
        return ret;
    }
    else
    {
        ret = true;
        printPath(r, parent[s], parent, res, ret);
        res.push_back(s);
    }
    return ret;
}

/*void dfs(vector<node> G, unsigned int r)
{
    stack<dfs_rel> S;
    S.push(dfs_rel(r, 0));
    vector<bool> visited(G.size(), false);
    while (!S.empty())
    {
        //Ottiene il primo elemento e rimuovilo dallo stack
        dfs_rel u = S.top();
        S.pop();

        if (!visited[u.pos])
        {
            visited[u.pos] = true;
            cout << u.pos << " : " << u.depth << ": ";
            for (auto v : G[u.pos].v)
            {
                S.push(dfs_rel(v, u.depth+1));
                cout << v << ' ';
            }
            cout << endl;
        }
    }
}*/

int main(int argc, char const *argv[])
{
    /*Read file*/
    ifstream in = ifstream("./mario/input/input13.txt");
    ofstream out = ofstream("./mario/test/output.txt");

    // ifstream in = ifstream("./input.txt");
    // ofstream out = ofstream("./output.txt");

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
    vector<unsigned int> parent(N, -1);

    /*Definizione del grafo orientato con conesisoni in entrabi i versi*/
    for (int i = 0, u, v; i < M; i++)
    {
        in >> u >> v;
        G[u].v.push_back(v);
        G[v].v.push_back(u);
    }

    /*Inizializazione dei Power-up*/
    vector<destination> powerUpTrip;

    /*Definizione dei power-up da trasportare presi dal file*/
    for (int i = 0, u, v; i < P; i++)
    {
        in >> u >> v;
        powerUpTrip.push_back(destination(u, v));
    }

    // cout << powerUpTrip[0].from << ' ' << powerUpTrip[0].to << endl;

    /*Distanza dal nodo from al nodo to*/
    bool trovato;
    trovato = BFSSeach(G, powerUpTrip[0].from, powerUpTrip[0].to, distance, parent);

    /*Dal nodo di arrivo al nodo di partenza trova il percorso*/
    vector<unsigned int> res;
    printPath(powerUpTrip[0].from, powerUpTrip[0].to, parent, res, trovato);

    out << trovato << endl;
    if (trovato == true)
    {
        out << res.size() - 1 << endl;

        for (int i = 0; i < res.size() - 1; i++)
        {
            out << res[i] << ' ' << res[i + 1] << endl;
        }
    }else{

    }
    

    return 0;
}
