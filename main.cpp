#include <iostream>
#include <string>
using namespace std;

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

    static void displayStats() {
        cout << "Total Products: " << totalProducts << endl;
        cout << "Total Revenue: Rs." << totalRevenue << endl;
    }


    virtual ~Product() {
        cout << "Product destructor called!" << endl;
    }
};

// Initialize static variables
int Product::totalProducts = 0;
int Product::totalRevenue = 0;

// Derived Class - Lipstick (Single Inheritance from Product)
class Lipstick : public Product {
public:
    // Constructor
    Lipstick() {
        totalProducts++;
        cout << "Lipstick constructor called!" << endl;
    }

    void setBrand(const string& a) override {
        this->brand = a;
    }

    void setShade(const string& b) override {
        this->shade = b;
    }

    void setPrice(int c) override {
        this->price = c;
        totalRevenue += c; 
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

    // Destructor
    ~Lipstick() {
        totalProducts--;  
        totalRevenue -= this->price;  
        cout << "Lipstick destructor called!" << endl;
    }
};

// Derived Class - Gloss (Hierarchical Inheritance from Product)
class Gloss : public Product {
public:
    // Constructor
    Gloss() {
        totalProducts++;  
        cout << "Gloss constructor called!" << endl;
    }

    void setBrand(const string& a) override {
        this->brand = a;
    }

    void setShade(const string& b) override {
        this->shade = b;
    }

    void setPrice(int c) override {
        this->price = c;
        totalRevenue += c;
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

    // Destructor
    ~Gloss() {
        totalProducts--;  
        totalRevenue -= this->price;
        cout << "Gloss destructor called!" << endl;
    }
};

// Derived Class - Foundation (Single Inheritance with Extension)
class Foundation : public Product {
private:
    string skinType; 

public:
    // Constructor
    Foundation() {
        totalProducts++;  
        cout << "Foundation constructor called!" << endl;
    }

    void setBrand(const string& a) override {
        this->brand = a;
    }

    void setShade(const string& b) override {
        this->shade = b;
    }

    void setPrice(int c) override {
        this->price = c;
        totalRevenue += c;
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

    // Destructor
    ~Foundation() {
        totalProducts--;  
        totalRevenue -= this->price;
        cout << "Foundation destructor called!" << endl;
    }
};

// Main Function
int main() {
    // Arrays for the properties
    std::string brands[] = {"Lakme", "Maybelline"};
    std::string shades[] = {"Red Wine", "Crystal Clear"};
    int prices[] = {699, 499};

    // Create Lipstick objects (demonstrating single inheritance)
    Lipstick* mattelipstick[2];
    for (int i = 0; i < 2; ++i) {
        mattelipstick[i] = new Lipstick();  
        mattelipstick[i]->setBrand(brands[i]);
        mattelipstick[i]->setShade(shades[i]);
        mattelipstick[i]->setPrice(prices[i]);
    }

    Foundation* foundation = new Foundation();
    foundation->setBrand("Loreal");
    foundation->setShade("Ivory");
    foundation->setPrice(999);
    foundation->setSkinType("Dry");

    for (int i = 0; i < 2; ++i) {
        mattelipstick[i]->description();
    }
    foundation->description();

    Product::displayStats();


    for (int i = 0; i < 2; ++i) {
        delete mattelipstick[i];  
    }
    delete foundation;

    Product::displayStats();

    return 0;
}
