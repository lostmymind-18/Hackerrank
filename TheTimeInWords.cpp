#include<iostream>
#include<string>

using namespace std;

string timeInWords(int h, int m)
{
	string timeInWords = "";
	string hour;
	string min;
	//convert Hour to Word
	if (m > 30)
	{
		if (h != 12) h++;
		else h = 1;
	}
	switch (h){
	case 1: 
		hour = "one";
		break;
	case 2: 
		hour = "two";
		break;
	case 3:
		hour = "three";
		break;
	case 4:
		hour = "four";
		break;
	case 5:
		hour = "five";
		break;
	case 6:
		hour = "six";
		break;
	case 7:
		hour = "seven";
		break;
	case 8:
		hour = "eight";
		break;
	case 9:
		hour = "nine";
		break;
	case 10:
		hour = "ten";
		break;
	case 11:
		hour = "eleven";
		break;
	case 12:
		hour = "twelve";
		break;
	default: break;
	}
	switch (m) {
	case 00:
		min = "o' clock";
		break;
	case 01:
		min = "one minute past";
		break;
	case 02:
		min = "two minutes past";
		break;
	case 03:
		min = "three minutes past";
		break;
	case 04:
		min = "four minutes past";
		break;
	case 05: 
		min = "five minutes past";
		break;
	case 06:
		min = "six minutes past";
		break;
	case 07:
		min = "seven minutes past";
		break;
	case 8:
		min = "eight minutes past";
		break;
	case 9:
		min = "nine minutes past";
		break;
	case 10:
		min = "ten minutes past";
		break;
	case 11:
		min = "eleven minutes past";
		break;
	case 12:
		min = "twelve minutes past";
		break;
	case 13:
		min = "thirteen minutes past";
		break;
	case 14:
		min = "fourteen minutes past";
		break;
	case 15:
		min = "quarter past";
		break;
	case 16:
		min = "sixteen minutes past";
		break;
	case 17:
		min = "seventeen minutes past";
		break;
	case 18:
		min = "eighteen minutes past";
		break;
	case 19:
		min = "nineteen minutes past";
		break;
	case 20:
		min = "twenty minutes past";
		break;
	case 21:
		min = "twenty one minutes past";
		break;
	case 22:
		min = "twenty two minutes past";
		break;
	case 23:
		min = "twenty three minutes past";
		break;
	case 24:
		min = "twenty four minutes past";
		break;
	case 25:
		min = "twenty five minutes past";
		break;
	case 26:
		min = "twenty six minutes past";
		break;
	case 27:
		min = "twenty seven minutes past";
		break;
	case 28:
		min = "twenty eight minutes past";
		break;
	case 29:
		min = "twenty nine minutes past";
		break;
	case 30:
		min = "half past";
		break;
	case 31:
		min = "twenty nine minutes to";
		break;
	case 32:
		min = "twenty eight minutes to";
		break;
	case 33:
		min = "twenty seven minutes to";
		break;
	case 34: 
		min = "twenty six minutes to";
		break;
	case 35:
		min = "twenty five minutes to";
		break;
	case 36:
		min = "twenty four minutes to";
		break;
	case 37:
		min = "twenty three minutes to";
		break;
	case 38:
		min = "twenty two minutes to";
		break;
	case 39:
		min = "twenty one minutes to";
		break;
	case 40:
		min = "twenty minutes to";
		break;
	case 41:
		min = "nineteen minutes to";
		break;
	case 42:
		min = "eighteen minutes to";
		break;
	case 43:
		min = "seventeen minutes to";
		break;
	case 44:
		min = "sixteen minutes to";
		break;
	case 45:
		min = "quarter to";
		break;
	case 46:
		min = "fourteen minutes to";
		break;
	case 47:
		min = "thirteen minutes to";
		break;
	case 48:
		min = "twelve minutes to";
		break;
	case 49:
		min = "eleven minutes to";
		break;
	case 50:
		min = "ten minutes to";
		break;
	case 51:
		min = "nine minutes to";
		break;
	case 52:
		min = "eight minutes to";
		break;
	case 53:
		min = "seven minutes to";
		break;
	case 54:
		min = "six minutes to";
		break;
	case 55:
		min = "five minutes to";
		break;
	case 56:
		min = "four minutes to";
		break;
	case 57:
		min = "three minutes to";
		break;
	case 58:
		min = "two minutes to";
		break;
	case 59:
		min = "one minutes to";
	}
	if (m == 0)
		timeInWords = hour + " " + min;
	else
		timeInWords = min + " " + hour;
	return timeInWords;
}
int main()
{
	int m, h;
	char loop = 'y';
	while (loop != 'n')
	{
		cout << "Enter hour: "; cin >> h;
		cout << "Enter minute: "; cin >> m;
		cout << timeInWords(h, m) << endl;
		cout << "Keep test? y/n";
		cin >> loop;
	}
}