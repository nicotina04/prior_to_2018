/* C++ BattleShip 프로젝트
작성일자 : 2018-05-30
학번 : 20171717 이름 : 최호경
*/
#include "../engine/Map.h"

Map::Map()
{
    for(int i = 0; i < MAP_SIZE; ++i)
    {
        for(int j = 0; j < MAP_SIZE; ++j)
        {
            m_pMap[i][j] = DATA_NONE;
        }
    }
}

Map::~Map() {}
