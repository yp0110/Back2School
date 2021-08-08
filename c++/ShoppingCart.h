#ifndef ShoppingCart_h
#define ShoppingCart_h
#include <iostream>
#include <vector>
#include <string>
#include "ItemToPurchase.h"

using namespace std;

class ShoppingCart{
	
	private:
	string customerName;
	string currentDate;
	vector <ItemToPurchase> cartItems; 	
	public:
	ShoppingCart();
	ShoppingCart(string customerName, string currentDate);
	string GetCustomerName();
	string GetDate();
	
	void AddItem(ItemToPurchase item);
	void RemoveItem(string item_name);
	void ModifyItem(ItemToPurchase item);
	int GetNumItemsInCart();
	int GetCostOfCart();
	void PrintTotal();
	void PrintDescriptions();
};

#endif


	
	
	