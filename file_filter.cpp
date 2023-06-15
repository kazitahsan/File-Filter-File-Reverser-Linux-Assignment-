#include <iostream>
#include <fstream>
#include <queue>
#include <cctype>

using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	string a;
	
	inFile.open ("input.txt"); // opening the file
	queue < char > myQueue;
	
	if(inFile.fail()) // check if file can be opened or not
	cout << "Couldn't open input file!" << endl;
	
	else
	{
		outFile.open ("output_filter.txt"); // opening and then checking if Outfile can be accessed
		if (!outFile)
		{
			cout << "Couldn't open output file!" << endl;
			return -1;
		}
		while (!inFile.eof())
		{
			getline (inFile, a);
			for (size_t i=0; i<a.length(); i++ ) //looping to insert each character in myQueue
			myQueue.push(a[i]);
		}
		
		while(!myQueue.empty()) // looping until each character is converted to uppercase
		{
			outFile << (char)toupper(myQueue.front()); // converting first character to uppercase
			myQueue.pop(); // removing the first character
		}
		
		inFile.close(); // Closing the files
		outFile.close();
	}
	
	return 0;
}


