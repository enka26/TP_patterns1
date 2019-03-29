#include "Village.h"
#include <iostream>

int main() {
    vector<int> stats {20, 251, 150, 30};
    Village v(BuildingID::HOSPITAL, stats);
    //
    std::cout << v.b.hospital(0);
    std::cout <<v.createBuilding(BuildingID::MARKET, 1)<< v.b.market(0)<<std::endl;
    //std::cout << v.createSquad(SquadID::WARRIOR, 1)<<"\n";
    //v.u.warrior(0)->help();
    return 0;
}