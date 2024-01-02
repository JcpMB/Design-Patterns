#include "MediaPlayer.hpp"

MediaPlayer :: MediaPlayer(){ 
    state = new Ready(this);
    inPlay = false;
    currentSong = 0;
}
bool MediaPlayer :: isPlaying(){ return inPlay; }
void MediaPlayer :: startPlaying(){
    inPlay = true;
    std::cout << "start playing " << std::endl;
}
void MediaPlayer :: stopPlaying(){
    inPlay = false;
    std::cout << "stop playing " << std::endl;
}
void MediaPlayer :: lockPlay(){
    state->clickLock();
}
void MediaPlayer :: nextSong(){
    currentSong++;
}
void MediaPlayer :: prevSong(){
    currentSong--;
}
void MediaPlayer :: changeState( State * s ){ state = s; }