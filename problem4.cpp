#include <iostream>
#include <string>
using namespace std;

class Product {
	string productName;
	float price;
public:
	Product(string name, float price) {
		this->productName = name;
		this->price = price;
	}
	void getCostlier(float discountPercentage) {
		this->price = this->price * (1 - discountPercentage / 100);
		cout << "Updated price of " << this->productName << ": " << this->price << endl;
	}
};

int main() {
	string name;
	float price, discount;
	cout << "Enter product name: ";
	getline(cin, name);
	cout << "Enter price: ";
	cin >> price;
	cout << "Enter discount percentage: ";
	cin >> discount;
	Product p(name, price);
	p.getCostlier(discount);
	return 0;
}