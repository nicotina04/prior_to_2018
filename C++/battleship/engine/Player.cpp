/* C++ BattleShip 프로젝트
작성일자 : 2018-05-30
학번 : 20171717 이름 : 최호경
*/
#include "../engine/Player.h"

Player::Player() {m_Map = new Map();}

Player::~Player()
{
    delete m_Map;
    for (auto pShip : m_Ships) {if(pShip) {delete pShip;}}
    m_Ships.clear();
}

void Player::SetupShips(const SHIPS& ships)
{
    m_Ships = ships;
    vector<Ship*>::iterator t;

    for (auto pShip : m_Ships)
    {
        srand(time(NULL));
        while (true)
        {
            Position pos;
            pos.x = rand() % MAP_SIZE;
            pos.y = rand() % MAP_SIZE;

            //Another ship is exist?
            if(m_Map->GetData(pos) != DATA_NONE) {continue;}

            Position dir;

            if (rand() % 2) {dir.x = rand()%2 ? 1 : -1;}
            else {dir.y = rand()%2 ? 1 : -1;}

            pos.x += dir.x;
            pos.y += dir.y;

            bool bSuccess = true;

            for (int i = 0; i < pShip->getSize(); ++i)
            {
                pos.x += dir.x;
                pos.y += dir.y;
                ShipType dataType = m_Map->GetData(pos);
                if (dataType != DATA_NONE)
                {
                    bSuccess = false;
                    break;
                }
                pShip->setPosition(i, pos);
            }
            if(bSuccess)
            {
                ShipType inputtype(pShip->getType());
                for (int i = 0; i < pShip->getSize(); i++)
                {
                    m_Map->setType(pShip->getPosition()[i].x, pShip->getPosition()[i].y, inputtype);
                }
                break;
            }
        }
    }
}

Position Player::Attack()
{
    Position setter;
    char Pos[2];
    keypad(stdscr, TRUE);
    mvprintw(17, 40, "            ");
    curs_set(0);
    mvscanw(17, 40, "%s", Pos);
    // getch();

    // 65-A 97-a
    int posX = Pos[0]-'0'-17;//'65';
    int posY = Pos[1]-'0';

    setter.x = posY-1;
    setter.y = posX;

    return setter;
}

HitResult Player::HitCheck(const Position& pos)
{

}
