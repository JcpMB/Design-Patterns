#include<iostream>
#include<vector>

class TreeType {
    private:
        std::string name;
        std::string color;
        std::string texture;
    public:
        TreeType( std::string name, std::string color, std::string texture ) : name(name), color(color), texture(texture) {}
        void draw(int x, int y){
            std::cout << "(x,y): (" << x << "," << y << ")" << std::endl; 
        }
};

class TreeFactory {
    private:
        static std::vector<TreeType> treeTypes;
    public:
        TreeFactory(){};
        static TreeType* getTreeType( std::string name, std::string color, std::string texture ){
            return new TreeType( name, color, texture );
        }

};

class Tree {
    private:
        int x;
        int y;
        TreeType *type;
    public:
        Tree( int x, int y, TreeType *type ) : x(x), y(y), type(type) {}
        void draw(){
            type->draw(x,y);
        }

};

class Forest {
    private:
        std::vector<Tree*> trees;
        TreeFactory *factory;
    public:
        Forest( TreeFactory *factory ) : factory(factory) {}
        void PlantTree( int x, int y, std::string name, std::string color, std::string texture ){
            TreeType *type = factory->getTreeType(name, color, texture );
            Tree *tree = new Tree( x, y, type );
            trees.push_back(tree);
            std::cout << "tree planted." << std::endl;
        }

        void draw(){
            for( Tree *tree : trees )
                tree->draw();
        }

};

/* 
    The flyweight pattern more than pattern is an optimization technique, its usefulness is basically for 
    saving some memory in RAM, at the cost of CPU cycle, in some case the tradeoff might not even be worthy

    In this case I split the type of a tree in its own type
 */

int main( int argc, char * argv[] ){

    Forest *forest = new Forest( new TreeFactory() );

    forest->PlantTree( 2,2, "Yggdrasil", "blue", "Swede");
    forest->PlantTree( 3,3, "Treaty Tree", "gree", "South Africa");
    forest->PlantTree( 4,4, "Tenere", "acacia", "Sahara");
    
}