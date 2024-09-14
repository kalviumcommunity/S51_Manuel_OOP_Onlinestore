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

    // Static member function to display static variables
    static void displayStats() {
        cout << "Total Products: " << totalProducts << endl;
        cout << "Total Revenue: Rs." << totalRevenue << endl;
    }

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

// Derived Class - Foundation
class Foundation : public Product {
private:
    string skinType; // New private member specific to Foundation

public:
    Foundation() {
        totalProducts++;  // Increment totalProducts when a new Foundation is created
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

    void setSkinType(const string& type) {
        this->skinType = type;
    }

    string getBrand() const override {
        return this->brand;
    }

    string getShade() const override {
        return this->shade;
    }

    string getSkinType() const {
        return this->skinType;
    }

    int getPrice() const override {
        return this->price;
    }

    void description() const override {
        cout << "Foundation - Brand: " << this->brand << ", Shade: " << this->shade << ", Price: Rs." << this->price
             << ", Skin Type: " << this->skinType << endl;
    }

    ~Foundation() {
        totalProducts--;  // Decrement totalProducts when a Foundation is destroyed
        totalRevenue -= this->price;  // Subtract the price from totalRevenue
    }
};

// Main Function
int main() {
    // Arrays for the properties
    std::string brands[] = {"Lakme", "Maybelline"};
    std::string shades[] = {"Red Wine", "Crystal Clear"};
    int prices[] = {699, 499};

    // Lipstick objects
    Lipstick* mattelipstick[2];
    for (int i = 0; i < 2; ++i) {
        mattelipstick[i] = new Lipstick();  // Allocate memory dynamically
        mattelipstick[i]->setBrand(brands[i]);
        mattelipstick[i]->setShade(shades[i]);
        mattelipstick[i]->setPrice(prices[i]);
    }

    // Foundation object
    Foundation* foundation = new Foundation();
    foundation->setBrand("Loreal");
    foundation->setShade("Ivory");
    foundation->setPrice(999);
    foundation->setSkinType("Dry");

    // Display the details of each lipstick
    for (int i = 0; i < 2; ++i) {
        mattelipstick[i]->description();
    }

    // Display foundation details
    foundation->description();

    // Use the static member function to display the statistics
    Product::displayStats();

    // Deallocate memory using delete
    for (int i = 0; i < 2; ++i) {
        delete mattelipstick[i];  // Release memory
    }
    delete foundation;

    // Display the static variables after deletion using the static function
    Product::displayStats();

    return 0;
}
