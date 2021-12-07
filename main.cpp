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

    /*Get the main paramiter*/
    int N, M, P;
    in >> N >> M >> P;

    /*Init the Graph as vector*/
    vector<node> G(N);

    for (int i = 0, u, v; i < M; i++)
    {
        in >> u >> v;
        G[u].v.push_back(v);
        G[v].v.push_back(u);
    }
    auto end = high_resolution_clock::now();

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
