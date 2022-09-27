#include <iostream>
#include "avl-tree.hpp"

/* Note: 
	1. You will have to comment main() when unit testing your code because catch uses its own main().
	2. You will submit this main.cpp file and any header files you have on Gradescope. 
	3. Mihir Rao
	4. Due Oct 3
	5. Strted : Sep 18
*/

int main(){
	AVLTree tree;



	//tree.insert("Brandon","45679999");
	//tree.insert("Brian","35459999");
	//tree.insert("Briana","87879999");
	//tree.insert("Bella","95469999");

	// std::cout<<tree.root->name<<endl;
	// std::cout<<tree.root->right->name<<endl;
	// std::cout<<tree.root->right->left->name<<endl;

	tree.insert("Mihir","33333333");
	tree.insert("Mihir","11111111");
	tree.insert("Ryan","22222222");
	tree.insert("Mihir","44444444");
	tree.insert("Ben","55555555");


	//tree.printInOrder();
	//std::cout<<'\n';
	//std::cout<<tree.root->name<<endl;
	// string name = "Mihir";
	// tree.searchName(name);
	// // string id = "55555555";
	// // tree.searchID(id);
	// tree.printPreOrder();
	// std::cout<<'\n';
	// tree.printPostOrder();
	// std::cout<<'\n';
	// cout<<tree.printLevelCount();

	return 0;
}

