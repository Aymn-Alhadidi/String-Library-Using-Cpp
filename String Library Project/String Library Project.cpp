#include <iostream>
#include"clsString.h";

using namespace std;




int main()
{
	clsString String2("Aymn, Ibrahim! Khalil.");


	//cout << String2.ReverseWordInString();
	//cout << endl << clsString::InvertCharcter('l');

	String2.RemovePunctuation();
	cout << clsString::TrimLeft("Aymn!!!!! ibrahim ..khalil/");



	system("pause>0");

}



