#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

string midstr(Node* root){
    string str;
    if(root->left != nullptr){
        str.append(midstr(root->left));
    }
    str.append(to_string(root->val));
    str.append("#");
    if(root->right != nullptr){
        str.append(midstr(root->right));
    }
    return str;
}

string aftstr(Node* root){
    string str;
    if(root->left != nullptr){
        str.append(aftstr(root->left));
    }
    if(root->right != nullptr){
        str.append(aftstr(root->right));
    }
    str.append(to_string(root->val));
    str.append("#");
    return str;
}

vector<int> to_int(string seqs){
    char ss[seqs.size()+1];
    strcpy(ss, seqs.c_str());
    int value=0;
    vector<int> num;
    for(size_t i=0;i < seqs.size();i++){
        if(ss[i] == '#'){
            num.push_back(value);
            value = 0;
        }
        else{
            value = value*10 + (int)(ss[i] - '0');
        }
    }
    return num;
}

Node* build(const vector<int>& inorder, const vector<int>& postorder, int inl, int inr, int pol, int por){
    int value = postorder[por];
    Node *root = new Node(value);
    
    if(pol == por){
        return root;
    }
    int flag = inl;
    for(int i=flag;i <= inr;i++){
        if(inorder[i] == value){
            flag = i;
            break;
        }
    }

    if(flag == inl){
        root->left = nullptr;
        root->right = build(inorder, postorder, inl+1, inr, pol, por-1);
    }
    else if(flag == inr){
        root->right = nullptr;
        root->left = build(inorder, postorder, inl, inr-1, pol, por-1);
    }
    else{
        root->left = build(inorder, postorder, inl, flag-1, pol, pol+flag-inl-1);
        root->right = build(inorder, postorder, flag+1, inr, pol+flag-inl, por-1);
    }

    return root;
}

Node* Deserialize(string seqs) {
    //write ur code here.
    if(seqs.size() == 0){
        return nullptr;
    }
    vector<int> inorder = to_int(seqs.substr(0, seqs.size()/2));
    vector<int> postorder = to_int(seqs.substr(seqs.size()/2+1, seqs.size()/2));
    Node *root = build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    return root;
}

string Serialize(Node* root) {
    //write ur code here.
    string inorder = midstr(root);
    string postorder = aftstr(root);
    inorder.append("/");
    inorder.append(postorder);
    return inorder;
}

void printTree(Node* root){
    if(root == nullptr){
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    string str;
    cin >> str;
    Node *root = Deserialize(str);
    printTree(root);
    cout << endl;
    cout << Serialize(root) << endl;
    root = Deserialize(Serialize(root));
    printTree(root);
}


//  6#8#15#16#21#18#24#45#32#41#48#49#/6#15#8#18#21#16#41#32#48#49#45#24#