#include<iostream>

class Iterator {
    public:
        Iterator(){}
        virtual Iterator getNext() = 0;
        virtual Iterator getCurrent() = 0;
        virtual bool hasMore() = 0;
};

/*
     It doesn't explain the logic behind an iterator, I would have to find something else for implementing one
    but I get how it works
 */

int main( int argc, char * argv[] ){

}