#include<iostream>

class Calculator {
    public:
        Calculator(){}
        int sum( int a, int b ){ return a+b; }
        int sub( int a, int b ){ return a-b; }
        int mul( int a, int b ){ return a*b; }
        int div( int a, int b ){
            if( b != 0 )
                return a/b;
            else
                return 0;
        }
};

/* The facade pattern are just API calls to a service, nothing fancy here */

int main( int argc, char * argv[] ){

    Calculator * cal = new Calculator();

    int sum = cal->sum(1,1);
    std::cout << "sum: " << sum << std::endl;

    return 0;
}