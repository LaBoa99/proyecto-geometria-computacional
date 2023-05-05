#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <iostream>

class Utils
{
    public:
        Utils() {}
        virtual ~Utils() {}
        // Randoms
        static inline int genRandomInt(int n, int m){
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_int_distribution<int> dist(n, m);
            return dist(mt);
        }

        static inline float genRandomFloat(float n = 0.0f, float m = 1.0f){
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<float> dist(n, m);
            return dist(mt);
        }

        static inline bool genBooleanWithProbability(float probability) {
            return Utils::genRandomFloat() < probability;
        }
};

#endif // UTILS_H
