/* Citation and Sources...
Final Project Milestone 5
Module: PosApp
Filename: PosApp.cpp
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
#ifndef SDDS_PERISHABLE
#define SDDS_PERISHABLE
#include "Item.h"
#include "Date.h"

namespace sdds
{
   class Perishable : public Item
   {
      Date expDate{};

   public:
      Perishable();
      ~Perishable();
      //overriding ItemType to identify as a Perishable 
      char ItemType() const;

      //overiding read function
      std::istream& read(std::istream& istr);
      //overiding write function
      std::ostream& write(std::ostream& ostr)const;
      //overiding load function
      std::ifstream& load(std::ifstream& file);
      //overiding save function
      std::ofstream& save(std::ofstream& file)const;

   };
}
#endif // !SDDS_PERISHABLE
