#ifndef TYPES
#define TYPES

namespace qlm
{
    enum class Choice
    {
        COOPERATE,
        DEFECT
    };

    struct Properties
    {
        bool niceness; // 1 -> nice (not the first to defect), 0 -> nasty (defects first)
        bool provocability;
        bool forgiveness;
        bool clarity;
    };

    struct PayOff
    {
        int cooperate_cooperate = 3;
        int cooperate_defect = 0;
        int defect_cooperate = 5;
        int defect_defect = 1;
    };
    
}

#endif