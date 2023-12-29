#include<iostream>

class Target {
    public:
        Target(){}
        virtual void handleData() = 0;
};

// 1. I start from this
class Adaptee {
    private:
        std::string header;
    public:
        Adaptee(){}
        void processData(){
            header = "aaaa";
            std::cout << "Processing some data" << std::endl;
        }
        std::string getHeader(){ return header; }
};

// 3. I create the class Adapter with the interface of Target, which incapsulated an instance of Adaptee through the constructor
class Adapter : public Target {
    private:
        Adaptee * adaptee;
    public:
        Adapter( Adaptee * a ){
            adaptee = a;
        }
        virtual void handleData() override {
            adaptee->processData();
            std::cout << "Handling some data" << std::endl;
        }
};

// 2. and I need to run this, the problem is that Target is != from Adaptee
class Service {
    public:
        Service( Target * target ){
            target->handleData();
        }
};

/* 
    I kinda understood the pattern, the problem is to think about a use case, to experiment on
    The process is kinda convoluted, i got more difficulties into thinking about use cases rather than the implementation itself.
    I can't imagine a situation where I'll need this.
 */

int main( int argc, char * argv[] ){

    Adaptee * adaptee = new Adaptee();
    Adapter * adapter = new Adapter( adaptee );

    // 4. when the time comes I'll input the adapter object, which will be recognized as Target object
    Service *service = new Service( adapter ); 

    return 0;
}