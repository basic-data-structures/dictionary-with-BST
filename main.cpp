#include "DictionaryBST.h"

int main() {

    DictionaryBST<int, string>* dictionary = new DictionaryBST<int, string>;

    string value;

    for (int i = 0; i < 5; i ++) {
        cout << "\tInsert the value: ";
        cin >> value;
        dictionary->insert(i*i, value);
    }

    cout << "\n";

    dictionary->displayData();

    delete dictionary;

    return 0;
}