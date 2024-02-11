#include "strategies.hpp"
#include <cmath>

namespace qlm
{
    // constructor
    FirstByNydegger::FirstByNydegger(const PayOff& pay_off) : Strategy(pay_off), arr{1, 6, 7, 17, 22, 23, 26, 29, 30, 31, 33, 38, 39, 45, 49, 54, 55, 58, 61}
    {
        name = "First by nydegger";
        info = "The program begins with tit for tat for the first three moves, \
                except > that if it was the only one to cooperate on the first move \
                and the only one > to defect on the second move, it defects on the third move. \
                After the third > move, its choice is determined from the 3 preceding outcomes \
                in the > following manner. Let A be the sum formed by counting the other’s defection > as 2 points \
                and one’s own as 1 point, and giving weights of 16, 4, and 1 to > the preceding three moves \
                in chronological order. The choice can be > described as defecting only when \
                A equals 1, 6, 7, 17, 22, 23, 26, 29, 30, > 31, 33, 38, 39, 45, 49, 54, 55, 58, or 61. \
                Thus if all three preceding moves > are mutual defection, A = 63 and the rule cooperates. \
                This rule was > designed for use in laboratory experiments as a stooge which had a memory > \
                and appeared to be trustworthy, potentially cooperative, but not gullible > (Nydegger, 1978).";
        probabilistic_action = false;
        properties.niceness = 1;
    }

    // First action function
    Choice FirstByNydegger::FirstAction()
    {
        my_history.push_back(Choice::COOPERATE);
        return Choice::COOPERATE;
    }

    // Action function
    Choice FirstByNydegger::Action(const Choice opponent_play)
    {
        Choice action;
        const int round =  my_history.size() + 1;

        if (round < 4)
        {
            if ((round == 3) &&
                (my_history[0] == Choice::COOPERATE && opponent_history[0] == Choice::DEFECT) && 
                (my_history[1] == Choice::DEFECT && opponent_history[0] == Choice::COOPERATE))
            {
                
                action = Choice::DEFECT;
            }   
            else
            {
                action = opponent_play;
            }
        }
        else
        {
            auto get_score = [] (const Choice my_a, const Choice opp_a)
            {
                int score {0};

                if (my_a == Choice::DEFECT && opp_a == Choice::DEFECT)
                {
                    score = 3;
                }
                else if (my_a == Choice::COOPERATE && opp_a == Choice::DEFECT)
                {
                    score = 2;
                }
                else if (my_a == Choice::DEFECT && opp_a == Choice::COOPERATE)
                {
                    score = 1;
                }
                else
                {
                    score = 0;
                }

                return score;
            };

            const int a1 = get_score(my_history[my_history.size() - 1], opponent_play);
            const int a2 = get_score(my_history[my_history.size() - 2], opponent_history[opponent_history.size() - 1]);
            const int a3 = get_score(my_history[my_history.size() - 3], opponent_history[opponent_history.size() - 2]);

            const int outcome = 16 * a1 + 4 * a2 + a3;
          
            action = Choice::COOPERATE;

            for (int i = 0; i < 19; i++)
            {
                if (outcome == arr[i])
                {
                    action = Choice::DEFECT;
                    break;
                }
            }

        }

        // update history
        UpdateHistory(action, opponent_play);  
              
        return action;
    }

    // rest function
    void FirstByNydegger::Reset()
    {
        Strategy::Reset();
        flags.reset();
    }

}