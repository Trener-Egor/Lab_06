#pragma once
#include <string>
#include <exception>
#include <stdexcept>


class date_exception : public std::out_of_range
{	
public:
	date_exception(const std::string& error_string);
	date_exception(int day, int month, int year);
	date_exception(int day, int month, int year, const char* msg);

	//virtual const char* what() const noexcept;//
	//const char*  what() const noexcept override;
	virtual void invalide_date() const noexcept;

private:
	//const char* msg_ = "invalide date format";
	std::string msg_ = "invalide date format";
	int     day_;
	int     month_;
	int    year_;
};



class date
{
public:
	date(const std::string&);
	void print()const noexcept;
private:
	int     day_;
	int     month_;
	int     year_;
};