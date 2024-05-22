#include <iostream>
#include "Date.h"






int main()
{
    std::string date_line;
    std::cout << "enter date: ";
    std::getline(std::cin, date_line);

    try
    {   
        date d(date_line);
        d.print();
        //throw date_exception(5, 13, 2024);
        //throw std::runtime_error("main() runtime error");
        //throw std::exception("my_exception");
        //throw 1;
    }

    catch(date_exception& e)
    {
        std::cout << e.what() << "\n";
        e.invalide_date();
    }
    catch(std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
    catch(...)
    {
        std::cout << "catch global exception\n";
    }
    




}
