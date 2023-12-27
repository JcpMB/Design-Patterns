#include<iostream>

class Product {
    public:
        Product(){}
        virtual void doStuff() = 0;
};

class ProductA : public Product {
    public:
        ProductA(){};
        void doStuff() override{
            std::cout<< "I'm Product A and I'm doing stuff" << std::endl;
        }
};

class ProductB : public Product {
    public:
        ProductB(){}
        void doStuff() override{
            std::cout<< "I'm Product B and I'm doing other stuff" << std::endl;
        }
};

class Creator {
    public:
        Creator(){}
        ~Creator(){}
        virtual Product* createProduct() = 0;
};

class ConcreteCreatorA : public Creator {
    public:
        Product* createProduct() override{
            std::cout << "I'm creating a product A" << std::endl;
            return new ProductA();
        }
};

class ConcreteCreatorB : public Creator {
    public:
        Product* createProduct() override{
            std::cout << "I'm creating a product B" << std::endl;
            return new ProductB();
        }
};

/*
    The main takeway is that this approach separates the construction of instances of object
    from the implementation of the object itself. the examples with Shapes Object is easier to understand.

    In order to create another object I will have to create another creator subclass and override the factory method.
*/

int main( int argc, char * argv[] ){

    ConcreteCreatorA * cca = new ConcreteCreatorA();
    ConcreteCreatorB * ccb = new ConcreteCreatorB();

    Product * a_product = cca->createProduct();
    Product * b_product = ccb->createProduct();

    a_product->doStuff();
    b_product->doStuff();

    return 0;
}