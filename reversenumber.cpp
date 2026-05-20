#include <iostream>
using namespace std;

void reverseNumber(int n) {
    
    cout << n % 10; 
    reverseNumber(n / 10); 
}

int main() {
    int n;
    cin >> n;
    
    reverseNumber(n);
    return 0;
}