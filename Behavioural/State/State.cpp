#include "State.hpp"

State :: State( MediaPlayer * player ) : player(player){}

void Locked :: clickLock() {
    if( player->isPlaying() )
        player->changeState(new Play(player));
}

void Locked :: clickPlay() {}
void Locked :: clickNext() {}
void Locked :: clickPrevious() {}

void Play :: clickLock() { player->changeState( new Locked(player) ); }
void Play :: clickPlay() { 
    player->stopPlaying();
    player->changeState( new Ready( player ));
}
void Play :: clickNext() { player->nextSong(); }
void Play :: clickPrevious() { player->prevSong(); }

void Ready :: clickLock() { player->changeState( new Locked( player ) ); }
void Ready :: clickPlay() {
    player->startPlaying();
    player->changeState( new Play(player) );
}
void Ready :: clickNext() { player->nextSong(); }
void Ready :: clickPrevious() { player->prevSong(); }