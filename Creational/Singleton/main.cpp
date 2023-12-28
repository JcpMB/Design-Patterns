#include<iostream>

class Singleton{
    private:
        Singleton(){
            count = 0;
        }
        ~Singleton(){}
        Singleton(const Singleton& other) = delete;
        Singleton& operator=(const Singleton& other) = delete;
        static int count;

    public:
        static Singleton * getInstance(){
            static Singleton * instance;
            count++;
            return instance;
        }
        static void log_message( std::string msg ){
            std::cout << "msg: " << msg << ", count:" << count << std::endl;
        }

};

int Singleton::count;
Singleton * single = Singleton::getInstance();

/* 
    Not gonna lie, despite its simplicity this took me the longest to implement, the trick in c++ for creating a singleton class 
    is to rely on the static keyword when inside a class, when inside the getInstance declare the instance  inside the method(static)
    the static ensure the object remain the same when invoked several other times.
 */

int main( int argc, char * argv[] ){

    for( int i=0; i<10; i++ ){
        Singleton * new_single = Singleton::getInstance();
        single->log_message("hello there, brave new world");
    }

    return 0;
}