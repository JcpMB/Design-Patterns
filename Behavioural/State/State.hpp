
#pragma once
#include<iostream>
#include<vector>
#include "MediaPlayer.hpp"

class MediaPlayer;

class State {
    protected:
        MediaPlayer *player;
    public:
        State(MediaPlayer *player);
        virtual void clickLock() = 0;
        virtual void clickPlay() = 0;
        virtual void clickNext() = 0;
        virtual void clickPrevious() = 0;
};

class Locked : public State {
    using State::State;
    public:
        Locked();
        void clickLock();
        void clickPlay();
        void clickNext();
        void clickPrevious();
};

class Play : public State {
    using State::State;
    public:
        Play();
        void clickLock();
        void clickPlay();
        void clickNext();
        void clickPrevious();
};

class Ready : public State {
    using State::State;
    public:
        Ready();
        void clickLock();
        void clickPlay();
        void clickNext();
        void clickPrevious();
};