/* C++ BattleShip 프로젝트
작성일자 : 2018-05-26
학번 : 20171717 이름 : 최호경
*/
#include "../core.h"

class Ship
{
public:
    Ship();
    Ship(int size, ShipType itstype);
    ~Ship();

    string getName();
    void setName(string);

    vector<Position> getPosition();
    void setPosition(int x, int y);
    void setPosition(int index, const Position& pos);
    void setPosition(const Position & pos);

    void setLook(Direction look);
    Direction getLook();

    int getSize();
    ShipType getType();

    int hitCheck();

protected:
    int m_hp, m_size;
    ShipType m_type;
    Position m_position;
    vector<Position> m_cordis;
    Direction m_look;
    string m_name;
};
