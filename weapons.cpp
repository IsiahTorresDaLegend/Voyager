/* 
    weapons.cpp
    Souce code file by Isiah Torres
    Member function definitions for Weapons class
                                                    */
//===============================================
// Preprocessor Directives
#include <iostream>
#include <string>
#include "weapons.h"    // weapons.h has the Weapons class.

using namespace std;
//===============================================
// Member functions (methods) definitions
// Constuctors
// Since these functions are outside of the class definition, we have to prefix them with Weapons::
Weapons::Weapons() {} // blank definition, just sets aside memory for object

Weapons::Weapons(string name, string type, string rarity, string attr, int damage, int wpnHealth) :
    m_WpnName(name),
    m_Type(type),
    m_Rarity(rarity),
    m_Attribute(attr),  // member initializer list (the shorthand way)
    m_DmgPerHit(damage),
    m_Condition(wpnHealth)
{} 
// the above constructor has a member initializer list, we use : after the Constuctor, then list the data members
// and assign the values according to the parameter in parenthesis ( ).
// set methods definitions - sets values for private data members
void Weapons::SetWpnName(string name)    // Weapons name
{
    m_WpnName = name; 
}
void Weapons::SetType(string type) // Weapon type
{
    m_Type = type;
}
void Weapons::SetRarity(string rarity)   // Weapons rarity rank
{
    m_Rarity = rarity;    
}
void Weapons::SetAttribute(string attr)  // Weapons special attribute if any
{
    m_Attribute = attr;
}
void Weapons::SetDmgPerHit(int damage)   // Weapons damage per hit default is MIN_DAMAGE
{
    if (damage < MIN_DAMAGE)
    {
        m_DmgPerHit = MIN_DAMAGE; // controls what is the lowest a weapons damage should be.
    }
    else
    {
        m_DmgPerHit = damage;
    }
}
void Weapons::SetCondition(int wpnHealth) // Weapons condition (0 is broken, delete weapon) default = MAX_CONDITION
{
    if (wpnHealth < MIN_CONDITION)
    {
        m_Condition = MIN_CONDITION; // lowest condition a weapon should be
    }
    else if (wpnHealth > MAX_CONDITION)
    {
        m_Condition = MAX_CONDITION; // highest condition a weapon can be
    }
    else 
    {
        m_Condition = wpnHealth; // or else define by parameter
    }
}
// get methods definitions - just returns values of private data members
string Weapons::GetWpnName()
{
    return m_WpnName;
}
string Weapons::GetType()
{
    return m_Type;
}
string Weapons::GetRarity()
{
    return m_Rarity;
}
string Weapons::GetAttribute()
{
    return m_Attribute;
}
int Weapons::GetDmgPerHit()
{
    return m_DmgPerHit;
}
int Weapons::GetCondition()
{
    return m_Condition;
}
int Weapons::GetMaxCondition()
{
    return MAX_CONDITION;
}
int Weapons::GetMinCondition()
{
    return MIN_CONDITION;
}
int Weapons::GetMinDamage()
{
    return MIN_DAMAGE;
}
// display method definition
void Weapons::Display() // prints out the objects values to screen
{
    cout << "\nWeapon Name: " << m_WpnName;
    cout << "\nType: " << m_Type;
    cout << "\nRarity: " << m_Rarity;
    cout << "\nAttributes: " << m_Attribute;
    cout << "\nDamage: " << m_DmgPerHit;
    cout << "\nCondition: " << m_Condition;
}

