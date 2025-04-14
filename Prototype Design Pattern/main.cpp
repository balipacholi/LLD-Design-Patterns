#include <iostream>
using namespace std;

class ProductPrototype
{
public:
    virtual ProductPrototype *clone() = 0;
    virtual void display() = 0;
    virtual ~ProductPrototype() {}
};

// concrete prototype class representing a product
class Product : public ProductPrototype
{
private:
    string name;
    double price;

public:
    Product(const string &name, double price) : name(name), price(price) {}

    ProductPrototype *clone() override
    {
        return new Product(*this); // Copy constructor use for cloning
    }

    void display() override
    {
        cout << "this is a product:" << name << endl;
        cout << "Price: $" << price << endl;
    }
};

int main()
{
    // Create prototype instances of products
    ProductPrototype *product1 = new Product("Laptop", 999.99);
    ProductPrototype *product2 = new Product("SmartPhone", 499.99);

    // Clone the prototypes to create new product isntance
    ProductPrototype *newProduct1 = product1->clone();
    ProductPrototype *newProduct2 = product2->clone();

    // Display product details
    cout << "original Products: \n";
    product1->display();
    product2->display();

    cout << "Cloned Products: \n";
    newProduct1->display();
    newProduct2->display();

    // clean up
    delete product1;
    delete product2;
    delete newProduct1;
    delete newProduct2;

    return 0;
}