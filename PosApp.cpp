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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "PosApp.h"
#include <iomanip>
#include<fstream>
#include<stdio.h>
#include "Perishable.h"
#include "NonPerishable.h"
#include "Item.h"
#include <algorithm>
#include<string>
#include<cstring>

using namespace std;

namespace sdds
{
   int PosApp::actionTitle() const
   {
      cout << ">>>> ";
      cout << left << setw(73) << setfill('.') << this->dataFilename << endl;

      return 0;
   }
   void PosApp::setEmpty()
   {
      for (int i = 0; i < this->nptr; i++)
      {
         /*delete[] this->Iptr[i];*/
         this->Iptr[i] = nullptr;
      }
   }
   bool PosApp::isEmpty()
   {
      return this->dataFilename[0] == '\0';
   }
   PosApp::PosApp(const char* filename)
   {
      strcpy(this->dataFilename, filename);
      for (int i = 0; i < MAX_NO_ITEMS; i++)
      {
         this->Iptr[i] = nullptr;
      }
   }

   void PosApp::run()
   {
      bool loop = true;
      ifstream fstr;
      string str{};
      bool check = true;
      int opt{};

      fstr.open(dataFilename);
      getline(fstr, str, '\n');

      cout << ">>>> Loading Items..........................................................." << endl;
      this->loadRecs();
      /*cout << "Loading data from " << this->dataFilename << endl;*/
      do
      {
         cout << "The Sene-Store" << endl;
         cout << "1- List items" << endl;
         cout << "2- Add item" << endl;
         cout << "3- Remove item" << endl;
         cout << "4- Stock item" << endl;
         cout << "5- POS" << endl;
         cout << "0- exit program" << endl << "> ";

         do
         {          
            cin >> opt;
            if (cin.fail())
            {
               cout << "Invalid Integer, try again: ";
               cin.clear();
               cin.ignore(1000, '\n');
            }
            else if (opt > 5 || opt < 0)
            {
               cout << "[0<=value<=5], retry: > ";
            }
            else if (opt <= 5 && opt >= 0)
            {               
               switch (opt)
               {
               case 1:

                  cout << ">>>> Listing Items..........................................................." << endl;
                  cin.clear();
                  this->listItems();
                  check = false;
                  break;
                 
               case 2:

                  cout << ">>>> Adding Item to the store................................................" << endl;
                  cin.clear();
                  this->addItem();
                  check = false;
                  break;

               case 3:

                  cin.ignore(10000, '\n');
                  cout << ">>>> Remove Item............................................................." << endl;
                  cout << ">>>> Item Selection by row number............................................" << endl;
                  cout << "Press <ENTER> to start...."; 
                  cin.clear();
                  cin.ignore(10000, '\n');
                  cout << ">>>> Listing Items..........................................................." << endl;
                  this->removeItem();
                  check = false;
                  break;

               case 4:

                  cin.ignore(10000, '\n');
                  cout << ">>>> Select an item to stock................................................." << endl;
                   cout << ">>>> Item Selection by row number............................................" << endl;
                  cout << "Press <ENTER> to start...."; 
                  cin.clear();
                  cin.ignore(10000, '\n');
                  cout << ">>>> Listing Items..........................................................." << endl;
                  this->stockItem();
                  check = false;
                  break;

               case 5:
                  
                  cin.ignore(1000, '\n');
                  cout << ">>>> Starting Point of Sale.................................................." << endl;
                  this->Pos();
                  check = false;
                  break;

               case 0:

                  cout << ">>>> Saving Data............................................................." << endl;
                  /*cout << "Saving data in " << this->dataFilename << endl;*/
                  cout << "Goodbye!" << endl;
                  this->saveRecs();
                  check = false;
                  loop = false;
                  break;

                  default:
                  break;
               }
            }
         } while (check);

         if (loop)
            check = true;

      } while (loop);
   }

