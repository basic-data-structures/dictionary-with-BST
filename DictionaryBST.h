//
// Created by valentina on 4/6/20.
//

#ifndef BINARYTREESEARCHTEMPLATE_BST_H
#define BINARYTREESEARCHTEMPLATE_BST_H

#include "DictionaryBSTNode.h"
#include <iostream>

using namespace std;

template <typename Key, typename Value>
class DictionaryBST {

    private:
        DictionaryBSTNode<Key, Value>* root;

    public:
        DictionaryBST();
        ~DictionaryBST();
        void insert(Key key, Value value);
        int getHeight();
        DictionaryBSTNode<Key, Value>* getRoot();
        DictionaryBSTNode<Key, Value>* getMaxNode(DictionaryBSTNode<Key, Value>* treeNode);
        DictionaryBSTNode<Key, Value>* getMinNode(DictionaryBSTNode<Key, Value>* treeNode);
        void deleteKey(Key key);
        void deleteAll();
        bool isBalanced();
        bool exists(Key key);
        Key successor(Key key);
        Key predecessor(Key key);
        void inOrder();
        void preOrder();
        void postOrder();
        void displayData();

private:
        DictionaryBSTNode<Key, Value>* insert(DictionaryBSTNode<Key, Value>* treeNode, Key key, Value value);
        bool isBalanced(DictionaryBSTNode<Key, Value>* treeNode);
        int getHeight(DictionaryBSTNode<Key, Value>*treeNode);
        DictionaryBSTNode<Key, Value>* search(DictionaryBSTNode<Key, Value>* treeNode, Key key);
        DictionaryBSTNode<Key, Value>* deleteKey(DictionaryBSTNode<Key, Value>* treeNode, Key key);
        DictionaryBSTNode<Key, Value>* deleteCaseLeaf(DictionaryBSTNode<Key, Value>* treeNode);
        DictionaryBSTNode<Key, Value>* deleteCaseOneChild(DictionaryBSTNode<Key, Value>* treeNode);
        DictionaryBSTNode<Key, Value>* deleteCaseTwoChilds(DictionaryBSTNode<Key, Value>* treeNode);
        void deleteAll(DictionaryBSTNode<Key, Value>* treeNode);
        Key successor(DictionaryBSTNode<Key, Value>* treeNode);
        Key predecessor(DictionaryBSTNode<Key, Value>* treeNode);
        void inOrder(DictionaryBSTNode<Key, Value>* treeNode);
        void preOrder(DictionaryBSTNode<Key, Value>* treeNode);
        void postOrder(DictionaryBSTNode<Key, Value>* treeNode);
};

/* ------------------------------- Public Methods ------------------------------- */

template <typename Key, typename Value>
DictionaryBST<Key, Value>:: DictionaryBST() {
    root = 0;
}

////////////////////////////////////////////////
template <typename Key, typename Value>
DictionaryBST<Key, Value>:: ~DictionaryBST() {
    deleteAll();
}

////////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBST<Key, Value>:: insert(Key key, Value value) {
    root = insert(root, key, value);
}

////////////////////////////////////////////////
template <typename Key, typename Value>
int DictionaryBST<Key, Value>:: getHeight() {
    return getHeight(root);
}

////////////////////////////////////////////////
template <typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBST<Key, Value>:: getRoot() {
    return root;
}

////////////////////////////////////////////////
template <typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBST<Key, Value>:: getMaxNode(DictionaryBSTNode<Key, Value>* treeNode) {
    if (!root) {
        cout <<  "The DictionaryBST is empty!" << endl;
        return 0;
    }
    while(treeNode->getRight())
        treeNode = treeNode->getRight();
    return treeNode;
}

////////////////////////////////////////////////
template <typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBST<Key, Value>:: getMinNode(DictionaryBSTNode<Key, Value>* treeNode) {
    if (!root) {
        cout <<  "The DictionaryBST is empty!" << endl;
        return 0;
    }
    while(treeNode->getLeft())
        treeNode = treeNode->getLeft();

    return treeNode;
}

////////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBST<Key, Value>:: deleteKey(Key key) {
    root = deleteKey(root, key);
}

////////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBST<Key, Value>:: deleteAll() {
    deleteAll(root);
}

////////////////////////////////////////////////
template <typename Key, typename Value>
bool DictionaryBST<Key, Value>:: isBalanced() {
    return isBalanced(root);
}

