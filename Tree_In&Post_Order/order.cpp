#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* build(const vector<int>& inorder, const vector<int>& postorder, int inl, int inr, int pol, int por){
    TreeNode *root = new TreeNode;
    root->val = postorder[por];
    
    if(pol == por){
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    int val = root->val;
    int flag = inl;
    for(int i=flag;i <= inr;i++){
        if(inorder[i] == val){
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

void printTree(TreeNode* root){
    if(root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    string line1;
    string line2;
    // 读取第一行
    vector<int> inorder;
    vector<int> postorder;
    int val;
    while(cin >> val){
        inorder.push_back(val);
        if(cin.get() == '\n'){
            break;
        }
    }
    while(cin >> val){
        postorder.push_back(val);
        if(cin.get() == '\n'){
            break;
        }
    }

    TreeNode *root = build(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    printTree(root);
}

