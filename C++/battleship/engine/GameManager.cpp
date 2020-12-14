/* C++ BattleShip 프로젝트
작성일자 : 2018-06-04
학번 : 20171717 이름 : 최호경
*/
#include "../engine/GameManager.h"
#include <map>
#include <fstream>
#include <iostream>

using std::ofstream;

void GameManager::simulate()
{
    Player *testfield = new Player();

    vector<Ship*> vecShip;

    vecShip.push_back(new Ship(5, CARRIER));
    vecShip.push_back(new Ship(4, BATTLESHIP));
    vecShip.push_back(new Ship(3, CRUISER));
    vecShip.push_back(new Ship(2, DESTROYER));
    vecShip.push_back(new Ship(2, DESTROYER));

    ofstream monte("data.txt");

    for(int i = 0; i < 1000; ++i)
    {
        testfield->SetupShips(vecShip);
        //std::cout << "start" << '\n';
        for(int j = 0; j < MAP_SIZE; ++j)
        {
            for(int k = 0; k < MAP_SIZE; ++k)
            {
                if(testfield->getMap()->getType(j, k) != DATA_NONE)
                {
                    //std::cout << "FOUND" << '\n';
                    monte << j << " " << k << "\n";
                }
            }
        }
        for(int j = 0; j < MAP_SIZE; ++j)
        {
            for(int k = 0; k < MAP_SIZE; ++k)
            {
                testfield->getMap()->setType(j, k, DATA_NONE);
            }
        }
    }
}

GameManager::GameManager()
{
    m_App = nullptr;
    m_p1 = nullptr;
    m_p2 = nullptr;
    this->m_GameMode = PLAY_RANDOM;
    this->m_Turn = 0;
}

GameManager::~GameManager()
{
    if (m_p1)
    {
        delete m_p1;
        m_p1 = nullptr;
    }
    if (m_p2)
    {
        delete m_p2;
        m_p2 = nullptr;
    }
}

void GameManager::Init()
{
    m_p1 = new Player();
    m_p2 = new Player();
    m_App = new CBattleShipApp();

    m_App->Init();

    vector<Ship*> vecShip;

    vecShip.push_back(new Ship(5, CARRIER));
    vecShip.push_back(new Ship(4, BATTLESHIP));
    vecShip.push_back(new Ship(3, CRUISER));
    vecShip.push_back(new Ship(2, DESTROYER));
    vecShip.push_back(new Ship(2, DESTROYER));

    m_p2->SetupShips(vecShip);
    m_p1->SetupShips(vecShip);

    for (int i = 0; i < MAP_SIZE; ++i)
    {
        for (int j = 0; j < MAP_SIZE; ++j)
        {
            char a = '?';
            switch (m_p2->getMap()->getType(i, j))
            {
                case CARRIER:
                    a = 'A';
                    break;
                case BATTLESHIP:
                    a = 'B';
                    break;
                case CRUISER:
                    a = 'C';
                    break;
                case DESTROYER:
                    a = 'D';
                    break;
                default:
                break;
            }
            m_App->getMap()->SetMapData(i, j, a);
        }

    }
}

