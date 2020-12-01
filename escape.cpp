#include <iostream>
#include <string>
#include <windows.h>
#include <random>

#define ONE_SECOND 1000

using namespace std;

//함수
int getRandomNumber50p()
{
    random_device rn;
    mt19937_64 rnd(rn());
    uniform_int_distribution<int> range(0, 1);
    return range(rnd);
}

int getRandomNumber33p()
{
    random_device rn;
    mt19937_64 rnd(rn());
    uniform_int_distribution<int> range(0, 2);
    return range(rnd);
}

int getRandomNumber3p()
{
    random_device rn;
    mt19937_64 rnd(rn());
    uniform_int_distribution<int> range(0, 29);
    return range(rnd);
}

int getRandomNumber5p()
{
    random_device rn;
    mt19937_64 rnd(rn());
    uniform_int_distribution<int> range(0, 19);
    return range(rnd);
}

void playManage(int *pplayturn, int limitturn, int* health, int* mental);
void itemProb(int *playerhealth, int* playermental);

//클래스
class player
{
public:
    int health = 10, mental = 7;
    string name = "";

    void currentStatus(int *playerhealth, int *playermental)
    {
        cout << "현재 체력: " << *playerhealth << " 현재 정신력: " << *playermental << endl;
    }

    void damageHealth()
    {
        health -= 1;
    }

    void damageMental()
    {
        mental -= 1;
    }

};

class item
{
public:
    void healthItem(int *gethealth)
    {
        *gethealth += 3;
        cout << " 체력 아이템 획득" << endl;
        Sleep(ONE_SECOND);
        cout << " ++체력 3 획득" << endl;
        Sleep(ONE_SECOND);
        cout << " ++현재 체력: " << *gethealth << endl;
    }

    void mentalItem(int *getmental)
    {
        *getmental += 2;
        cout << " 정신력 아이템 획득" << endl;
        Sleep(ONE_SECOND);
        cout << " ++정신력 2 획득" << endl;
        Sleep(ONE_SECOND);
        cout << " ++현재 정신력: " << *getmental << endl;
    }

    void goldItem()
    {
        cout << endl << "드디어 황금 보물을 찾았어...!" << endl;
    }
};

class godTotem
{
public:
    item golditem;

    void getGoldItem(string playername)
    {
        golditem.goldItem();
        cout << endl << "드디어 나 " << playername << "이(가) 미로에서 빠져나왔군...!" << endl;
        Sleep(ONE_SECOND);
        cout << "힘든 모험이었어...!" << endl;
        Sleep(ONE_SECOND);
        cout << endl;
        Sleep(ONE_SECOND);
        cout << "끝" << endl;
        exit(0);
    }
};

class infoMessage
{
public:

    void exitWay(string playername)
    {
        cout << endl << "탈출구를 발견했어...!" << endl;
        Sleep(ONE_SECOND);
        cout << "드디어 나 " << playername << "이(가) 미로에서 빠져나왔군...!" << endl;
        Sleep(ONE_SECOND);
        cout << endl;
        Sleep(ONE_SECOND);
        cout << "끝" << endl;
        exit(0);
    }

    void failGame()
    {
        cout << endl << "쿠구구궁...!!!" << endl;
        Sleep(ONE_SECOND);
        cout << "이런... 미로가 무너지고 있어...!" << endl;
        Sleep(ONE_SECOND);
        cout << "나의 모험은 여기까지군..." << endl;
        Sleep(ONE_SECOND);
        cout << endl;
        Sleep(ONE_SECOND);
        cout << "끝" << endl;
        exit(0);
    }

    void diePlayer()
    {
        cout << endl << "으윽...!" << endl;
        Sleep(ONE_SECOND);
        cout << "플레이어가 사망했습니다." << endl;
        Sleep(ONE_SECOND);
        cout << endl;
        Sleep(ONE_SECOND);
        cout << "끝" << endl;
        exit(0);
    }
};

class gameMenu
{
public:
    void gameExit()
    {
        int select;

        cout << "게임을 종료하시겠습니까? (yes : 1)" << endl;
        cin >> select;
        if (select == 1)
        {
            Sleep(ONE_SECOND);
            cout << "게임을 종료합니다." << endl;
            exit(0);
        }
        else
        {
            Sleep(ONE_SECOND);
            cout << "1을 입력하지 않았네요." << endl;
            Sleep(ONE_SECOND);
            cout << "그래도 종료합니다." << endl;
            Sleep(ONE_SECOND);
            cout << endl << "끝" << endl;
            exit(0);
        }
    }
};

