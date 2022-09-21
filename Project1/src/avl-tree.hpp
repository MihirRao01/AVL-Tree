#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode{
    string name;
    string id;
    int height;
    int balanceFactor;
    TreeNode* right;
    TreeNode* left;

TreeNode(string name, string id){
    this->name = name;
    this->id = id;
    height = 1;
    balanceFactor = 0;
    this->right = nullptr;
    this->left = nullptr;
}



};

class AVLTree{

    //TreeNode* root;
    bool nameValid(const string& name);
    bool idValid(const string& id);
    void heightBalance(TreeNode* node);
    TreeNode* insertBST(TreeNode* node, const string& name, const string& id);
    void InOrderTraversal(TreeNode* node, string& output);
    
    
    public:
    // root needs to be private but public now for
    TreeNode* root;
    AVLTree():root(nullptr){};
    void insert(const string& name,const string& id);
    void printInOrder();
    


};

//check if the id is a valid
bool AVLTree::idValid(const string& id){
    // check if the id 8 digits long
    if(id.length()!=8){
        cout<<"unsuccessful"<<endl;
        return false;
    }
    // check if the id only contains digits
    for(int i=0;i<id.length();i++){

        if(id[i]<'0'||id[i]>'9'){
             cout<<"unsuccessful"<<endl;
             return false;
        }
    }
    return true;
}

// check if the name is a valid
bool AVLTree::nameValid(const string& name) {

    // if name contains non-letters
    for (int i = 0; i < name.length(); i++) {

        if (!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 'A' && name[i] <= 'Z') && name[i] != ' ') {
            cout <<  "unsuccessful"  << endl;
            return false;
        }
    }

    return true;
}

// assign a height to each node and a balanceFactor
void AVLTree::heightBalance(TreeNode* node){

    if(node == nullptr){
        return;
    }

    // if at leaf, the height is 1
    // if at a node and the only child is the right, the height is 1+ the height of the child (same thing as left)
    if(node->left==nullptr && node->right == nullptr){
        node->height = 1;
    }
    else if(node->left==nullptr && node->right!=nullptr){
        node->height = 1+node->right->height;
    }
    else if(node->left!=nullptr&& node->right==nullptr){
        node->height = 1+node->left->height;
    }
    else if(node->left!=nullptr&& node->right!=nullptr){
        node->height = 1+max(node->left->height,node->right->height);
    }
    else{
        node->height = 1;
        node->balanceFactor =0;
    }
}

TreeNode* AVLTree::insertBST(TreeNode* node, const string& name, const string& id){
    // base case 
    if (!node) {
        cout <<  "successful"  << endl;
        return new TreeNode(name, id);
    }

    // inserting node
    if (stoi(id) < stoi(node->id))

        node->left = insertBST(node->left, name, id);

    else if (stoi(id) > stoi(node->id))  

        node->right = insertBST(node->right, name, id);

    else {
        cout <<"unsuccessful" << endl;
        return node;
    }

    cout<<node->name<<endl;

    return node;

    // calculate the height of each node as it is added in 
    // perform the rotations as necessary
}

void AVLTree::insert(const string&name, const string&id){
    if(!nameValid(name)){
        return;
    }
    if(!idValid(id)){
        return;
    }
    
    // if the tree is empty, make the inserted node the root node
    if(!root){
        root = new TreeNode(name,id);
        cout<<"sucessful" << endl;
        return;
    }
    //cout<<"Tree is not empty and the root is :"<<root->name<<endl;
    // if the tree is not empty recursively add the new node
    root = insertBST(root,name,id);

}

void AVLTree::InOrderTraversal(TreeNode* node, string& output){
    if(node==nullptr){
    }
    else{
        InOrderTraversal(node->left, output);
        output+=node->name+", ";
        InOrderTraversal(node->right,output);
    }
}

void AVLTree::printInOrder(){
    string output = "";
    
    InOrderTraversal(root,output);

    if(output.length()!=0){
        output = output.substr(0,output.length()-2);
    }
    cout<< output;
}



