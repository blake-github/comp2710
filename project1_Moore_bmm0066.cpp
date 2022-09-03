/* File Name: project1_Moore_bmm0066.cpp
* AUTHOR: Blake Moore 
* UserID: bmm0066
* Class: Comp 2710 
* Complie with: g++ project1_Moore_bmm0066.cpp
* Run by: ./a.out
* Location: /home/u2/bmm0066
* Got help from the project1 hints file on Canvas 
*/ 

#include <iostream> 
#include <typeinfo>
using namespace std;

int   main() {
// VARIABLE INITIALIZATION 
   double interestRate = 0;
   double monthlyPaid = 0;
   double interestRateC = 0;
   int currentMonth = 0;
   double principal = 0;
   double loan = 0;
   double interestTotal = 0;
   double check = 0;
   

//FORMATTING
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

// USER INPUT
// NOTE: For valid input, the loan, interest, and monthly payment must 
// be positive. The monthly payment must also be large enough to 
// terminate the loan. 
   cin.clear();
   cout << "\nLoan Amount: "; 
   cin >>  loan;
   while (loan < 0)
   {
      cout << "Cannot input a negative number. Please try again";
      cout << "\nLoan Amount: ";
      cin >> loan;
   }
   if (!cin)
   {
      cout << "You did not input a number, please run the program again";
      cout << endl;
      return 0;
   }
   cout << "Interest Rate (% per year): ";
   cin >> interestRate;
   while (interestRate < 0)
   {
      cout << "Cannot input a negative number. Please try again";
      cout << "\nInterest Rate (% per year): ";
      cin >> interestRate;
   }
   if (!cin)
   {
      cout << "You did not input a number, please run the program again";
      cout << endl;
      return 0;
   }
   interestRate /= 12;
   cout << "Monthly Payments: ";
   cin >> monthlyPaid;
   while (monthlyPaid < 0)
   {
      cout << "Cannot input a negative number. Please try again";
      cout << "\nMonthly Payments: ";
      cin >> monthlyPaid;
   }
   if (!cin)
   {
      cout << "You did not input a number, please run the program again";
      cout << endl;
      return 0;
   }
   cout << endl;
   double canPay = loan * interestRate / 100;
   while (monthlyPaid <= canPay)
   {
      cout << "You need more in your monthly payment to be able to pay off your loan. Please run the program again.";
      cout << endl;
      return 0;
   }
   
//TABLE
   cout << "*****************************************************************\n"
        << "\tAmortization Table\n"
        << "*****************************************************************\n"
        << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
   while (loan > 0)
   {
      if (currentMonth == 0)
      {
         cout << currentMonth++ << "\t" << loan;
         if (loan < 1000) cout << "\t";
         cout << "\t"  << "\tN/A\tN/A\tN/A\t\tN/A\n";
      }
      else
      {
         if (monthlyPaid > loan + interestRateC)
         {
            interestRateC = loan * (interestRate / 100);
            monthlyPaid = loan + interestRateC;
            principal = monthlyPaid - interestRateC;
            loan = 0;
            interestTotal += interestRateC;
            if (monthlyPaid < 1000)
            {
               cout << currentMonth++ << "\t$" << loan << "\t\t$" << monthlyPaid << "\t" << interestRate << "\t$" << interestRateC << "\t\t$" << principal << "\n";
            }
            else
            {
               cout << currentMonth++ << "\t$" << loan << "\t\t$" << monthlyPaid << interestRate << "\t$" << interestRateC << "\t\t$" << principal << "\n";
            
            }
         }
         else
         {
            interestRateC = loan * (interestRate / 100);
            principal = monthlyPaid - interestRateC;
            loan = loan - principal;
            interestTotal += interestRateC;
            if (loan >= 1000)
            {
               cout << currentMonth++ << "\t$" << loan << "\t$" << monthlyPaid << "\t" << interestRate << "\t$" << interestRateC << "\t\t$" << principal << "\n";
            }
            else
            {
               cout << currentMonth++ << "\t$" << loan << "\t\t$" << monthlyPaid << "\t" << interestRate << "\t$" << interestRateC << "\t\t$" << principal << "\n";
            }
         }
      }
   }
   cout << "****************************************************************\n";
   cout << "\nIt takes " << -- currentMonth <<  " months to pay off"
           << " the loan.\n"  
           << "Total interest paid is: $" 
           << interestTotal; 
   cout << endl; 
   return 0;
}


