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

	string numCommands;

	getline(cin,numCommands);

	 for (int i = 0; i < stoi(numCommands); i++) {

        string command;
        getline(cin, command);

        if (command.find("insert") == 0) {

            string studentName = parseName(command);
            string studentId = parseId(command);
            tree.insert(studentName, studentId);
        }
        else if (command.find("remove") == 0) {

            if (command.find("removeInorder") == 0) {

                string index = parseId(command);
                tree.removeInorder(stoi(index));
            }
            else {

                string studentId = parseId(command);
                tree.removeId(studentId);
            }
        }
        else if (command.find("search") == 0) {

            if (command.find("\"") != -1) {

                string studentName = parseName(command);
                tree.searchName(studentName);                
            }
            else {
                string studentId = parseId(command);
                tree.searchID(studentId);
            }
        }
        else if (command.find("printInorder") == 0) 
            tree.printInOrder();
        else if (command.find("printPreorder") == 0)
            tree.printPreOrder();
        else if (command.find("printPostorder") == 0)
            tree.printPostOrder();
        else if (command.find("printLevelCount") == 0)
            cout<<tree.printLevelCount()<<endl;
        else 
            cout << "invalid command" << endl;
    }
	return 0;
}


