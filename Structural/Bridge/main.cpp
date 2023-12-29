#include<iostream>

class Device {
    public:
        Device(){}
        virtual bool isEnabled() = 0;
        virtual void enable() = 0;
        virtual void disable() = 0;
        virtual int getVolume() = 0;
        virtual void setVolume( int v ) = 0;
        virtual int getChannel() = 0;
        virtual void setChannel( int c ) = 0;
};

class RemoteControl {
    protected:
        Device *device;
    public:
        explicit RemoteControl( Device * d ){
            device = d;
        }
        void togglePower(){
            std::cout << "toggling power up" << std::endl;
            if( device->isEnabled() )
                device->disable();
            else
                device->enable();
        }

        void volumeDown(){
            device->setVolume( device->getVolume() - 10 );
        }
        void volumeUp(){
            device->setVolume( device->getVolume() + 10 );
        }
        void channelDown(){
            device->setChannel( device->getChannel() -1 );
        }
        void channelUp(){
            device->setChannel( device->getChannel() +1 );
        }
};

class AdvancedRemoteControl : public RemoteControl {
    using RemoteControl::RemoteControl;
    public:
        void mute(){
            device->setVolume(0);
        }
};

class Tv : public Device {
    private:
        bool en;
        int volume;
        int channel;
    public:
        Tv(){
            en = false;
            volume = 0;
            channel = 0;
        }
        bool isEnabled(){ return en; }
        void enable(){ en = true;}
        void disable(){ en = false; }
        int getVolume(){ return volume; }
        void setVolume( int v ){ volume = v; }
        int getChannel(){ return channel; }
        void setChannel( int c ){ channel = c;}
};

class Radio : public Device {
    private:
        bool en;
        int volume;
        int channel;
    public:
        Radio(){
            en = false;
            volume = 0;
            channel = 0;
        }
        bool isEnabled(){ return en;}
        void enable(){ en = true;}
        void disable(){ en = false; }
        int getVolume(){ return volume; }
        void setVolume( int v ){ volume = v; }
        int getChannel(){ return channel; }
        void setChannel( int c ){ channel = c;}
};

/* 
    The bridge pattern here allow to communicate between classes through a shared interface, in particular an instance ( of the interface )
    defined inside a class and another class which implement said interface, the process work also with subclasses, the connection happen
    inside the constructor, by passing an object of the defined interface as parameter.

    the limit is that the communication is unidirectional in this case

    separation between abstraction and implementation

    kinda meh, you still have to create a lot of stuff 
 */

int main( int argc, char * argv[] ){

    Tv * tv = new Tv();
    RemoteControl * remote = new RemoteControl(tv);
    remote->togglePower();

    Radio * radio = new Radio();
    remote = new AdvancedRemoteControl(radio);

    return 0;
}