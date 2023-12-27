#include<iostream>
#include<array>

class Furniture {
    public:
        virtual void sitOn() = 0;
};

class Chair : public Furniture {
    public:
        Chair(){}
        void sitOn(){
            std::cout << "I'm currently sit on the chair" << std::endl;
        }
};

class ModernChair : public Chair {
    public:
        ModernChair(){}
        void sitOn(){
            std::cout << "I'm currently sit on a Modern chair" << std::endl;
        }
};

class VictorianChair : public Chair {
    public:
        VictorianChair(){}
        void sitOn(){
            std::cout << "I'm currently sit on a Victorian chair" << std::endl;
        }
};

class ArtDecoChair : public Chair {
    public:
        ArtDecoChair(){}
        void sitOn(){
            std::cout << "I'm currently sit on a Art Deco chair" << std::endl;
        }
};

class Sofa : public Furniture {
    public:
        Sofa(){}
        void sitOn(){
            std::cout << "I'm currently sit on the Sofa" << std::endl;
        }
};

class ModernSofa : public Sofa {
    public:
        ModernSofa(){}
        void sitOn(){
            std::cout << "I'm currently sit on a Modern Sofa" << std::endl;
        }
};

class VictorianSofa : public Sofa {
    public:
        VictorianSofa(){}
        void sitOn(){
            std::cout << "I'm currently sit on a Victorian Sofa" << std::endl;
        }
};

class ArtdecoSofa : public Sofa {
    public:
        ArtdecoSofa(){}
        void sitOn(){
            std::cout << "I'm currently sit on Art Deco Sofa" << std::endl;
        }
};

class Table : public Furniture {
    public:
        Table(){}
        void sitOn(){
            std::cout << "I'm currently sit on the table" << std::endl;
        }
};

class ModernTable : public Table {
    public:
        ModernTable(){}
        void sitOn(){
            std::cout << "I'm currently sit on a Modern table" << std::endl;
        }
};

class VictorianTable : public Table {
    public:
        VictorianTable(){}
        void sitOn(){
            std::cout << "I'm currently sit on a Victorian table" << std::endl;
        }
};

class ArtDecoTable : public Table {
    public:
        ArtDecoTable(){}
            void sitOn(){
            std::cout << "I'm currently sit on a Art Deco table" << std::endl;
        }
};

class FurnitureFactory {
    public:
        FurnitureFactory(){}
        virtual Chair* createChair() = 0;
        virtual Sofa* createSofa() = 0;
        virtual Table* createTable() = 0;
};

class ModernFurnitureFactory : public FurnitureFactory {
    public:
        ModernFurnitureFactory(){}
        Chair* createChair(){
            return new ModernChair();
        }
        Sofa* createSofa(){
            return new ModernSofa();
        }
        Table* createTable(){
            return new ModernTable();
        }
};

class VictorianFurnitureFactory : public FurnitureFactory {
    public:
        VictorianFurnitureFactory(){}
        Chair* createChair(){
            return new VictorianChair();
        }
        Sofa* createSofa(){
            return new VictorianSofa();
        }
        Table* createTable(){
            return new VictorianTable();
        }
};

class ArtDecoFurnitureFactory : public FurnitureFactory {
    public:
        ArtDecoFurnitureFactory(){}
        Chair* createChair(){
            return new ArtDecoChair();
        }
        Sofa* createSofa(){
            return new ArtdecoSofa();
        }
        Table* createTable(){
            return new ArtDecoTable();
        }
};

/*
    The main takeaways here are the extra compatibility among variants of the same type of objects
    and factories, the only downside is that the code bloat quite rapidly since it require the 
    creation of a new subclass for every variants.
*/

int main( int argc, char * argv[] ){

    std::array<FurnitureFactory*,3> factories;

    factories[0] = new ModernFurnitureFactory();
    factories[1] = new VictorianFurnitureFactory();
    factories[2] = new ArtDecoFurnitureFactory();

    for( int i=0; i<3; i++ ){
        Chair *chair = factories[i]->createChair();
        Sofa *sofa = factories[i]->createSofa();
        Table * table = factories[i]->createTable();

        chair->sitOn();
        sofa->sitOn();
        table->sitOn();
    }

    return 0;
}