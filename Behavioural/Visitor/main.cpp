#include<iostream>

class Rectangle;
class Circle;
class Dot;

class Visitor {
    public:
        Visitor(){}
        virtual void visit( Rectangle *rect ) = 0;
        virtual void visit( Circle *circle ) = 0;   
        virtual void visit( Dot *dot ) = 0;   
};

class Shape {
    public:
        Shape(){}
        virtual void move() = 0;
        virtual void draw() = 0;
        virtual void accept( Visitor *v ) = 0;
};

class Rectangle : public Shape {
    public:
        Rectangle(){}
        void move() override{ std::cout << "I'm moving the rect" << std::endl; }
        void draw() override { std::cout << "|_-|" << std::endl; }
        void accept( Visitor *visitor ) override { visitor->visit(this); }
};

class Circle : public Shape {
    public:
        Circle(){}
        void move(){ std::cout << "I'm moving the circle" << std::endl; }
        void draw(){ std::cout << "()" << std::endl; }
        void accept( Visitor *visitor ) override{ visitor->visit(this); }
};

class Dot : public Shape {
    public:
        Dot(){}
        void move(){ std::cout << "I'm moving the dot" << std::endl; }
        void draw(){ std::cout << "·" << std::endl; }
        void accept( Visitor *visitor ) override{ visitor->visit(this); }
};

class Printer : public Visitor {
    public:
        Printer(){}
        void visit( Rectangle *rect ){
            rect->draw();
        }
        void visit( Circle *circle ){
            circle->draw();
        }
        void visit( Dot *dot ){
            dot->draw();
        }
};

/*  
    I dont like this, once all hope is lost and one cannot modify an object definition, the Visitor pattern does allow to access
    object's classes everything in it, by creating a new class and by basically linking this class with an interface that the 
    original class must inherit.

    It's a very specific instance of a problem, that does allow also to separate one logic from the behaviour of a class that maybe
    has nothing to do with said logic. I still don't like it.
 */

int main( int argc, char *argv[] ){

    Printer *print = new Printer();

    Rectangle *rect = new Rectangle();
    Circle *circle = new Circle();
    Dot *dot = new Dot();

    print->visit( rect );
    print->visit( circle );
    print->visit( dot );

    return 0;
}