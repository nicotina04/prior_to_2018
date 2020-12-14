/* C++ BattleShip 프로젝트
작성일자 : 2018-05-28
학번 : 20171717 이름 : 최호경
*/
#include "../core.h"
#include "CBattleShipApp.h"

CBattleShipApp::CBattleShipApp() {}

CBattleShipApp::~CBattleShipApp() {}

void CBattleShipApp::Init()
{
    initscr();
    start_color();
    cbreak();
    refresh();

    //Set colors
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);

    m_AImap = new CBattleShipMap(2, 2);
    m_pMap = new CBattleShipMap(2, 14);
    m_pStatPane = new StatPane(30, 3, 30, 10);
    m_pInputPane = new InputPane(30, 15, 30, 4);
}

void CBattleShipApp::Play()
{
    int turn(0);
    while (true)
    {
        Render();

        move(17, 40);
        keypad(m_pInputPane->getWindow(), false);
        char cmd[2];
        scanw("%s", cmd);
        string scmd(cmd);
        if (scmd == "gg" || scmd == "GG") {break;}
        if(m_AImap->GetMapData(cmd) == 'F' || m_AImap->GetMapData(cmd) == 'X' || m_AImap->GetMapData(cmd) == 'O') {continue;}
        else if (m_AImap->GetMapData(cmd) == '?')
        {
            m_AImap->SetMapData(cmd[0] - 65, cmd[1] - 48 - 1, 'O');
            ++turn;
        }
        else
        {
            m_AImap->SetMapData(cmd[0] - 65, cmd[1] - 48 - 1, 'X');
            ++turn;
        }

        m_AImap->Draw();
        mvprintw(8,39,"%d", turn);

        wrefresh(m_pInputPane->getWindow());
    }
    mvprintw(8,39,"%s", "GAME END");
    Destroy();
}

void CBattleShipApp::Render()
{
    mvprintw(1, 1, "<<Battleship>>");

    (*m_AImap).Draw();
    (*m_pMap).Draw();
    (*m_pStatPane).Draw();
    (*m_pInputPane).Draw();

    refresh();
}

void CBattleShipApp::Destroy()
{
    getch();
    endwin();
    delete m_AImap;
    delete m_pMap;
}
