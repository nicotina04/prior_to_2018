/* C++ BattleShip 프로젝트
작성일자 : 2018-05-27
학번 : 20171717 이름 : 최호경
*/
#include "../UI/StatPane.h"
#include "../engine/CBattleShipMap.h"
#include "../UI/InputPane.h"

class CBattleShipApp
{
public:
    CBattleShipApp();
    ~CBattleShipApp();

    void Init();
    void Render();
    void Destroy();

    CBattleShipMap* getMap() {return m_AImap;}
    CBattleShipMap* getPMap() {return m_pMap;}
    InputPane* getInputPane() {return m_pInputPane;}
    StatPane* getStatPane() {return m_pStatPane;}

    void Play();

protected:
    CBattleShipMap *m_pMap;
    CBattleShipMap *m_AImap;
    StatPane *m_pStatPane;
    InputPane *m_pInputPane;
};
