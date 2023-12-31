#include<iostream>

class Request {
    public:
        std::string task;
        Request( std::string task ) : task(task) {}

};

class Handler {
    public:
        Handler(){}
        virtual void handle( Request *request ) = 0;
};

class BaseHandler : public Handler {
    protected:
        Handler *nextHandler;
    public:
        BaseHandler(){}
        void handle( Request *request ) override {
            if( request != NULL )
                nextHandler->handle( request );
            else
                std::cerr << "[BaseHandler] Chain terminated" << std::endl;
        }
        void setNextHandler(Handler *handler){ nextHandler = handler; }

};

class NumericHandler : public BaseHandler {
    private:
        std::string seq;
    public:
        NumericHandler( Handler *handler ) {
            nextHandler = handler;
            seq = "0123456789";
        }
        NumericHandler(){
            seq = "0123456789";
        }
        void handle( Request *request ) {
            if( nextHandler != NULL ){
                std::cout << "[NumericHandler] Checking numeric values ...";
                bool found = false;
                for( int i=0; i<request->task.size(); i++ ){
                    if( request->task.find_first_of(seq,i) != std::string::npos ){
                        found = true;
                        break;
                    }
                }
                if( found )
                    std::cout << "check" << std::endl;
                else
                    std::cout << std::endl << "No numbers found, exiting" << std::endl;
                
                if( nextHandler != NULL )
                    nextHandler->handle(request);

            }
        }
};

class SpecialCharacterHandler : public BaseHandler {
    private:
        std::string seq;
    public:
        SpecialCharacterHandler( Handler *handler ){
            nextHandler = handler;
            seq = "_-[]{}!£$%&/()=@";
        }
        SpecialCharacterHandler(){
            seq = "_-[]{}!£$%&/()=";
        }
        void handle( Request *request ) {
                std::cout << "[SpeciaCharacterHandler] Checking special characters ...";
                bool found = false;
                for( int i=0; i<request->task.size(); i++ ){
                    if( request->task.find_first_of(seq, i) != std::string::npos ){
                        found = true;
                        break;
                    }
                }
                if( found )
                    std::cout << "check" << std::endl;
                else
                    std::cout << std::endl << "No special character found" << std::endl;
                
                if( nextHandler != NULL )
                    nextHandler->handle(request);
        }
};

/* 
    Pattern similar to the composite pattern, with a container of size = 1 for every element, Maybe I could make this better with a container class ?
 */

int main( int argc, char * argv[] ){

    BaseHandler * h_num = new NumericHandler();
    BaseHandler * h_spe = new SpecialCharacterHandler();

    h_num->setNextHandler(h_spe);
    h_spe->setNextHandler(NULL);

    Request *request = new Request("Obi-Wan.Kenobi69@hellothere.com");

    h_num->handle( request );

    return 0;
}