#include "../core.h"

#ifndef Included_Pane_H
#define Included_Pane_H

class Pane
{
public:
    Pane(int x, int y, int width, int height);
    virtual ~Pane();
    virtual void Draw();

    WINDOW* getWindow();

protected:
    int m_width, m_height;
    int m_x, m_y;
    WINDOW *m_pWindow;
};

#endif
