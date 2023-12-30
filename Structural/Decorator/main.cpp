#include<iostream>

class Notification {
    public:
        Notification(){}
        virtual void send(std::string msg) = 0;
};

class Notifier : public Notification {
    public:
        Notifier(){}
        void send(std::string msg){
            std::cout << "Sending: " << msg << std::endl;
        }
};

class NotifyDecorator : public Notification {
    protected:
        Notification *notify;
    public:
        NotifyDecorator( Notification *notify ) : notify{notify} {}
        void send( std::string mesg ){
            notify->send(mesg);
        }
};

class ConcreteDecoratorNotify : public NotifyDecorator {
    public:
        using NotifyDecorator::NotifyDecorator;
        void send( std::string mesg ) override {
            std::cout << "[HARDCORE CONCRETE NOTIFY] message from the concrete decorator, before the message" << std::endl;
            notify->send(mesg);
        }      
};

/* 
    Pattern for adding new functionalities on runtime to established objects, the only requirement is a common interface between the object and the decorator
    nothing fancy
 */

int main( int argc, char * argv[] ){

    Notification * notify = new Notifier();

    Notification * decorator = new ConcreteDecoratorNotify(notify);

    decorator->send("Hello there by the client");

    return 0;
}