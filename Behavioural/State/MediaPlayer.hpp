#pragma once
#include "State.hpp"

class State;
class Locked;
class Ready;
class Play;

class MediaPlayer {
    private:
        State *state;
        bool inPlay;
        std::vector<int> playList{1,2,3,4,5,6,7,8,9};
        int currentSong;
    public:
        MediaPlayer();
        bool isPlaying();
        void startPlaying();
        void stopPlaying();
        void lockPlay();
        void nextSong();
        void prevSong();
        void changeState( State * s );
};
