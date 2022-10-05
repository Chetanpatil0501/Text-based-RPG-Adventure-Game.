

//Run this code in visual studio.....


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <chrono>
#include <fstream>
#include <thread>
#include <iostream>

using namespace std;

int Random_number(int upper, int lower)
{
    srand(time(NULL));

    int number = (rand() % (upper - lower + 1)) + lower;
    return number;
}

class player
{
    int  damage, heal;
    string User_name;
    bool continue_game;

public:
    int health;
    int curHealth;
    player(string user, int h, int d, int h_eal)
    {
        setPlayerName(user);
        setHealth(h);
        SetDamage(d);
        setHeal(h_eal);

    }
    void setPlayerName(string name)
    {
        User_name = name;
    }
    string getUserName()
    {
        return User_name;
    }
    void setHealth(int h)
    {
        health = h;
    }

    int GetHealth()
    {
        return health;
    }

    void SetDamage(int D)
    {
        damage = D;
    }

    int GetDamage()
    {
        return damage;
    }

    void setHeal(int h_eal)
    {
        heal = h_eal;
    }

    int GetHeal()
    {
        return heal;
    }
    void Hero_Damage(int D)
    {
        damage = health - D;
        health = damage;
        cout << "\nPlayer damaged by : " << D << endl;
        cout << "\nplayer health is : " << health << endl;
        Player_is_alive();
        curHealth = health;

    }
    void healing(int h, int curhealth)
    {
        if (health < curhealth)
        {
            health += heal;
            cout << "Player heal with : " << h << " Points" << endl;
            cout << "Player health after healing : " << health << endl;
        }
        else {
            cout << "You can't heal because your health is full." << endl;
        }
    }
    bool Player_is_alive()
    {
        if (health <= 0)
        {
            cout << "\nPlayer died... you loose your city...\n" << endl;
            return false;
        }
        else { return true; }
    }

};

class enemy
{
    int  melee_damage, Ranged_damage;
    string Enemy_name;

public:
    int health;

    enemy(string name, int h)
    {
        GetHealth(h);
        GetEnemyName(name);

    }
    void GetHealth(int h)
    {
        health = h;
    }
    int setHealth()
    {
        return health;
    }
    void GetEnemyName(string name)
    {
        Enemy_name = name;
    }
    string EnemyName()
    {
        return Enemy_name;
    }

    void meleedamage(int m_D)
    {
        melee_damage = health - m_D;
        health = melee_damage;

        cout << "\nEnemy damaged by melee attack : " << m_D << endl;

    }
    void Random_Ranaged_damage(int max, int low)
    {
        Ranged_damage = Random_number(max, low);

        int RangeDamage = health - Ranged_damage;
        health = RangeDamage;

        cout << "\nEnemy damaged by ranged attack : " << Ranged_damage << endl;
    }
    void total_Damage(int meleeDamage, int max, int min)
    {
        meleedamage(meleeDamage);
        Random_Ranaged_damage(max, min);

        cout << "\nEnemy Health is : " << health << endl;
        Enemy_is_alive();
    }

    bool Enemy_is_alive()
    {
        if (health <= 0)
        {
            cout << "\nPlayer won the battle..." << endl;
            return false;
        }
        else { return true; }
    }
};

void sleep(std::chrono::duration<int> time)
{
    std::this_thread::sleep_for(time);
}
void BattleStats(int enemies_count, string user, int h, int d, int h_eal, string Enemyname, int E_health)
{
    bool BattleContinue = true;
    player* p;
    enemy* e;
    p = new player(user, h, d, h_eal);
    e = new enemy(Enemyname, E_health);

    int enemies;
    enemies = enemies_count;

    do
    {

        char input;
        cout << "\n\nEnter 'A' to attack and 'H' To heal\n";
        cin >> input;

        switch (input)
        {
        case 'A':
            e->total_Damage(20, 30, 10);
            break;

        case 'a':
            e->total_Damage(20, 30, 10);
            break;

        case 'h':
            p->healing(20, h);
            break;

        case 'H':
            p->healing(20, h);
            break;
        }
        int Enemy_random_attack = Random_number(2, 1);

        if (Enemy_random_attack == 2)
        {
            p->Hero_Damage(10);
        }

        if (e->health <= 0)
        {
            system("cls");
            cout << "You killed " << e->EnemyName() << " Successfully\n\n" << endl; sleep(1s);
            BattleContinue = false;
            system("pause");

        }
        if (p->health <= 0)
        {
            system("cls");
            p->Player_is_alive();
            BattleContinue = false;
            system("pause");

        }

    }

    while (BattleContinue);


    delete p, e;

}

