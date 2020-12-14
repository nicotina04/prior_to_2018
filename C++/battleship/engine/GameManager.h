/* C++ BattleShip 프로젝트
작성일자 : 2018-05-27
학번 : 20171717 이름 : 최호경
*/
#include "../core.h"
#include "../engine/CBattleShipApp.h"
#include "../engine/Player.h"
#include "../ships/Cruiser.h"
#include "../ships/Carrier.h"
#include "../ships/Battleship.h"
#include "../ships/Destroyer.h"

class GameManager
{
public:
    enum GameMode {PLAY_INPUT = 0, PLAY_RANDOM = 1, AIVSAI = 2};
    GameManager();
    ~GameManager();

    void simulate();

    static GameManager* GetInstance()
    {
        static GameManager instance;
        return &instance;
    }

    void setGameMode(GameMode mod);
    int getGameMode();

    void AddTurn();
    void setTurn(int t);
    int getTurn();

    void Init();
    void Play();
    void Render();

    void Destroy();

    ShipType AttackByInput(char* cmd);
    int AttackByInput(int i, int j);

    int isDead();

private:
    int m_Turn;
    GameMode m_GameMode;
    Player *m_p1, *m_p2;
    CBattleShipApp *m_App;
};
