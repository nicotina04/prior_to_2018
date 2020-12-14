#include "../UI/Pane.h"

Pane::Pane(int x, int y, int width, int height)
{
    this->m_x = x;
    this->m_y = y;
    this->m_width = width;
    this->m_height = height;
    this->m_pWindow = newwin(height, width, y, x);

    box(this->m_pWindow, 0, 0);
    wrefresh(this->m_pWindow);
}

Pane::~Pane() {delwin(this->m_pWindow);}

void Pane::Draw()
{
    box(this->m_pWindow, 0, 0);
    wrefresh(this->m_pWindow);
}

WINDOW* Pane::getWindow()
{
    return this->m_pWindow;
}
