#include <random>
#include "TypeDefs.hpp"

#if defined(__i386__)

class RandomIntegral
{
private:
    //
    static inline std::mt19937 randomEngine;
public:
    ///
    ///
    ///
    static int getRandom(int Min, int Max)
    {
        std::uniform_int_distribution< int > randomDistribution(Min, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    ///
    ///
    static int getRandom(int Max)
    {
        std::uniform_int_distribution< int > randomDistribution(0, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    ///
    ///
    static int getRandom()
    {
        std::uniform_int_distribution< int > randomDistribution;
        return randomDistribution(randomEngine); 
    }
};


class RandomReal
{
private:
    //
    static inline std::mt19937 randomEngine;
public:
    ///
    ///
    ///
    static float getRandom(float Min, float Max)
    {
        std::uniform_real_distribution< float > randomDistribution(Min, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    ///
    ///
    static float getRandom(float Max)
    {
        std::uniform_real_distribution< float > randomDistribution(0.f, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    ///
    ///
    static float getRandom()
    {
        std::uniform_real_distribution< float > randomDistribution;
        return randomDistribution(randomEngine); 
    }
};

#else

class RandomIntegral
{
private:
    //
    static inline std::mt19937_64 randomEngine;
public:
    ///
    ///
    ///
    static int getRandom(int Min, int Max)
    {
        std::uniform_int_distribution< int > randomDistribution(Min, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    ///
    ///
    static int getRandom(int Max)
    {
        std::uniform_int_distribution< int > randomDistribution(0, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    ///
    ///
    static int getRandom()
    {
        std::uniform_int_distribution< int > randomDistribution;
        return randomDistribution(randomEngine); 
    }
};


class RandomReal
{
private:
    //
    static inline std::mt19937_64 randomEngine;
public:
    ///
    ///
    ///
    static float getRandom(float Min, float Max)
    {
        std::uniform_real_distribution< float > randomDistribution(Min, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    ///
    ///
    static float getRandom(float Max)
    {
        std::uniform_real_distribution< float > randomDistribution(0.f, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    ///
    ///
    static float getRandom()
    {
        std::uniform_real_distribution< float > randomDistribution;
        return randomDistribution(randomEngine); 
    }
};

#endif