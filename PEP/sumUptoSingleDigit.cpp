#include<iostream>
using namespace std;

int superDigit(string n) {
    int num = 0;

    for (char c : n) { // this step is required if the parameter is a string
        num = num * 10 + (c - '0');
    }
     
    return num % 9? num % 9 : num? 9: num;
}

int main(){

    int digit = superDigit("9875");
    cout<<digit<<endl;

    return 0;
}