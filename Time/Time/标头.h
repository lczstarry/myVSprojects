#include<iostream>
using namespace std;
class Time
{
public:
	Time(){}
	Time(int h, int m, int s)
	{
		hour = h;
		minute = m;
		second = s;
	}


	friend Time operator +(Time & t, int s);
	Time operator -(int s);
	friend ostream& operator <<(ostream& out, const Time&t);
	Time& operator ++();
	Time& operator --();


private:
	int hour;
	int minute;
	int second;
};
Time operator+(Time & t, int s)
{
	int S;
	S = t.second + s;
	if (S < 60)
	{
		t.second = S;
	}
	if (S >= 60)
	{
		t.minute=t.minute+S/60;
		t.second = S -(S/60)*60;
		if (t.minute >= 60)
		{
			t.hour=t.hour+t.minute/60;
			t.minute = t.minute -(t.minute/60)* 60;
			if (t.hour >= 24)
			{
				t.hour = t.hour - (t.hour / 24) * 24;
			}
		}

	}
	return t;
}
Time Time::operator-(int s)
{
	
	second = second - s;
	if (second< 0)
	{
		minute = minute - (second / 60);
		second = (second / 60) * 60 - second;
		if (minute < 0)
		{
			hour = hour - minute / 60;
			minute = (minute / 60) * 60 - minute;
			if (hour <0)
			{
				hour = (hour / 24) * 24 - hour;
			}
		}
	}

	return Time();

}
ostream& operator <<(ostream& out, const Time&t)
{
	out << t.hour << ":" << t.minute << ":" << t.second << endl;
	return out;
}
Time& Time::operator ++()
{
	second++;
	if (second > 59)
	{
		minute++;
		second = 0;
		if (minute > 59)
		{
			hour++;
			minute = 0;
			if (hour > 23)
				hour = 0;
		}
	}
	return *this;

}
Time& Time::operator --()
{
	second--;
	if (second <0)
	{
		minute--;
		second = 59;
		if (minute <0)
		{
			hour--;
			minute = 59;
			if (hour <0)
				hour = 23;
		}
	}
	return *this;
}