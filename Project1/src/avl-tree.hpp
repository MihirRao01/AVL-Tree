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

TreeNode(string name, string id) : name(name), id(id), 
    height(1), balanceFactor(0), left(nullptr), right(nullptr) {}

};

class AVLTree{

    TreeNode* root;
    bool nameValid(const string& name);
    bool idValid(const string& id);
    void heightBalance(TreeNode* node);
    TreeNode* insertBST(TreeNode* node, const string& name, const string& id);
    void InOrderTraversal(TreeNode* node, string& output);
    void PreOrderTraversal(TreeNode* node, string& output);
    void PostOrderTraversal(TreeNode* node, string& output);
    TreeNode* rotateLeft(TreeNode* node);
    TreeNode* rotateRight(TreeNode* node);
    TreeNode* rotateLeftRight(TreeNode* node);
    TreeNode* rotateRightLeft(TreeNode* node);
    string searchIdHelper(TreeNode* node,const string& key);
    void searchNameHelper(TreeNode*, const string& name, string& output);
    void ClearTree(TreeNode* &node);
    TreeNode* RemoveNodeHelper(TreeNode* node, const string& key);
    void RemoveNodeInorderHelper(TreeNode* node, vector<string>& outptu);
    
public:
    AVLTree():root(nullptr){};
    ~AVLTree();
    void insert(const string& name,const string& id);
    string printInOrder();
    string printPreOrder();
    string printPostOrder();
    int printLevelCount();
    void searchID(string& id);
    void searchName(string& name);
    void removeId(const string& id);
    void removeInorder(int N);
    


};
// deallocte the memory for all the nodes in the tree
void AVLTree::ClearTree(TreeNode* &node){
    if(node!=nullptr){
        ClearTree(node->left);
        ClearTree(node->right);
        delete node;
        node = nullptr;
    }
}

AVLTree::~AVLTree(){
    
    ClearTree(root);
   
}

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

// look for the specified Id in the tree and return the name
string AVLTree::searchIdHelper(TreeNode* node, const string& key){
    if(!node){

        return "unsuccessful";
    } 
    else if(stoi(node->id) == stoi(key)){
        return node->name;
    }
    else if (stoi(node->id)> stoi(key)){

       return searchIdHelper(node->left,key);
    }
    else{

       return searchIdHelper(node->right,key);
    }
}
// this function is the command the user calls and this function calls search ID helper to get the naem
void AVLTree::searchID(string& id){

    if (!idValid(id)) return;    

    string result;

    result = searchIdHelper(root,id);

    cout<<result<<endl;

}
// same as searchIdHelper, but return the ids for the name specified
void AVLTree::searchNameHelper(TreeNode* node, const string& name, string& output){

    if(!node){
    }
    else{
        if(node->name == name){
           output+=node->id + "\n";
        }
         searchNameHelper(node->left,name,output);
         searchNameHelper(node->right,name,output);
    }
}

void AVLTree::searchName(string& name){

    string output;

    searchNameHelper(root,name, output);
    
    if(output.length() == 0){
        cout<<"unsuccessful"<<endl;
    }
    else{
        cout<<output;
    }
}


// Left Rotation 
TreeNode* AVLTree::rotateLeft(TreeNode* node){
    TreeNode* grandchild = node->right->left;
    TreeNode* newParent = node->right;
    newParent->left = node;
    node->right = grandchild;
    // update the height of the node and the new parent
    heightBalance(node);
    heightBalance(newParent);
    return newParent;
    
}
// rotate right miror image of rotate left
TreeNode* AVLTree::rotateRight(TreeNode* node){
    TreeNode* grandchild = node->left->right;
    TreeNode* newParent  = node->left;
    newParent->right = node;
    node->left = grandchild;
    
    heightBalance(node);
    heightBalance(newParent);
    return newParent;
}

TreeNode* AVLTree::rotateLeftRight(TreeNode* node){
    // roate left on the root's left subtree and then rotate right on the root
    node->left = rotateLeft(node->left);
    return rotateRight(node);
}

TreeNode* AVLTree::rotateRightLeft(TreeNode* node){
    // roate right on the root's right subtree and then rotate left on the root
    node->right = rotateRight(node->right);
    return rotateLeft(node);
}


// assign a height to each node and a balanceFactor
void AVLTree::heightBalance(TreeNode* node){

    if(node == nullptr){
        return;
    }
    // if at leaf, the height is 1
    // if at a node and the only child is the right, the height is 1+ the height of the child (same thing as left)
     if (node->right && node->left) {

        node->height = 1 + max(node->left->height, node->right->height);
        node->balanceFactor = node->left->height - node->right->height;
    }
    else if (node->left) {

        node->height = 1 + node->left->height;
        node->balanceFactor = node->left->height;
    }
    else if (node->right) {

        node->height = 1 + node->right->height;
        node->balanceFactor = -1 * node->right->height;
    }
    else {
        node->height = 1;
        node->balanceFactor = 0;
    }
}

