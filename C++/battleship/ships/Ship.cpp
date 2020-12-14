/* C++ BattleShip 프로젝트
작성일자 : 2018-05-26
학번 : 20171717 이름 : 최호경
*/
#include "../ships/Ship.h"

Ship::Ship() {}

Ship::Ship(int size, ShipType itstype)
{
    m_hp = m_size = size;
    m_type = itstype;
    m_cordis.resize(size);
}

Ship::~Ship() {}

//Set the base position
void Ship::setPosition(int x, int y)
{
    this->m_position.x = x;
    this->m_position.y = y;
}

//Set the piece coordinate of position
void Ship::setPosition(int idx, const Position & pos) {m_cordis[idx] = pos;}

void Ship::setPosition(const Position &pos) {m_cordis.push_back(pos);}

vector<Position> Ship::getPosition() {return this->m_cordis;}

void Ship::setLook(Direction look) {this->m_look = look;}

Direction Ship::getLook() {return this->m_look;}

int Ship::getSize() {return this->m_size;}

ShipType Ship::getType() {return this->m_type;}

void Ship::setName(string name) {this->m_name = name;}
string Ship::getName() {return this->m_name;}