void level6(player* p, enemy* e)
{
    system("cls");
    int health;
    char input;
    cout << "\n\n...................................Chapter 6  : Boss Vecna......................................\n\n";
    cout << "\n" << p->getUserName() << " Congratulation !you completed all the four level successfully but in this level vecna will be reveal.\n"; sleep(2s);
    cout << "\n You need to fight with vecna and save the hawkins city and your friends.\n"; sleep(1s);
    cout << "\nWe got a message from your friends that the vecna is in the upper bedroom.\n"; sleep(1s);
    cout << "\nVecna is now in mindslayer state he is using his power to open the door of the real world\n"; sleep(2s);
    cout << "\n\nLet's go to upper bedroom.\n\n"; sleep(2s);

    cout << "\nEnter 'E' to open the door of bedroom.\n"; sleep(2s);
    cin >> input;

    if (input == 'E' || input == 'e')
    {
        cout << "\nDoor opened\n";
    }
    else
    {
        cout << "\nPlease enter right input.\n\n";

    }

    cout << "\n\n Use fire arrow to burn his branches which is controling the whole upside-down world\n\n"; sleep(1s);

    cout << "\nEnter '2' to use arrow\n";
    cin >> input;
    if (input == '2')
    {
        cout << "\nArrow taken\n";
    }
    else
    {
        cout << "\nPlease enter right input.\n\n";
    }
    cout << "\nEnter 'A' To attack\n";
    cin >> input;
    if (input == 'A' || input == 'a')
    {
        cout << "\nWell-done you burn all his branches\n";
    }
    else
    {
        cout << "\nPlease enter right input.\n\n";
    }
    cout << "\nUntill he was in his mind but now he is in reality. Now vecna can hear you and attack you.\n"; sleep(2s);
    cout << "\nNow it's a time to kill the vecna and save hawkins\n"; sleep(1s);
    cout << "\nStart the battle....\n";
    system("pause");
    cout << "\n\nTip : Use sword it will help you to fight with vecna\n\n"; sleep(1s);
    BattleStats(1, p->getUserName(), health = 300, 30, 25, "Vecna", 150);
    cout << "\n\n\nWait....\n\n\n"; sleep(3s);
    cout << "\nVecna is alive and now he is using his mind slayer power to control your mind\n\nBe aware\n"; sleep(2s);

    cout << "\nThis battle will be different from the past fights. you need to use your mind powers to fight with vechna\n"; sleep(2s);
    BattleStats(1, p->getUserName(), health, 30, 25, "Vecna", 100);
    cout << "\nYou successfully killed the bose monster Vecna\n"; sleep(1s);
    cout << "\nYou saved hawkins city. now the city is out of fear of vecna....\n"; sleep(1s);
    system("pause");
    delete(p, e);
}
void level5(player* p, enemy* e)
{
    system("cls");
    int health = 300;
    char attack;
    cout << "\n\n...................................Chapter 5  : Vecna's House ......................................\n\n";
    cout << "\n" << p->getUserName() << " Now you are able to kill the vecna you are insane because you faught to many enemiesand still you are alive.\n"; sleep(2s);
    cout << "\nNow it's time to enter in Vecna's house you nee to use you all inventory items to kill the gaurds they are on the door of the house.\n"; sleep(3s);
    cout << "\n\nLet's do it......\n\n"; sleep(1s);
    cout << "\nFirst kill the two of them who are busy in talk to each other.\n"; sleep(1s);
    cout << "\n\nThere is a tree over them cut the tree with the sword.\n\n"; sleep(2s);
    cout << "\nEnter 'A' to cut the tree.\n"; sleep(2s);
    cin >> attack;
    if (attack == 'A' || attack == 'a')
    {
        cout << "\nA tree was cuted and the monsters are killed by a tree fall on them.\n";
    }
    else
    {
        cout << "\nYou failed to cut a tree and they noticed you and killed you.\n\n";

        cout << "\nRestart the checkpoint\n";
        system("pause");
        system("cls");
        return level5(p, e);

    }
    cout << "\nNow three enemies are remain and they are in the house\n"; sleep(2s);
    cout << "\nEnter 'E' to open the door.\n"; sleep(2s);
    cin >> attack;

    if (attack == 'E' || attack == 'e')
    {
        cout << "\nDoor opened\n";
    }
    else
    {
        cout << "\nPlease enter right input.\n\n";

    }
    cout << "\nNow you are entered in the monster house there are three monsters killed them with the power of sword.\n"; sleep(2s);
    cout << "\n\nStart the Fight\n\n";
    system("pause");
    system("cls");
    BattleStats(1, p->getUserName(), health, 30, 25, "Shadow monster-1", 80);

    BattleStats(1, p->getUserName(), health, 30, 25, "Shadow monster-2", 80);

    BattleStats(1, p->getUserName(), health, 30, 25, "Shadow monster-3", 80);
    system("cls");
    cout << "\nWelldone " << p->getUserName() << " You successfully killed all the Shadow monsters\n"; sleep(2s);
    cout << "\n\nCongratulations.... Inventory added Arrow and Bow ....\n\n"; sleep(1s);
    cout << "\nBonus Inventory added 'Fire arrow', You can use fire bow to burn to vecna's body\n"; sleep(2s);
    system("pause");
    level6(p, e);
    delete p, e;
}
void level4(player* p, enemy* e)
{
    int health = 300;
    system("cls");
    cout << "\n\n...................................Chapter 4  : Armour ......................................\n\n";
    cout << "\n" << p->getUserName() << " You are serching for the powerfull armour.\n"; sleep(1s);
    cout << "\nWhich will help you to increase you strength in fight with vecna.\n"; sleep(3s);
    cout << "\nThere is a cave which is full of darkness. And in the darkness you see the sparckle of metal.\n"; sleep(1s);
    cout << "\nThere is a armour and there are also the protectors of the armour.\n"; sleep(1s);
    cout << "\nYou need to kill the 4 kratos monster to get the armour.\n"; sleep(2s);
    cout << "\nLet's enter in the cave....\n"; sleep(2s);
    cout << "\nOne of the monster noticed your foot step sound and they all are now seeking.\n"; sleep(2s);
    cout << "\nLet attack from behind and kill one of them\n"; sleep(2s);

    cout << "\nAttack ASAP....\n"; sleep(1s);
    system("pause");
    system("cls");
    BattleStats(1, p->getUserName(), health, 30, 25, "Kratos-1", 80);
    cout << "\nYou killed him very claverly... Good job...\n"; sleep(1s);
    cout << "\nNow there are three more...kill them like him...\n"; sleep(1s);
    BattleStats(1, p->getUserName(), health, 30, 25, "Kratos-2", 80);
    BattleStats(1, p->getUserName(), health, 30, 25, "Kratos-3", 80);
    BattleStats(1, p->getUserName(), health, 30, 25, "Kratos-4", 80);

    cout << "\nWelldone " << p->getUserName() << " You successfully killed all the four monsters...\n"; sleep(1s);
    cout << "\nand " << p->getUserName() << " you got the epic armour it will increas you health power by 50 points.\n"; sleep(2s);
    cout << "\nNow your health is 300 hp.\n"; sleep(1s);
    cout << "\n\nCongratulations.... Inventory added Armour....\n";
    system("pause");

    level5(p, e);
    delete p, e;
}
void level3(player* p, enemy* e)
{
    system("cls");
    int health = 250;
    cout << "\n\n...................................Chapter 3 : The UpSide-Down......................................\n\n";
    cout << "\nNow you are falling down to the monster world...\n"; sleep(1s);
    cout << "\nyou falling downand starts screaming you look around there is nothing but darknessand lightning in the sky.\n"; sleep(3s);
    cout << "\nyou speedly falls on the ground.\n"; sleep(1s);
    cout << "\nyou get up starts walking around.\n"; sleep(1s);
    cout << "\nFurther you see that there are three big monsters tring to protect some kind of shield.\n"; sleep(2s);
    cout << "\nbut the monster are different from the monster you encounter earlier.\n"; sleep(1s);
    cout << "\nyou start walking towards them and the monsters see you they starts to run toward you to attack you.\n"; sleep(3s);
    system("pause");
    system("cls");
    cout << "\nNow you have sword and you can use it in this fight to kill the mosters\n"; sleep(1s);
    cout << "\nYou HP is also increased by 50 points..... and now your health is 250hp\n"; sleep(1s);
    cout << "\n\nintense fight will start between you and monsters.\n\n" << endl; sleep(1s);
    system("pause");
    BattleStats(1, p->getUserName(), health, 30, 25, "Giant Demogorgan-1", 70);
    BattleStats(1, p->getUserName(), health, 30, 25, "Giant Demogorgan-2", 70);
    BattleStats(1, p->getUserName(), health, 30, 25, "Giant Demogorgan-3", 70);
    system("cls");
    cout << "\nWelldone " << p->getUserName() << " You successfully killed all the three monsters...\n"; sleep(1s);
    cout << "\nand " << p->getUserName() << " you got the epic shield which is made with super-powers.\n"; sleep(1s);
    cout << "\nIt will help you to absorb the power of the vecna which is insane powerfull attack of vecna\n"; sleep(1s);
    cout << "\n\nCongratulations.... Inventory added shield....\n";
    system("pause");

    level4(p, e);
    delete p, e;
}