   bool PosApp::addItem()
   {
      bool check = false;

      Item* number{};
      char temp{};
      if (this->nptr == MAX_NO_ITEMS)
      {
         check = true;
      }
      else
      {
         cout << "Is the Item perishable? (Y)es/(N)o: ";
         
         cin >> temp;
         if (temp == 'n')
         {
            number = new NonPerishable();
         }
         else if (temp == 'y')
         {
            number = new Perishable();
         }
         check = true;
      }
      cin >> *number;
      while (cin.fail())
      {
         cin.clear();
         cin.ignore(1000, '\n');
         cout << *number << ", try again..." << endl;
      }

      Iptr[this->nptr] = number;
      this->nptr++;

      cout << ">>>> DONE!..................................................................." << endl;

      return check;
   }

   bool PosApp::loadRecs()
   {
      bool check = false;
     /* cout << this->actionTitle();*/

      if (this->isEmpty())
         check = true;
      else {
         ifstream input(this->dataFilename);
         
         //Item* temp = nullptr;
         if (input.is_open())
         {
            this->setEmpty();

            while (!input.fail() && nptr < MAX_NO_ITEMS)
            {
               if (input.fail())
               {
                  break;
               }
               else
               {
                  check = true;
                  char read{};
                  input >> read;
                  input.ignore(1000, ',');
                   
                  if (read != '\0')
                  {
                     if (read == 'P')
                     {
                        Iptr[this->nptr] = new Perishable();
                        Iptr[this->nptr]->load(input);
                     }
                     else if (read == 'N')
                     {
                        Iptr[this->nptr] = new NonPerishable();
                        Iptr[this->nptr]->load(input);
                        input.ignore(1000, '\n');
                     }

                     //checking the data and ifstream
                     if (input.fail())
                     {
                        for (int i = 0; i < MAX_NO_ITEMS; i++)
                        {
                           /*delete this->Iptr[i];*/
                           this->Iptr[i] = nullptr;
                        }
                        this->nptr = 0;
                        check = false;
                     }
                     else
                        ++this->nptr;
                  }
               }
            }
            check = true;
            input.close();
         }
         else {
            ofstream ouput(this->dataFilename, ios::out);
            ouput.close();
            check = true;
         }
      }
      return check;
   }
   int PosApp::selectItem()
   {
      int rowNumber{};

      Item* temp{};
      for (int i = 0; i < nptr - 1; i++)
      {
         int minIndex = i;
         for (int j = i + 1; j < nptr; j++)
         {
            if (*Iptr[minIndex] > *Iptr[j])
            {
               minIndex = j;
            }
         }
         temp = Iptr[minIndex];
         Iptr[minIndex] = Iptr[i];
         Iptr[i] = temp;
      }

      cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
      cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;

      for (int i = 0; i < nptr; i++)
      {
         this->Iptr[i]->displayType(1);
         cout << std::setw(4) << setfill(' ') << std::right << i + 1 << " | " << std::left << *Iptr[i] << setw(8) << endl;
      }

      cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
      
      cout << "Enter the row number: ";
      do
      {
         cin >> rowNumber;
         if (cin.fail())
         {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Integer, try again: ";

         }else if (rowNumber > 26 || rowNumber < 1)
         {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[1<=value<=26], retry: Enter the row number: ";
         }
         else 
         {
            break;
         }
      } while (true);

      return rowNumber;
   }

