#include<iostream>
#include<vector>
using namespace std;

void count(int arr[], int n){
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++){
        if(visited[i] == true) continue;

        int count = 1;
        for(int j = i+1; j < n; j++){
            if(arr[i] == arr[j]){
                visited[j] = true;
                count++;
            }
        }
        cout<<arr[i]<<" "<<count<<endl;
    }
}

int main(){

    int arr[] = {30, 20, 10, 10, 30, 50, 10, 20, 20, 30, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    count(arr, size);
    
    return 0;
}