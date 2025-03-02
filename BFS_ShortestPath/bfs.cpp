#include <iostream>
#include <vector>

#define MAX_INT 1000000

using namespace std;

class Edge;

// Node
class Node{
public:
    int id;
    bool black;
    vector<Edge*> edges;

    Node(int id){
        this->id = id;
        this->black = false;
    }

    ~Node(){}

    void addEdge(Edge* edge){
        this->edges.push_back(edge);
    }
};

// Edge
class Edge{
public:
    Node* from;
    Node* to;
    int weight;

    Edge(Node* x, Node* y, int w){
        this->from = x;
        this->to = y;
        this->weight = w;
    }
};

vector<Node*> graph;


int BFSearch(Node* src, Node* dst){
    if(src->id == dst->id) {
        return 0;
    }
    int minstep = MAX_INT;
    src->black = true;       // 染黑
    for(Edge* e: src->edges){
        if(e->to->black){
            continue;
        }
        int step = e->weight + BFSearch(e->to, dst);
        minstep = step < minstep ? step: minstep;
    }
    src->black = false;      // 染白
    // cout << "from " << src->id << " to " << dst->id << " step: " << minstep << endl;
    return minstep;
}

int main(){

    int n, m, u, v;
    cin >> n >> m >> u >> v;
    for(int i=0; i < n; i++){
        graph.push_back(new Node(i));
    }
    int a, b, w;
    for(int i=0; i < m; i++){
        cin >> a >> b >> w;
        // 加入一条有向边
        graph[a]->addEdge(new Edge(graph[a], graph[b], w));
    }

    int distance = BFSearch(graph[u], graph[v]);
    if(distance == MAX_INT){
        // 无法到达，返回 -1
        distance = -1;
    }
    cout << distance << endl;

    return 0;
}