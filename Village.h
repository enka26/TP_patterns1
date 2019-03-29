//
// Created by enka on 27.03.19.
//

#ifndef PATTERNS_VILLAGE_H
#define PATTERNS_VILLAGE_H

#include "buildings.h"
#include "squads.h"
#include <vector>
#include <memory>

using std::vector;

enum class BuildingID{
    HOSPITAL, CHURCH, WALL, MOAT, MARKET
};

enum class SquadID{
    BUILDER, WARRIOR, HUNTER, PEASANT
};
class UnitStore{
public:
    UnitStore();

    void addBuilders(Squad* b);
    //void addWarriors(std::shared_ptr<Squad*> w);
    void addWarriors(Squad* w);
    void addPeasants(Squad* b);
    void addHunters(Squad* h);
    //фигня переписать
    Squad* builder(int i);
    //std::shared_ptr<Squad*> warrior(int i);
    Squad* warrior(int i);
    Squad* peasant(int i);
    Squad* hunter(int i);


    //деструктор  delete!!!!!
    ~UnitStore();

private:
    void delStore(vector<Squad*>& v);
    vector<Squad*> builders_;
    //vector<std::shared_ptr<Squad*>> warriors_;
    vector<Squad*> warriors_;
    vector<Squad*> peasants_;
    vector<Squad*> hunters_;
    int allunits = 0;
};


class BuildingsStore{
public:
    //constructor???
    void addHospital(SocialBuild* h);
    void addChurch(SocialBuild* c);
    void addWall(WarBuild* _w);
    void addMoat(WarBuild* _m);
    void addMarket(EconomicBuild* m);
    SocialBuild* hospital(int i);
    SocialBuild* church(int i);
    EconomicBuild* market(int i);

    //дестурктор
    WarBuild* wall = nullptr;
    WarBuild* moat = nullptr;
    ~BuildingsStore();
private:

    vector<SocialBuild*> hospitals;
    vector<SocialBuild*> churches; //разобраться с указателями

    vector<EconomicBuild*> markets;
};



//class SquadFactory{
//public:
//    virtual std::shared_ptr<Squad*> createSquad(int level) = 0;
//    virtual int getPrice() = 0;
//    virtual ~SquadFactory() = default;
//};

class SquadFactory{
public:
    virtual Squad* createSquad(int level) = 0;
    virtual int getPrice() = 0;
    virtual ~SquadFactory() = default;
};

//_______________SQUAD FACTORIES________________//
class BuilderFactory: public SquadFactory{
public:
    Squad* createSquad(int level) override;
    int getPrice() override;
private:
    int price = 30;
};

//class WarriorFactory: public SquadFactory{
//public:
//    std::shared_ptr<Squad*> createSquad(int level) override;
//    int getPrice() override;
//
//private:
//    int price = 40;
//};

class WarriorFactory: public SquadFactory{
public:
    Squad* createSquad(int level) override;
    int getPrice() override;

private:
    int price = 40;
};
class HunterFactory: public SquadFactory{
public:
    Squad* createSquad(int level) override;
    int getPrice() override;

private:
    int price = 50;
};

class PeasantFactory: public SquadFactory{
public:
    Squad* createSquad(int level) override;
    int getPrice() override;

private:
    int price = 30;
};
//____________________BUILDING FACTORIES_________________//


class SocialBuildFactory{
public:
    virtual SocialBuild* createSB(int level) = 0;

    virtual ~SocialBuildFactory() = default;
};

class CreateHospital:public SocialBuildFactory{
public:
    SocialBuild* createSB(int level) override;
    const int price = 250;
};

class CreateChurch:public SocialBuildFactory{
public:
    SocialBuild* createSB(int level) override;
    const int price = 250;
};
////////////////////////////////////////////////////////
class WarBuildFactory{
public:
    virtual WarBuild* createWB(int level) = 0;
    virtual ~WarBuildFactory() = default;
};
class CreateWall:public WarBuildFactory{
public:
    WarBuild* createWB(int level) override;

    const int price = 500;
};

class CreateMoat:public WarBuildFactory{
public:
    WarBuild* createWB(int level) override;
    const int price = 300;
};
//////////////////////////////////////////////////
class EconomicBuildFactory{
public:
    virtual EconomicBuild* createEB(int level) = 0;
    virtual ~EconomicBuildFactory() = default;
};

class CreateMarket: public EconomicBuildFactory{
public:
    EconomicBuild* createEB(int level) override;
    const int price = 250;
};
////////////////////////////////////
class BuildingFactory{
public:
    SocialBuildFactory* SocialBF;
    WarBuildFactory* WarBF;
    EconomicBuildFactory* EconomicBF;
};
//___________________________VILLAGE____________________________//
class Village{
public:
    Village(BuildingID id, vector<int>& stats);
    Village();

    UnitStore u; //не запихнуть ли их в приватые
    BuildingsStore b;
    BuildingFactory BF;
    SquadFactory* SF;


    bool createSquad(SquadID id, int level);
    bool createBuilding(BuildingID id , int level);
//    void demography();
//    void addResource();
//    void statistic();
//    double getHappy(); //коэф рандомно выбирается на каждом ходе
private:
    int residents = 20;
    int money = 150;
    double happy = 1;
    int meal = 150;
    int fur  =50;
};

#endif //PATTERNS_VILLAGE_H
