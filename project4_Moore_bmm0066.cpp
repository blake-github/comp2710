/* File Name: project4_Moore_bmm0066.cpp
* AUTHOR: Blake Moore 
* UserID: bmm0066
* Class: Comp 2710 
* Complie with: g++ project4_Moore_bmm0066.cpp
* Run by: ./a.out
* Location: /home/u2/bmm0066
* Got help from the project4 hints file on Canvas 
*/ 

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cassert>
using namespace std;

//#define UNIT_TESTING 
//Un-Comment to test

//Global variables
int totalPoints = 0;

//Structure for creating nodes
struct TriviaNode {
   string question;
   string answer;
   int points;
};
//Trivia node pointer
typedef TriviaNode* TriviaNodePtr;

//Linked list class for trivia nodes
//Uses trivia node struct to create list of trivia questions/answers
//Can input data in constructor or add afterwards.
class TriviaList {
	public: 
   TriviaList(){}
   TriviaList(string theQuestion, string theAnswer, int thePoints, TriviaList* theLink)
   {
      node.question = theQuestion; node.answer = theAnswer; node.points = thePoints; link = theLink;
   }
   
   TriviaList* getLink() 
   {
      return link;
   }
      
   string getQuestion()
   {
      return node.question;
   }
      
   string getAnswer()
   {
      return node.answer;
   }
      
   int getPoints() 
   {
      return node.points;
   }
   void setQuestion(string theQuestion) 	
   {
      node.question = theQuestion;
   }
   
   void setAnswer(string theAnswer)	
   {
      node.answer = theAnswer;
   }
   
   void setPoints(int thePoints)	
   {
      node.points = thePoints;
   }
   
   void setLink (TriviaList* pointer)
   {
      link = pointer;
   }
   
	private: TriviaNode node;
   TriviaList* link;
};

typedef TriviaList* TriviaListPtr;

//Function declaration

//Initializes trivia list with three questions
TriviaListPtr initList();

//Adds nodes
TriviaListPtr addNode(string question, string answer, int points, TriviaListPtr node);

//Quiz player, Asks question and returns 0 for success and 1 for fail
int quizPlayer(TriviaListPtr list, int questions);

//Prompts user for information for trivia
//Adds to list using addNode()
TriviaListPtr getTrivia(TriviaListPtr node);

//Test function declaration

//Testing of initList()
void test_initList();

//Testing of addNode()
void test_addNode();

//Testing of quizPlayer()
void test_quizPlayer();

//Testing of getTrivia()
void test_getTrivia();

//Functions
int main() {
	#ifdef UNIT_TESTING
   test_quizPlayer();
   //Runs the entire debugging version to match assignment example
	
	#else
	//Regular version
   TriviaListPtr head = NULL;
   cout << "*** Welcome to Blake Moore's trivia quiz game ***\n";
	//Get questions
   string cont;
   int i = 0;
   do {
   		//Get input
      head = getTrivia(head);
   		//Prompt to add more
      cout << "Continue? (Yes/No): ";
      getline(cin, cont);
   		//Get valid yes/no input
      while (cont != "Yes" && cont != "No") {
         cout << "Please enter valid input (Yes/No): ";
         getline(cin, cont);
      }
      i++;
   }
   	while (cont == "Yes");
   string question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
   string answer = "Wii Sports";
   int points = 20;
   head = addNode(question, answer, points, head);
   question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
   answer = "Bank of Italy";
   points = 50;
   head = addNode(question, answer, points, head);
   question = "How long was the shortest war on record? (Hint: how many minutes)";
   answer = "38";
   points= 100;
   head = addNode(question, answer, points, head);
   int questions = 3 + i;
   cout << endl;
   int test;
   test = quizPlayer(head, questions);
   cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
	#endif
}

//Initializes list
TriviaListPtr initList() {
   TriviaListPtr head;
   string question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
   string answer = "Wii Sports";
   int points = 20;
   head = new TriviaList(question, answer, points, NULL);
   question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
   answer = "Bank of Italy";
   points = 50;
   head = new TriviaList(question, answer, points, head);
   question = "How long was the shortest war on record? (Hint: how many minutes)";
   answer = "38";
   points= 100;
   head = new TriviaList(question, answer, points, head);
   return head;
}

//Adds node
TriviaListPtr addNode(string theQuestion, string theAnswer, int thePoints, TriviaListPtr theLink) {
   TriviaListPtr head = new TriviaList(theQuestion, theAnswer, thePoints, theLink);
   return head;
}

