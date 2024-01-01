#include<iostream>

enum class Type{ Component, OkBtn, CancelBtn };
class Component;

class Mediator {
    public:
        Mediator(){}
        virtual void notify( Component *c, std::string event ) = 0;
};

class Component {
    protected:
        Mediator *mediator;
    public:
        Component( Mediator *mediator ) : mediator(mediator){}
        //Component( Mediator *mediator ){}
        virtual Type type() = 0;
};

class Dialog : public Mediator {
    public:
        Dialog(){}
        void notify( Component *component, std::string event ){
            switch( component->type() ){
                case Type::OkBtn:
                    std::cout << "[Dialog] ok button has been pressed, event:" << event << std::endl;
                    break;

                case Type::CancelBtn:
                    std::cout << "[Dialog] cancel button has been pressed, event: " << event << std::endl;
                    break;
            }
        }
};

class OkBtn : public Component {
    using Component::Component;
    public:
        OkBtn();
        Type type() override { return Type::OkBtn; }
        void OkClick(){
            mediator->notify( this, "OK click");
        }
        void ExitClick(){
            mediator->notify( this, "Exit click");
        }
};

class CancelBtn : public Component {
    using Component::Component;
    public:
        CancelBtn();
        Type type() override { return Type::CancelBtn; }
        void DialogOutClick(){
            mediator->notify( this, "Out Cancel click");
        }
        void CancelInClick(){
            mediator->notify( this, "In cancel click");
        }
};

/* 
    This pattern is some sort of static server, where the mediator will react on the actions of the components without know it
 */

int main( int argc, char * argv[] ){

    Mediator * mediator = new Dialog();

    OkBtn *okay_button = new OkBtn(mediator);
    CancelBtn *cancel_button = new CancelBtn(mediator);

    okay_button->OkClick();
    cancel_button->CancelInClick();

    return 0;
}