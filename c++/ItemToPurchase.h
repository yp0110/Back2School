
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H

#include <string>
#include <iostream>

using namespace std;

//Declare class
class ItemToPurchase
{
public:
   ItemToPurchase();
   //parameterized constructor
   ItemToPurchase(string, string,int,int);
   void SetName(string name);
   string GetName();
   void SetPrice(int price);
   int GetPrice();
   void SetQuantity(int quantity);
   int GetQuantity();

   //Added methods in the class
   void SetDescription(string);
   string GetDescription();
   void PrintItemDescription();
   void PrintItemCost();

private:
   
   string itemName;
   int itemPrice;
   int itemQuantity;
   string itemDescription;
};
#endif