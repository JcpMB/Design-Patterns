#include<iostream>
#include<stack>

class Editor {
    private:
        std::string text;
    public:
        Editor(){}
        
        void setText( std::string t ){ text = t; }
        
        class Memento {
            private: 
                std::string text;
            public:
                Memento( std::string text ) : text(text){}
                void Backup( Editor *editor ){ editor->setText(text); }
        };
        Memento * BackupState(){ return new Memento(text); }
        void printState(){ std::cout << "state:" << text << std::endl; }
};

class Command {
    private:
        std::stack<Editor::Memento*> history;
        Editor * editor;
    public:
        Command( Editor *editor ) : editor(editor){}
        void doBackup(){
            history.push( editor->BackupState() );
        }
        void Undo(){
            history.pop();// apparently the pop doesn't return the object
            history.top()->Backup(editor);    
        }
};

/* 
    Easy pattern, easy to implement, a nice way to make backup on runtime
 */

int main( int argc, char * argv[] ){

    Editor * editor = new Editor();
    editor->setText("Hello there");

    Command * backup = new Command( editor );
    backup->doBackup();

    editor->setText("General Kenobi");
    backup->doBackup(); 

    editor->printState();

    backup->Undo();
    editor->printState();

    return 0;
}