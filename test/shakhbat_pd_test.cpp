#include "shakhbat_pd_test.hpp"

namespace test
{
    void FillStrategies()
    {
        ADD_STRATEGY(qlm::Cooperator);
        ADD_STRATEGY(qlm::TitForTat);
        ADD_STRATEGY(qlm::Grudger);
        ADD_STRATEGY(qlm::Defector);
        ADD_STRATEGY(qlm::FirstByDavis);
    }

    bool Test_IPD(const int num_rounds = 15)
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
        const char sep = ',';

        // loop over the strategies
        for (int st_0 = 0; st_0 < strategy_list.size(); st_0++)
        {
            for (int st_1 = st_0; st_1 < strategy_list.size(); st_1++)
            {
                // run shakhbat_pd library 
                auto match = qlm::Match(*strategy_list[st_0], *strategy_list[st_1], num_rounds);
                // match info
                auto winner = match.Winner().first == "DRAW"? "False" : match.Winner().first;
                auto player_0_score = match.GetPlayer0Score();
                auto player_1_score = match.GetPlayer1Score();
                auto player_0_actions = match.GetPlayer0History();
                auto player_1_actions = match.GetPlayer1History();

                std::vector<std::string> lib_header_res {winner, std::to_string(match.GetPlayer0Score()), std::to_string(match.GetPlayer1Score())};

                // read python results
                // read first line  (winner, score_0, score_1)
                std::string line;
                if (!std::getline(file, line))
                {
                    std::cout << "File python_results.txt is empty\n";
                    file.close();
			        return false;
                }

                std::stringstream ss_header(line);
                std::string token;
                std::vector<std::string> py_header_res;
                while (std::getline(ss_header, token, sep)) 
                {
                    py_header_res.push_back(token);
                }
                
                // for (int i = 0; i < 3; i++)
                // {
                //     std::cout << py_header_res[i] << " " << lib_header_res[i] << "\n";
                // }
                

                // compare 
                if (py_header_res[0] != lib_header_res[0] ||
                    py_header_res[1] != lib_header_res[1] ||
                    py_header_res[2] != lib_header_res[2])
                {
                    status = false;
                    std::cout << match.GetPlayer0() << " VS " << match.GetPlayer1() << " : Failed\n";
                    continue;
                }

                // read second line (actions)
                if (!std::getline(file, line))
                {
                    std::cout << "File python_results.txt is not completed\n";
                    file.close();
			        return false;
                }

                std::stringstream ss_actions(line);
                int index = 0;
                while (std::getline(ss_actions, token, sep)) 
                {
                    //std::cout << token << " " << player_0_actions[index] << "\n";

                    if (!((token == "C" && player_0_actions[index] == qlm::Choice::COOPERATE) || 
                          (token == "D" && player_0_actions[index] == qlm::Choice::DEFECT)))
                    {
                        status = false;
                        std::cout << match.GetPlayer0() << " VS " << match.GetPlayer1() << " : Failed\n";
                        continue;
                    }

                    std::getline(ss_actions, token, sep);

                    if (!((token == "C" && player_1_actions[index] == qlm::Choice::COOPERATE) || 
                          (token == "D" && player_1_actions[index] == qlm::Choice::DEFECT)))
                    {
                        status = false;
                        std::cout << match.GetPlayer0() << " VS " << match.GetPlayer1() << " : Failed\n";
                        continue;
                    }

                    index++;
                }

                // reset strategies
                strategy_list[st_0]->Reset();
                strategy_list[st_1]->Reset();
            }
        }

        file.close();

        return status;
    }
}


int main ()
{
    bool status = test::Test_IPD();

    if (status == true)
    {
        std::cout << "All tests PASSED\n";
    }
}