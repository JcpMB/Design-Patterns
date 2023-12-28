#include<iostream>

class Shape {
    public:
        Shape(){}
        virtual Shape * clone() = 0;
};

class Circle : public Shape {
    private:
        int x;
        int y;
        int radius;
    public:
        Circle( int x_, int y_, int radius_ ){
            x = x_;
            y = y_;
            radius = radius_;
        }
        Circle( Circle *c ){
            x = c->x;
            y = c->y;
            radius = c->radius;
        }
        Circle * clone(){
            return new Circle(this);
        }
        void printStats(){
            std::cout << "x: " << x << ", y: " << y << ", radius: " << radius << std::endl;
        }
};

/* 
    This is relatively an easy pattern, the main takeaway is that you can make a copy out of your object by simply Overloading the constructor 
    with an object of the same type passed as a parameter and then calling the clone method and then return a new instance with said constructor, 
    the constructor will handle the actual copy and the clone will return it.

    Why and when should I use this ?
    I guess it depends on the type of object you're making, one has to engineering the thing in advance to actually know.
 */

int main( int argc, char * argv[]){

    Circle * circle = new Circle(3,4,10);
    Circle * new_circle = circle->clone();

    new_circle->printStats();

    return 0;
}