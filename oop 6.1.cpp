#include <iostream>
#include <string>

using namespace std;

class Base
{
protected:
    int x;
    int y;

public:
    Base(int x, int y) : x(x), y(y) {}

    virtual void paint() const
    {
        cout << "Coordinates: (" << x << ", " << y << ")";
    }
};

class Stone : public Base
{
private:
    int imageId;

public:
    Stone(int x, int y, int imageId) : Base(x, y), imageId(imageId) {}

    void paint() const override
    {
        Base::paint();
        cout << ", Image ID: " << imageId << endl;
    }
};

class Chest : public Base
{
private:
    unsigned int width;
    unsigned int height;
    int coin;

public:
    Chest(int x, int y, unsigned int width, unsigned int height, int coin):
        Base(x, y), width(width), height(height), coin(coin) {}

    void paint() const override
    {
        Base::paint();
        cout << ", Width: " << width << ", Height: " << height << ",  Coins: " << coin << endl;
    }
};

class Trader : public Base
{
private:
    int itemType;
    int itemCount;

public:
    Trader(int x, int y, int itemType, int itemCount) : Base(x, y), itemType(itemType), itemCount(itemCount) {}

    void paint() const override
    {
        Base::paint();
        cout << ", Item Type: " << itemType << ", Item Count: " << itemCount << endl;
    }
};

class Player : public Base
{
private:
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    string name;

public:
    Player(int x, int y, unsigned char red, unsigned char green, unsigned char blue, const std::string& name)
        : Base(x, y), red(red), green(green), blue(blue), name(name) {}

    void paint() const override {
        Base::paint();
        cout << ", Color: (" << static_cast<int>(red) << ", " << static_cast<int>(green) << ", " << static_cast<int>(blue) << "), Name: " << name << endl;
    }
};

int main() {
    Stone stone(-100, 35, 5200);
    Chest chest(1148, 888, 50, 50, 100);
    Trader trader(666, 666, 1, 10);
    Player player(302, -906, 255, 0, 255, "Nagibator2007");

    stone.paint();
    chest.paint();
    trader.paint();
    player.paint();

    return 0;
}