TreeNode* AVLTree::insertBST(TreeNode* node, const string& name, const string& id){
    // base case : reach the point of insertion, creating a new leaf node
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
        //return node;
    }
    // calculate the hight of the node 
    heightBalance(node);
    // perform the necesary rotations
    if(node->balanceFactor == -2){
        // if the tree's right subtree is left heavy
        if(node->right->balanceFactor == -1){

             return rotateLeft(node);
        }
        else{
           // right left rotation
           return rotateRightLeft(node);
        }
    }
    else if(node->balanceFactor == 2){

        if(node->left->balanceFactor== 1){
            // rotate Right;
            return rotateRight(node);

        }
        else{
            // rotate left Right;
            return rotateLeftRight(node);
        }
    }
    return node;
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
        cout<<"successful" << endl;
        return;
    }
    //cout<<"Tree is not empty and the root is :"<<root->name<<endl;
    // if the tree is not empty recursively add the new node
    root = insertBST(root,name,id);

}


TreeNode* AVLTree::RemoveNodeHelper(TreeNode* node, const string& key){
    // if the root is null then the item is not in the tree, else compare to the root
    if(!node){ 
        cout<<"unsuccessful\n";
        return nullptr;
    }
    else if(stoi(node->id)> stoi(key)){
        node->left = RemoveNodeHelper(node->left,key);
    }
    else if(stoi(node->id)<stoi(key)){
        node->right = RemoveNodeHelper(node->right,key);
    }
    else{ // the item is in the local root
        cout<<"successful\n";
        if(node->left==nullptr && node->right==nullptr){
            delete node;
            node = nullptr; 
            return node;
        }
        else if (node->left == nullptr){// node only has one child a right one
            TreeNode* temp = node->right;
            delete node;
            heightBalance(temp);
            return temp;
        }
        else if( node->right == nullptr){ // node only has one child a right one
            TreeNode* temp = node->left;
            delete node;
            heightBalance(temp);
            return temp;
        }
        else { //node has two children, so replace the node with the inorder sucessor, the right subtree left most child
            // finding the inorder succesor
            TreeNode* successorParent = node;
            TreeNode* successor = node->right;

            while(successor->left){
                successorParent = successor;
                successor = successor->left;
            }
            // replace the node with the inorder successor
            node->name = successor->name;
            node->id = successor->id;

            // repalce the child of the successor
            if (successor == node->right) {
                node->right = successor->right;
            }
            else{
                successorParent->left = successor->right;
            }

            delete successor;

            
        }
    }

    heightBalance(node);
    return node;

}

void AVLTree::removeId(const string& id){

    if(!idValid(id)){
        cout<<"unsuccessful\n";
    }
    root = RemoveNodeHelper(root,id);

}

void AVLTree::RemoveNodeInorderHelper(TreeNode* node, vector<string>& output){
     
     if(node){
        RemoveNodeInorderHelper(node->left, output);
        output.push_back(node->id);
        RemoveNodeInorderHelper(node->right,output);
     }
}

void AVLTree::removeInorder(int N){

    vector<string>output;
    RemoveNodeInorderHelper(root, output);

    if(N>output.size()){
        cout<<"unsuccessful\n";
    }
    else{
        root = RemoveNodeHelper(root,output[N]);
    }
    
    

}


int AVLTree::printLevelCount(){
    // height of the root will be the same as the total number of levels sine both are 1 based
    int levelCount; 
    if(!root){
        levelCount = 0;
    }
    else{
        levelCount = root->height;
    }
    
    return levelCount;
}

// Prints the nodes from least to greatest going through both subtress starting from the left
void AVLTree::InOrderTraversal(TreeNode* node, string& output){
    if(node==nullptr){
    }
    else{
        InOrderTraversal(node->left, output);
        output+=node->name+", ";
        InOrderTraversal(node->right,output);
    }
}

string AVLTree::printInOrder(){
    string output = "";

    InOrderTraversal(root,output);

    if(output.length()!=0){
        output = output.substr(0,output.length()-2);
    }
    cout<< output<<"\n";
    return output;
}
// prints the nodes in the left subtree and then the right
void AVLTree::PreOrderTraversal(TreeNode* node, string& output){ 
//NLR traversal
    if(node==nullptr){
    }
    else{
         output+=node->name+", ";
         PreOrderTraversal(node->left,output);
         PreOrderTraversal(node->right,output);
    }
}

string AVLTree::printPreOrder(){
    string output = "";
    PreOrderTraversal(root,output);
     if(output.length()!=0){
        output = output.substr(0,output.length()-2);
    }
    cout<< output<<"\n";
    return output;
}
// prints the left and right subtrees and then the node
void AVLTree::PostOrderTraversal(TreeNode* node,string& output){
    //LRN traversal
    if(node==nullptr){
    }
    else{
        PostOrderTraversal(node->left,output);
        PostOrderTraversal(node->right,output);
        output+=node->name+", ";
    }
}

string AVLTree::printPostOrder(){
    string output = "";
    PostOrderTraversal(root,output);
     if(output.length()!=0){
        output = output.substr(0,output.length()-2);
    }
    cout<< output<<"\n";
    return output;

}


// parse the name in the string
string parseName(string& command) {

    int spaceIndex = command.find(" ");
    command = command.substr(spaceIndex + 2, command.length());
    int quoteIndex = command.find("\"");
    string data = command.substr(0, quoteIndex);
    return data;
}


// function to parse the id in main
string parseId(string& command) {

    int spaceIndex = command.find(" ");
    string data = command.substr(spaceIndex + 1, command.length());
    return data;
}





