/* C++ BattleShip 프로젝트
작성일자 : 2018-05-26
학번 : 20171717 이름 : 최호경
*/
//This header includes important headers and options.
#ifndef __CORE_H__
#define __CORE_H__

#include <ncurses.h>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <unistd.h>

using std::vector;
using std::string;

const int MAP_SIZE = 8;

struct Position
{
    int x;
    int y;
    Position() {x = y = 0;}
};

enum ShipType
{
    DATA_ERROR = -1,
    DATA_NONE,
    CARRIER,
    BATTLESHIP,
    CRUISER,
    DESTROYER
};

enum Direction {NOT = -1, HORIZONTAL = 0, VERTICAL = 1};

enum HitResult {MISS, HIT, DESTROY};

#endif
