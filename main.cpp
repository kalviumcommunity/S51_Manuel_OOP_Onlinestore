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

// Derived Class - Lipstick
class Lipstick : public Product {
public:
    void setBrand(const string& a) override {
        this->brand = a;
    }

    void setShade(const string& b) override {
        this->shade = b;
    }

    void setPrice(int c) override {
        this->price = c;
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
};

// Derived Class - Gloss
class Gloss : public Product {
public:
    void setBrand(const string& a) override {
        this->brand = a;
    }

    void setShade(const string& b) override {
        this->shade = b;
    }

    void setPrice(int c) override {
        this->price = c;
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
};

// Main Function
int main() {
    Lipstick mattelipstick;
    mattelipstick.setBrand("Lakme");
    mattelipstick.setShade("Red wine");
    mattelipstick.setPrice(699);

    mattelipstick.description();

    Gloss shinygloss;
    shinygloss.setBrand("Maybelline");
    shinygloss.setShade("Crystal Clear");
    shinygloss.setPrice(499);

    shinygloss.description();

    return 0;
}

