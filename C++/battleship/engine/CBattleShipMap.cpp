/* C++ BattleShip 프로젝트
작성일자 : 2018-05-29
학번 : 20171717 이름 : 최호경
*/
#include "../engine/CBattleShipMap.h"

CBattleShipMap::CBattleShipMap():Pane(4, 4, MAP_SIZE + 3, MAP_SIZE + 2)
{

    for(int i = 0; i < MAP_SIZE; ++i)
    {
        for(int j = 0; j < MAP_SIZE; ++j)
        {
            //INIT MAP data
            m_mapData[i][j] = 'O';
        }
    }

    //PRINT SECTOR
    for(int i = 0; i < MAP_SIZE; ++i)
    {
        mvprintw(i + 1 + m_y, m_x - 1, "%c", 'A' + i);
        mvprintw(m_y + m_height, m_x + 2 + i, "%d", i + 1);
    }

    //PRINT TITLE
    mvwprintw(m_pWindow, 0, 3, "<MAP>");
}

CBattleShipMap::CBattleShipMap(int x, int y):Pane(x, y, MAP_SIZE + 3, MAP_SIZE + 2)
{
    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; ++j)
        {
            m_mapData[i][j] = '?';
        }
    }

    for (int i = 0; i < MAP_SIZE; ++i)
    {
        mvprintw(i + 1 + m_y, m_x - 1, "%c", 'A' + i);
        mvprintw(m_y + m_height, m_x + 2 + i, "%d", 1 + i);
    }

    mvwprintw(m_pWindow, 0, 3, "<MAP>");
}

CBattleShipMap::~CBattleShipMap() {}

void CBattleShipMap::Draw()
{
    wattron(m_pWindow, COLOR_PAIR(1));
    for(int i = 0; i < MAP_SIZE; ++i)
    {
        for(int j = 0; j < MAP_SIZE; ++j)
        {
            mvwprintw(m_pWindow, i + 1, j + 2, "%c", m_mapData[i][j]);
        }
    }
    wattroff(m_pWindow, COLOR_PAIR(1));

    wrefresh(m_pWindow);
}

void CBattleShipMap::SetMapData(int i, int j, char a)
{
    m_mapData[i][j] = a;
}

char& CBattleShipMap::GetMapData(char const cmd[2])
{
    if (cmd[0] <= 72 && cmd[0] >= 65 && cmd[1] < '9' && cmd[1] > '0')
    {
        return m_mapData[cmd[0] - 65][cmd[1] - 48 - 1];
    }
    else if(cmd[0] <= 104 && cmd[0] >= 97 && cmd[1] < '9' && cmd[1] > '0')
    {
        return m_mapData[cmd[0] - 97][cmd[1] - 48 - 1];
    }
}

char CBattleShipMap::GetMapData(int i, int j)
{
    if(i >= MAP_SIZE || j >= MAP_SIZE || i < 0 || j < 0)
    {
        return 'F';
    }
    else
    {
        return m_mapData[i][j];
    }
}
