/* Citation and Sources...
Final Project Milestone 4
Module: NonPerishable
Filename: NonPerishable.cpp
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
#include <iostream>
#include "NonPerishable.h"

using namespace std;

namespace sdds
{
   char NonPerishable::ItemType() const
   {
      return 'N';
   }

   NonPerishable::~NonPerishable()
   {
   }

   std::ofstream& NonPerishable::save(std::ofstream& file) const
   {
      Item::save(file);
      file << endl;
      return file;
   }

   std::ostream& NonPerishable::write(std::ostream& ostr) const
   {
      Item::write(ostr);
      if (!this->err)
      {
         if (this->POS_LIST)
         {
            ostr << "     N / A   |";
         }
         else if (this->POS_FORM)
         {
            ostr << "=============^" << endl;
         }
      }
      return ostr;
   }
}