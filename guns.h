/*  
    guns.h
    Header file by Isiah Torres
    Defines Guns class
    Used for simulating firearm weapons
                                       */
//=======================================
// Include Guard
#ifndef __GUNS_H_INCLUDED__   // if guns.h hasn't been included yet
#define __GUNS_H_INCLUDED__   // define guns.h so compiler includes it.

//=======================================
//Preprocessor Directives
#include <iostream>
#include <string>
#include "weapons.h" // parent class header file

using namespace std;
//=======================================
// Class Definition
class Guns : public Weapons // class named Guns is a child class of Weapons, we use : to inherit from Weapons with public access
{
    public:
    // constructors
        Guns(); // default constructor
        Guns(string name, string type, string rarity, string attr, string sound,
        int damage, int wpnHealth, int ammoCap = MIN_AMMO_CAP); // this class has additional members so theres additional parameters 
        
    // set methods
        void SetAmmoCap(int ammoCap);
        void SetSound(string sound);
    // get methods
        int GetAmmoCap();
        string GetSound();
    // display method
        void Display();
    // Miscellaneous
        void Shoot(); // just display how the weapon sounds
    private:
        static const int MIN_AMMO_CAP = 1; // const for lowest ammo capacity
        int m_AmmoCapacity; // this class has its own data members
        string m_Sound; 
};
//=======================================

#endif // __GUNS_H_INCLUDED__ end if statement, file will be skipped over if already included