   bool PosApp::saveRecs() {

      bool check = false;
      ofstream output(this->dataFilename,ios::out);
      if (output.is_open()) {
         for (int i = 0; i < this->nptr; i++) {
            this->Iptr[i]->save(output);
            delete this->Iptr[i];
            this->Iptr[i] = nullptr;
         }
         check = true;
         
      }
      else {
         cerr << "Error: could not open file " << this->dataFilename << " for writing." << endl;
      }
      output.close();
      return check;
   }
   void PosApp::listItems()
   {
         Item* temp{};
         for (int i = 0; i < nptr - 1; i++)
         {
            int minIndex = i;
            for (int j = i + 1; j < nptr; j++)
            {
               if (*Iptr[minIndex]  > *Iptr[j] )
               {
                  minIndex = j;
               }
            }
            temp = Iptr[minIndex];
            Iptr[minIndex] = Iptr[i];
            Iptr[i] = temp;
         }

      cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
      cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;

      double totalAssets = 0.0;

      for (int i = 0; i < nptr; i++)
      {
         this->Iptr[i]->displayType(1);
         cout << std::setw(4) << setfill(' ') << std::right << i + 1 << " | " << std::left << *Iptr[i] << setw(8) << endl;
         totalAssets += Iptr[i]->cost() * Iptr[i]->quantity();
      }

      cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
      cout << "                               Total Asset: $  |" << setw(14) << setprecision(2) << totalAssets << "|" << endl;
      cout << "-----------------------------------------------^--------------^" << endl << endl;

   }
   void PosApp::removeItem()
   {
      /*bool check = false;*/
      int index = this->selectItem();
      cout << "Removing...." << endl;

      for (int i = 0; i < this->nptr; i++)
      {
         if (i == index - 1)
         {
            this->Iptr[i]->setPOSFormat(2);
            cout << *this->Iptr[i];
            delete this->Iptr[i];
            this->Iptr[i] = nullptr;

            for (int j = i; j < this->nptr; j++)
            {
               this->Iptr[j] = this->Iptr[j + 1];
            }

            cout << ">>>> DONE!..................................................................." << endl;
            --this->nptr;
            break;
         }
      }
   }

   void PosApp::stockItem()
   {
      bool check = true;
      int index = this->selectItem();

      for (int i = 0; i < this->nptr && check; i++)
      {
         if (i == index - 1)
         {
            cout << "Selected Item:" << endl;
            this->Iptr[i]->setPOSFormat(2);
            cout << *this->Iptr[i];

            cout << "Enter quantity to add: ";
            do
            {
               int qty{};
               cin >> qty;
               if (cin.fail())
               {
                  cin.clear();
                  cin.ignore(1000, '\n');
                  cout << "Invalid Integer, try again: ";
               }
               else if (qty > 1 && qty < (MAX_STOCK_NUMBER - this->Iptr[i]->quantity()))
               {
                  *this->Iptr[i] += qty;
                  cout << ">>>> DONE!..................................................................." << endl;
                  check = false;
                  break;
               }
               else
               {
                  cout << "[1<=value<=69], retry: Enter quantity to add: ";
               }

            } while (true);
            
         } 
      }
   }

   Item* PosApp::search(const char* sku) const
   {
      for (int i = 0; i < nptr; i++)
      {
         if (*Iptr[i] == sku)
         {
            return Iptr[i];
         }
      }
      return nullptr;
   }

   void PosApp::Pos()
   {
      char sku[MAX_SKU_LEN]{};
      
      Item* bill[MAX_NO_ITEMS]{};
      double total{};
      int count{0};
      do
      {
            cout << "Enter SKU or <ENTER> only to end sale..." << endl;
            cout << "> " ;
            cin.getline(sku, MAX_SKU_LEN + 1);

            if (sku[0] != '\0' && !cin.fail())
            {
               Item* item = search(sku);
              
               if (item != nullptr)
               {
                  //subtract the quantity by one
                  if (item->quantity() != 0)
                  {
                     *item -= 1;
                     item->setPOSFormat(2);
                     cout << *item;

                     bill[count] = item;
                     ++count;
                     total += item->cost();

                     cout << endl << ">>>>> Added to bill" << endl;
                     cout << ">>>>> Total: " << total << endl;
                  }
                  else
                  {
                     cout << "Item out of stock" << endl;
                  }
               }
               else
               {
                  cout << "!!!!! Item Not Found !!!!!" << endl;
               }
            }
            else
            {
               cout << "v---------------------------------------v" << endl;
               cout << "| ";
               Date obj{};
               cout << obj;
               cout << setw(21) << "|" << endl;
               cout << "+---------------------v-----------v-----+" << endl;
               cout << "| Item                |     Price | Tax +" << endl;
               cout << "+---------------------v-----------v-----+" << endl;
               for (int i = 0; i < count; i++)
               {
                  bill[i]->bprint(cout);
               }
               cout << "+---------------------^-----------^-----+" << endl;
               cout << "| total:" << setw(25) << total << " |" << endl;
               cout << "^---------------------------------^" << endl;
               break;
            }
      } while (true);
   }
}  