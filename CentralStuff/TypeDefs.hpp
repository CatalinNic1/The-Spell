#pragma once

// Used for defining the uint type, typically define for Linux already (Cross compilling reasons)
typedef unsigned int uint;
//
typedef unsigned long ulong;
//
#define TextureMinSize 512u
// Self-explanatory
#define MovingSpeed 300.f
//
#define TileSize sf::Vector2f(32.f, 32.f)
//
#define DefaultSize sf::Vector2f(480.f, 270.f)
//
#define PseudoLineMultiplier 2.f
//
#define DifferenceOffset 1.1f