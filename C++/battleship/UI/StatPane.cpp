#include "../UI/StatPane.h"

StatPane::StatPane(int x, int y, int width, int height):Pane(x, y, width, height)
{
    mvwprintw(this->m_pWindow, 0, 3, "< STATUS >");
}

StatPane::~StatPane() {}

void StatPane::Draw()
{
    wattron(m_pWindow, COLOR_PAIR(2));
    mvwprintw(m_pWindow, 1, 2, "AIR CARRIER : AAAAA");
    mvwprintw(m_pWindow, 2, 2, "BATTLESHIP : BBBB");
    mvwprintw(m_pWindow, 3, 2, "CRUISER : CCC");
    mvwprintw(m_pWindow, 4, 2, "DESTROYER : DD DD");
    mvwprintw(m_pWindow, 5, 2, "TURN : ");
    mvwprintw(m_pWindow, 6, 2, "ATTACK RESULT : ");
    mvwprintw(m_pWindow, 7, 2, "ROUND : ");
    mvwprintw(m_pWindow, 8, 2, "AVG OF TURNs : ");        

    wattroff(m_pWindow, COLOR_PAIR(2));

    wrefresh(m_pWindow);
}
