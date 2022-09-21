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



	tree.insert("Brandon","45679999");
	tree.insert("Brian","35459999");
	tree.insert("Briana","87879999");
	tree.insert("Bella","95469999");

	// std::cout<<tree.root->name<<endl;
	// std::cout<<tree.root->right->name<<endl;
	// std::cout<<tree.root->right->left->name<<endl;

	tree.printInOrder();


}

