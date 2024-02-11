#ifndef HELPER
#define HELPER


#include "types.hpp"
#include <iostream>
#include <fstream>
namespace qlm
{
    inline std::ostream & operator << (std::ostream &out, const Choice &choice)
    {
        if (choice == Choice::COOPERATE)
        {
            out << "COOPERATE";
        }
        else
        {
            out << "DEFECT";
        }
        
        return out;
    }

    inline std::ofstream& operator<<(std::ofstream& os, const Choice &choice)
    {
        if (choice == Choice::COOPERATE)
        {
            os << "COOPERATE";
        }
        else
        {
            os << "DEFECT";
        }
        
        return os;
    }
}

#endif