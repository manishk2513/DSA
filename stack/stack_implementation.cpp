#include<iostream>
using namespace std;

class Stack{
public:
	int capacity;
	int top;
	int *arr;

	Stack(int cap){
		this->capacity = cap;
		top = -1;
		arr = new int[capacity];
	}

	bool isFull(){
		return top >= capacity;
	}

	void push(int data){
		if(isFull()){
			cout<<"stack overflow"<<endl;
		} else {
			arr[++top] = data;
			cout<<data<<" is inserted"<<endl;
		}
	}
};

int main(){

	Stack s(5);

	s.push(10);
	s.push(12);


	return 0;
}