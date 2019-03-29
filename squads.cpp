//
// Created by enka on 27.03.19.
//

#include <iostream>
#include "squads.h"

//constructor!
int Squad::getProd(int rnd) {
    return 0;
}
Builders::Builders(int level): level_(level), life_(FullLife), price_(30){}
void Builders::help()const{
    std::cout << "You need them to build new houses in the Village.\n";
    std::cout << "They have different levels on which the speed of construction depends.\n";
    std::cout << "You can raise their level for money in game menu.";
}

void Builders::decreaseLife(){
    --life_;
}
int Builders::getlevel()const{
    return level_;
}

void Builders::increaselevel(){
    ++level_;
    life_ = FullLife;
}
int Builders::life()const{
    return life_;
}
int Builders::price()const{
    return price_;
}
Builders::~Builders(){
    std::cout << "Squad of builders(level = "<<level_<<") is gone";
}
Warriors::Warriors(int level): level_(level), life_(FullLife), price_(40){}
void Warriors::help()const{                                                          //write about life
    std::cout << "You need them to protect the Village.\n";
    std::cout << "They have different levels on which their effectiveness depends.\n";
    std::cout << "You can raise their level for money in game menu.";
}
void Warriors::decreaseLife(){
    --life_;
}
int Warriors::getlevel()const{
    return level_;
}
void Warriors::increaselevel(){
    ++level_;
    life_ = FullLife;
}
int Warriors::life()const{
    return life_;
}
int Warriors::price()const{
    return price_;
}
Warriors::~Warriors(){
    std::cout << "Squad of warriors(level = "<<level_<<") is gone";
}
Hunters::Hunters(int level): level_(level), life_(FullLife), price_(50){}
void Hunters::help()const{
    std::cout << "They produce fur. You can sell it.\n";
    std::cout << "They have different levels on which their effectiveness depends.\n";
    std::cout << "You can raise their level for money in game menu.";
}
void Hunters::decreaseLife(){
    --life_;
}
int Hunters::getlevel()const{
    return level_;
}

void Hunters::increaselevel(){
    ++level_;
    life_ = FullLife;
}
int Hunters::life()const{
    return life_;
}
int Hunters::price()const{
    return price_;
}
int Hunters::getProd(int rnd) const {
    return (rnd % (10 * level_)  + 5 * level_); //
}
Hunters::~Hunters(){
    std::cout << "Squad of hunters(level = "<<level_<<") is gone";
}
Peasants::Peasants(int level): level_(level), life_(FullLife), price_(30){}
void Peasants::help()const{
    std::cout << "They produce meal. You need it to feed your people, also you can sell it.\n";
    std::cout << "They have different levels on which their effectiveness depends.\n";
    std::cout << "You can raise their level for money in game menu.";
}
void Peasants::decreaseLife(){
    --life_;
}
int Peasants::getlevel()const{
    return level_;
}
void Peasants::increaselevel(){
    ++level_;
    life_ = FullLife;
}
int Peasants::life()const{
    return life_;
}
int Peasants::price()const{
    return price_;
}
int Peasants::getProd(int rnd)const {
    return (rnd % (50 * level_)  + 10 * level_);
}
Peasants::~Peasants(){
    std::cout << "Squad of peasants(level = "<<level_<<") is gone";
}