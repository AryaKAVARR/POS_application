/* Citation and Sources...
Final Project Milestone 3
Module: PosIO
Filename: PosIO.h
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
#ifndef SDDS_POS
#define SDDS_POS

namespace sdds
{

   const int MAX_NAME_LEN = 40;

   const int POS_LIST = 1;
   const int POS_FORM = 2;

   const char ERROR_POS_SKU[50] = "SKU too long";
   const char ERROR_POS_NAME[50] = "Item name too long";
   const char ERROR_POS_PRICE[50] = "Invalid price value";
   const char ERROR_POS_TAX[50] = "Invalid tax status";
   const char ERROR_POS_QTY[50] = "Invalid quantity value";
   const char ERROR_POS_STOCK[50] = "Item out of stock";
   const char ERROR_POS_EMPTY[50] = "Invalid Empty Item";

   //milestone 2
   const double TAX = 0.13;
   const int MAX_SKU_LEN = 7;
   const int MIN_YEAR = 2000;
   const int MAX_YEAR = 2030;
   const int MAX_STOCK_NUMBER = 99;
   const int MAX_NO_ITEMS = 200;
}
#endif // !SDDS_POS
