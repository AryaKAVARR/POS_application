/* Citation and Sources...
Final Project Milestone 5
Module: PosApp
Filename: PosApp.h
Version 1.0
Author	Arya Kavar
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_POSAPP
#define SDDS_POSAPP
#include "POS.h"
#include"Item.h"
namespace sdds
{
   class PosApp
   {
      char dataFilename[128]{};
      Item* Iptr[MAX_NO_ITEMS]{}; // array of pointer to hold items
      int nptr{}; // attribute to hold the number of items of Iptr

      int actionTitle()const;

      void setEmpty();
      bool isEmpty();
   public:
      PosApp(const char* filename);
      void run();

      //for adding the items
      bool addItem();
      //for loading the items into data
      bool loadRecs();
      //for selecting the items
      int selectItem();
      //deleting the item
      void removeItem();
      //for saving the items after adding or deleting it
      bool saveRecs();
      //for listing items in ascending order
      void listItems();
      //for adding stock to the list
      void stockItem();
      //search method to get sku for bill
      Item* search(const char* sku) const;
      
      void Pos();
   };
}
#endif // !SDDS_POSAPP