ShipType GameManager::AttackByInput(char *cmd)
{
    if(m_App->getMap()->GetMapData(cmd) == 'F' || m_App->getMap()->GetMapData(cmd) == 'X' || m_App->getMap()->GetMapData(cmd) == 'O')
    {
        mvprintw(9,46,"%s", "WRONG INPUT");
        return DATA_ERROR;
    }
    else if(m_App->getMap()->GetMapData(cmd) == '?')
    {
        mvprintw(9, 46, "            ");
        m_App->getMap()->SetMapData(cmd[0] - 65, cmd[1] - 48 - 1, 'O');
        AddTurn();
        mvprintw(9,46,"%s", "MISS");
        return DATA_NONE;
    }
    else if(m_App->getMap()->GetMapData(cmd) == 'A')
    {
        mvprintw(9, 46, "            ");
        m_App->getMap()->SetMapData(cmd[0] - 65, cmd[1] - 48 - 1, 'X');
        AddTurn();
        mvprintw(9,46,"%s", "HIT");
        return CARRIER;
    }
    else if(m_App->getMap()->GetMapData(cmd) == 'B')
    {
        mvprintw(9, 46, "            ");
        m_App->getMap()->SetMapData(cmd[0] - 65, cmd[1] - 48 - 1, 'X');
        AddTurn();
        mvprintw(9,46,"%s", "HIT");
        return BATTLESHIP;
    }
    else if(m_App->getMap()->GetMapData(cmd) == 'C')
    {
        mvprintw(9, 46, "            ");
        m_App->getMap()->SetMapData(cmd[0] - 65, cmd[1] - 48 - 1, 'X');
        AddTurn();
        mvprintw(9,46,"%s", "HIT");
        return CRUISER;
    }
    else if(m_App->getMap()->GetMapData(cmd) == 'D')
    {
        mvprintw(9, 46, "            ");
        m_App->getMap()->SetMapData(cmd[0] - 65, cmd[1] - 48 - 1, 'X');
        AddTurn();
        mvprintw(9,46,"%s", "HIT");
        return DESTROYER;
    }
    else {return DATA_ERROR;}
}

int GameManager::AttackByInput(int i, int j)
{
    if(m_App->getMap()->GetMapData(i, j) == 'F' || m_App->getMap()->GetMapData(i, j) == 'X' || m_App->getMap()->GetMapData(i, j) == 'O')
    {
        mvprintw(9,46,"%s", "WRONG INPUT");
        return -1;
    }
    else if(m_App->getMap()->GetMapData(i, j) == '?')
    {
        mvprintw(9, 46, "            ");
        m_App->getMap()->SetMapData(i, j, 'O');
        AddTurn();
        mvprintw(9,46,"%s", "MISS");
        return 0;
    }
    else if(m_App->getMap()->GetMapData(i, j) == 'A')
    {
        mvprintw(9, 46, "            ");
        m_App->getMap()->SetMapData(i, j, 'X');
        AddTurn();
        mvprintw(9,46,"%s", "HIT");
        return 1;
    }
    else if(m_App->getMap()->GetMapData(i, j) == 'B')
    {
        mvprintw(9, 46, "            ");
        m_App->getMap()->SetMapData(i, j, 'X');
        AddTurn();
        mvprintw(9,46,"%s", "HIT");
        return 1;
    }
    else if(m_App->getMap()->GetMapData(i, j) == 'C')
    {
        mvprintw(9, 46, "            ");
        m_App->getMap()->SetMapData(i, j, 'X');
        AddTurn();
        mvprintw(9,46,"%s", "HIT");
        return 1;
    }
    else if(m_App->getMap()->GetMapData(i, j) == 'D')
    {
        mvprintw(9, 46, "            ");
        m_App->getMap()->SetMapData(i, j, 'X');
        AddTurn();
        mvprintw(9,46,"%s", "HIT");
        return 1;
    }
    else {return -1;}
}

void GameManager::AddTurn() {++m_Turn;}

void GameManager::setTurn(int t) {this->m_Turn = t;}

int GameManager::getTurn() {return m_Turn;}

void GameManager::setGameMode(GameMode mod) {this->m_GameMode = mod;}

int GameManager::getGameMode() {return this->m_GameMode;}

