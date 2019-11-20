#pragma once

#include <SFML/Graphics/Texture.hpp>

#include <unordered_map>
#include <memory>

// Used for defining the uint type, typically define for Linux already (Cross compilling reasons)
typedef unsigned int uint;

// Used for sharing resoources, thus using less memory
class ResourceManager
{
public:
    /// @brief Used for loading a Texture and stores it in Textures map
    ///
    /// @return A smart pointer to the Texture object it is already there
    ///
    /// @param TextureFileName - The path to the texture
    static std::shared_ptr< sf::Texture > Acquire(const std::string& TextureFileName);
    /// @brief Used for loading a Texture and stores it in Textures map if the Texture is bigger that what gpu supports (used for background)
    ///
    /// @return A smart pointer to the Texture object it is already there
    ///
    /// @param TextureFileName - The path to the texture
    ///
    /// @param TextureArea - The size and the position of the Texture
    static std::shared_ptr< sf::Texture > Acquire(const std::string& TextureFileName, sf::IntRect TextureArea);
    /// @brief If an Texture isn't used anywere it will be deleted
    static void RemoveOrphans();
    /// @brief Destroyes the Texture map because it is a static object and the default destructor isn't applied anymore 
    static void Clear();
private:
    // Where all Textures (smart pointers) will be stored 
    static inline std::unordered_map< std::string, std::shared_ptr< sf::Texture > > TextureMap;
    // The iterator for it (Declared here because it's faster)
    static inline std::unordered_map< std::string, std::shared_ptr< sf::Texture > >::iterator TextureMapIter;
};