//Plays quiz and iterates through the amount of questions
int quizPlayer(TriviaListPtr list, int numOfQuestions) {
   if (numOfQuestions <= 0) 
   {
      cout << "Warning - the number of trivia to be asked must equal to or larger than 1.\n";
      return 1;
   }
   else if (list == NULL) 
   {
      cout << "Warning - an empty list is not a valid trivia list\n";
      return 1;
   }
   else 
   {
      TriviaListPtr head = list;
      TriviaListPtr next = head->getLink();
      int size = 1;
      while (next != NULL) 
      {
         next = next->getLink();
         size++;
      }
      if (size < numOfQuestions) 
      {
         cout << "Warning - There is only " << size << " trivia in the list\n";
         return 1; 
      }
      else 
      {
         next = head;
         string answer;
         int index = 0;
         while (next != NULL && index < numOfQuestions)
         {
            cout << "Question: " << next->getQuestion() << endl;
            cout << "Answer: ";
            getline(cin, answer);
            if (answer == "") 
            {
               getline(cin, answer);
            }
            if (answer == next->getAnswer())
            {
               cout << "Your answer is correct! You receive " << next->getPoints() << " points.\n";
               totalPoints += next->getPoints();
            }
            else 
            {
               cout << "Your answer is wrong. The correct answer is " << next->getAnswer() << endl;
            }
            cout << "Your total points: " << totalPoints << "\n\n";
            next = next->getLink();
            index++;
         }
         return 0;
      }
   }
}   

//Makes trivia nodes off user input
TriviaListPtr getTrivia(TriviaListPtr list) {
   TriviaListPtr head = list;
   string question;
   string answer;
   int points;
   cout << "Enter a question: ";
   getline(cin, question);
   cout << "Enter an answer: ";
   getline(cin, answer);
   cout << "Enter award points: ";
   while (!(cin >> points) || points <= 0) {
      cout << "Points must be a number greater than 0. Try again: ";
      cin.clear();
      cin.ignore(1000, '\n');
   }
   head = addNode(question, answer, points, head);
   cin.clear();
   cin.ignore(1000, '\n');
   return head;
}

//Test functions

void test_initList() {
   TriviaListPtr head = initList();
   cout << "Test for initList():\n";
   assert("How long was the shortest war on record? (Hint: how many minutes)" == head->getQuestion());
   assert("38" == head->getAnswer());
   assert(100 == head->getPoints());
   cout << "\tTrivia 1 matches\n";
   TriviaListPtr next = head->getLink();
   assert("What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)" == next->getQuestion());
   assert("Bank of Italy" == next->getAnswer());
   assert(50 == next->getPoints());
   cout << "\tTrivia 2 matches\n";
   next = next->getLink();
   assert("What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)" == next->getQuestion());
   assert("Wii Sports" == next->getAnswer());
   assert(20 == next->getPoints());
   assert(NULL == next->getLink());
   cout << "\tTrivia 3 matches\n";
}

void test_addNode() {
   cout <<"Test for addNode()\n";
   TriviaListPtr head = NULL;
   head = addNode("test", "test", 5, head);
   assert("test" == head->getQuestion());
   assert("test" == head->getAnswer());
   assert(5 == head->getPoints());
   assert(NULL == head->getLink());
   cout << "\tTest 1: Empty/new list passed\n";
   head = addNode("test2", "test2", 20, head);
   assert("test2" == head->getQuestion());
   assert("test2" == head->getAnswer());
   assert(20 == head->getPoints());
   TriviaListPtr next = head->getLink();
   assert("test" == next->getQuestion());
   assert("test" == next->getAnswer());
   assert(5 == next->getPoints());
   assert(NULL == next->getLink());
   cout << "\tTest 2: Add to existing list passed\n";
}

//Definition of test driver for test_quizPlayer
//This is the driver required in Step 6 of the outline.
void test_quizPlayer() {
	//Create a list of the 3 questions. initList has already been tested to show it works.
   TriviaListPtr list = initList();
   int test;
   cout << "*** This is a debugging version ***\n";
	
	//Case 1: No questions
   cout << "Unit test Case 1: Ask no questions. The program should give a warning message.\n";
   test = quizPlayer(list, 0);
   cout << "Case 1 Passed\n";
	
	//Case 2.1: Ask 1 question, give incorrect answer.
   cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. the tester enters an incorrect answer.\n";
   test = quizPlayer(list, 1);
   assert(0 == totalPoints);
   cout << "Case 2.1 Passed\n";
	
	//Case 2.2: Ask 1 question, give correct answer.
   cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.\n";
   test = quizPlayer(list, 1);
   assert(100 == totalPoints);
   cout << "Case 2.2 Passed\n";
	
	//Case 3.1 Ask 3 questions, give incorrect answers.
   totalPoints = 0; //Reset points
   cout << "\nUnit Test Case 3: Asks all the questions of the last trivia in the linked list.\n";
   test = quizPlayer(list, 3);
   assert(0 == test);
   cout << "Case 3 Passed\n";
	
	//Case 4: Ask too many questions
   cout << "\nTest Case 4: Ask 5 questions. The program should give a warning\n";
   test = quizPlayer(list, 5);
   cout << "Case 4 Passed\n";
	
   cout<<"\n*** End of Debugging Version ***";
}

//Test driver for getTrivia
void test_getTrivia() {
   cout << "Test for getTrivia. Please input the following when prompted\nQuestion: How old are you?\nAnswer: 20\nPoints: 100\n";
   TriviaListPtr head = NULL;
   head = getTrivia(head);
   assert("How old are you?" == head->getQuestion());
   assert("20" == head->getAnswer());
   assert(100 == head->getPoints());
   cout << "Test passed\n";
}



