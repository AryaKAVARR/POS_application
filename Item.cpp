/* Citation and Sources...
Final Project Milestone 3
Module: Item
Filename: Item.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include<iostream>
#include<cstring>
#include <iomanip>
#include<fstream>

using namespace std;

namespace sdds
{
   Item::Item()
   {
      this->sku[0] = '\0';
      this->name = nullptr;
      this->price = 0.0;
      this->taxable = false;
      this->no_of_item = 0;
      this->empty = true;
   }

   Item::~Item()
   {
      delete[] this->name;
      this->name = nullptr;
   }

   Item::Item(const Item& itm)
   {
      this->sku[0] = '\0';
      this->name = nullptr;
      this->price = 0.0;
      this->taxable = false;
      this->no_of_item = 0;
      this->empty = true;
      this->display = 0;

      *this = itm;
   }
   bool Item::operator==(const char* itm) const
   {
      return !strcmp(this->sku, itm);
   }

   bool Item::operator>(const Item& itm)const
   {
      return strcmp(this->name,itm.name) > 0;
   }

   bool Item::isEmpty() const {
      return name == nullptr;
   }

   int Item::operator+=(int qty)
   {
      if (qty > 0)
      {
         this->no_of_item += qty;
         if (this->no_of_item > MAX_STOCK_NUMBER)
         {
            this->no_of_item = MAX_STOCK_NUMBER;
            this->err.clear();
            this->err = ERROR_POS_QTY;
         }
      }
      return this->no_of_item;
   }

   int Item::operator-=(int qty)
   {
      if (qty > 0)
      {

         if (qty > this->no_of_item)
         {
            this->no_of_item = 0;
            this->err.clear();
            this->err = ERROR_POS_STOCK;
         }
         else
         {
            this->no_of_item -= qty;
         }
      }
      return this->no_of_item;
   }

   Item::operator bool() const
   {
      return !(this->err);
   }

   Item& Item::displayType(const int lhs)
   {
      if (lhs == 1)
      {
         this->POS_LIST = true;
         this->display = lhs;
      }
      else if (lhs == 2)
      {
         this->POS_LIST = false;
         this->POS_FORM = true;
         this->display = lhs;
      }

      return *this;
   }

   double Item::cost() const
   {
      return price * (1 + taxable * TAX);
   }

   int Item::quantity() const
   {
      return this->no_of_item;
   }

   Item& Item::clearError()
   {
      this->err.clear();
      return *this;
   }
   Item& Item::operator=(const Item& I)
   {
      if (this != &I) {

         if (this->name != nullptr)
            delete[] this->name;

         this->name = new char[strlen(I.name) + 1];
         strcpy(this->name, I.name);

         strcpy(this->sku, I.sku);

         this->price = I.price;
         this->no_of_item = I.no_of_item;
         this->taxable = I.taxable;
      }
      return *this;
   }

   std::ostream& Item::write(std::ostream& ostr) const
   {
      if (!isEmpty()) {
         if (err) {
            err.read(ostr);
         }
         else {
            char name[21]{};
            if (this->name != nullptr) strncpy(name, this->name, 20);

            ostr.setf(ios::fixed);
            ostr.precision(2);

            if (this->POS_LIST) {
               cout.setf(ios::left);
               ostr.width(7);
               ostr << this->sku;
               ostr << "|";

               ostr.width(20);
               ostr << name;
               cout.unsetf(ios::left);
               ostr << "|";

               ostr.width(7);
               ostr << this->price;
               ostr << "|";

               ostr.width(3);
               if (this->taxable) ostr << " X ";
               else ostr << "";
               ostr << "|";

               ostr.width(4);
               ostr << this->no_of_item;
               ostr << "|";

               ostr.width(9);
               ostr << (cost() * this->no_of_item);
               ostr << "|";
            }
            else if (this->POS_FORM) {
               ostr.fill('=');
               ostr.width(13);
               ostr << '=';
               ostr << "v" << endl;
               ostr << "Name:        " << name << endl;
               ostr << "Sku:         " << this->sku << endl;
               ostr << "Price:       " << this->price << endl;
               ostr << "Price + tax: ";
               if (taxable) {
                  ostr << cost();
               }
               else {
                  ostr << "N/A";
               }
               ostr << endl;
               ostr << "Stock Qty:   " << this->no_of_item << endl;
            }
         }
      }
      return ostr;
   }

   std::ofstream& Item::save(std::ofstream& file)const
   {
      if (!isEmpty())
      {
         if (this->err)
         {
            cout << this->err << endl;
         }
         else
         {
            file.setf(ios::fixed);
            file.precision(2);
            file << this->ItemType() << ",";
            file << this->sku << ",";
            file << this->name << ",";
            file << this->price << ",";
            file << this->taxable << ",";
            file << this->no_of_item;
         }
      }
      return file;
   }
   std::istream& Item::read(std::istream& istr)
   {
      cout << "Sku" << endl << "> ";
      do {
         istr >> this->sku;
         if (strlen(this->sku) > MAX_SKU_LEN)
         {
            istr.clear();
            istr.ignore(1000, '\n');
            cout << ERROR_POS_SKU << endl << "> ";
            /*istr >> this->sku;*/
         }
         else
         {
            break;
         }
      } while (true);

      istr.ignore(1000, '\n');
      cout << "Name" << endl << "> ";
      do {
         char temp[41]{};
         istr.getline(temp, 40);
         if (istr.fail())
         {
            istr.clear();
            istr.ignore(1000, '\n');
            cout << ERROR_POS_NAME << endl << "> ";
            /*istr >> temp*/
         }
         else
         {
            this->name = new char[strlen(temp) + 1];
            strcpy(this->name, temp);
            break;
         }
      } while (true);

      cout << "Price" << endl << "> ";
      do
      {
         istr >> this->price;
         if (this->price < 0 || istr.fail())
         {
            istr.clear();
            istr.ignore(1000, '\n');
            cout << ERROR_POS_PRICE << endl << "> ";
            /*istr >> this->price;*/
         }
         else
         {
            istr.ignore();
            break;
         }
      } while (true);

      cout << "Taxed?" << endl << "(Y)es/(N)o: ";
      do
      {
         char opt{};
         istr >> opt;
         if (istr.fail() || (toupper(opt) != 'Y' && toupper(opt) != 'N'))
         {
            istr.clear();
            istr.ignore(1000, '\n');
            cout << "Only 'y' and 'n' are acceptable: ";
         }
         else
         {
            opt == 'y' ? this->taxable = true : this->taxable = false;
            break;
         }
      } while (true);

      cout << "Quantity" << endl << "> ";
      do
      {
         istr >> this->no_of_item;
         if (istr.fail() || (this->no_of_item <= 0 || this->no_of_item > MAX_STOCK_NUMBER))
         {
            istr.clear();
            istr.ignore(1000, '\n');
            cout << ERROR_POS_QTY << endl << "> ";
         }
         else
         {
            break;
         }
      } while (true);

      return istr;
   }

   std::ifstream& Item::load(std::ifstream& file)
   {
      this->err.clear();
      //char row[5]{};
      char tSku[100]{};
      char tName[100]{};
      double tPrice{};
      int tax{};
      int qty{};

      //file.getline(row, 2, ',');
      file.getline(tSku, 100, ',');
      file.getline(tName, 100, ',');
      file >> tPrice;
      file.ignore();
      file >> tax;
      file.ignore();
      file >> qty;

      if (!file.fail())
      {
         if (strlen(tSku) > MAX_SKU_LEN) {
            this->err = ERROR_POS_SKU;
         }
         else if (strlen(tName) > MAX_NAME_LEN) {
            this->err = ERROR_POS_NAME;
         }
         else if (tPrice < 0) {
            this->err = ERROR_POS_PRICE;
         }
         else if (tax != 0 && tax != 1) {
            this->err = ERROR_POS_TAX;
         }
         else if (qty > MAX_STOCK_NUMBER) {
            this->err = ERROR_POS_QTY;
         }
         if (!this->err) {
            strcpy(this->sku, tSku);
            if (this->name) 
               delete[] this->name;
            this->name = nullptr;
            this->name = new char[strlen(tName) + 1];
            strcpy(this->name, tName);
            this->price = tPrice;
            if (tax == 0) {
               this->taxable = false;
            }
            else {
               this->taxable = true;
            }
            this->no_of_item = qty;
         }
      }

      return file;
   }

   std::ostream& Item::bprint(std::ostream& ostr) const
   {
      char name[21]{};
      strncpy(name, this->name, 20);

      cout.fill(' ');
      cout.setf(ios::left);
      ostr << "| ";

      ostr.width(20);
      ostr << name;
      cout.unsetf(ios::left);
      ostr << "|";

      ostr.width(10);
      ostr << cost();
      ostr << " |";

      ostr.width(3);
      if (this->taxable) ostr << "T";
      else ostr << " ";
      ostr << "  |" << endl;

      return ostr;
   }

   void Item::setPOSFormat(int num)
   {
      if (num == 1)
      {
         this->POS_LIST = true;
         this->POS_FORM = false;
      }
      else
      {
         this->POS_LIST = false;
         this->POS_FORM = true;
      }
   }

   double& operator+=(double& left, const Item& itm)
   {
      left += (itm.cost() * itm.quantity());
      return left;
   }

}