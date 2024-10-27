#include <iostream>
#include <vector>

using namespace std;

class Node{
    int name;
    vector<Node*> neighbor;
public:
    Node(int id): name(id){};
    int id(){
        return name;
    }
    vector<Node*>& child(){
        return neighbor;
    }
    void addedge(Node* node){
        if(node != this){
            neighbor.push_back(node);
        }
    }
};

int maxr(int a, int b){
    return a > b ? a: b;
}
int minr(int a, int b){
    return a > b ? b: a;
}

int high(Node* root, Node* node){
    int value = 0;
    for(size_t i=0;i < node->child().size();i++){
        if(node->child()[i] != root){
            value = maxr(value, high(node, node->child()[i]));
        }
    }
    return value+1;
}

int main()
{
    int n;
    cin >> n;
    vector<Node*> nodes;
    for(int i=0;i < n;i++){
        Node* newnode = new Node(i);
        nodes.push_back(newnode);
    }
    int u, v;
    for(int i=1;i < n;i++){
        cin >> u >> v;
        nodes[u]->addedge(nodes[v]);
        nodes[v]->addedge(nodes[u]);
    }
    int minhigh = n+1;
    for(size_t k=0;k < nodes.size();k++){
        minhigh = minr(minhigh, high(nullptr, nodes[k]));
    }
    cout << minhigh-1 << endl;
}