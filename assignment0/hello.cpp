#include <iostream>

using namespace std;
int main(int argc, char* argv[]) {

	//Error if no arguments detected
	if(argc == 1)
	{	
		cerr << "Incorrect output" << endl;
	}
	//If arguments are detected
	else
	{


	cout << "Hello ";

	//For loop displaying all arguments in order
	//i represents argument count placeholder
	for(int i = 1; argc > i; i++)
	{
		cout << argv[i];
	}
	
	cout << ", Welcome to CS311!" << endl;
	}
}
