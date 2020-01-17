#pragma once

#include <array>

#include "../Tile/Tile.hpp"

#define ChunkLength 8

class MapChunk
{
private:
    //
    class std::array< std::array< MapTile, ChunkLength >, ChunkLength > Chunk;
public:

};