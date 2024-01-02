#include<iostream>

class GameAI {
    public:
        GameAI(){}
        virtual void turn() final {
            collectResources();
            buildStructures();
            buildUnits();
            attack();
        }
        virtual void collectResources() = 0;
        virtual void buildStructures() = 0;
        virtual void buildUnits() = 0;
        virtual void attack(){
            std::cout << "[GeneralAI] ATTACK" << std::endl;
        }
};

class Monster : public GameAI {
    public:
        Monster(){}
        void collectResources() override{}
        void buildStructures() override{}
        void buildUnits() override{ std::cout << "[Monster] +10 goblin created" << std::endl; }
        //void attack() { std::cout << "[Monster] Attack feral" << std::endl; }
};

class Knight : public GameAI {
    public:
        Knight(){}
        void collectResources() override{ std::cout << "[Knight] +5 resources" << std::endl; }
        void buildStructures() override{ std::cout << "[knight] fort built!" << std::endl; }
        void buildUnits() override{ std::cout << "[Knight] +10 spawn created" << std::endl; }
        void attack() { std::cout << "[knight] Attack sword" << std::endl; }
};

class Orc : public GameAI {
    public:
        Orc(){}
        void collectResources() override{ std::cout << "[Orc] +15 iron" << std::endl; }
        void buildStructures() override{ std::cout << "[Orc] Enemy fortress built!" << std::endl; }
        void buildUnits() override{}
        void attack() { std::cout << "[Orc] Attack cleave" << std::endl; }
};

/* 
    this patter heavily rely on inheritance and overriding, similar to the Builder but with a template method instead than a director
 */

int main( int argc, char * argv[] ){

    Knight * knight = new Knight();
    Monster *monster = new Monster();
    Orc *orc = new Orc();

    knight->turn();
    monster->turn();
    orc->turn();
    monster->turn();

    return 0;
}