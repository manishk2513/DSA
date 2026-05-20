#include<iostream>
#include<vector>
using namespace std;

class HashTable{
	vector<int> table;
	int size;

public:
	HashTable(int s){
		size = s;
		table.resize(size, -1);
	}

	int hash(int key){
		return (key % size);
	}

	void linearInsert(int key){
		int index = hash(key);
		int i = 0;

		while(table[(index + i) % size] != -1){
			i++;
			if(i == size){
				cout<<"HashTable is full"<<endl;
				return;
			}
		}

		table[(index + i) % size] = key;
		cout<<key<<" is insrted in the HashTable"<<endl;
	}

	void quadraticInsert(int key){
		int index = hash(key);
		int i = 0;

		while(table[(index + i*i) % size] != -1){
			i++;
			if(i == size){
				cout<<"HashTable is full"<<endl;
				return;
			}
		}

		table[(index + i*i) % size] = key;
		cout<<key<<" is inserted in the HashTable"<<endl;
	}

	void print(){
		for(int i = 0; i < size; i++){
			cout<<i<<" -> ";
			if(table[i] == -1){
				cout<<"Empty";
			} else {
				cout<<table[i];
			}
			cout<<endl;
		}
	}

	void searchLinear(int key){
		int index = hash(key);
		int i = 0;

		while(table[(index + i) % size] != -1){
			if(table[(index + i) % size] == key){
				cout<<"target found"<<endl;
				return;
			}
		}

		cout<<"target not found!"<<endl;
	}

	void searchQuadratic(int key){
		int index = 0;
		int i = 0;

		while(table[(index + i*i) % size] != -1){
			if(table[(index + i*i) % size] == key){
				cout<<"target found"<<endl;
				return;
			}
		}

		cout<<"target not found!"<<endl;
	}
};

int main(){
	int size;
	cout<<"enter size of the HashTables: ";
	cin>>size;

	HashTable *linTable = new HashTable(size); 
	HashTable *quadTable = new HashTable(size);


	cout<<"Enter the keys in the linearTable: "<<endl;
	for(int i = 0; i < size; i++){
		int key;
		cout<<"input key: ";
		cin>>key;
		linTable->linearInsert(key);
	}

	cout<<"Displaying the HashTable:"<<endl;
	linTable->print();

	cout<<"Enter the keys in the quadTable: "<<endl;
	for(int i = 0; i < size; i++){
		int key;
		cout<<"input key: ";
		cin>>key;
		quadTable->quadraticInsert(key);
	}

	cout<<"Displaying the HashTable:"<<endl;
	quadTable->print();

	return 0;
}