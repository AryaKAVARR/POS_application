/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.cpp
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
#include "Perishable.h"
#include<iostream>
#include<cstring>
#include <iomanip>
#include<fstream>
#include<string>
#include "Date.h"

using namespace std;

namespace sdds
{
   char Perishable::ItemType() const
   {
      return 'P';
   }
   Perishable::Perishable()
   {}

   Perishable::~Perishable()
   {
   }

   std::istream& Perishable::read(std::istream& istr)
   {
      Item::read(istr);
      this->expDate.SetMode(true);
      if (this->err || !(istr.fail()))
      {
         Date obj{};
         obj.SetMode(true);
         if (istr)
            cout << "Expiry date (YYYY/MM/DD)" << endl << "> ";


         istr >> obj;
         if (obj)
         {
            this->expDate = obj;
         }
         else
         {
            this->err = obj.error();
         }
      }
      return istr;
   }
   std::ostream& Perishable::write(std::ostream& ostr) const
   {
      Item::write(ostr);
      Date date{};
      if (this->POS_LIST)
      {
         ostr << "  " << this->expDate << " " << "|";
      }
      else
      {
         cout << "Expiry date: " << expDate << endl << "=============^" << endl;
      }
      return ostr;
   }
   std::ifstream& Perishable::load(std::ifstream& file)
   {
      Item::load(file);
      if (this->err || !(file.fail()))
      {
         Date obj{};
         obj.setEmpty();
         obj.SetMode(true);
         file.ignore();
         file >> obj;
         if (obj)
         {
            this->expDate = obj;
         }
         else
            this->err = obj.error();
      }
      return file;

   }

   std::ofstream& Perishable::save(std::ofstream& file) const
   {
      Item::save(file);
      if (!file.fail())
      {
         file << "," << this->expDate << endl;
         file.clear();
      }
      return file;
   }
}