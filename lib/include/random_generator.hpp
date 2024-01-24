#ifndef RANDOM_GENERATOR
#define RANDOM_GENERATOR

#include "types.hpp"
#include <random>

namespace qlm
{
    class RandomGenerator
    {
        private:
        std::mt19937 rng; // Mersenne Twister 64-bit random number generator
        int seed;

        public:
        // Constructor
        RandomGenerator(int seed = 2357136044) : rng(seed), seed(seed) {}

        // Function to set a seed
        void SetSeed(int seed_) 
        {
            rng.seed(seed_);
        }

         // Function to generate a random float [0 - 1]
        double Random() 
        {
            // just to match numpy random for testing
            int a = rng() >> 5;
            int b = rng() >> 6;
            double value = (a * 67108864.0 + b) / 9007199254740992.0;
            return value;
        }

        // Function to generate a random integer in [a, b]
        int RandInt(int a, int b) 
        {
            std::uniform_int_distribution<int> distribution(a, b - 1);
            return distribution(rng);
        }

        // Function to reset the random generator to the original seed
        void Reset() 
        {
            rng.seed(seed);
        }

        // Function to generate a random choice based on a probability
        Choice random_choice(double p = 0.5f) 
        {
            if (p == 0.0f) 
            {
                return Choice::DEFECT;
            }

            if (p == 1.0f) 
            {
                return Choice::COOPERATE;
            }

            double r = this->Random();

            return r < p ? Choice::COOPERATE : Choice::DEFECT;
        }
       
    };
}

#endif