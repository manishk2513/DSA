#include<iostream>
using namespace std;

union PaymentDetail {
    int cash;
    string* cc;
    string* upi;
};

struct Payment
{
    string cname;
    PaymentDetail p;
    int flag;
};


int main(){
    int n;
    int choice;
    int flag;
    cout<<"Enter number of payments: ";
    cin>>n;
    Payment x[n];
    for(int i=0;i<n;i++){
        cout<<"Enter customer name: "<<i+1<<": ";
        cin>>x[i].cname;
        cout<<"Enter payment method (1. cash/2. cc/3. upi): ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"Enter cash amount: ";
                cin>>x[i].p.cash;
                flag = 1;
                break;
            case 2:
                cout<<"Enter credit card number: ";
                cin>>*x[i].p.cc;
                flag = 2;
                break;
            case 3:
                cout<<"Enter UPI ID: ";
                cin>>*x[i].p.upi;
                flag = 3;
                break;
                
            default:
                cout<<"Invalid payment method selected.";
        }

        for(i=0;i<n;i++){
            switch(x[i].flag) {
                case 1:
                    cout<<"Payment Method: Cash"<<x[i].p.cash<<endl;
                    break;
                case 2:
                    cout<<"Payment Method: Credit Card"<<x[i].p.cc<<endl;
                    break;
                case 3:
                    cout<<"Payment Method: UPI"<<x[i].p.upi<<endl;
                    break;
                default:
                    cout<<"Invalid payment method selected.";
            }
        }
    }
    return 0;
}