////////////////////////////////////////////////
template <typename Key, typename Value>
bool DictionaryBST<Key, Value>:: exists(Key key) {
    DictionaryBSTNode<Key, Value>* result = search(root, key);
    return result != 0;
}

////////////////////////////////////////////////
template <typename Key, typename Value>
Key DictionaryBST<Key, Value>::successor(Key key) {

    DictionaryBSTNode<Key, Value>* keyNode = search(root, key);

    if(keyNode == 0)
        return -1;
    else
        return successor(keyNode);
}

////////////////////////////////////////////////
template <typename Key, typename Value>
Key DictionaryBST<Key, Value>::predecessor(Key key) {

    DictionaryBSTNode<Key, Value>* keyNode = search(root, key);

    if(keyNode == 0)
        return -1;
    else
        return predecessor(keyNode);

}

////////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBST<Key, Value>:: inOrder() {
    inOrder(root);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBST<Key, Value>:: preOrder() {
    preOrder(root);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBST<Key, Value>:: postOrder() {
    postOrder(root);
    cout << "\n";
}

////////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBST<Key, Value>:: displayData() {
    cout << "\tIn order:\n";
    inOrder();
    cout << "\tPre order:\n";
    preOrder();
    cout << "\tPost order:\n";
    postOrder();

    cout << "\n\tThe root of this DictionaryBST is: " << root->getKey() << "\n";
    cout << "\tThe height of this DictionaryBST is: " << getHeight() << "\n";
    cout << "\tMax key: " << getMaxNode(root)->getKey() << " its value is: " << getMaxNode(root)->getValue() << "\n";
    cout << "\tMin key: " << getMinNode(root)->getKey() << " its value is: " << getMinNode(root)->getValue() << "\n";

    if (isBalanced())
        cout << "\tDictionaryBST is balanced! " << "\n\n";
    else
        cout << "\tDictionaryBST is not balanced! " << "\n\n";

    cout << "____________________________________\n";
}

/* ------------------------------------------------------------------------------ */


/* ------------------------------- Private Methods ------------------------------ */

////////////////////////////////////////////////
template <typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBST<Key, Value>:: insert(DictionaryBSTNode<Key, Value>* treeNode, Key key, Value value) {
    if (treeNode == 0)
        treeNode = new DictionaryBSTNode<Key, Value>(key, value);

    else if (key > treeNode->getKey())
        treeNode->setRight(insert(treeNode->getRight(), key, value));

    else
        treeNode->setLeft(insert(treeNode->getLeft(), key, value));

    return treeNode;
}

////////////////////////////////////////////////
template<typename Key, typename Value>
int DictionaryBST<Key, Value>:: getHeight(DictionaryBSTNode<Key, Value>* treeNode) {
    if (!treeNode)
        return 0;
    return 1 + max(getHeight(treeNode->getLeft()), getHeight(treeNode->getRight()));
}

////////////////////////////////////////////////
template<typename Key, typename Value>
bool DictionaryBST<Key, Value>:: isBalanced(DictionaryBSTNode<Key, Value>* treeNode) {
    if (!treeNode)
        return false;

    int leftHeight = getHeight(treeNode->getLeft());
    int rightHeight = getHeight(treeNode->getRight());

    return abs(leftHeight - rightHeight) <= 1;
}

////////////////////////////////////////////////
template<typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBST<Key, Value>:: deleteCaseLeaf(DictionaryBSTNode<Key, Value>* treeNode) {
    delete treeNode;
    return 0;
}

////////////////////////////////////////////////
template<typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBST<Key, Value>:: deleteCaseOneChild(DictionaryBSTNode<Key, Value>* treeNode) {

    if (treeNode->onlyRightChildren()) {
        DictionaryBSTNode<Key, Value>* rightNode = treeNode->getRight();
        rightNode->setParent(treeNode->getParent());
        DictionaryBSTNode<Key, Value>* aux = treeNode;
        delete aux;
        return rightNode;
    }

    else if (treeNode->onlyLeftChildren()) {
        DictionaryBSTNode<Key, Value>* leftNode = treeNode->getLeft();
        leftNode->setParent(treeNode->getParent());
        DictionaryBSTNode<Key, Value>* aux = treeNode;
        delete aux;
        return leftNode;
    }
}

////////////////////////////////////////////////
template<typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBST<Key, Value>:: deleteCaseTwoChilds(DictionaryBSTNode<Key, Value>* treeNode) {
    Key successorKey = successor(treeNode->getKey());
    treeNode->setKey(successorKey);
    treeNode->setRight(deleteKey(treeNode->getRight(), successorKey));
    return treeNode;
}

