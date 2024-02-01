import axelrod as axl

def run_matches(strategies, rounds=100):
    '''
    winner, player_0_score, player_1_score
    C,D,D,C ... #ply0,ply1,...
    '''
    file = open('../build/test/python_results.txt','w')

    for strategy1_idx in range(len(strategies)):
        for strategy2_idx in range(strategy1_idx, len(strategies)):
            players = (strategies[strategy1_idx].clone(), strategies[strategy2_idx].clone())
            match = axl.Match(players, turns=rounds)
            match.set_seed(0)
            # Extract relevant information
            interactions = match.play()
            scores = match.final_score()
            winner = match.winner()

            file.write("%s;%d;%d\n" % (winner, scores[0], scores[1]))
            moves = ";".join(["{};{}".format(move[0], move[1]) for move in interactions])
            file.write("%s\n" % moves)

    file.close()

if __name__ == "__main__":
    # Define the list of strategies you want to test
    strategy_list = [axl.Cooperator(), axl.TitForTat(), axl.Grudger(), axl.Defector(), axl.FirstByDavis(), axl.FirstByGrofman(),
                     axl.FirstByJoss(), axl.FirstByShubik(), axl.FirstByFeld(), axl.FirstByTullock()]
    
    # Run matches
    run_matches(strategy_list, 200)
