/* C++ BattleShip 프로젝트
작성일자 : 2018-05-30
학번 : 20171717 이름 : 최호경
*/
#include "../core.h"

class Map
{
public:
    Map();
    ~Map();

    ShipType GetData(const Position& pos)
    {
        if (pos.x >= MAP_SIZE || pos.y >= MAP_SIZE || pos.x < 0 || pos.y < 0)
        {
            return DATA_ERROR;
        }
        return m_pMap[pos.x][pos.y];
    }


    ShipType getType(int row, int col) {return m_pMap[row][col];}
    void setType(int row, int col, ShipType type) {m_pMap[row][col] = type;}

protected:
    ShipType m_pMap[MAP_SIZE][MAP_SIZE];
};
