#include<iostream>

class Command {
    public:
        Command(){}
        virtual void execute() = 0;
};

class Receiver {
    public:
        Receiver(){}
        void start(){
            std::cout << "Start command is on" << std::endl;
        }
        void stop(){
            std::cout << "Stop command is on" << std::endl;
        }
};

class StartCommand : public Command {
    private:
        Receiver * receiver;
    public:
        StartCommand( Receiver * recv ) : receiver(recv) {}
        void execute() override {
            receiver->start();
        }
};

class StopCommand : public Command {
    private:
        Receiver * receiver;
    public:
        StopCommand( Receiver *recv ) : receiver(recv) {}
        void execute() override {
            receiver->stop();
        }
};

class Invoker {
    private:
        Command * command;
    public:
        Invoker(){}
        void setCommand( Command * c ){
            command = c;
        }
        void action(){
            command->execute();
        }
};

/* 
    Quite straightforward pattern, I kinda had to get some help to implement this since in the book is written in very convoluted way
    very useful pattern.
 */

int main( int argc, char * argv[] ){

    Receiver * recv = new Receiver();

    Command *start = new StartCommand(recv);
    Command *stop = new StopCommand(recv);

    Invoker * inv = new Invoker();

    inv->setCommand(start);
    inv->action();

    inv->setCommand(stop);
    inv->action();

    return 0;
}