////////////////////////////////////////////////
template<typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBST<Key, Value>:: deleteKey(DictionaryBSTNode<Key, Value>* treeNode, Key key) {

    if (treeNode == 0)
        return 0;

    if(treeNode->getKey() == key) {

        if (treeNode->isLeaf())
            treeNode = deleteCaseLeaf(treeNode);

        else if (treeNode->onlyRightChildren() || treeNode->onlyLeftChildren())
            treeNode = deleteCaseOneChild(treeNode);

        else
            treeNode = deleteCaseTwoChilds(treeNode);
    }

    else if (treeNode->getKey() < key)
        treeNode->setRight(deleteKey(treeNode->getRight(), key));

    else
        treeNode->setLeft(deleteKey(treeNode->getLeft(), key));

    return treeNode;
}

////////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBST<Key, Value>:: deleteAll(DictionaryBSTNode<Key, Value>* treeNode) {
    if(treeNode == 0)
        return;
    deleteAll(treeNode->getLeft());
    deleteAll(treeNode->getRight());
    delete treeNode;
}

////////////////////////////////////////////////
template <typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBST<Key, Value>:: search(DictionaryBSTNode<Key, Value> *treeNode, Key key) {
    if (treeNode == 0 || treeNode->getKey() == key)
        return treeNode;
    if (key > treeNode->getKey())
        return search(treeNode->getRight(), key);
    return search(treeNode->getLeft(), key);
}

////////////////////////////////////////////////
template<typename Key, typename Value>
Key DictionaryBST<Key, Value>:: successor(DictionaryBSTNode<Key, Value>* treeNode) {

    if (!treeNode->onlyRightChildren()) {
        DictionaryBSTNode<Key, Value>* minNode = getMinNode(treeNode->getRight());
        return minNode->getKey();
    }

    DictionaryBSTNode<Key, Value>* successor = 0;
    DictionaryBSTNode<Key, Value>* predecessor = root;

    while (predecessor != treeNode) {
        if (treeNode->getKey() < predecessor->getKey()) {
            successor = predecessor;
            predecessor = predecessor->getLeft();
        }
        else
            predecessor = predecessor->getRight();
    }
    return successor->getKey();
}

////////////////////////////////////////////////
template<typename Key, typename Value>
Key DictionaryBST<Key, Value>:: predecessor(DictionaryBSTNode<Key, Value>* treeNode) {
    if (!treeNode->onlyLeftChildren())
        return getMinNode(treeNode->onlyLeftChildren());

    DictionaryBSTNode<Key, Value>* successor = 0;
    DictionaryBSTNode<Key, Value>* predecessor = root;

    while (predecessor != treeNode) {
        if (treeNode->getKey() < predecessor->getKey()) {
            successor = predecessor;
            predecessor = predecessor->getRight();
        }
        else
            predecessor = predecessor->getLeft();
    }
    return successor->getKey();
}

////////////////////////////////////////////////
template<typename Key, typename Value>
void DictionaryBST<Key, Value>:: inOrder(DictionaryBSTNode<Key, Value>* treeNode) {
    if (!treeNode)
        return;
    inOrder(treeNode->getLeft());
    cout << "\t\tKey: " << treeNode->getKey() << "\t\tValue: " << treeNode->getValue() << "\n";
    inOrder(treeNode->getRight());
}

/////////////////////////////////////////////////////////////////////////////////////////
template<typename Key, typename Value>
void DictionaryBST<Key, Value>:: preOrder(DictionaryBSTNode<Key, Value>* treeNode) {
    if (!treeNode)
        return;
    cout << "\t\tKey: " << treeNode->getKey() << "\t\tValue: " << treeNode->getValue() << "\n";
    preOrder(treeNode->getLeft());
    preOrder(treeNode->getRight());
}

/////////////////////////////////////////////////////////////////////////////////////////
template<typename Key, typename Value>
void DictionaryBST<Key, Value>:: postOrder(DictionaryBSTNode<Key, Value>* treeNode) {
    if (!treeNode)
        return;
    postOrder(treeNode->getLeft());
    postOrder(treeNode->getRight());
    cout << "\t\tKey: " << treeNode->getKey() << "\t\tValue: " << treeNode->getValue() << "\n";
}

/* ------------------------------------------------------------------------------ */



#endif //BINARYTREESEARCHTEMPLATE_BST_H