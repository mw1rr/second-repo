#include <iostream>
#include <string>
using namespace std;

struct House {
    string address;
    double price;
    double size;
    string phone_number;
};

int main() {
    int n;
    int max = -99999999;
    cout << "Enter the number of houses: ";
    cin >> n;

    House house[n];

    for(int i = 0; i < n; i++) {
        cout << "House " << i + 1 << ": " << endl;
        cout << "House's address: ";
        cin >> house[i].address;

        cout << "Price: ";
        cin >> house[i].price;

        cout << "Size: ";
        cin >> house[i].size;

        cout << "Telethon number of owner: ";
        cin >> house[i].phone_number;
    }
    int max_index = 0;
    for(int i = 0; i < n; i++) {
        if(house[i].price > max) {
            max = house[i].price;
            max_index = i;
        }
    }

    cout << "      " << endl;
    cout << "House's address: " << house[max_index].address << endl;
    cout << "Price: " << house[max_index].price << endl;
    cout << "Size: " << house[max_index].size << endl;
    cout << "Telethon number of owner: " << house[max_index].phone_number << endl;
    cout << "      " << endl;
}