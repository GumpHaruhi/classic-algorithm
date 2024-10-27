#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge;

struct Node{
    int value;
    bool black; // black标记这个点是否被走过，防止搜索走回头路
    vector<Edge*> edges;  // 容器中保存这个点的所有边
    Node* parent;
};

struct Edge{
    Node* fir;  // fir and sec 是边的两个端点
    Node* sec;
    int weight;
};

Node* creatNode(int data){
    Node* node = new Node;
    node->black = false;
    node->parent = node;
    node->value = data;
    return node;
}

Edge* creatEdge(Node* node1, Node* node2, int data){
    Edge* edge = new Edge;
    edge->fir = node1;
    edge->sec = node2;
    edge->weight = data;
    return edge;
}

Node* find_set(Node* node){  // 并查集，查找祖宗
    if(node->parent == node){
        return node;
    }
    return find_set(node->parent);
}

void Union(Node* node1, Node* node2){
    if(node1 == node2 || find_set(node1) == find_set(node2)){
        return;
    }
    find_set(node2)->parent = find_set(node1);
}

int minPath(Node* current, const Node* goal){  // BFS 的核心搜索函数
    if(current == goal){
        return 0;
    }

    current->black = true;   // 染黑
    int total = INT_MAX, flag = 0;   // flag 起到标记作用，标记一条路能否走到终点（死路一条）
    for(size_t i=0;i < current->edges.size();++i){
        Node* node = current == current->edges[i]->fir ? current->edges[i]->sec: current->edges[i]->fir;
        if(!node->black){
            cout << "from " << current->value << " to " << node->value <<" wei " << current->edges[i]->weight<<endl;
            int step = minPath(node, goal);
            if(step != -1){
                flag = 1;
                step += current->edges[i]->weight;
                total = step < total ? step: total;
            }
        }
    }
    current->black = false;   // 染白
    return flag == 0 ? -1: total;
}

int main(){
    int n, m, u, v;
    vector<Node*> graph;  // graph是图
    cin >> n >> m >> u >> v;
    if(u == v){
        cout << 0 << endl;
        return 0;
    }
    for(int i=0;i < n;++i){
        graph.push_back(creatNode(i));
    }

    int a, b, w;
    for(int i=0;i < m;++i){
        cin >> a >> b >> w;
        if(a != b){
            Edge* edge = creatEdge(graph[a], graph[b], w);
            graph[a]->edges.push_back(edge);
            graph[b]->edges.push_back(edge);
            Union(graph[a], graph[b]);
        }
    }

    if(find_set(graph[a]) != find_set(graph[b])){
        cout << -1 << endl;
        return 0;
    }
    
    cout << minPath(graph[u], graph[v]) << endl;
}