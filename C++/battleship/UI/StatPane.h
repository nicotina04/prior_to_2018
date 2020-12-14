#include "../UI/Pane.h"

class StatPane: Pane
{
public:
    StatPane(int x, int y, int width, int height);
    ~StatPane();

    virtual void Draw();
};
