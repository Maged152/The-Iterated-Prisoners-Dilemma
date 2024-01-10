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
}

#endif