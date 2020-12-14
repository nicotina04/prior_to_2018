/* C++ BattleShip 프로젝트
작성일자 : 2018-05-26
학번 : 20171717 이름 : 최호경
*/
#include "GameManager.h"

int main()
{
    int counter(0);
    int sums(0);

    GameManager manager;
    //데이터를 축적하기 위한 메서드
    manager.simulate();



    for(int i = 0; i < 10; ++i)
    {
        ++counter;
        manager.Init();
        manager.Render();
        manager.Play();
        mvprintw(10,39,"%d", counter);
    }

    sums = manager.getTurn() / counter;
    mvprintw(11, 46, "%d", sums);
    mvprintw(10,39,"%d", counter);
    manager.Destroy();



    return 0;
}
