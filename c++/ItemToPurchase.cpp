#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

//Default constructor
ItemToPurchase::ItemToPurchase()
{
   itemName = "";
   itemDescription = "none";
   itemPrice = 0;
   itemQuantity = 0;
}

//parameterized constructor
ItemToPurchase::ItemToPurchase(string name, string description,
int price, int quantity)
{
   itemName = name;
   itemPrice = price;
   itemQuantity = quantity;
   itemDescription = description;
}
//Implement methods accessors and mutators
string ItemToPurchase::GetName()
{
   return itemName;
}

int ItemToPurchase::GetPrice()
{
   return itemPrice;
}

int ItemToPurchase::GetQuantity()
{
   return itemQuantity;
}

void ItemToPurchase::SetName(string name)
{
   itemName = name;
}

void ItemToPurchase::SetPrice(int price)
{
   itemPrice = price;
}
void ItemToPurchase::SetQuantity(int quantity)
{
   itemQuantity = quantity;
}
void ItemToPurchase::SetDescription(string item)
{
   itemDescription = item;
}
string ItemToPurchase:: GetDescription()
{
   return itemDescription;
}
//Implement output display methods
void ItemToPurchase::PrintItemDescription()
{
   cout << GetName() << ":" << GetDescription();
}

void ItemToPurchase::PrintItemCost()
{
   cout << GetName() << GetPrice() << "@" << GetQuantity()
       << GetPrice()*GetQuantity();
}

