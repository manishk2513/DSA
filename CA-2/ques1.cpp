// implement a heap, take a random arrray in max heap, insertion and deletion, print heap

#include<iostream>
using namespace std;

class MaxHeap{
	int *arr;
	int size;
	int total_size;

	void heapify(int index){
		while(index > 0 && arr[(index - 1) /2] > arr[index]){
			swap(arr[(index -1)/2], arr[index]);
			index = (index - 1) /2;
		} 
	}

public:
	MaxHeap(int n){
		total_size = n;
		size = 0;
		arr = new int(n);
	}

	void insert(int val){
		if(size == total_size){
			cout<<"overflow";
			return;
		}

		arr[size] = val;
		heapify(size);
		size++;
	}

	void print(){
		cout<<"heap: ";
		for(int i = 0; i < size; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){

int arr[] = {3, 5, 12, 6, 1, 9, 23};
int n = sizeof(arr) / sizeof(arr[0]);

MaxHeap h(n);

for(int i = 0; i < n; i++){
	h.insert(arr[i]);
}

h.print();

	return 0;
}