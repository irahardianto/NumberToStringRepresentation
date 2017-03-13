#include <iostream>
#include <string>

using namespace std;

enum Language { English, Indonesia };

struct NUMBER
{
	string Unit[19];
	string Tens[8];
	string HighNumbers[2];
};

NUMBER numbers[2] = 
	{ 
		{ 
			{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "ninteen" }, 
			{ "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" }, 
			{ "hundred", "thousand" } 
		},
		{
			{ "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas" },
			{ "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh" },
			{ "ratus", "ribu" }
		}
	};

string IntToText(int i, Language lang)
{
	if (i < 0 || i > 10000)
	{
		return "Number is beyond desired calculation";
	}

	if (i == 0)
	{
		return "Zero";
	}
	else if (i <= 19)
	{
		return numbers[lang].Unit[i - 1];
	}
	else if (i <= 99)
	{
		return numbers[lang].Tens[i / 10 - 2] + "-" + IntToText(i % 10, lang);
	}
	else if (i <= 999)
	{
		string returnValue = "";

		if (lang == Indonesia && i <= 199)
		{
			returnValue = "Seratus " + IntToText(i % 100, lang);
		} 
		else
		{
			returnValue = numbers[lang].Unit[i / 100 - 1] + " " + numbers[lang].HighNumbers[0] + " " + IntToText(i % 100, lang);
		}

		return returnValue;
	}
	else if (i <= 9999)
	{
		string returnValue = "";

		if (lang == Indonesia && i <= 1999)
		{
			returnValue = "Seribu " + IntToText(i % 1000, lang);
		}
		else
		{
			returnValue = numbers[lang].Unit[i / 1000 - 1] + " " + numbers[lang].HighNumbers[1] + " " + IntToText(i % 1000, lang);
		}

		return returnValue;
	}
	else
	{
		"Number is beyond desired calculation";
	}
}

void main()
{
	int inputNumber = 0;

	cout << "Enter your desired number : ";
	cin >> inputNumber;

	cout << IntToText(inputNumber, English) << "\n";

	system("pause");
}