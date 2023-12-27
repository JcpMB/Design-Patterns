#include<iostream>

class Car {
    private:
        int n_seats{0};
        std::string engine{""};
        std::string computer{""};
        bool gps{false};
    public:
        void setSeats( int n ){ n_seats = n; }
        void setEngine( std::string e ){ engine = e; }
        void setTripComputer( std::string pc ){ computer = pc; }
        void setGps( bool p ){ gps = p; };
        void showStats(){
            std::cout << "seats: " << n_seats << ", engine: " << engine << ", computer: " << computer << ", hasGPS: " << gps << std::endl;
        }
};

class Builder {
    public:
        virtual void reset() = 0;
        virtual void setSeats(int n) = 0;
        virtual void setEngine(std::string e) = 0;
        virtual void setTripComputer(std::string pc) = 0;
        virtual void setGps(bool p) = 0;
};

class CarBuilder : public Builder {
    private:
        Car *car;
    public:
        CarBuilder(){ reset(); }
        void reset(){ car = new Car(); }
        void setSeats(int n){ car->setSeats(n); }
        void setEngine(std::string e){ car->setEngine(e); }
        void setTripComputer(std::string pc){ car->setTripComputer(pc); }
        void setGps(bool p){ car->setGps(p); }
        Car * getProduct(){ return car; }
};

class Director{
    private: 
        Builder * builder;
    public:
        Director( Builder * b ){ builder = b; }
        void setBuilder( Builder * builder );
        void BuilSportCar( Builder * builder ){
            builder->reset();
            builder->setSeats(2);
            builder->setEngine("V6");
            builder->setTripComputer("Ryzen 7 7700");
            builder->setGps(false);
        }
        void BuildSUV( Builder * builder ){
            builder->reset();
            builder->setSeats(5);
            builder->setEngine("V10");
            builder->setTripComputer("Ryzen 9 5900x");
            builder->setGps(true);
        }

};

/*
    The main takeaways with this pattern is that it let you reuse the same construction code when building different variants
    it doesn't let you fetch an incomplete object since all the building steps occur in one function, the main con are the need
    to create a new class for every object you wanna to build, bummer
*/

int main( int argc, char * argv[] ){

    CarBuilder * builder = new CarBuilder();

    Director *director = new Director(builder);

    director->BuilSportCar(builder);

    Car * car = builder->getProduct();
    car->showStats();

    director->BuildSUV(builder);

    Car * suv = builder->getProduct();
    suv->showStats();
}