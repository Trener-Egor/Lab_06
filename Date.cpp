#include "Date.h"
#include<iostream>


date_exception::date_exception(const std::string& error_string)
	: std::out_of_range(msg_)
	, day_(-1)
	, month_(-1)
	, year_(-1)
{
	msg_ += " - " + error_string;
}
date_exception::date_exception(int day, int month, int year)
	: std::out_of_range(msg_)
	, day_(day) 
	, month_(month)
	, year_(year)
{

}
date_exception::date_exception(int day, int month, int year, const char* msg)
	: std::out_of_range(msg)
	, msg_  (msg)
	, day_  (day)
	, month_(month)
	, year_ (year)
{

}

//const char* date_exception::what() const noexcept 
//{
//	return msg_.empty() ? "default date_exception" :msg_.c_str();
//}

void date_exception::invalide_date() const noexcept
{
	std::cout << "Invalide date: " << (int)day_ << " " << (int)month_ << " " << (int)day_ << "\n";
}

/*
* date(" 23");
* throw date_exception(d)
*/

date::date(const std::string& line)
{
	//dd mm yyyy
	int day;
	int month;
	int year;
	int slen = line.size();
	int i = 0;
	int start = -1;
	int end = -1;

	while (i < slen)
	{
		if (line[i] != ' ' && start == -1)
		{
			start = i;
		}
		else if (line[i] == ' ' && start != -1)
		{
			end = i - 1;
			break;
		}
		i++;
	}
	if(start == -1 || end == -1)
	{
		throw date_exception(line);
	}
	std::string word = std::string(line.begin() + start, line.begin() + end);

	//for (int i = 0;i<word.size();i++)
	for (char c : word)
	{
		if (std::isdigit(c) == false)
		{
			throw date_exception(line);
		}
	}
	day = std::stoi(word);
	//
	day_ = day;
}
void date::print()const noexcept
{
	std::cout << "Date:\n";
	std::cout << "Day:   " << day_   << "\n";
	std::cout << "Month: " << month_ << "\n";
	std::cout << "Year:  " << year_  << "\n";
}
