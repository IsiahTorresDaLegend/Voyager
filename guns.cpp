/* 
    guns.cpp
    Souce code file by Isiah Torres
    Member function definitions for Guns class
                                                */
//================================================
//Preprocessor Directives
#include <iostream>
#include <string>
#include "guns.h" // guns class is defined in this header file

using namespace std;
//================================================
// Member function definitions
// constuctors
Guns::Guns() {}; // default constuctor
Guns::Guns(string name, string type, string rarity, string attr, string sound,
    int damage, int wpnHealth, int ammoCap) : 
        Weapons(name, type, rarity, attr, damage, wpnHealth),
        m_Sound(sound),
        m_AmmoCapacity(ammoCap)
    {};
// Another member initializer list, this time the first on the list is the constuctor from weapons,
// Weapons constuctor will initialize the data members inherited from Weapons according to its parameters.
// shorthand and efficient way to initialize data members.
// set methods
void Guns::SetAmmoCap(int ammoCap)
{
    if (ammoCap < MIN_AMMO_CAP) // cant have a gun with no ammo capacity
    {
        m_AmmoCapacity = MIN_AMMO_CAP;
    }
    else
    {
        m_AmmoCapacity = ammoCap;
    }
}
void Guns::SetSound(string sound)
{
    m_Sound = sound;
}
// get methods
int Guns::GetAmmoCap()
{
    return m_AmmoCapacity;
}
string Guns::GetSound()
{
    return m_Sound;
}
// display method
void Guns::Display()
{
    Weapons::Display(); // Display() is overloaded, if this function is ran from this child class, 
                        // it will run Weapons Display() first which prints the attributes from that class,
                        // then we print the additional attribute from this class.
    cout << "\nAmmo Capacity: " << m_AmmoCapacity;
}
// Miscellaneous methods
void Guns::Shoot()
{
    cout << "\n**" << m_Sound << "!!!**\n"; // what ever string is assigned to m_Sound for each gun will pop up.
}