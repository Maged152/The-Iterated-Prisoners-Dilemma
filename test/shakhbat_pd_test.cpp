#include "shakhbat_pd_test.hpp"
#include <random>
namespace test
{
    void FillStrategies()
    {
        ADD_STRATEGY(qlm::Cooperator);
        ADD_STRATEGY(qlm::TitForTat);
        ADD_STRATEGY(qlm::Grudger);
        ADD_STRATEGY(qlm::Defector);
        ADD_STRATEGY(qlm::FirstByDavis);
        ADD_STRATEGY(qlm::FirstByGrofman);
        ADD_STRATEGY(qlm::FirstByJoss);
        ADD_STRATEGY(qlm::FirstByShubik);
        ADD_STRATEGY(qlm::FirstByFeld);
        ADD_STRATEGY(qlm::FirstByTullock);
        ADD_STRATEGY(qlm::FirstByNydegger);
        ADD_STRATEGY(qlm::FirstByDowning);
        ADD_STRATEGY(qlm::Random);
    }

    bool Test_IPD(const int num_rounds = 200)
    {
        bool status = true;
        // fill the vector
        FillStrategies();

        // open the file
		std::fstream file;
		file.open("python_results.txt", std::ios::in);

		if (!file.is_open())
		{
            std::cout << "File python_results.txt is not found\n";
			return false;
		}

        // used for reading and parsing the text
        const char sep = ';';

        // loop over the strategies
        for (int st_0 = 0; st_0 < strategy_list0.size(); st_0++)
        {
            for (int st_1 = st_0; st_1 < strategy_list0.size(); st_1++)
            {
                // run shakhbat_pd library 
                auto match = qlm::Match(*strategy_list0[st_0], *strategy_list1[st_1], num_rounds);
                // match info
                auto winner = match.Winner().first == "DRAW"? "False" : match.Winner().first;
                auto player_0_score = match.GetPlayer0Score();
                auto player_1_score = match.GetPlayer1Score();
                auto player_0_actions = match.GetPlayer0History();
                auto player_1_actions = match.GetPlayer1History();

                std::vector<std::string> lib_header_res {winner, std::to_string(match.GetPlayer0Score()), std::to_string(match.GetPlayer1Score())};

                // read python results
                // read first line  (winner, score_0, score_1)
                std::string line_header, line_actions;
                if (!std::getline(file, line_header))
                {
                    std::cout << "File python_results.txt is empty\n";
                    file.close();
			        return false;
                }

                std::stringstream ss_header(line_header);
                std::string token;
                std::vector<std::string> py_header_res;
                while (std::getline(ss_header, token, sep)) 
                {
                    py_header_res.push_back(token);
                }

                // compare 
                if (py_header_res[0] != lib_header_res[0] ||
                    py_header_res[1] != lib_header_res[1] ||
                    py_header_res[2] != lib_header_res[2])
                {
                    status = false;
                    std::cout << match.GetPlayer0() << " VS " << match.GetPlayer1() << " : Failed\n";
                    for (int i = 0; i < 3; i++)
                    {
                        std::cout << "py : " << py_header_res[i] << " , lib : " << lib_header_res[i] << "\n";
                    }

                    // dummy read
                    std::getline(file, line_actions);

                    continue;
                }

                // read second line (actions)
                if (!std::getline(file, line_actions))
                {
                    std::cout << "File python_results.txt is not completed\n";
                    file.close();
			        return false;
                }

                std::stringstream ss_actions(line_actions);
                int index = 0;
                while (std::getline(ss_actions, token, sep)) 
                {
                    if (!((token == "C" && player_0_actions[index] == qlm::Choice::COOPERATE) || 
                          (token == "D" && player_0_actions[index] == qlm::Choice::DEFECT)))
                    {
                        status = false;
                        std::cout << match.GetPlayer0() << " VS " << match.GetPlayer1() << " ,round = " << index + 1 << " : Failed\n";
                        std::cout << "py : " << token << " ,pl_0 : " << player_0_actions[index] << "\n";
                    }

                    std::getline(ss_actions, token, sep);

                    if (!((token == "C" && player_1_actions[index] == qlm::Choice::COOPERATE) || 
                          (token == "D" && player_1_actions[index] == qlm::Choice::DEFECT)))
                    {
                        status = false;
                        std::cout << match.GetPlayer0() << " VS " << match.GetPlayer1() << " ,round = " << index + 1 << " : Failed\n";
                        std::cout << "py : " << token << " ,pl_1 : " << player_1_actions[index] << "\n";
                    }

                    index++;
                }

                // reset strategies
                strategy_list0[st_0]->Reset();
                strategy_list1[st_1]->Reset();
            }
        }

        file.close();

        return status;
    }
}


int main ()
{
    bool status = test::Test_IPD(200);

    if (status == true)
    {
        std::cout << "All tests PASSED\n";
    }
}