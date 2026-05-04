#include<iostream>
using namespace std;

class Maxheap{
	int *arr;
	int size;
	int total_size;

public:
	Maxheap(int n){
		arr = new int[n];
		size = 0;
		total_size = n;
	}

	void insert(int val){
		if(size == total_size){
			cout<<"heap overflow"<<endl;
			return;
		}

		arr[size] = val;
		int index = size;
		size++;

		while(index > 0 && arr[(index - 1)/2] < arr[index]){
			swap(arr[(index - 1)/2], arr[index]);
			index = (index - 1)/2;
		}

		cout<<val<<" inserted in the heap"<<endl;
	}

	void print(){
		for(int i = 0; i < size; i++){
			cout<<arr[i]<<" ";
		}
	}
};

int main(){
	Maxheap heap1(10);

	heap1.insert(78);
	heap1.insert(80);
	heap1.insert(52);
	heap1.insert(10);

	heap1.print();

	return 0;
}