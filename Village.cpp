//
// Created by enka on 27.03.19.
//

#include <iostream>
#include "Village.h"

UnitStore::UnitStore():
        allunits(0){}

void UnitStore::addBuilders(Squad* b){
    builders_.push_back(b);
    ++allunits;
}


//void UnitStore::addWarriors(std::shared_ptr<Squad*> w){
//    warriors_.push_back(w);
//    ++allunits;
//}
void UnitStore::addWarriors(Squad* w){
    warriors_.push_back(w);
    ++allunits;
}

void UnitStore::addPeasants(Squad* p){
    peasants_.push_back(p);
    ++allunits;
}

void UnitStore::addHunters(Squad* h){
    hunters_.push_back(h);
    ++allunits;
}
Squad* UnitStore::builder(int i) {
    return builders_[i]; //куда б впихнуть проверку индекса
}

//std::shared_ptr<Squad*> UnitStore::warrior(int i) {
//    return warriors_[i];
//}
Squad* UnitStore::warrior(int i) {
    return warriors_[i];
}
Squad* UnitStore::hunter(int i) {
    return hunters_[i];
}
Squad* UnitStore::peasant(int i) {
    return peasants_[i];
}

void UnitStore::delStore(vector<Squad*>& v){
    while(! v.empty()){
        Squad* t = v.back();
        v.pop_back();
        delete t;
    }
}


UnitStore::~UnitStore() {
    delStore(builders_);
    delStore(warriors_);
    delStore(hunters_);
    delStore(peasants_);
}



void BuildingsStore::addChurch(SocialBuild* c) {
    churches.push_back(c);
}
void BuildingsStore::addHospital(SocialBuild *h) {
    hospitals.push_back(h);
}
void BuildingsStore::addMarket(EconomicBuild *m) {
    markets.push_back(m);
}
void BuildingsStore::addMoat(WarBuild *_m) {
    moat = _m;
}
void BuildingsStore::addWall(WarBuild *_w) {
    wall = _w;
}
SocialBuild* BuildingsStore::church(int i) {
    return churches[i];
}
SocialBuild* BuildingsStore::hospital(int i) {
    return hospitals[i];
}
EconomicBuild* BuildingsStore::market(int i) {
    return markets[i];
}
BuildingsStore::~BuildingsStore() {
    while(!churches.empty()){
        SocialBuild* t = churches.back();
        churches.pop_back();
        delete t;
    }
    while(!hospitals.empty()){
        SocialBuild* t = hospitals.back();
        hospitals.pop_back();
        delete t;
    }
    while(!markets.empty()){
        EconomicBuild* t = markets.back();
        markets.pop_back();
        delete t;
    }

}









//-------------------------------------------------------//
Squad* BuilderFactory::createSquad(int level){
    return new Builders(level);
}
int BuilderFactory::getPrice() {
    return price;
}
//std::shared_ptr<Squad*> WarriorFactory::createSquad(int level){
//    return std::make_shared<Squad*>(new Warriors(level));
//}
Squad* WarriorFactory::createSquad(int level){
    return new Warriors(level);
}
int WarriorFactory::getPrice() {
    return price;
}
Squad* HunterFactory::createSquad(int level){
    return new Hunters(level);
}
int HunterFactory::getPrice() {
    return  price;
}
Squad* PeasantFactory::createSquad(int level){
    return new Peasants(level);
}
int PeasantFactory::getPrice() {
    return  price;
}
//-------------------------------------------------------//
SocialBuild* CreateChurch::createSB(int level) {
    return new Church(level);
}
SocialBuild* CreateHospital::createSB(int level) {
    return new Hospital(level);
}
EconomicBuild* CreateMarket::createEB(int level) {
    return new Market(level);
}
WarBuild* CreateMoat::createWB(int level) {
    return new Moat(level);
}
WarBuild* CreateWall::createWB(int level) {
    return new Wall(level);
}


bool Village::createSquad(SquadID id, int level) {

        switch (id) {
        case SquadID::BUILDER: {
            BuilderFactory f;
            if (f.getPrice() * level < money) {
                u.addBuilders(f.createSquad(level));// SMART POINTER
                money -= f.getPrice() * level;
                return true;
            }

            break;
        }
        case SquadID::HUNTER: {
            HunterFactory f;
            if (f.getPrice() * level < money) {
                u.addHunters(f.createSquad(level));
                money -= f.getPrice() * level;
                return true;
            }
            break;
        }
        case SquadID::PEASANT: {
            PeasantFactory f;
            if(f.getPrice() * level < money){
                u.addPeasants(f.createSquad(level));
                money -= f.getPrice() * level;
                return true;
            }
            break;
        }
        case SquadID::WARRIOR: {
            WarriorFactory f;
            if(f.getPrice() * level < money){
                u.addWarriors(f.createSquad(level));
                money -= f.getPrice() * level;
                return true;
            }
            break;
        }
        default:
            break;
        }

    return false;
}
bool Village::createBuilding(BuildingID id, int level) {
    switch (id){
        case BuildingID::HOSPITAL:{
            CreateHospital f;
            if(f.price * level < money) {
                b.addHospital(f.createSB(level));
                money -= f.price * level;
                return true;
            }
            break;
        }
        case BuildingID::CHURCH:{
            CreateChurch f;
            if(f.price * level < money) {
                b.addChurch(f.createSB(level));
                money -= f.price * level;
                return true;
            }
            break;
        }
        case BuildingID::WALL:{
            CreateWall f;
            if(f.price * level < money) {
                b.addWall(f.createWB(level));
                money -= f.price * level;
                return  true;
            }
            break;
        }
        case BuildingID::MOAT:{
            CreateMoat f;
            if(f.price * level < money) {
                b.addMoat(f.createWB(level));
                money -= f.price * level;
                return true;
            }
            break;
        }
        case BuildingID::MARKET:{
            CreateMarket f;
            if(f.price * level < money) {
                b.addMarket(f.createEB(level));
                money -= f.price * level;
                return true;
            }
            break;
        }
        default:
            break;
    }
    return false;
}
Village::Village(): residents(20), money(300), happy(1.0), meal(150), fur(50){}
Village::Village(BuildingID id, vector<int> &stats):
    residents(stats[0]), money(stats[1]), meal(stats[2]), fur(stats[3]), happy(1.0) {
    //деньги уменьшаются, добавить!
    createBuilding(id, 1); //проблема здесь! не
}

//Village::getHappy(){
//    return happy;
//}