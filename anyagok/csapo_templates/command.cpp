#include <iostream>
using namespace std;

class Command
{
public:
    virtual void execute() = 0;
};

class LightUpCommandFake : public Command
{
public:
    void execute() { cout << "Lampa felkapcsol" << endl; }
};

class LightDownCommandFake : public Command
{
public:
    void execute() { cout << "Lampa lekapcsol" << endl; }
};

class LightUpCommandReal : public Command
{
public:
    void execute() { cout << "Lampa felkapcsol, nemcsak kiir" << endl; }
};

class LightDownCommandReal : public Command
{
public:
    void execute()
    {
        cout << "Lampa lekapcsol, nemcsak kiir" << endl;
    }
};

class LightSwitch
{
    Command &upC;
    Command &downC;

public:
    LightSwitch(Command &up, Command &down) : upC(up), downC(down) {}
    void turnUp() { upC.execute(); }
    void turnDown() { downC.execute(); }
};

int main()
{
    LightUpCommandFake lucf;
    LightDownCommandFake ldcf;
    LightUpCommandReal lucr;
    LightDownCommandReal ldcr;
    LightSwitch fs(lucf, ldcf);
    LightSwitch rs(lucr, ldcr);
    fs.turnUp();
    fs.turnDown();
    rs.turnUp();
    rs.turnDown();
}