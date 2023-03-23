/* 
   weapons.h 
   Header file by Isiah Torres
   Defines Weapon Class,
   Used to create objects that simulates a weapon 
                                                 */
//=================================================
// Include Guard
#ifndef __WEAPONS_H_INCLUDED__  // if weapons.h hasnt been included yet...
#define __WEAPONS_H_INCLUDED__  // #define this file so the compiler knows its included.

//=================================================
// Preprocessor Directives
#include <iostream>
#include <string>

using namespace std;
//=================================================
// Class definition
class Weapons // class named Weapons
{
  public: // public access level means members are accessable anywhere in the program
  // Static Members
     static const int MAX_CONDITION = 100;
     static const int MIN_CONDITION = 5; // used constants so others can understand what I am thinking
     static const int MIN_DAMAGE = 5;

  // Constuctors
     Weapons(); // Default constructor - no parameters, no values get changed, memory gets set aside for objects
     Weapons(string name, string type, string rarity, string attr, int damage = MIN_DAMAGE, int wpnHealth = MAX_CONDITION);
     // the above constructor assigns values to data members
  // set methods, modifies member values
    void SetWpnName(string name);
    void SetType(string type);
    void SetRarity(string rarity);
    void SetAttribute(string attr);
    void SetDmgPerHit(int damage);
    void SetCondition(int wpnHealth);
  // get methods, returns member values
    string GetWpnName();
    string GetType();
    string GetRarity();
    string GetAttribute();
    int GetDmgPerHit();
    int GetCondition();
    int GetMaxCondition();
    int GetMinCondition();
    int GetMinDamage();
  // display method
    void Display();
    
  private: // private access level, means only accessable by members of the class (can be protected: since there is inheritance)
    
    string m_WpnName;
    string m_Type;
    string m_Rarity;
    string m_Attribute;
    int m_DmgPerHit;
    int m_Condition;
};
//=================================================



#endif // end of if statement, header file will be skipped over if already included.