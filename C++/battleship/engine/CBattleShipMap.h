#include "../UI/Pane.h"
#include "../core.h"

#define MAP_SIZE 8

class CBattleShipMap: Pane
{
public:
    CBattleShipMap();
    CBattleShipMap(int x, int y);
    ~CBattleShipMap();

    void Draw();
    void SetMapData(int i, int j, char a);
    char GetMapData(int i, int j);
    char& GetMapData(char const cmd[2]);
protected:
    char m_mapData[MAP_SIZE][MAP_SIZE];
};
