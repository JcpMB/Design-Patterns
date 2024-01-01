#include<iostream>
#include<vector>
#include<random>

enum Events { PRICE_UP, PRICE_DOWN };

class Subscriber {
    public:
        Subscriber(){}
        virtual void Update( int event, int price ) = 0;
        int position;
        int event;
};

class AmazonSubscriber : public Subscriber {
    private:
        int myEvent;
    public:
        AmazonSubscriber( int myEvent ) : myEvent(myEvent){}
        void Update( int event, int price ) override {
            if( event == myEvent ){
                if( myEvent == Events::PRICE_DOWN )
                    std::cout << "[Amazon] Update: the price went down at: " << price << ", BUY!!!" << std::endl;

                if( myEvent == Events::PRICE_UP)   
                    std::cout << "[Amazon] Update: the price went up at: " << price << ", SELL!!!" << std::endl;
            }
        }
};

class Publisher {
    private:
        std::vector<Subscriber*> subscribers;
    public:
        Publisher(){}
        void AddSubscriber( Subscriber *sub ){
            sub->position = subscribers.size();
            subscribers.push_back( sub );
        }
        void RemoveSubscriber( Subscriber *sub ){
            subscribers.erase(subscribers.begin() + sub->position);
        }
        void Notify( int event, int price  ){
            for( Subscriber *sub : subscribers ){
                switch( sub->event ){
                    case Events::PRICE_DOWN:
                        sub->Update( event, price );
                        break;

                    case Events::PRICE_UP:
                        sub->Update( event, price );
                        break;
                }
            }
        }
};

int genRand( int min, int max ){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);
    return dist6(rng);
}

/* 
    Simple Demo that shoot an update to a specific subscriber when a specific condition is met
 */

int main( int argc, char * argv[]){

    Subscriber *sub1 = new AmazonSubscriber( Events::PRICE_DOWN );
    Subscriber *sub2 = new AmazonSubscriber( Events::PRICE_UP );

    Publisher * publisher = new Publisher();
    publisher->AddSubscriber(sub1);
    publisher->AddSubscriber(sub2);

    int old_price = genRand(30,70);

    while( true ){

        int price = genRand(1,100);

        if( price != old_price ){

            if( price >= 90  )
                publisher->Notify(Events::PRICE_UP, price);
            
            if( price <= 10 )
                publisher->Notify(Events::PRICE_DOWN, price);
        }
        old_price = price;
    }

    return 0;
}