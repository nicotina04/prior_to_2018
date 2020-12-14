#include "Pane.h"

class InputPane : public Pane
{
public:
    InputPane(int x, int y, int width, int height);
    ~InputPane();

    virtual void Draw();
    void PrintResult();
    void Update();
};
