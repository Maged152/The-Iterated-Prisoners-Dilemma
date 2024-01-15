#ifndef HELPER
#define HELPER


#include "types.hpp"
#include <iostream>

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
}

#endif