void GameManager::Play()
{
    if(getGameMode() == PLAY_INPUT)
    {
        int carrierhp(5);
        int battleshiphp(4);
        int cruiserhp(3);
        int destroyerhp(4);
        while (true)
        {
            Render();

            move(17, 40);
            keypad(m_App->getInputPane()->getWindow(), false);
            char cmd[2];
            scanw("%s", cmd);
            mvprintw(17, 40, "            ");
            string scmd(cmd);
            if (scmd == "gg" || scmd == "GG") {break;}
            //AttackByInput(cmd);
            if(AttackByInput(cmd) == DATA_ERROR) {continue;}
            else if (AttackByInput(cmd) == DATA_NONE) {}
            else
            {
                if(m_p2->getMap()->getType(cmd[0] - 65, cmd[1] - 48 - 1) == CARRIER)
                {
                    --carrierhp;
                    if(!carrierhp)
                    {
                        mvprintw(9, 46, "            ");
                        mvprintw(9,46,"%s", "CAREIER DOWN");
                    }
                }
                else if(m_p2->getMap()->getType(cmd[0] - 65, cmd[1] - 48 - 1) == BATTLESHIP)
                {
                    --battleshiphp;
                    if(!battleshiphp)
                    {
                        mvprintw(9, 46, "            ");
                        mvprintw(9,46,"%s", "B-SHIP DOWN");
                    }
                }
                else if(m_p2->getMap()->getType(cmd[0] - 65, cmd[1] - 48 - 1) == CRUISER)
                {
                    --cruiserhp;
                    if(!cruiserhp)
                    {
                        mvprintw(9, 46, "            ");
                        mvprintw(9,46,"%s", "CRUISER DOWN");
                    }
                }
                else if(m_p2->getMap()->getType(cmd[0] - 65, cmd[1] - 48 - 1) == DESTROYER)
                {
                    --destroyerhp;
                    if(destroyerhp == 2)
                    {
                        mvprintw(9, 46, "            ");
                        mvprintw(9,46,"%s", "D HALF DOWN");
                    }
                    if(destroyerhp == 0)
                    {
                        mvprintw(9, 46, "            ");
                        mvprintw(9,46,"%s", "ALL D DOWN");
                    }
                }
            }

            m_App->getMap()->Draw();
            mvprintw(8,39,"%d", getTurn());

            wrefresh(m_App->getInputPane()->getWindow());
            if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp){break;}
        }
        mvprintw(8,39,"%s", "GAME END");
        Destroy();
    }
    else if(getGameMode() == PLAY_RANDOM)
    {
        std::map<string, int> bigdata;
        std::map<string, int>::iterator tv;
        vector<string>::iterator v;
        string target("");

        vector<string> high;
        vector<string> highmid;
        vector<string> medium;
        vector<string> low;

        vector<string> temp;

        std::fstream opener;
        opener.open("data.txt");
        for(int i = 0; i < MAP_SIZE; ++i)
        {
            for(int j = 0; j < MAP_SIZE; ++j)
            {
                char left('0' + i); char right('0' + j);
                string tmp("");
                tmp += left; tmp += right;
                //string tmp(std::to_string(i) + std::to_string(j)); <- C++11 standard
                bigdata[tmp] = 0;
            }
        }
        while(!opener.eof())
        {
            string temp;
            opener >> temp; target = temp; opener >> temp; target += temp;
            ++bigdata[target];
            target = "";
        }
        //mvprintw(19,39,"%d", bigdata.size());

        while(bigdata.size() > 0)
        {
            string delt;
            auto comper(-1);
            for(tv = bigdata.begin(); tv != bigdata.end(); ++tv)
            {
                if(comper < tv->second) {comper = tv->second;}
            }
            for(tv = bigdata.begin(); tv != bigdata.end(); ++tv)
            {
                if(comper == tv->second)
                {
                    temp.push_back(tv->first);
                    delt = tv->first;
                    break;
                }
            }
            bigdata.erase(delt);
        }


        int delimeter(0);

        while(temp.size() > 0)
        {
            if(delimeter < 16)
            {
                high.push_back(temp.back());
                temp.pop_back();
            }
            else if(delimeter < 40)
            {
                highmid.push_back(temp.back());
                temp.pop_back();
            }
            else if(delimeter < 54)
            {
                medium.push_back(temp.back());
                temp.pop_back();
            }
            else
            {
                low.push_back(temp.back());
                temp.pop_back();
            }
            ++delimeter;
        }

        int carrierhp(5);
        int battleshiphp(4);
        int cruiserhp(3);
        int destroyerhp(4);

        int chars, nums;
        bool isHIT(false);

        while(1)
        {
            Render();
            mvprintw(17, 40, "PLAYING AUTO");

            if(high.size() > 0)
            {
                std::random_shuffle(high.begin(), high.end());

                chars = high.back()[0] - 48;
                nums = high.back()[1] - 48;
                high.pop_back();
            }
            else if(highmid.size() > 0)
            {
                std::random_shuffle(highmid.begin(), highmid.end());

                chars = highmid.back()[0] - 48;
                nums = highmid.back()[1] - 48;
                highmid.pop_back();
            }
            else if(medium.size() > 0)
            {
                std::random_shuffle(medium.begin(), medium.end());

                chars = medium.back()[0] - 48;
                nums = medium.back()[1] - 48;
                medium.pop_back();
            }
            else
            {
                std::random_shuffle(low.begin(), low.end());

                chars = low.back()[0] - 48;
                nums = low.back()[1] - 48;
                low.pop_back();
            }

            if(m_App->getMap()->GetMapData(chars, nums) == '?' || m_App->getMap()->GetMapData(chars, nums) == 'O' || m_App->getMap()->GetMapData(chars, nums) == 'X')
            {
                isHIT = false;
                AttackByInput(chars, nums);
            }
            else
            {
                isHIT = true;
                AttackByInput(chars, nums);
                if(m_p2->getMap()->getType(chars, nums) == CARRIER)
                {
                    m_p2->getMap()->setType(chars, nums, DATA_ERROR);
                    --carrierhp;
                    if(!carrierhp)
                    {
                        mvprintw(9, 46, "            ");
                        mvprintw(9,46,"%s", "CAREIER DOWN");
                    }
                }
                else if(m_p2->getMap()->getType(chars, nums) == BATTLESHIP)
                {
                    m_p2->getMap()->setType(chars, nums, DATA_ERROR);
                    --battleshiphp;
                    if(!battleshiphp)
                    {
                        mvprintw(9, 46, "            ");
                        mvprintw(9,46,"%s", "B-SHIP DOWN");
                    }
                }
                else if(m_p2->getMap()->getType(chars, nums) == CRUISER)
                {
                    m_p2->getMap()->setType(chars, nums, DATA_ERROR);
                    --cruiserhp;
                    if(!cruiserhp)
                    {
                        mvprintw(9, 46, "            ");
                        mvprintw(9,46,"%s", "CRUISER DOWN");
                    }
                }
                else if(m_p2->getMap()->getType(chars, nums) == DESTROYER)
                {
                    m_p2->getMap()->setType(chars, nums, DATA_ERROR);
                    --destroyerhp;
                    if(destroyerhp == 2)
                    {
                        mvprintw(9, 46, "            ");
                        mvprintw(9,46,"%s", "D HALF DOWN");
                    }
                    if(destroyerhp == 0)
                    {
                        mvprintw(9, 46, "            ");
                        mvprintw(9,46,"%s", "ALL D DOWN");
                    }
                }
            }

                if(isHIT == true)
                {

                    if(chars > 0 && chars < 7 && nums > 0 && nums < 7)
                    {
                        AttackByInput(chars + 1, nums);
                        if(m_p2->getMap()->getType(chars + 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars + 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars + 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars - 1, nums);
                        if(m_p2->getMap()->getType(chars - 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars - 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars - 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars, nums + 1);
                        if(m_p2->getMap()->getType(chars, nums + 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums + 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums + 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars, nums - 1);
                        if(m_p2->getMap()->getType(chars, nums - 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums - 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums - 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                    }
                    else if(chars > 0 && chars < 7 && nums == 0)
                    {
                        AttackByInput(chars + 1, nums);
                        if(m_p2->getMap()->getType(chars + 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars + 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars + 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars - 1, nums);
                        if(m_p2->getMap()->getType(chars - 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars - 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars - 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars, nums + 1);
                        if(m_p2->getMap()->getType(chars, nums + 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums + 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums + 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                    }
                    else if(chars > 0 && chars < 7 && nums == 7)
                    {
                        AttackByInput(chars + 1, nums);
                        if(m_p2->getMap()->getType(chars + 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars + 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars + 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars - 1, nums);
                        if(m_p2->getMap()->getType(chars - 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars - 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars - 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars, nums - 1);
                        if(m_p2->getMap()->getType(chars, nums - 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums - 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums - 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                    }
                    else if(chars == 0 && nums > 0 && nums < 7)
                    {
                        AttackByInput(chars + 1, nums);
                        if(m_p2->getMap()->getType(chars + 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars + 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars + 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars, nums + 1);
                        if(m_p2->getMap()->getType(chars, nums + 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums + 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums + 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars, nums - 1);
                        if(m_p2->getMap()->getType(chars, nums - 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums - 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums - 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                    }
                    else if(chars == 7 && nums > 0 && nums < 7)
                    {
                        AttackByInput(chars - 1, nums);
                        if(m_p2->getMap()->getType(chars - 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars - 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars - 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                        AttackByInput(chars, nums + 1);
                        if(m_p2->getMap()->getType(chars, nums + 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums + 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums + 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                        AttackByInput(chars, nums - 1);
                        if(m_p2->getMap()->getType(chars, nums - 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums - 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums - 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                    }
                    else if(chars == 0 && nums == 0)
                    {
                        AttackByInput(chars + 1, nums);
                        if(m_p2->getMap()->getType(chars + 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars + 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars + 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars, nums + 1);
                        if(m_p2->getMap()->getType(chars, nums + 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums + 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums + 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                    }
                    else if(chars == 0 && nums == 7)
                    {
                        AttackByInput(chars + 1, nums);
                        if(m_p2->getMap()->getType(chars + 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars + 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars + 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars + 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars, nums - 1);
                        if(m_p2->getMap()->getType(chars, nums - 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums - 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums - 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                    }
                    else if(chars == 7 && nums == 0)
                    {
                        AttackByInput(chars - 1, nums);
                        if(m_p2->getMap()->getType(chars - 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars - 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars - 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}

                        AttackByInput(chars, nums + 1);
                        if(m_p2->getMap()->getType(chars, nums + 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums + 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums + 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums + 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                    }
                    else if(chars == 7 && nums == 7)
                    {
                        AttackByInput(chars - 1, nums);
                        if(m_p2->getMap()->getType(chars - 1, nums) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars - 1, nums) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars - 1, nums) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars - 1, nums, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                        AttackByInput(chars, nums - 1);
                        if(m_p2->getMap()->getType(chars, nums - 1) != DATA_ERROR)
                        {
                            if(m_p2->getMap()->getType(chars, nums - 1) == CARRIER) {--carrierhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == BATTLESHIP) {--battleshiphp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == CRUISER) {--cruiserhp;}
                            else if(m_p2->getMap()->getType(chars, nums - 1) == DESTROYER) {--destroyerhp;}
                            m_p2->getMap()->setType(chars, nums - 1, DATA_ERROR);
                        }
                        m_App->getMap()->Draw();
                        mvprintw(8,39,"%d", getTurn());
                        if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
                    }
                    isHIT = false;
                }


            m_App->getMap()->Draw();
            mvprintw(8,39,"%d", getTurn());
            usleep(110000);

            wrefresh(m_App->getInputPane()->getWindow());
            if(!carrierhp && !battleshiphp && !cruiserhp && !destroyerhp) {break;}
        }
    }
    else{}

}

void GameManager::Render() {m_App->Render();}

void GameManager::Destroy() {m_App->Destroy();}
