#include <iostream>
#include "btreePractice.hpp"


using namespace std;

/* following BST

              50
            /    \
          30      70
         /  \    /  \
       20   40  60   80
*/

int main()
{
    struct Node* root;
    root = NULL;
    root = insert(root, 50);

    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    if (iterativeSearch(root, 15)) { // EDIT
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}