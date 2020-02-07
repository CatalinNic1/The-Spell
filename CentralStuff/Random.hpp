#include <random>

class RandomIntegral
{
private:
    //
    static inline std::uniform_int_distribution< std::mt19937_64::result_type > randomDistribution;
    //
    static inline std::mt19937_64 randomEngine;
public:
    ///
    ///
    ///
    static int getRandom(int Min, int Max)
    {
        return randomDistribution(randomEngine) % (Max + 1 - Min) + Min;
    }
    ///
    ///
    ///
    static int getRandom(int Max)
    {
        return randomDistribution(randomEngine) % Max;
    }
    ///
    ///
    ///
    static int getRandom()
    {
        return randomDistribution(randomEngine);
    }
};


class RandomReal
{
private:
    //
    static inline std::uniform_int_distribution< std::mt19937_64::result_type > randomDistribution;
    //
    static inline std::mt19937_64 randomEngine;
public:
    ///
    ///
    ///
    static float getRandom()
    {
        return static_cast< float >(randomDistribution(randomEngine)) / static_cast< float >(std::numeric_limits< uint_fast64_t >::max());
    }
};
