/*1. Inventory Management System:
- Design an inventory management system for a any small business. Use
an array to store the quantity of different products in stock. Implement
functionalities to add products (quantity of product), update quantities,
display the current inventory.
- Perform inventory management functionalities and alert when a product
is running low on stock.
Note:
- Each element in the array represents a different product.
- Allow the addition and removal of products dynamically*/


#include<iostream>
#include<string>
using namespace std;

class Inventory{
public:
    float p_q[100][2];
    string prod[100];

    int trackingProducts;

    Inventory(){
        trackingProducts = 0;
    }

    void addProduct(string name, float price, float quantity){
        if(trackingProducts < 100){
            prod[trackingProducts] = name;
            p_q[trackingProducts][0] = price;
            p_q[trackingProducts][1] = quantity; 
            trackingProducts++;
            cout << "Product added successfully." << endl;
        } else {
            cout << "Inventory is full. Cannot add more products." << endl;
        }
    }

    void updateQuantity(string name, int newQuantity){
        for(int i = 0; i < trackingProducts; i++){
            if(prod[i] == name){
                p_q[i][1] = newQuantity;
                cout << "Quantity updated successfully." << endl;
                return;
            }
        }
        cout << "Product not found in inventory." << endl;
    }

    void removeProduct(string name){
        for(int i = 0; i < trackingProducts; i++){
            if(prod[i] == name){
                for(int j = i; j < trackingProducts - 1; j++){
                    prod[j] = prod[j + 1];
                    p_q[j][0] = p_q[j + 1][0];
                    p_q[j][1] = p_q[j + 1][1];
                }
                trackingProducts--;
                cout << "Product removed successfully." << endl;
                return;
            }
        }
        cout << "Product not found in inventory." << endl;
    }

    void displayInventory(){
        cout << "Inventory:" << endl;
        cout << "----------------------------------------" << endl;
        cout << "S.No\tProduct Name\tPrice\tQuantity" << endl;
        for(int i = 0; i < trackingProducts; i++){
            cout <<i+1<<".\t"<< prod[i] << "\t\t₹" << p_q[i][0] << "\t" << p_q[i][1] << endl;
        }
        cout << "----------------------------------------" << endl;
    }
};

int main(){
    Inventory a;
    int choice;
    cout<<"\n\t WELCOME \n";
    do{
        cout << "\n1. Add Product\n2. Update Quantity\n3. Remove Product\n4. Display Inventory\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:{
                string name;
                float price, quantity;
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter price: ₹";
                cin >> price;
                cout << "Enter quantity: ";
                cin >> quantity;
                a.addProduct(name, price, quantity);
                break;
            }
            case 2:{
                string name;
                float newQuantity;
                cout << "Enter product name: ";
                cin >> name;
                cout << "Enter new quantity: ";
                cin >> newQuantity;
                a.updateQuantity(name, newQuantity);
                break;
            }
            case 3:{
                string name;
                cout << "Enter product name to remove: ";
                cin >> name;
                a.removeProduct(name);
                break;
            }
            case 4:
                a.displayInventory();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 5);

    return 0;
}

