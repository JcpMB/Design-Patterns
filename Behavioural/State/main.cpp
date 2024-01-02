#include "MediaPlayer.hpp"

/* 
    This took more than it should have due to the circular declaration/inclusion of classes among each other
    also once has to be very careful with circular class between state and context you might get a loop
 */

int main( int argc, char * argv[] ){

    MediaPlayer * player = new MediaPlayer();

    std::cout << "Mediaplayer created" << std::endl;

    player->startPlaying();
    std::cout << "Startplaying" << std::endl;
    player->nextSong();
    std::cout << "next song" << std::endl;
    player->nextSong();
    player->stopPlaying();
    
    return 0;
}