void level2(player* p, enemy* e)
{
    system("cls");
    int health = 200;
    cout << "\n\n...................................Chapter 2 : The Door......................................\n\n";
    cout << "\nOhhhh.......what the fuck it is ?\n"; sleep(1s);
    cout << "\nThe door is very huge and you have insufficient power to close it.\n"; sleep(1s);
    cout << "\nAnd there are two big demogorgans who are kiled the cops because cops tryed to close the door but they can't.\n"; sleep(1s);
    cout << "\nNow you need Sword to kill them and you can get the sword by hypnotice them.\n"; sleep(1s);


    char input;
    cout << "\n\nEnter H to use your hypnotice power........\n";
    cin >> input;

    if (input == 'h' || input == 'H')
    {
        cout << "\nyou successfully hypnotice them and you got the sword now you can kill them with the powerfull sword.\n";
    }
    else
    {
        cout << "\nYou failed to hypnotice them and they saw you and killed you...\n\n"; \

            cout << "\nRestart the checkpoint\n";
        system("pause");
        system("cls");
        return level2(p, e);

    }
    cout << "\n\n There are two big demogorgans and you can kill them with powerfull sword.\n\n"; sleep(1s);
    cout << "\n\n ............................Battle begins...............................\n\n"; sleep(1s);
    BattleStats(1, p->getUserName(), health, 20, 15, "Denogorgan-1", 70);
    BattleStats(1, p->getUserName(), health, 20, 15, "Denogorgan-2", 70);
    system("cls");
    cout << "\nyou killed them and one of the monsters head was cuted from his body with the sword's power.\n"; sleep(1s);
    cout << "\nNow you starts the process to close the door from the another world.....\n\n"; sleep(1s);
    cout << p->getUserName() << ": This energy is more powerfull than mine still then I'm trying to close....."; sleep(1s);
    cout << "ohhhhh.....no...... it's vaccum energy is trying to take me in the upside - down world........"; sleep(1s);
    cout << "\nI'm getting weak....\n"; sleep(1s);
    cout << "\nYou are feeling Unconscious and you entered in The monster world....\n";

    cout << "\n\nCongratulations.... Inventory added sword. It will help you to fight with vecna\n";
    system("pause");

    level3(p, e);
    delete p, e;
}

