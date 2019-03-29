//
// Created by enka on 27.03.19.
//

#ifndef PATTERNS_GAME_H
#define PATTERNS_GAME_H
#include "Village.h"
class Game{
public:
    int time = 0;
    Village  v;

    void start();
    void menu();
    void specialEvent();
private:
    bool isDead = false;
};

#endif //PATTERNS_GAME_H
