#include<iostream>
#include<vector>
using namespace std;

class HashTable {
	vector<vector<int>> table;
	int size;

public:
	HashTable(int s){
		size = s;
		table.resize(size);
	}

	int hash(int key){
		return (key%size);
	}

	void insert(int key){
		int index = hash(key);
		table[index].push_back(key);

		cout<<key<<" inserted into HashTable"<<endl;
	}

	void search(int key){
		int index = hash(key);

		for(int k : table[index]){
			if(key == k){
				cout<<"target found:)"<<endl;
				return;
			}
		}
		cout<<"target not found:("<<endl;
	}

	void print(){
		for(vector<int> v : table){
			cout<<" -> ";

			for(int key : v){
				cout<<key<<", ";
			}
			cout<<endl;
		} 
	}
};

int main(){

	int size;
	cout<<"enter size of the HashTable: ";
	cin>>size;

	HashTable *t = new HashTable(size);

	cout<<"enter the keys in the HashTable:"<<endl;
	for(int i = 0; i < size; i++){
		int key;
		cout<<"input key: ";
		cin>>key;
		t->insert(key);
	}




	// t->insert(43);
	// t->insert(99);
	// t->insert(23);
	// t->insert(52);
	// t->insert(34);
	
	cout<<"displaying the HashTable:"<<endl;
	t->print();
	

	return 0;
}