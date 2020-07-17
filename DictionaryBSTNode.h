#ifndef BINARYTREESEARCHTEMPLATE_BSTNODE_H
#define BINARYTREESEARCHTEMPLATE_BSTNODE_H

template <typename Key, typename Value>
class DictionaryBSTNode {

    private:
        DictionaryBSTNode<Key, Value>* left;
        DictionaryBSTNode<Key, Value>* right;
        DictionaryBSTNode<Key, Value>* parent;
        Key key;
        Value value;

    public:
        DictionaryBSTNode(Key key, Value value);
        DictionaryBSTNode(Key key, Value value, DictionaryBSTNode* left, DictionaryBSTNode* right);
        Key getKey();
        Value getValue();
        DictionaryBSTNode<Key, Value>* getLeft();
        DictionaryBSTNode<Key, Value>* getRight();
        DictionaryBSTNode<Key, Value>* getParent();
        void setKey(Key key);
        void setLeft(DictionaryBSTNode<Key, Value>* left);
        void setRight(DictionaryBSTNode<Key, Value>* right);
        void setParent(DictionaryBSTNode<Key, Value>* parent);
        bool isLeaf();
        bool onlyRightChildren();
        bool onlyLeftChildren();
};

/* ------------------------------- Public Methods ------------------------------- */
template <typename Key, typename Value>
DictionaryBSTNode<Key, Value>:: DictionaryBSTNode(Key key, Value value) {
    this->key = key;
    this->value = value;
    left = 0;
    right = 0;
    parent = 0;
}

/////////////////////////////////////////////
template <typename Key, typename Value>
DictionaryBSTNode<Key, Value>:: DictionaryBSTNode(Key key, Value value, DictionaryBSTNode* left, DictionaryBSTNode* right) {
    this->key = key;
    this->value = value;
    this->left = left;
    this->right = right;
}

/////////////////////////////////////////////
template <typename Key, typename Value>
Key DictionaryBSTNode<Key, Value>:: getKey() {
    return key;
}

/////////////////////////////////////////////
template <typename Key, typename Value>
Value DictionaryBSTNode<Key, Value>:: getValue() {
    return value;
}

/////////////////////////////////////////////
template <typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBSTNode<Key, Value>:: getLeft() {
    return left;
}

/////////////////////////////////////////////
template <typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBSTNode<Key, Value>:: getRight() {
    return right;
}

/////////////////////////////////////////////
template <typename Key, typename Value>
DictionaryBSTNode<Key, Value>* DictionaryBSTNode<Key, Value>:: getParent() {
    return parent;
}

/////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBSTNode<Key, Value>:: setKey(Key key) {
    this->key = key;
}

/////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBSTNode<Key, Value>:: setLeft(DictionaryBSTNode<Key, Value>* left) {
    this->left = left;
}


/////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBSTNode<Key, Value>:: setRight(DictionaryBSTNode<Key, Value>* right) {
    this->right = right;
}

/////////////////////////////////////////////
template <typename Key, typename Value>
void DictionaryBSTNode<Key, Value>:: setParent(DictionaryBSTNode<Key, Value>* parent) {
    this->parent = parent;
}

/////////////////////////////////////////////
template <typename Key, typename Value>
bool DictionaryBSTNode<Key, Value>:: isLeaf() {
    return (right == 0 && left == 0);
}

/////////////////////////////////////////////
template <typename Key, typename Value>
bool DictionaryBSTNode<Key, Value>:: onlyLeftChildren() {
    return (right == 0 && left != 0);
}

/////////////////////////////////////////////
template <typename Key, typename Value>
bool DictionaryBSTNode<Key, Value>:: onlyRightChildren() {
    return (right != 0 && left == 0);
}
/* ------------------------------------------------------------------------------ */

#endif //BINARYTREESEARCHTEMPLATE_BSTNODE_H