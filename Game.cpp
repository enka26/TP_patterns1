//
// Created by enka on 27.03.19.
//

#include <iostream>
#include "Game.h"
// переписать меню, возваращать статы
// Game::start() {
//    std::cout << "Create village: ordinary - print 1, special - print 2\n";
//    int answ;
//    std::cin >> answ;
//    if (answ == 1) {
//        Village v;
//    }
//    else if(answ == 2){
//        std::cout << "Choose modification:\n 1. Add Hospital \n 2.Add church\n 3.Add market\n";
//        std::cout << "4. Add wall\n 5. Add moat\n Print number of  modification\n";
//
//        std::cin >> answ;
//        switch (answ){
//            case 1:{
//                vector<int> stats {20, 150, 150, 30};
//                Village v(BuildingID::HOSPITAL, stats);
//                break;
//            }
//            case 2:{
//                vector<int> stats {15, 150, 170, 20};
//                Village v(BuildingID::CHURCH, stats);
//                break;
//            }
//            case 3:{
//                vector<int> stats {40, 150, 130, 50};
//                Village v(BuildingID::MARKET, stats);
//                break;
//            }
//            case 4:{
//                vector<int> stats {25, 120, 170, 10};
//                Village v(BuildingID::WALL, stats);
//                break;
//            }
//            case 5:{
//                vector<int> stats {25, 120, 170, 10};
//                Village v(BuildingID::MOAT, stats);
//                break;
//            }
//            default:
//                std::cout << "Wrong modification\n";
//                break;
//        }
//    } else {
//        std::cout << "Wrong input\n";
//        return nullptr;
//    }
//    }
//void Game::menu() {
//    std::cout<<"Create building - 1, create squad - 2\n";
//    int answ;
//    std::cin >> answ;
//    if(answ == 1){
//        std::cout << "Choose building";
//
//    }
//
//}

//void Game::game(){
//    while (!isDead) {
//        menu();
//        specialEvent();
//        ++time;
//        if(time > 545 || v.getHappy() < 0.05)
//            isDead = true;
//    }
//}
