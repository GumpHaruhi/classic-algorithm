#include <iostream>
#include <vector>

using namespace std;

int m;

struct Node{
    Node* parent;
    Node* next;
    Node* neighbor;
    int value;
};

Node* make_set(int data){
    Node* node = new Node;
    node->parent = node;
    node->next = nullptr;
    node->neighbor = nullptr;
    node->value = data;
    return node;
}

vector<Node*> graph;

void add_neighbor(Node* host, Node* guest){
    if(host->value == guest->value){
        return;
    }
    guest->parent = host;
    if(host->neighbor == nullptr){
        host->neighbor = guest;
    }
    else{
        guest->neighbor = host->neighbor;
        host->neighbor = guest;
    }
}

void Union(Node* node1, Node* node2){
    if(node1 == node2){
        return;
    }
    Node* father = node1->parent;
    Node* son = node2->parent;
    Node* tail = father;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    tail->next = son;
    while(son != nullptr){
        son->parent = father;
        son = son->next;
    }
}

int minval(int x, int y){
    return x < y ? x: y;
}

bool check(const int value, const vector<int>& road){
    for(size_t i=0;i < road.size();i++){
        if(value == road[i]){
            return false;
        }
    }
    return true;
}

int findPath(const Node* beginer, const Node* endline, vector<int> road){
    if(beginer == endline){
        return 0;
    }
    Node* p = beginer->neighbor;
    road.push_back(beginer->value);
    int step = m+1;
    while(p != nullptr){
        if(check(p->value, road)){
            step = minval(step, findPath(graph[p->value], endline, road));
        }
        p = p->neighbor;
    }
    return step + 1;
}

int main()
{
    int n, u, v;
    cin >> n >> m >> u >> v;
    if(u == v){
        cout << 0 <<endl;
        return 0;
    }
    for(int i=1;i <= n;i++){
        graph.push_back(make_set(i));
    }
    int a, b;
    for(int i=0;i < m;i++){
        cin >> a >> b;
        if((a == u && b == v) || (a == v && b == u)){
            cout << 1 << endl;
            return 0;
        }
        else if(graph[a]->parent != graph[b]->parent){
            Union(graph[a], graph[b]);
        }
        add_neighbor(graph[a], make_set(b));
        add_neighbor(graph[b], make_set(a));
    }
    if(graph[u]->parent != graph[v]->parent){
        cout << -1 << endl;
        return 0;
    }
    vector<int> road;
    int step = findPath(graph[u], graph[v], road);
    cout << step << endl;
    return 0;
}