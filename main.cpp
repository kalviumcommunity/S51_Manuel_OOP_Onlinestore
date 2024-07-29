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

class Lipstick : public Product {
public:
    void setBrand(const string& a) override {
        brand = a;
    }

    void setShade(const string& b) override {
        shade = b;
    }

    void setPrice(int c) override {
        price = c;
    }

    string getBrand() const override {
        return brand;
    }

    string getShade() const override {
        return shade;
    }

    int getPrice() const override {
        return price;
    }

    void description() const override {
        cout << "Lipstick - Brand: " << brand << ", Shade: " << shade << ", Price: Rs." << price << endl;
    }
};

class Gloss : public Product {
public:
    void setBrand(const string& a) override {
        brand = a;
    }

    void setShade(const string& b) override {
        shade = b;
    }

    void setPrice(int c) override {
        price = c;
    }

    string getBrand() const override {
        return brand;
    }

    string getShade() const override {
        return shade;
    }

    int getPrice() const override {
        return price;
    }

    void description() const override {
        cout << "Gloss - Brand: " << brand << ", Shade: " << shade << ", Price: Rs." << price << endl;
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