void level1(player* p, enemy* e)
{
    system("cls");
    e = new enemy("Demogorgan", 50);

    sleep(1s);
    cout << "\n\n...................................Chapter 1 : The Map......................................\n\n";
    cout << "\nyou run away from the hawkins lab and now you are entering in the city centre.\n"; sleep(1s);
    cout << "\nAnd " << p->getUserName() << " you need to find the city map to find where is the vecna.\n"; sleep(1s);
    cout << "\nBut first you need to kill the Demogorgan who is a protector of the map.\n"; sleep(1s);
    cout << "\nA demogorgan is walking towards you and he will attack you.\n"; sleep(1s);
    cout << "\nYou should fight to him and kill him.\n\n"; sleep(1s);

    cout << "Fight Begins.............................................." << endl; sleep(1s);

    BattleStats(1, p->getUserName(), 200, 20, 15, "Denogorgan", 50);

    system("cls");
    cout << "you killed demogorgans successfully by using your super powerfull attacks.\n\n"; sleep(1s);
    cout << "But you opened the door of up-side down world and you should close it ASAP...\n\n"; sleep(1s);
    cout << "if you failed to close then hawkins city will in huge risk from the monster \n"; sleep(1s);
    cout << "because monster can entered in the city by using this door.\n\n";  sleep(1s);

    cout << "\n\nCongratulations.... Inventory added map....which will help you out to find vecna\n";
    system("pause");
    system("cls");
    level2(p, e);
    delete p, e;
}
void intro()
{
    cout << "Wel-Come To Hawkins City\n\n" << endl; sleep(1s);

    string userName;
    cout << "Enter your name..." << endl;
    cin >> userName;

    player* p;
    enemy* e;
    e = new enemy("Demogorgan", 50);
    p = new player(userName, 200, 20, 15);
    cout << "\nHello " << userName << endl; sleep(1s);
    cout << "\nyou're the hero of this game..."; sleep(1s);
    cout << "\nyour hawkins city is captured by the monster vecna and"; sleep(1s);
    cout << "\nyou should save the hawkins city by killing vecna with your super powers."; sleep(1s);
    cout << "\nbest of luck for your further journey.." << endl; sleep(1s);
    system("pause");
    system("cls");
    level1(p, e);
    level2(p, e);
    level3(p, e);
    level4(p, e);
    level5(p, e);
    level6(p, e);
}




int main()
{
    intro();
}

