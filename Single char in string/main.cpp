#include <iostream>
#include <string>

using namespace std;

char flag;

void func(string str, int node);



typedef struct Block{
    void* l;
    void* r;
    bool used;
    bool ocupy;
    struct Block* prev;
    struct Block* next;
} Block;



int main() {
    string str;
    cin >> str;
    func(str, 0);
    // cout << (uintptr_t)sizeof(Block);
    return 0;
}

void func(string str, int node)
{
    if(node == 0){
        flag = str[0];
    }
    else if(str[node] == flag || flag == '#'){
        flag = '#';
        for(int i = 0;i <= node;i++){
            bool found = false;

            for(int j = 0;j <= node;j++){
                if(str[i] == str[j] && j != i){
                    break;
                }
                else if(j == node){
                    flag = str[i];
                    found = true;
                    break;
                }
            }

            if(found){break;}
        }
    }

    cout << flag;
    if(node < str.size() - 1) {
        return func(str, node + 1);
    }
}
