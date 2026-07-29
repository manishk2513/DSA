#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void count(int arr[], int n){
    unordered_map<int, int>map;

    for(int i = 0; i < n; i++){
        map[arr[i]]++;
    }
    for(auto x : map){
        cout<<x.first<<" "<<x.second<<endl;
    }
}

int main(){

    int arr[] = {30, 20, 10, 10, 30, 50, 10, 20, 20, 30, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    count(arr, size);
    
    return 0;
}