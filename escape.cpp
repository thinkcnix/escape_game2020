#include <iostream>
#include <string>
#include <windows.h>
#include <random>

#define ONE_SECOND 1000

using namespace std;

//�Լ�
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

//Ŭ����
class player
{
public:
    int health = 10, mental = 7;
    string name = "";

    void currentStatus(int *playerhealth, int *playermental)
    {
        cout << "���� ü��: " << *playerhealth << " ���� ���ŷ�: " << *playermental << endl;
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
        cout << " ü�� ������ ȹ��" << endl;
        Sleep(ONE_SECOND);
        cout << " ++ü�� 3 ȹ��" << endl;
        Sleep(ONE_SECOND);
        cout << " ++���� ü��: " << *gethealth << endl;
    }

    void mentalItem(int *getmental)
    {
        *getmental += 2;
        cout << " ���ŷ� ������ ȹ��" << endl;
        Sleep(ONE_SECOND);
        cout << " ++���ŷ� 2 ȹ��" << endl;
        Sleep(ONE_SECOND);
        cout << " ++���� ���ŷ�: " << *getmental << endl;
    }

    void goldItem()
    {
        cout << endl << "���� Ȳ�� ������ ã�Ҿ�...!" << endl;
    }
};

class godTotem
{
public:
    item golditem;

    void getGoldItem(string playername)
    {
        golditem.goldItem();
        cout << endl << "���� �� " << playername << "��(��) �̷ο��� �������Ա�...!" << endl;
        Sleep(ONE_SECOND);
        cout << "���� �����̾���...!" << endl;
        Sleep(ONE_SECOND);
        cout << endl;
        Sleep(ONE_SECOND);
        cout << "��" << endl;
        exit(0);
    }
};

class infoMessage
{
public:

    void exitWay(string playername)
    {
        cout << endl << "Ż�ⱸ�� �߰��߾�...!" << endl;
        Sleep(ONE_SECOND);
        cout << "���� �� " << playername << "��(��) �̷ο��� �������Ա�...!" << endl;
        Sleep(ONE_SECOND);
        cout << endl;
        Sleep(ONE_SECOND);
        cout << "��" << endl;
        exit(0);
    }

    void failGame()
    {
        cout << endl << "������...!!!" << endl;
        Sleep(ONE_SECOND);
        cout << "�̷�... �̷ΰ� �������� �־�...!" << endl;
        Sleep(ONE_SECOND);
        cout << "���� ������ ���������..." << endl;
        Sleep(ONE_SECOND);
        cout << endl;
        Sleep(ONE_SECOND);
        cout << "��" << endl;
        exit(0);
    }

    void diePlayer()
    {
        cout << endl << "����...!" << endl;
        Sleep(ONE_SECOND);
        cout << "�÷��̾ ����߽��ϴ�." << endl;
        Sleep(ONE_SECOND);
        cout << endl;
        Sleep(ONE_SECOND);
        cout << "��" << endl;
        exit(0);
    }
};

class gameMenu
{
public:
    void gameExit()
    {
        int select;

        cout << "������ �����Ͻðڽ��ϱ�? (yes : 1)" << endl;
        cin >> select;
        if (select == 1)
        {
            Sleep(ONE_SECOND);
            cout << "������ �����մϴ�." << endl;
            exit(0);
        }
        else
        {
            Sleep(ONE_SECOND);
            cout << "1�� �Է����� �ʾҳ׿�." << endl;
            Sleep(ONE_SECOND);
            cout << "�׷��� �����մϴ�." << endl;
            Sleep(ONE_SECOND);
            cout << endl << "��" << endl;
            exit(0);
        }
    }
};

//����
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

    //1:Ȳ�ݹ߰�Ȯ�� 2:Ż�ⱸ�߰�Ȯ�� 3:������ȹ��Ȯ��
    int randGold = NULL, randExit = NULL, randItem = NULL;
    

    cout << "Ȳ���� ã�� ���� �̷ο� ���� ��... ���� �̸���...?" << endl;
    cin >> player1.name;
    cout << "���� ���� �Ҿ���..." << endl;
    Sleep(ONE_SECOND);
    cout << "���� �ð��� ������ �� �̷δ� ��������...!" << endl;
    Sleep(ONE_SECOND);
    cout << "Ȳ���� ã�ų� �ⱸ�� ã�ƾ� �� �� �־�...!" << endl;
    Sleep(ONE_SECOND);
    cout << "� ����...!" << endl;
    player1.currentStatus(pPlayerHealth, pPlayerMental);

    while (1)
    {
        cout << endl << "-���������� ���� �������� ����? (������: 1, ����: 0)" << endl;
        cin >> inputRL;

        //������
        if (inputRL == 1)
        {
            Sleep(ONE_SECOND);
            randGold = getRandomNumber3p();
            randExit = getRandomNumber5p();
            randItem = getRandomNumber33p();

            playManage(pPlayturn, limitturn, pPlayerHealth, pPlayerMental);

            cout << endl << "������ ��� ���� ��..." << endl;
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
                cout << endl << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�." << endl;
            }
            
        }
        //����
        else if (inputRL == 0)
        {
            Sleep(ONE_SECOND);
            randGold = getRandomNumber3p();
            randExit = getRandomNumber5p();
            randItem = getRandomNumber33p();

            playManage(pPlayturn, limitturn, pPlayerHealth, pPlayerMental);

            cout << endl << "���� ��� ���� ��..." << endl;
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
                cout << endl << "�ƹ� �ϵ� �Ͼ�� �ʾҴ�." << endl;
            }
        }
        //�޴�
        else if (inputRL == 4)
        {
            gamemenu.gameExit();
        }
        //1, 0, 4�̿��� ��ǲ
        else
        {
            Sleep(ONE_SECOND);
            cout << "\"incorrect input\"" << endl;
            Sleep(ONE_SECOND);
        }
    }
}

//�Լ� ����
void playManage(int* pplayturn, int limitturn, int* health, int* mental)
{
    infoMessage info;
    player player;

    *pplayturn += 1;
    *health -= 1;
    *mental -= 1;

    cout << "������: " << *pplayturn << endl;
    cout << "���� ü��: " << *health << " ���� ���ŷ�: " << *mental << endl;

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