#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;



//set 1

void printRecForward(id *cu)
    {
        if (cu == nullptr)
            return;

        cout << cu->number << endl;
        printRecForward(cu->next);
    }


  void print_guilty(id* current, ofstream& output, bool printed){
    if(current == NULL){
      return;
    }
    else if(!current->is_innocent){
      if(printed){
         output << "Guilty: " << endl;
        printed = false;
      }
      output <<current->number << endl;
    }
    print_guilty(current->next, output, printed);
  }


  void print_innocent(id* current, ofstream& output, bool printed){
    
    if(current == NULL){
      return;
    }
    else if(current->is_innocent){
      if(printed){
         output << "Innocent: " << endl;
        printed = false;
      }
      output << current->number << endl;
    }
    print_innocent(current->next, output, printed);
  }



//set 2

void bar::print(node * head) //prints all of the items
{
  if(head == nullptr) return; //if no items dont print

  if(head -> next != nullptr)
  {
    cout << head -> val << endl; //gives us the string value of each item
    print(head -> next); //recursive call to keep going
  }
  else
    cout << head -> val << endl; // gives us last item in the list
} 






//set 3

// Recursive function to print guilty IDs in ascending order
    void printGuiltyRecursive(Node* curr) {
        if (curr == nullptr)
            return;
        if (curr->count > 1)
            cout << curr->id << endl;
        printGuiltyRecursive(curr->next);
    }

    // Recursive function to print innocent IDs in ascending order
    void printInnocentRecursive(Node* curr) {
        if (curr == nullptr)
            return;
        if (curr->count == 1)
            cout << curr->id << endl;
        printInnocentRecursive(curr->next);
    }



//set 4  does printing need to be recursive??


ofstream outputFile("output1.txt");
    outputFile << "Guilty:" << endl;
    for (string guiltyID : guiltyIDs) {
        outputFile << guiltyID << endl;
    }
    outputFile << "Innocent:" << endl;
    for (string innocentID : innocentIDs) {
        outputFile << innocentID << endl;
    }
    outputFile.close();

    return 0;















//set 5



void print ()
{
	if (guiltyCount > 0) //have variable to count number of guilty ID's
	{
		output << "Guilty:" << \n << //print guilty id's separated by new lines. for loop?
	}
	if (innocentCount > 0) //have variable to count number of innocent ID's
	{
		output << "Innocent:" << \n << //print innocent id's separated by new lines. for loop?
	}
}

/* string decodeID(string encodedID) {
    int start = -1, end = -1;
    for (int i = 0; i < encodedID.length(); i++) {
        if (encodedID[i] == '(') {
            start = i;
        } else if (encodedID[i] == ')') {
            end = i;
            reverse(encodedID.begin() + start + 1, encodedID.begin() + end);
            start = -1;
            end = -1;
        }
    }
    reverse(encodedID.begin(), encodedID.end());
    return encodedID;
} */

int main(int argc, char* argv[])
{
 /* ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output")); */

	ifstream input ("input1.txt");
  ofstream output ("output1.txt");
	
	//if guilty
	//print :: 
	//"Guilty:"
	//guilty id's separated by \n
	//if innocent
	//print ::
	//"Innocent:"
	//innocent id's separated by \n

	map<string, int> IDs;
  vector<string> guiltyIDs, innocentIDs;

  string bar, encodedID;
  while (input >> bar) 
	{
    if (bar == "Bar1" || bar == "Bar2") 
		{
      while (input >> encodedID && encodedID[0] != 'B') 
			{
        string decodedID = decodeID(encodedID);
        IDs[decodedID]++;
      }
    }
  }
  input.close();

  for (auto &id : IDs) 
	{
    if (id.second > 1) 
		{
      guiltyIDs.push_back(id.first);
    } 
		else 
		{
      innocentIDs.push_back(id.first);
    }
  }

  sort(guiltyIDs.begin(), guiltyIDs.end());
  sort(innocentIDs.begin(), innocentIDs.end());

  output << "Guilty:" << endl;
  for (auto &id : guiltyIDs) 
	{
    output << id << endl;
  }
  output << "Innocent:" << endl;
  for (auto &id : innocentIDs) 
	{
    output << id << endl;
  }
  output.close();

  return 0;
}