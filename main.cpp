#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Product {
protected:
    string brand;
    string shade;
    int price;

public:
    static int totalProducts;  // Static variable to count total products
    static int totalRevenue;   // Static variable to track total revenue

    virtual void setBrand(const string& a) = 0;
    virtual void setShade(const string& b) = 0;
    virtual void setPrice(int c) = 0;

    virtual string getBrand() const = 0;
    virtual string getShade() const = 0;
    virtual int getPrice() const = 0;

    virtual void description() const = 0;

    // Virtual destructor for proper cleanup of derived objects
    virtual ~Product() {}
};

// Initialize static variables
int Product::totalProducts = 0;
int Product::totalRevenue = 0;

// Derived Class - Lipstick
class Lipstick : public Product {
public:
    Lipstick() {
        totalProducts++;  // Increment totalProducts when a new Lipstick is created
    }

    void setBrand(const string& a) override {
        this->brand = a;
    }

    void setShade(const string& b) override {
        this->shade = b;
    }

    void setPrice(int c) override {
        this->price = c;
        totalRevenue += c;  // Add the price to totalRevenue
    }

    string getBrand() const override {
        return this->brand;
    }

    string getShade() const override {
        return this->shade;
    }

    int getPrice() const override {
        return this->price;
    }

    void description() const override {
        cout << "Lipstick - Brand: " << this->brand << ", Shade: " << this->shade << ", Price: Rs." << this->price << endl;
    }

    ~Lipstick() {
        totalProducts--;  // Decrement totalProducts when a Lipstick is destroyed
        totalRevenue -= this->price;  // Subtract the price from totalRevenue
    }
};

// Derived Class - Gloss
class Gloss : public Product {
public:
    Gloss() {
        totalProducts++;  // Increment totalProducts when a new Gloss is created
    }

    void setBrand(const string& a) override {
        this->brand = a;
    }

    void setShade(const string& b) override {
        this->shade = b;
    }

    void setPrice(int c) override {
        this->price = c;
        totalRevenue += c;  // Add the price to totalRevenue
    }

    string getBrand() const override {
        return this->brand;
    }

    string getShade() const override {
        return this->shade;
    }

    int getPrice() const override {
        return this->price;
    }

    void description() const override {
        cout << "Gloss - Brand: " << this->brand << ", Shade: " << this->shade << ", Price: Rs." << this->price << endl;
    }

    ~Gloss() {
        totalProducts--;  // Decrement totalProducts when a Gloss is destroyed
        totalRevenue -= this->price;  // Subtract the price from totalRevenue
    }
};

// Main Function
int main() {
    // Arrays for the properties
    std::string brands[] = {"Lakme", "Maybelline"};
    std::string shades[] = {"Red Wine", "Crystal Clear"};
    int prices[] = {699, 499};

    // Dynamically allocate array of pointers to Lipstick objects
    Lipstick* mattelipstick[2];

    // Loop to initialize the objects using dynamic memory allocation
    for (int i = 0; i < 2; ++i) {
        mattelipstick[i] = new Lipstick();  // Allocate memory dynamically
        mattelipstick[i]->setBrand(brands[i]);
        mattelipstick[i]->setShade(shades[i]);
        mattelipstick[i]->setPrice(prices[i]);
    }

    // Display the details of each lipstick
    for (int i = 0; i < 2; ++i) {
        mattelipstick[i]->description();
    }

    // Display the static variables
    cout << "Total Products: " << Product::totalProducts << endl;
    cout << "Total Revenue: Rs." << Product::totalRevenue << endl;

    // Deallocate memory using delete
    for (int i = 0; i < 2; ++i) {
        delete mattelipstick[i];  // Release memory
    }

    // Display the static variables after deletion
    cout << "Total Products after deletion: " << Product::totalProducts << endl;
    cout << "Total Revenue after deletion: Rs." << Product::totalRevenue << endl;

    return 0;
}
