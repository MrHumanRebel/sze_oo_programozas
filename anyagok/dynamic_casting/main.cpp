#include <iostream>
#include <string>
using namespace std;

class Entity
{
public:
    virtual void PrintName() {}
};

class Player : public Entity
{
public:
};
class Enemy : public Entity
{
public:
};

int main()
{
    Player *p0 = new Player();
    Entity *e0 = new Player();

    cout << p0 << endl;
    cout << e0 << endl;

    //######################//

    Player *p1 = (Player *)e0;
    cout << p1 << endl;

    //######################//

    Player *p2 = static_cast<Player *>(e0);
    cout << p2 << endl;

    //######################//

    Player *p3 = dynamic_cast<Player *>(e0);
    cout << p3 << endl;

    //######################//

    Player *player = new Player();
    Entity *actuallyEnemy = new Enemy();
    Entity *actuallyPlayer = player;

    Player *p4 = dynamic_cast<Player *>(actuallyEnemy);
    cout << p4 << endl;
    Player *p5 = dynamic_cast<Player *>(actuallyPlayer);
    cout << p5 << endl;

    return 0;
}