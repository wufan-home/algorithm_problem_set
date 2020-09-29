/*
 * Given a binary tree, find the longest path from root down to some node 
 * such that values along with this path are distinct. Return the length is good.
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct tree {
    int x;
    tree *left;
    tree *right;

    tree(int val) : x(val), left(NULL), right(NULL) {}
};

void getUniqeValuePath(tree *root, unordered_set<int> &distincts, int &maxLength) {
    if (root == NULL)
        return;

    if (distincts.size() > maxLength)
        maxLength = distincts.size();

    if (root->left != NULL && distincts.find(root->left->x) == distincts.end()) {
        distincts.insert(root->left->x);
        getUniqeValuePath(root->left, distincts, maxLength);
        distincts.erase(root->left->x);
    }

    if (root->right != NULL && distincts.find(root->right->x) == distincts.end()) {
        distincts.insert(root->right->x);
        getUniqeValuePath(root->right, distincts, maxLength);
        distincts.erase(root->right->x);
    }
}

int solution(tree *root) {
    if (root == NULL) {
        return 0;
    }

    int maxLength = 0;
    unordered_set<int> distincts;
    distincts.insert(root->x);
    getUniqeValuePath(root, distincts, maxLength);
    return maxLength;
}

int main(void) {
    tree *root = NULL;

    root = new tree(1);
    cout << "Test 1: " << solution(root) << endl;
    delete root;

    root = new tree(1);
    root->left = new tree(2);
    cout << "Test 2: " << solution(root) << endl;
    delete root->left;
    delete root;

    root = new tree(1);
    root->left = new tree(1);
    cout << "Test 3: " << solution(root) << endl;
    delete root->left;
    delete root;

    root = new tree(1);
    root->left = new tree(2);
    root->left->right = new tree(1);
    cout << "Test 4: " << solution(root) << endl;
    delete root->left->right;
    delete root->left;
    delete root;

    return 1;
}
