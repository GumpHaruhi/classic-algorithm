#include <iostream>
#include <vector>

using namespace std;

class Node{
    int name;
    Node* fa;
public:
    Node(int name): name(name){
        fa = this;
    }
    int id(){
        return name;
    }
    Node* parent(){
        if(fa->fa == fa){
            return fa;
        }
        else{
            return fa->parent();
        }
    }
    void epic(Node* node){
        fa = node;
    }
};

class Edge{
    Node* node1;
    Node* node2;
    int val;
public:
    Edge(Node* node1, Node* node2, int data): node1(node1), node2(node2), val(data){};
    Node* pre(){
        return node1;
    }
    Node* lat(){
        return node2;
    }
    int value(){
        return val;
    }
};


int main()
{
    int n, e;
    cin >> n >> e;
    vector<Node*> nodes;
    vector<Edge*> edges;
    for(int i=0;i < n;i++){
        Node* newnode = new Node(i);
        nodes.push_back(newnode);
    }
    int a, b, v;
    for(int i=0;i < e;i++){
        cin >> a >> b >> v;
        Edge* newedge = new Edge(nodes[a], nodes[b], v);
        if(edges.size() == 0){
            edges.push_back(newedge);
        }
        else{
            int flag = 0;
            for(size_t k=0;k < edges.size();k++){
                if(v <= edges[k]->value()){
                    edges.insert(edges.begin()+k, newedge);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){ edges.push_back(newedge);}
        }
    }

    int sumvalue = 0;
    for(size_t i = 0;i < edges.size();i++){
        if(edges[i]->pre()->parent() != edges[i]->lat()->parent()){
            sumvalue += edges[i]->value();
            edges[i]->lat()->parent()->epic(edges[i]->pre()->parent());
        }
    }
    cout << sumvalue << endl;
}