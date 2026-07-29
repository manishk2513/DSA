#include<iostream>
using namespace std;

struct Stack {
private:
	int top;
	int capacity;
	int *arr;
public:
	Stack(int size = 10){
		capacity = size;
		arr = new int[capacity];
		top = -1;
	}

	~Stack(){
		delete[] arr;
	}

	void push(int val){
		if(top == capacity - 1){
			resize();
		}
		arr[++top] = val;
	}

	int pop(){
		if(isEmpty()){
			throw underflow_error("Stack is Empty");
		}
		return arr[top--]; 
	}

	int peek(){
		if(isEmpty()){
			throw underflow_error("Stack is Empty");
		}
		return arr[top];
	}

	bool isEmpty(){
		return top == -1;
	}

	int size(){
		return top + 1;
	}

	bool isFull(){
		return top == capacity - 1;
	}

private:
	void resize(){
		capacity *= 2;
		int* newArr = new int[capacity];

		for(int i = 0; i <= top; i++){
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
	}

}