#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	string a;
	
	inFile.open ("input.txt"); // opening the file
	stack < char > myStack;
	
	if(!inFile) // check if file can be accessed or not 
	
	cout << "Couldn't open input file!" << endl; 
	
	else
	{
		outFile.open ("output_reverse.txt");
		if(!outFile)
		{
			cout << "Couldn't open output file!" << endl;
			return -1;
		}
		while (!inFile.eof())
		{
			getline (inFile, a);
			for (size_t i=0; i<a.length(); i++)
			myStack.push(a[i]);
		}
		
		 while (!myStack.empty())
		 {
		    outFile << myStack.top(); //top character will be stored at OutFile
		    myStack.pop(); // removing the top character
		 }
		 
		 inFile.close(); // closing the files
		 outFile.close();
	}
	   return 0;	
}
