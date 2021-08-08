#include <iostream>
#include<string>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
using namespace std;

void AddItem(ShoppingCart &cart)
{
	ItemToPurchase addItem;
	string addItemName;
	string addItemDescription;
	int addItemPrice;
	int addItemQuantity;
	
	cout <<"Add Item to Cart" <<endl;
	cout <<"Enter the item name: " <<endl;
	cin.ignore();
	getline(cin, addItemName);
	
	addItem.SetName(addItemName);
	cout <<"Enter the item description: "<<endl;
	getline(cin, addItemDescription);
	addItem.SetDescription(addItemDescription);
	
	cout<<"Enter the item price: "<<endl;
	cin >>addItemPrice;
	addItem.SetPrice(addItemPrice);
	
	cout <<"Enter the item quantity: "<<endl;
	cin >>addItemQuantity;
	addItem.SetQuantity(addItemQuantity);
	cart.AddItem(addItem);
}
	
	//method remove item
void RemoveItem(ShoppingCart &cart) 
{
   string removeItem;

   cout << "Remove Item From Cart" << endl;
   cout << "Enter name of item to remove: " << endl;
   cin.ignore();
   getline(cin, removeItem);
   cart.RemoveItem(removeItem);
}
	
//method change item quantity
void ChangeItemQuantity(ShoppingCart &cart)
{
   string changeQuantityItem;
   int changeQuantityNumber;
   ItemToPurchase updateItem;
   cout << "Change Item Quantity" << endl;
   cout << "Enter the item name: " << endl;
   cin.ignore();
   getline(cin, changeQuantityItem);
   updateItem.SetName(changeQuantityItem);  
   cout << "Enter the new quantity: " << endl;
   cin >> changeQuantityNumber;
   updateItem.SetQuantity(changeQuantityNumber);
   cart.ModifyItem(updateItem);
  
}

//method output item description
void OutputItemsDescriptions(ShoppingCart cart,
   string customerName, string todaysDate)
{  
   cout << "OUTPUT ITEMS' DESCRIPTIONS"<<endl;
   cout << customerName << "'s Shopping Cart - " << todaysDate << endl;
   cout << endl;
   cart.PrintDescriptions();
}

//method output shopping catt
void OutputShoppingCart(ShoppingCart cart, string customerName,
   string todaysDate)
{
   cout << endl << "OUTPUT ITEMS's Description";
   cout << endl << customerName << "'s Shopping Cart - " << todaysDate;
   cout << endl;
   cart.PrintTotal();
}

//method Print menu
void PrintMenu(ShoppingCart cart)
{
	string customerName;
	string todaysDate;
	char user_option ='1';
	cout<<"Enter Customer's Name: "<<endl;
	getline(cin, customerName);
	cout<<"Enter today's date: " <<endl;
	getline(cin, todaysDate);
	cout <<endl<<"Customer Name: "<<customerName;
	cout <<endl <<"Today's date: "<<todaysDate;
	
	do 
	{
		cout <<endl <<"MENU" <<endl
		<< "a - Add item to cart" << endl
        << "d - Remove item from cart" << endl
        << "c - Change item quantity" << endl
        << "i - Output items\' descriptions" << endl
        << "o - Output shopping cart"
        << endl << "q - Quit" << endl;
		
		do {
			cout << endl << "Choose an option: ";
           cin >> user_option;
           if (cin.fail()) {
               cin.clear();
               cin.ignore('\n', 1000);
               return;
           }
       } while (user_option != 'a' && user_option != 'd' &&
           user_option != 'c' && user_option != 'i' &&
           user_option != 'o' && user_option != 'q');
       if (user_option == 'a')
	   {
           AddItem(cart);
       }
       else if (user_option == 'd')
       {
           RemoveItem(cart);
       }
       else if (user_option == 'c')
       {
           ChangeItemQuantity(cart);
       }
       else if (user_option == 'i')
       {
           OutputItemsDescriptions(cart, customerName, todaysDate);
       }
       else if (user_option == 'o')
       {
           OutputShoppingCart(cart, customerName, todaysDate);
       }
   } while (user_option != 'q');
}


//main function
int main()
{
   //Create object for the class Shopping cart
   ShoppingCart cart;
   //call the method with the object
   PrintMenu(cart);
   return 0;
}
