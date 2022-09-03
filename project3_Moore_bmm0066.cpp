/* File Name: project3_Moore_bmm0066.cpp
* AUTHOR: Blake Moore 
* UserID: bmm0066
* Class: Comp 2710 
* Complie with: g++ project3_Moore_bmm0066.cpp
* Run by: ./a.out
* Location: /home/u2/bmm0066
* Got help from the project2 hints file on Canvas 
*/ 

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cassert>
using namespace std;

//Global variables
ofstream outFile;


//Read the numbers in the files into array
vector<int> read_file(string);

//Writes final array to new file
void write_file(string, vector<int>);

//Combines and sorts two input arrays
vector<int> merge(vector<int>, vector<int>);

//Displays arrays to the file
void to_string(string, vector<int>);

//Test methods
void readFileTest();

void writeFileTest();

void mergeTest();


//Main driver
int main()
{
   string file1, file2, outName;
   cout << "*** Welcome to Blake Moore's sorting program ***\nEnter the first input file name: ";
   cin >> file1;
   if (!cin)
   {
      cout << "You did not input anything, please try again";
      cout << endl;
      return 0;
   }
   vector<int> inArray1 = read_file(file1); 
   if (inArray1.empty())
   {
      return 0;
   }
   int inArray1Size = inArray1.size();
   cout << "The list of " << inArray1Size << " numbers in file " << file1 << " is: \n";
   for (int i = 0; i < inArray1.size(); i++)
   {
      cout << inArray1.at(i) << "\n";
   }
   cout << "\nEnter the second input file name: ";
   cin >> file2;
   if (!cin)
   {
      cout << "You did not input anything, please try again";
      cout << endl;
      return 0;
   }
   vector<int> inArray2 = read_file(file2); 
   int inArray2Size = inArray2.size();
   cout << "The list of " << inArray2Size << " numbers in file " << file2 << " is: \n";
   for (int i = 0; i < inArray2.size(); i++)
   {
      cout << inArray2.at(i) << "\n";
   }
   vector<int> lastArray = merge(inArray1, inArray2);
   to_string("out", lastArray);
   cout << "Enter the output file name: ";
   cin >> outName;
   if (!cin)
   {
      cout << "You did not input anything, please try again";
      cout << endl;
      return 0;
   }
   write_file(outName, lastArray);
   cout << "*** Please check the new file - " << outName << " ***";
   cout << "\n*** Goodbye. ***" << endl;
   //Commented out testing
   // readFileTest();
   // writeFileTest();
   // mergeTest();
   return 1;
}


vector<int> read_file(string title)
{
   ifstream openFile(title.c_str());
   vector<int> array;
   if (!openFile.is_open())
   {
      cout << "Problem opening file" << endl;
      return array;
   }
   string line;
   int number;
   while(!openFile.eof())
   {
      getline(openFile, line);
      stringstream conversion(line);
      conversion >> number;
      array.push_back(number);
      // array.resize(array.size() + 1);
      // array[array.size() - 1] = number;
   }
   openFile.close();
   array.pop_back();
   return array;
}

void write_file(string name, vector<int> final)
{
   outFile.open(name.c_str());
   if (outFile.is_open())
   {
      for (int i = 0; i < final.size(); i++)
      {
         outFile << final.at(i) << "\n";
      }
   }
   else
   {
      cout << "Problem opening output file" << endl;
   }
   outFile.close();
}

vector<int> merge(vector<int> first, vector<int> second)
{
   vector<int> finalArray;
   sort(first.begin(), first.end());
   sort(second.begin(), second.end());
   vector<int> close(first.size() + second.size());
   merge(first.begin(), first.end(), second.begin(), second.end(), close.begin());
   sort(close.begin(), close.end());
   finalArray = close;
   return finalArray;
}

void to_string(string called, vector<int> list)
{
   int size = list.size();
   cout << "\nThe sorted list of " << size << " numbers is: ";
   for (int i = 0; i < list.size(); i++)
   {
      cout << list.at(i) << " ";
   }
   cout << endl;
}


//Testing methods

//Causes compilation errors in server 
//because it uses a different compiler, 
//methods only for personal integration testing

// void readFileTest()
// {
   // vector<int> read = read_file("input1.txt");
   // vector<int> should = {4, 13, 14, 17, 23, 89};
   // assert(should == read);
   // cout << "Read 1 passed";
   // vector<int> read2 = read_file("test1.txt");
   // vector<int> should2 = {3, 4, -7, -8, 0, 6, 2, -10};
   // assert(should2 == read2);
   // cout << "Read 2 passed";
// }
// 
// void writeFileTest()
// {
   // vector<int> should = {-4, -5, 4, 13, 14, 17, 23, 89};
   // write_file("outTest.txt", should);
   // vector<int> read = read_file("outTest.txt");
   // assert(should == read);
   // cout << "Write test passed";
// }
// 
// void mergeTest()
// {
   // vector<int> one = {-5, -6, 0, 0, 1, 2, 3};
   // vector<int> two = {53, -47, 87, 12, 3, 4};
   // vector<int> merged = merge(one, two);
   // vector<int> test = {-47, -6, -5, 0, 0, 1, 2, 3, 3, 4, 12, 53, 87};
   // assert(test == merged);
   // cout << "Merge test passed";
// }




