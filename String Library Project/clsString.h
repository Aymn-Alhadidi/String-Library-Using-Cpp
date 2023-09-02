#pragma once

#include <iostream>
#include<vector>;

using namespace std;

class clsString
{
private:
	string _Value;


public:

	enum enWhatToCount { SamllLetter = 0, CapitalLetters = 1, All = 2 };

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void setValue(string vlaue)
	{
		_Value = vlaue;
	}
	string getValue()
	{
		return _Value;
	}

	__declspec(property(get = getValue, put = setValue)) string Value;

	static short CountWordInString(string Text)
	{

		string delim = " ";
		short Counter = 0;
		short Pos = 0;
		string sWord;

		while ((Pos = Text.find(delim)) != std::string::npos)
		{
			sWord = Text.substr(0, Pos); // Store the word

			if (sWord != "")
			{
				Counter++;
			}

			Text.erase(0, Pos + delim.length());
		}

		if (Text != "")
			Counter++;

		return Counter;
	}
	short CountWordInString()
	{
		return CountWordInString(_Value);
	}

	static void PrintFirstLetterOfEachWord(string Text)
	{
		bool IsFirstLetter = true;

		cout << "\nFirst Letter Of This String Is: \n\n";
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && IsFirstLetter)
			{
				cout << Text[i] << endl;
			}

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}
	}
	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string Text)
	{
		bool IsFirstLetter = true;

		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && IsFirstLetter)
			{
				Text[i] = toupper(Text[i]);
			}

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}

		return Text;
	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string Text)
	{
		bool IsFirstLetter = true;

		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && IsFirstLetter)
			{
				Text[i] = tolower(Text[i]);
			}

			IsFirstLetter = (Text[i] == ' ' ? true : false);
		}

		return Text;
	}
	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string LowerAllLetters(string Text)
	{

		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = tolower(Text[i]);
		}

		return Text;
	}
	void LowerAllLetters()
	{
		_Value = LowerAllLetters(_Value);
	}

	static string UpperAllLetters(string Text)
	{

		for (short i = 0; i < Text.length(); i++)
		{
			Text[i] = toupper(Text[i]);
		}

		return Text;
	}
	void UpperAllLetters()
	{
		_Value = UpperAllLetters(_Value);
	}

	static char InvertCharcter(char Letter)
	{
		return isupper(Letter) ? tolower(Letter) : toupper(Letter);
	}

	static string InvertAllLetterCase(string Text)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = InvertCharcter(Text[i]);
		}

		return Text;
	}
	void InvertAllLetterCase()
	{
		_Value = InvertAllLetterCase(_Value);
	}

	static int CounterLetter(string Text, enWhatToCount WhatToCount = All)
	{
		if (WhatToCount == enWhatToCount::All)
			return Text.length();

		int Counter = 0;

		for (int i = 0; i < Text.length(); i++)
		{
			if (enWhatToCount::CapitalLetters == WhatToCount && isupper(Text[i]))
				Counter++;

			else if (enWhatToCount::SamllLetter == WhatToCount && islower(Text[i]))
				Counter++;
		}

		return Counter;
	}
	int CounterLetter(enWhatToCount WhatToCount = All)
	{
		return CounterLetter(_Value, WhatToCount);
	}

	static short CountSpecificLetter(string Text, char Letter)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] == Letter)
				Counter++;
		}

		return Counter;
	}
	short CountSpecificLetter(char Letter)
	{
		return CountSpecificLetter(_Value, Letter);
	}

	static short CountLetter_MatchCase(string Text, char Letter, bool MatchCase = true)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (MatchCase)
			{
				if (Text[i] == Letter)
					Counter++;
			}

			else
			{
				if (tolower(Text[i]) == tolower(Letter))
					Counter++;
			}
		}

		return Counter;
	}
	short CountLetter_MatchCase(char Letter, bool MatchCase = true)
	{
		return CountLetter_MatchCase(_Value, Letter, MatchCase);
	}

	static bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);

		return ((Letter == 'a') || (Letter == 'i') || (Letter == 'e') || (Letter == 'o') || (Letter == 'u'));
	}

	static short CountVowel(string Text)
	{
		short Counter = 0;

		for (short i = 0; i < Text.length(); i++)
		{
			if (IsVowel(Text[i]))
				Counter++;
		}

		return Counter;
	}
	short CountVowel()
	{
		return CountVowel(_Value);
	}

	static void PrintAllVowel(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (IsVowel(Text[i]))
				cout << Text[i] << "   ";
		}
	}
	void PrintAllVowel()
	{
		return PrintAllVowel(_Value);
	}

	static void PrintEachWordInString(string Text)
	{

		string delim = " ";

		cout << "\nYour string words Position are: \n\n";
		short Pos = 0;
		string sWord;

		while ((Pos = Text.find(delim)) != std::string::npos)
		{
			sWord = Text.substr(0, Pos); // Store the word

			if (sWord != "")
			{
				cout << sWord << endl;
			}

			Text.erase(0, Pos + delim.length());
		}

		if (Text != "")
			cout << Text << endl;
	}
	void PrintEachWordInString()
	{
		return  PrintEachWordInString(_Value);
	}

	static vector <string> Split(string Text, string delim)
	{
		vector<string> vString;

		short Pos = 0;
		string sWord;

		while ((Pos = Text.find(delim)) != std::string::npos)
		{
			sWord = Text.substr(0, Pos); // Store the word


			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			Text.erase(0, Pos + delim.length());
		}

		if (Text != "")
			vString.push_back(Text);

		return vString;
	}
	vector <string> Split(string delim)
	{
		return Split(_Value, delim);
	}

	static string TrimLeft(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ')
				return Text.substr(i, Text.length() - i);
		}

		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string Text)
	{


		for (int i = Text.length() - 1; i >= 0; i--)
		{

			if (Text[i] != ' ')
				return Text.substr(0, i + 1);

		}

		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string Text)
	{

		return TrimRight(TrimLeft(Text));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string> Words, string delim)
	{
		string s1 = "";
		for (string& s : Words)
		{
			s1 = s1 + s + delim;
		}

		return s1.substr(0, s1.length() - delim.length());
	}
	static string JoinString(string arrWords[], short Length, string delim)
	{
		string s1 = "";
		for (short i = 0; i < Length; i++)
		{
			s1 = s1 + arrWords[i] + delim;
		}

		return s1.substr(0, s1.length() - delim.length());
	}

	static string ReverseWordInString(string s1)
	{
		vector<string> vSplitWords = Split(s1, " ");
		string s2 = "";

		vector<string>::iterator iter = vSplitWords.end();

		while (iter != vSplitWords.begin())
		{
			--iter;
			s2 += *iter + " ";

		}

		return s2.substr(0, s2.length() - 1);

	}
	void ReverseWordInString()
	{
		_Value = ReverseWordInString(_Value);
	}

	static string ReplaceWordInString(string s1, string WordToReplace, string ReplaceTo)
	{
		short Pos = s1.find(WordToReplace);

		while (Pos != std::string::npos)
		{
			s1.replace(Pos, WordToReplace.length(), ReplaceTo);
			Pos = s1.find(WordToReplace);
		}

		return s1;
	}
	void ReplaceWordInString(string WordToReplace, string ReplaceTo)
	{
		_Value = ReplaceWordInString(_Value, WordToReplace, ReplaceTo);
	}

	static string ReplaceWordInString_MatchCase(string Text, string WordToReplace, string ReplaceTo, bool MatchCase = true)
	{
		vector <string> vWords = Split(Text, " ");
		string s1 = "";

		for (string& s : vWords)
		{
			if (MatchCase)
			{
				if (s == WordToReplace)
					s = ReplaceTo;
			}

			else
			{
				if (LowerAllLetters(s) == LowerAllLetters(WordToReplace))
				{
					s = ReplaceTo;
				}
			}
		}

		return JoinString(vWords, " ");
	}
	void ReplaceWordInString_MatchCase(string WordToReplace, string ReplaceTo, bool MatchCase = true)
	{
		_Value = ReplaceWordInString_MatchCase(_Value, WordToReplace, ReplaceTo, MatchCase);
	}

	static string RemovePunctuation(string s1)
	{
		string s2 = "";
		for (short i = 0; i < s1.length(); i++)
		{
			if (!ispunct(s1[i]))
				s2 += s1[i];
		}
		return s2;
	}
	void RemovePunctuation()
	{
		_Value = RemovePunctuation(_Value);
	}

};

