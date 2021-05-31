/* 
    CPP Program to simulate battles between warriors of custom health and powers.
*/

#include <iostream>
#include <string>

using namespace std;

class Warrior
{
    public:
        int maxPower=100;
        int health=100;
        string name="unnamed";
    
        Warrior() {}
        Warrior(string name, int maxPower, int health)
        {
            this->name=name;
            this->maxPower=maxPower;
            this->health=health;
        }
        void introduce()
        {
            cout << "Hey there! I'm " <<name<<endl;
        }
        int attack()
        {
            return rand()%maxPower + 1;
        }
};

class Battle
{
    public:
    static int moves;
    
    static void printConsequence(int damage, Warrior A, Warrior B)
    {
        cout << A.name << " attacked " << B.name << " and dealt " << damage << " damage. (" << A.name << "'s health: " << A.health <<", " << B.name << "'s health: " << B.health << endl;
    }
    
    static void startBattle(Warrior &A, Warrior &B)
    {
        cout << "The epic battle between "<<A.name << " and "<<B.name<< " has begun!" << endl;
       while(true)
            if(!performAttack(A, B)) break;   
        
        if(A.health) cout << A.name << " has defeated "<<B.name <<" with "<<A.health<< " remaining!";
        else cout << B.name << " has defeated "<<A.name <<" with "<<B.health<< " health remaining!";
        cout << "Total number of moves: " << moves;
    }
    
    static int performAttack(Warrior &A, Warrior &B)
    {
        int damageDoneOnB = A.attack();
        B.health-=(B.health-damageDoneOnB)>0?damageDoneOnB:B.health;
        printConsequence(damageDoneOnB, A, B);
        moves++;
        if(!B.health) return 0;
        
        int damageDoneOnA = B.attack();
        A.health-=(A.health-damageDoneOnA)>0?damageDoneOnA:A.health;
         printConsequence(damageDoneOnA, B, A);
         moves++;
        if(!A.health) return 0;
        
        return 1;
    }
};

int Battle::moves = 0;

int main()
{
    srand(time(NULL));

    Warrior hulk("The Hulk", 70, 1000);
    Warrior thor("Thor", 110, 600);
    Battle::startBattle(hulk, thor);
    return 0;
}
