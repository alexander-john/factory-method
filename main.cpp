#include <iostream>

// Product interface
class Product {
public:
    virtual void use() = 0;
};

// Concrete Product A
class ConcreteProductA : public Product {
public:
    void use() override {
        std::cout << "Using Product A" << std::endl;
    }
};

// Concrete Product B
class ConcreteProductB : public Product {
public:
    void use() override {
        std::cout << "Using Product B" << std::endl;
    }
};

// Creator interface
class Creator {
public:
    virtual Product* createProduct() = 0;
};

// Concrete Creator A
class ConcreteCreatorA : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProductA();
    }
};

// Concrete Creator B
class ConcreteCreatorB : public Creator {
public:
    Product* createProduct() override {
        return new ConcreteProductB();
    }
};

int main() {
    Creator* creator = new ConcreteCreatorA(); // or ConcreteCreatorB
    Product* product = creator->createProduct();
    product->use();
    delete product;
    delete creator;
    return 0;
}
