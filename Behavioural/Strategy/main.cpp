#include<iostream>

class Fibonacci {
    public:
        Fibonacci(){}
        virtual int MakeSequence( int n) = 0;
};

int recursive_fibonacci( int n ){
    if( n == 0 ){
        return 0;
    } else if( n == 1 ){
        return 1;
    }else{
        return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
    }
}

class SequentialFibonacci : public Fibonacci {
    public:
        SequentialFibonacci(){}
        int MakeSequence( int n ) override {
            int a = 1,b = 1, s;
            for( int i=0; i<n; i++ ){
                s = a+b;
                a = b;
                b = s;
            }
            return s;
        };
};

class RecursiveFibonacci : public Fibonacci {
    public:
        RecursiveFibonacci(){}
        int MakeSequence( int n ) override {
            return recursive_fibonacci(n);
        };
};

class GenerateSequence {
    private:
        Fibonacci * generator;
        int seq;
    public:
        GenerateSequence(){}
        void setGenerator( Fibonacci * g ){ generator = g; }
        void generateSequence(int n){
            seq = generator->MakeSequence(n);
        }
        void printSeq(){ std::cout << "sequence: " << seq << std::endl; }
};

/* 
    Pretty straightforward pattern, not difficult at all to understand, it allows to replace inheritance with composition
 */

int main( int argc, char *argv[] ){

    Fibonacci * seq = new SequentialFibonacci();
    Fibonacci * rec = new RecursiveFibonacci();

    GenerateSequence *gen = new GenerateSequence();

    gen->setGenerator(seq);
    gen->generateSequence(10);
    gen->printSeq();

    gen->setGenerator(rec);
    gen->generateSequence(12);
    gen->printSeq();

    return 0;
}