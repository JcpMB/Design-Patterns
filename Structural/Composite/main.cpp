#include<iostream>
#include<vector>

class FileSystemComponent {
    public:
        FileSystemComponent(){}
        virtual std::string getName() const = 0;
        virtual std::vector<FileSystemComponent*> getChildren() const = 0;
        virtual void printDirectory() const = 0;
};

class File : public FileSystemComponent {
    private:
        std::string name;
    public:
        File( const std::string &name ) : name(name) {}
        std::string getName() const override { return name; }
        std::vector<FileSystemComponent*> getChildren() const override { return {}; }
        void printDirectory() const override {
            std::cout << "File: " << getName() << std::endl;
        }
};

class Directory : public FileSystemComponent {
    private:
        std::string name;
        std::vector<FileSystemComponent*> children;
    public:
        Directory( const std::string &name ): name(name){}
        std::string getName() const override  { return name; }
        std::vector<FileSystemComponent*> getChildren() const override { return children; }
        void addChild( FileSystemComponent *child ){
            children.push_back(child);
        }
        void printDirectory() const override {
            std::cout << "Directory: " << getName() << std::endl;
            for( const auto& child : children )
                child->printDirectory();
        }
};

/* 
    This example clarify the use of the composite pattern, it can only be use if the program can be expressed as some sort of tree structure
    which require quite some introspection first on whether or not it can be done.
 */

int main( int argc, char * argv[] ){

    Directory *rootDirectory = new Directory("root");
    Directory *documentDirectory = new Directory("documents");
    Directory *imageDirectory = new Directory("images");

    rootDirectory->addChild( documentDirectory );
    rootDirectory->addChild( imageDirectory );

    FileSystemComponent *document1 = new File("document1.txt");
    FileSystemComponent *document2 = new File("document2.txt");
    documentDirectory->addChild( document1 );
    documentDirectory->addChild( document2 );

    FileSystemComponent *image1 = new File("image-1.png");
    FileSystemComponent *image2 = new File("image-2.png");
    imageDirectory->addChild(image1);
    imageDirectory->addChild(image2);

    rootDirectory->printDirectory();

    return 0;
}