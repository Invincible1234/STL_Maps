#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cstring> 
using namespace std;

int main() {
    string treeId, treeAd;
    string store;
    string op1, op2;
    int ans;
    map<string, string> adMap;
    map<string, string> idMap;

    ifstream file("trees.csv");

    if (!file.is_open()) {
        cerr << "Error opening the data file: " << strerror(errno) << endl;
        return -1;
    }

    while (getline(file, store, ',')) {
        treeId = store;
        getline(file, treeAd);
        adMap.insert(make_pair(treeId, treeAd));
        idMap.insert(make_pair(treeAd, treeId));
    }

    file.close(); 

    while (true) {
        cout << "Menu" << endl;
        cout << "1. Find tree ids by Address." << endl;
        cout << "2. Find tree address by id." << endl;
        cout << "3. Exit." << endl;
      cout << "Your choice: ";
        cin >> ans;
        cin.ignore(); 

        if (ans == 1) {
            cout << "Enter the address: ";
            getline(cin, op1);
            if (idMap.find(op1) != idMap.end()) {
                cout << "The ID of the address is: " <<idMap[op1] << endl;
              cout << endl;
            } else {
                cout << "Invalid entry, not found." << endl;
              cout << endl;
            }
        } else if (ans == 2) {
            cout << "Enter the id: ";
            cin >> op2;
            if (adMap.find(op2) != adMap.end()) {
                cout << "The address of the ID is: "<<adMap[op2] << endl;
              cout << endl;
            } else {
                cout << "Invalid entry, not found." << endl;
              cout << endl;
            }
        } else if (ans == 3) {
            cout << "Exiting..." << endl;
           cout << endl;
            break; 
        } else {
            cout << "Invalid option. Please try again." << endl;
          cout << endl;
        }
    }

    return 0;
}
