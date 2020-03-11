#include <random>
#include "TypeDefs.hpp"

template< typename T >
class RandomIntegral
{
private:
    // Random generator engine (64-bit)
    static inline std::mt19937_64 randomEngine;
public:
    ///
    /// @brief Generates a number between a Min and a Max, so, a range-based generation
    ///
    /// @param Min - I don't know what to put here (I'm open to sugestions in regards)
    ///
    /// @param Max - Same as Min
    ///
    /// @return A random generated int
    ///
    static T getRandom(T Min, T Max)
    {
        std::uniform_int_distribution< T > randomDistribution(Min, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    /// @brief Generates a number between 0 and Max, so, a range-based generation (I suggest to not put negative numbers)
    ///
    /// @param Max - I don't know what to put here (I'm open to sugestions in regards)
    ///
    /// @return A random generated int
    ///
    static T getRandom(T Max)
    {
        std::uniform_int_distribution< T > randomDistribution(0, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    /// @brief Idk, generates a random number
    ///
    /// @return A random number between 0 and 2^32 - 1
    ///
    static T getRandom()
    {
        std::uniform_int_distribution< T > randomDistribution;
        return randomDistribution(randomEngine); 
    }
};

template< typename T >
class RandomReal
{
private:
    // Random generator engine (64-bit)
    static inline std::mt19937_64 randomEngine;
public:
    ///
    /// @brief Generates a number between a Min and a Max, so, a range-based generation
    ///
    /// @param Min - I don't know what to put here (I'm open to sugestions in regards)
    ///
    /// @param Max - Same as Min
    ///
    /// @return A random generated int
    ///
    static T getRandom(T Min, T Max)
    {
        std::uniform_real_distribution< T > randomDistribution(Min, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    /// @brief Generates a number between 0 and Max, so, a range-based generation (I suggest to not put negative numbers)
    ///
    /// @param Max - I don't know what to put here (I'm open to sugestions in regards)
    ///
    /// @return A random generated int
    ///
    static T getRandom(T Max)
    {
        std::uniform_real_distribution< T > randomDistribution(0.f, Max);
        return randomDistribution(randomEngine); 
    }
    ///
    /// @brief Idk, generates a random number
    ///
    /// @return A random number between 0 and 1
    ///
    static T getRandom()
    {
        std::uniform_real_distribution< T > randomDistribution;
        return randomDistribution(randomEngine); 
    }
};
