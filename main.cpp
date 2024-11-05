#include <iostream>
#include <string>
using namespace std;

class ProductStats {  // SRP - Handles statistics only
public:
    static int totalProducts;
    static int totalRevenue;

    static void addProduct(int price) {
        totalProducts++;
        totalRevenue += price;
    }

    static void removeProduct(int price) {
        totalProducts--;
        totalRevenue -= price;
    }

    static void displayStats() {
        cout << "Total Products: " << totalProducts << endl;
        cout << "Total Revenue: Rs." << totalRevenue << endl;
    }
};

// Initialize static variables
int ProductStats::totalProducts = 0;
int ProductStats::totalRevenue = 0;

class Product {
protected:
    string brand;
    string shade;
    int price;

public:
    virtual void setBrand(const string& a) = 0;
    virtual void setShade(const string& b) = 0;
    virtual void setPrice(int c) = 0;

    virtual string getBrand() const = 0;
    virtual string getShade() const = 0;
    virtual int getPrice() const = 0;

    virtual void description() const = 0;
    virtual void description(bool detailed) const = 0;

    virtual ~Product() {
        cout << "Product destructor called!" << endl;
    }
};

// Derived Class - Lipstick (OCP - Extending Product without modification)
class Lipstick : public Product {
public:
    Lipstick() {
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
        ProductStats::addProduct(c);  // Adding to stats
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

    void description(bool detailed) const override {
        cout << "Lipstick - Brand: " << this->brand 
             << ", Shade: " << this->shade 
             << ", Price: Rs." << this->price 
             << (detailed ? " [Popular Choice!]" : "") << endl;
    }

    ~Lipstick() {
        ProductStats::removeProduct(this->price);  // Removing from stats
        cout << "Lipstick destructor called!" << endl;
    }
};

// Derived Class - Foundation (Extends Product and follows OCP)
class Foundation : public Product {
private:
    string skinType;

public:
    Foundation() {
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
        ProductStats::addProduct(c);  // Adding to stats
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
        cout << "Foundation - Brand: " << this->brand << ", Shade: " << this->shade 
             << ", Price: Rs." << this->price << ", Skin Type: " << this->skinType << endl;
    }

    void description(bool detailed) const override {
        cout << "Foundation - Brand: " << this->brand 
             << ", Shade: " << this->shade 
             << ", Price: Rs." << this->price 
             << ", Skin Type: " << this->skinType 
             << (detailed ? " [Best for dry skin!]" : "") << endl;
    }

    ~Foundation() {
        ProductStats::removeProduct(this->price);  // Removing from stats
        cout << "Foundation destructor called!" << endl;
    }
};

// Main Function
int main() {
    string brands[] = {"Lakme", "Maybelline"};
    string shades[] = {"Red Wine", "Crystal Clear"};
    int prices[] = {699, 499};

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
        mattelipstick[i]->description(true);
    }
    foundation->description();
    foundation->description(true);

    ProductStats::displayStats();

    for (int i = 0; i < 2; ++i) {
        delete mattelipstick[i];
    }
    delete foundation;

    ProductStats::displayStats();

    return 0;
}
