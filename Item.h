/* Citation and Sources...
Final Project Milestone 3
Module: Item
Filename: Item.h
Version 1.0
Author	Asad Norouzi
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
#ifndef SDDS_Item
#define SDDS_Item
#include "Error.h"
#include"POS.h"
#include "PosIO.h"
#include <istream>
#include <fstream>

namespace sdds
{
   class Item : public PosIO
   {
      char sku[MAX_SKU_LEN];
      char* name{};
      double price{};
      bool taxable{};
      int no_of_item{};
      bool empty;

   protected:
      bool POS_LIST;
      bool POS_FORM;
      Error err;
      int display{}; //POS_LIST = 1; POS_FROM = 2;
      bool isEmpty()const;

   public:
      //constructor
      Item();
      //copy assignment operator
      Item(const Item& itm);
      //destructor
      virtual ~Item();
      Item& operator=(const Item& I);
      //member operator overloads
      bool operator==(const char* itm)const;
      bool operator>(const Item& itm)const;
      int operator+=(int qty);
      int operator-=(int qty);

      //bool conversion
      operator bool() const;
      //virtual function
      virtual char ItemType() const = 0;

      Item& displayType(const int lhs);
      double cost()const;
      int quantity()const;
      Item& clearError();

      //base class methods
      std::ostream& write(std::ostream& ostr)const;
      std::ofstream& save(std::ofstream& file)const;
      std::istream& read(std::istream& istr);
      std::ifstream& load(std::ifstream& file);
      std::ostream& bprint(std::ostream& ostr) const;

      //extra function
      void setPOSFormat(int num);
   };
   //+= operator overload
   double& operator+=(double& left, const Item& itm);
}
#endif // !SDDS_Item
