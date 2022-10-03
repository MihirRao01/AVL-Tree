#include "../src/avl-tree.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the Project1 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp && build/test
*/

/*TEST_CASE("Left Rotation Test", "[Rotation]"){
	
		AVLTree tree;   
		tree.insert("Mihir","11111111");
		tree.insert("Ryan","22222222");
		tree.insert("Jose","33333333");

		REQUIRE(tree.printLevelCount()==2);
}

TEST_CASE("Right Rotation Test", "[Rotation]"){

	AVLTree tree;
	tree.insert("Mihir","33333333");
	tree.insert("Ryan","22222222");
	tree.insert("Jose","11111111");

	REQUIRE(tree.printLevelCount()==2);

}

TEST_CASE("Left-Right Rotation Test", "[Rotation]"){
	
	AVLTree tree;
	tree.insert("Mihir","33333333");
	tree.insert("Ryan","11111111");
	tree.insert("Jose","22222222");

	REQUIRE(tree.printLevelCount()==2);
}

TEST_CASE("Right-Left Rotation Test", "[Rotation]"){
	
	AVLTree tree;
	tree.insert("Mihir","11111111");
	tree.insert("Ryan","33333333");
	tree.insert("Jose","22222222");

	REQUIRE(tree.printLevelCount()==2);
}

TEST_CASE("1,000 insertions test", "[insertion]"){
	AVLTree tree;
	for(int i=10000000; i<10001000; i++){
		tree.insert("Mihir",to_string(i));
	}

	REQUIRE(tree.printLevelCount()==10);
}

TEST_CASE("10,000 insertion test", "[insertion]"){
	AVLTree tree;
	for(int i=10000000; i<100010000; i++){
		tree.insert("Mihir",to_string(i));
	}

	REQUIRE(tree.printLevelCount()==14);
}

TEST_CASE("100,000 insertion test", "[insertion]"){
	AVLTree tree;
	for(int i=10000000; i<10100000; i++){
		tree.insert("Mihir",to_string(i));
	}

	REQUIRE(tree.printLevelCount()==17);
}
*/

TEST_CASE("Test EMPTY Tree", "[EMPTY]"){
	AVLTree tree;
	REQUIRE(tree.printInOrder() == "");
    REQUIRE(tree.printPreOrder() == "");
    REQUIRE(tree.printPostOrder() == "");
    REQUIRE(tree.printLevelCount() == 0);
}

TEST_CASE("InorderTraversal","[Traversal]"){
	AVLTree tree;
	tree.insert("Mihir","11111111");
	tree.insert("Ryan","33333333");
	tree.insert("Jose","22222222");
	tree.insert("Daniel","44444444");
	REQUIRE(tree.printInOrder() == "Mihir, Jose, Ryan, Daniel");
}

TEST_CASE("PostOrder Traversal","[Traversal]"){
	AVLTree tree;
	tree.insert("Mihir","11111111");
	tree.insert("Ryan","33333333");
	tree.insert("Jose","22222222");
	tree.insert("Daniel","44444444");
	REQUIRE(tree.printPostOrder() == "Mihir, Daniel, Ryan, Jose");
}

TEST_CASE("PreOrder Traversal","[Traversal]"){
	AVLTree tree;
	tree.insert("Mihir","11111111");
	tree.insert("Ryan","33333333");
	tree.insert("Jose","22222222");
	tree.insert("Daniel","44444444");
	REQUIRE(tree.printPreOrder() == "Jose, Mihir, Ryan, Daniel");
}

