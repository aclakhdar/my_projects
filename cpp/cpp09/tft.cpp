#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

#include <algorithm>
#include <sys/time.h>
#include <limits>
#include <cstdlib>  // Add this for srand() and rand()

using namespace std;

// Forward declaration of tft class
class tft;

class normal
{
    public:
    int	hp;
    string name;
    int betray;
    normal()
    {
        hp = 100;
        name = "eve";
        betray = 0;
    }

    void	betrayAction(tft &h);  // Declaration only
    void	trade(tft &h);         // Declaration only
};

class tft
{
    public:
    int	hp;
    string name;
    int betray;
    tft()
    {
        hp = 100;
        name = "adam";
        betray = 0;
    }

    void	betrayAction(normal &h)  // Renamed to avoid conflict with member variable
    {
        cout << "human1 betrayed human 2\n";
        h.hp--;
        h.betray = 1;
    }

    void trade(normal &h)
    {
        if(betray)
            betrayAction(h);
        else
            h.hp++;
    }
};

// Now define normal's methods after tft is fully defined
void normal::betrayAction(tft &h)
{
    cout << "human2 betrayed human1\n";
    h.hp--;
    h.betray = 1;
}

void normal::trade(tft &h)
{
    srand(time(0));
    int b = rand() % 4;

    if (b==2)
        betrayAction(h);
    else
        h.hp++;
}

int main()
{
    tft human1;      // Remove () - this was declaring a function
    normal human2;   // Remove () - this was declaring a function

    while ((human1.hp && human2.hp))
    {
        human1.trade(human2);   // Remove & - pass by reference, not pointer
        human2.trade(human1);   // Remove & - pass by reference, not pointer
        cout << "human1 hp : " << human1.hp << " human2 hp : " << human2.hp << endl;
		if (human1.hp < 10000)
			human1.hp = 100;
		if (human2.hp < 10000)
			human2.hp = 100;

    }

    return 0;
}
