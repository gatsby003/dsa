// associative array

// key value mapping 
// insert search delete 
// collision handling method : chainging 

#include <iostream>
#include <list>

using namespace std;

class HashTable {
private:
    list<int> *table;
    list<int> *chain;
    int total_elements;

    int getHash(int key){
        return key % total_elements;
    }

public: 
    HashTable(int n){
        total_elements = n;
        table = new list<int>[total_elements];
        chain = new list<int>[total_elements];
    }

    void insert(int key){
        table[getHash(key)].push_back(key);
    }

    void remove(int key){
        int x = getHash(key);

        list<int> :: iterator i;

        for (i = table[x].begin(); i != table[x].end(); i++){
            if (*i == key)
                break;
        }

        if (i != table[x].end()){
            table[x].erase(i);
        }
    }

      void printAll(){
    // Traverse each index:
    for(int i = 0; i < total_elements; i++){
      cout << "Index " << i << ": ";
      // Traverse the list at current index:
      for(int j : table[i])
        cout << j << " => ";

      cout << endl;
    }
  }
};

int main() {
  // Create a hash table with 3 indices:
  HashTable ht(3);

  // Declare the data to be stored in the hash table:
  int arr[] = {2, 4, 6, 8, 10};

  // Insert the whole data into the hash table:
  for(int i = 0; i < 5; i++)
    ht.insert(arr[i]);

  cout << "..:: Hash Table ::.." << endl;
  ht.printAll();
  
  ht.remove(4);
  cout << endl << "..:: After deleting 4 ::.." << endl;
  ht.printAll();

  return 0;
};