//메인
int main()
{
    player player1;
    item getitem;
    infoMessage info;
    godTotem godtotem;
    gameMenu gamemenu;

    int inputRL = NULL;
    int playturn = 0, limitturn = 15;

    int* pPlayturn = &playturn;
    int* pPlayerHealth = &player1.health;
    int* pPlayerMental = &player1.mental;

    //1:황금발견확률 2:탈출구발견확률 3:아이템획득확률
    int randGold = NULL, randExit = NULL, randItem = NULL;
    

    cout << "황금을 찾기 위해 미로에 들어온 나... 나의 이름은...?" << endl;
    cin >> player1.name;
    cout << "나는 길을 잃었다..." << endl;
    Sleep(ONE_SECOND);
    cout << "일정 시간이 지나면 이 미로는 무너진다...!" << endl;
    Sleep(ONE_SECOND);
    cout << "황금을 찾거나 출구를 찾아야 살 수 있어...!" << endl;
    Sleep(ONE_SECOND);
    cout << "어서 가자...!" << endl;
    player1.currentStatus(pPlayerHealth, pPlayerMental);

    while (1)
    {
        cout << endl << "-오른쪽으로 갈까 왼쪽으로 갈까? (오른쪽: 1, 왼쪽: 0)" << endl;
        cin >> inputRL;

        //오른쪽
        if (inputRL == 1)
        {
            Sleep(ONE_SECOND);
            randGold = getRandomNumber3p();
            randExit = getRandomNumber5p();
            randItem = getRandomNumber33p();

            playManage(pPlayturn, limitturn, pPlayerHealth, pPlayerMental);

            cout << endl << "오른쪽 길로 가는 중..." << endl;
            Sleep(ONE_SECOND);

            if (randGold == 0)
            {
                godtotem.getGoldItem(player1.name);
            }
            if (randExit == 0)
            {
                info.exitWay(player1.name);
            }
            if (randItem == 0)
            {
                itemProb(pPlayerHealth, pPlayerMental);
            }
            else
            {
                Sleep(ONE_SECOND);
                cout << endl << "아무 일도 일어나지 않았다." << endl;
            }
            
        }
        //왼쪽
        else if (inputRL == 0)
        {
            Sleep(ONE_SECOND);
            randGold = getRandomNumber3p();
            randExit = getRandomNumber5p();
            randItem = getRandomNumber33p();

            playManage(pPlayturn, limitturn, pPlayerHealth, pPlayerMental);

            cout << endl << "왼쪽 길로 가는 중..." << endl;
            Sleep(ONE_SECOND);

            if (randGold == 0)
            {
                godtotem.getGoldItem(player1.name);
            }
            if (randExit == 0)
            {
                info.exitWay(player1.name);
            }
            if (randItem == 0)
            {
                itemProb(pPlayerHealth, pPlayerMental);
            }
            else
            {
                Sleep(ONE_SECOND);
                cout << endl << "아무 일도 일어나지 않았다." << endl;
            }
        }
        //메뉴
        else if (inputRL == 4)
        {
            gamemenu.gameExit();
        }
        //1, 0, 4이외의 인풋
        else
        {
            Sleep(ONE_SECOND);
            cout << "\"incorrect input\"" << endl;
            Sleep(ONE_SECOND);
        }
    }
}

//함수 정의
void playManage(int* pplayturn, int limitturn, int* health, int* mental)
{
    infoMessage info;
    player player;

    *pplayturn += 1;
    *health -= 1;
    *mental -= 1;

    cout << "현재턴: " << *pplayturn << endl;
    cout << "현재 체력: " << *health << " 현재 정신력: " << *mental << endl;

    if (*mental <= 0)
    {
        *health -= 1;
    }

    if (*health <= 0)
    {
        info.diePlayer();
    }

    if (*pplayturn >= limitturn)
    {
        info.failGame();
    }
}

void itemProb(int* playerhealth, int* playermental)
{
    item getitem;
    int randNum = getRandomNumber50p();

    int *ht = playerhealth;
    int *mt = playermental;

    if (randNum == 0)
    {
        getitem.healthItem(ht);
    }
    else if (randNum == 1)
    {
        getitem.mentalItem(mt);
    }
}