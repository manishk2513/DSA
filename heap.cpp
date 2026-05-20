
#include <iostream>
using namespace std;

class MaxHeap{
    int *arr;
    int size;
    int totalsize;
    public:
    MaxHeap(int n){
        arr = new int[n];
        size = 0;
        totalsize = n;
    }
    void insert(int val){
        if(size==totalsize-size){
            cout<<"Heap overflow"<<endl;
            return;
        }
    
    arr[size] = val;
    int index = size;
    size++;

    while(index>0&&arr[(index-1)/2]<arr[index]){
        swap(arr[(index-1)/2],arr[index]);
        index = (index-1)/2;
    }
    cout<<val<<"Insert in head"<<endl;

}
    void displayheap(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }

    }
};
int main(){

    MaxHeap h(10);

    h.insert(70);
    h.insert(59);
    h.insert(87);
    h.insert(91);

    h.displayheap();



}