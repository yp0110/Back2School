#include "ShoppingCart.h"
#include <iostream>
#include <string>
using namespace std;

ShoppingCart::ShoppingCart()
{
customerName ="none";
currentDate= " Janaury 1,2016";
}	
//parametrized constructor
ShoppingCart::ShoppingCart(string name, string date)
{
	currentDate = date;
	customerName = name;
}




string ShoppingCart::GetCustomerName()
{
   return customerName;
}

string ShoppingCart::GetDate()
{
   return currentDate;
}

// the method AddItem
void ShoppingCart::AddItem(ItemToPurchase item)
{
   this->cartItems.push_back(item);
}

//implement the method RemoveItem
void ShoppingCart::RemoveItem(string itemName)
{
   for (int i = 0; i < cartItems.size(); i++)
   {
       if (this->cartItems.at(i).GetName() == itemName)
       {
           this->cartItems.erase(cartItems.begin() + i);
           return;
       }
   }
   cout << endl << "Item not found in cart. Nothing removed.";
}

//implement the method ModifyItem
void ShoppingCart::ModifyItem(ItemToPurchase item)
{
   for (int i = 0; i < cartItems.size(); i++)
   {
       if (cartItems.at(i).GetName()==(item.GetName()))
       {
           cartItems.at(i).SetQuantity(item.GetQuantity());
           return;          
       }
   }
   cout << " Item not found in cart. Nothing modified.";
}

int ShoppingCart::GetNumItemsInCart()
{
   int numItems = 0;
   for (int i = 0; i < cartItems.size(); i++) {
       numItems += cartItems.at(i).GetQuantity();
   }
   return numItems;
}

//implement the method ModifyItem GetCostOfCart()
int ShoppingCart::GetCostOfCart()
{
   int totalCost = 0;
   for (int i = 0; i < cartItems.size(); i++)
   {
       totalCost += (cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity());
   }
   return totalCost;
}

//implement the method ModifyItem PrintTotal()
void ShoppingCart::PrintTotal()
{
   cout << "Number of Items: " << GetNumItemsInCart() << endl;
   for (int i = 0; i < cartItems.size(); i++)
   {
       cout << endl << cartItems.at(i).GetName() << " "
           << cartItems.at(i).GetQuantity() << " @ $"
           << cartItems.at(i).GetPrice()<< " = $"
           << (cartItems.at(i).GetQuantity() * cartItems.at(i).GetPrice());
   }
   if (cartItems.size() == 0)
   {
       cout << endl << endl << "SHOPPING CART IS EMPTY";
   }
   cout << endl << endl << "Total: $" << GetCostOfCart();
}

//implement the method ModifyItem PrintDescriptions()
void ShoppingCart::PrintDescriptions()
{
   cout << "Item Descriptions";
   for (int i = 0; i < cartItems.size(); i++) {
       cout << endl << cartItems.at(i).GetName() << ": "
           << cartItems.at(i).GetDescription();
   }
}