/* C++ BattleShip 프로젝트
작성일자 : 2018-05-30
학번 : 20171717 이름 : 최호경
*/
#include "../core.h"
#include "../engine/Map.h"
#include "../ships/Ship.h"

#define SHIPS std::vector<Ship*>

class Player
{
public:
    Player();
    ~Player();

    //Defender
    void SetupShips(const SHIPS& ships);
    HitResult HitCheck(const Position& pos);

    void simulate();

    //Attacker
    Position Attack();
    Map* getMap() {return m_Map;}

protected:
    Map* m_Map;
    SHIPS m_Ships;
};
