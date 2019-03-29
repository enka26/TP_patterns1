//
// Created by enka on 27.03.19.
//

#include <iostream>
#include "buildings.h"
//сделать wall и moat singleton

Wall::Wall(int level): level_(level), strength_(FullStr), price_(500){}
int Wall::price() const {
    return  price_;
}
void Wall::damage(int d) {
    strength_ -= d;
}
int Wall::getlevel() const {
    return  level_;
}
void Wall::increaselevel() {
    ++ level_;
    strength_ = FullStr * level_;
}

double Wall::protect() const {
    double factor = static_cast<double>(strength_) / (FullStr * level_);
    return factor * level_;
}
int Wall::strength() const {
    return  strength_;
}
Wall::~Wall() {
    std::cout << "The wall was destroyed \n";
}
//_____________________MOAT___________________________//
Moat::Moat(int level) :level_(level), strength_(FullStr), price_(300){}
int Moat::strength() const {
    return strength_;
}
double Moat::protect() const {
    double factor = static_cast<double>(strength_) / (FullStr * level_);
    return factor * level_;
}
void Moat::increaselevel() {
    ++level_;
    strength_ = FullStr * level_;
}
int Moat::getlevel() const {
    return  level_;
}
int Moat::price() const {
    return price_;
}
void Moat::damage(int d) {
    strength_ -= d;
}
Moat::~Moat() {
    std::cout << "The moat was destroyed\n";
}
//_________________________MARKET______________________________?//

Market::Market(int level):level_(level), tax_(5), price_(250), sellerNum(0) {}
int Market::price() const {
    return price_;
}
int Market::getlevel() const {
    return level_;
}
void Market::increaselevel() {
    ++level_;
}
int Market::tax() const {
    return tax_ * level_ * sellerNum;
}
void Market::expand() {
    ++sellerNum; //добавлять из расчета люди/деньги* ранд
}
Market::~Market() {
    std::cout << "Market was destroyed\n";
}
//_________________________HOSPITAL________________________//
Hospital::Hospital(int level): level_(level), price_(250), happiness_(50), strength_(FullStr){}
void Hospital::increaselevel() {
    ++level_;
    strength_ = FullStr * level_;
}
int Hospital::getlevel() const {
    return level_;
}
int Hospital::price() const {
    return  price_;
}
int Hospital::strength() {
    return strength_;
}
void Hospital::amortization() {
    --strength_;
}
void Hospital::repair() {
    strength_ = FullStr * level_;
}
int Hospital::happiness() const {
    return happiness_ * level_;
}
Hospital::~Hospital() {
    std::cout<<"Hospital level("<<level_<<") collapsed";
}
//_______________________CHURCH__________________________//
Church::Church(int level): level_(level), strength_(FullStr), price_(250), happiness_(50){}
void Church::increaselevel() {
    ++level_;
    strength_ = FullStr * level_;
}
int Church::getlevel() const {
    return level_;
}
int Church::price() const {
    return  price_;
}
int Church::strength() {
    return strength_;
}
void Church::amortization() {
    --strength_;
}
void Church::repair() {
    strength_ = FullStr * level_;
}
int Church::happiness() const {
    return happiness_ * level_;
}
Church::~Church() {
    std::cout<<"Church level("<<level_<<") collapsed";
}
