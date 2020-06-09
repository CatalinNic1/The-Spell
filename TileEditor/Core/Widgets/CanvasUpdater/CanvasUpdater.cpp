#include <exception>

#include "CanvasUpdater.hpp"

void CanvasUpdater::add(const CanvasInfo& Item)
{
    if(Item.first == nullptr)
        throw std::runtime_error("Bad shared pointer");
    Items.emplace_back(Item);
}

CanvasUpdater::CanvasUpdater(std::function< bool() > Handler)
    :IsOpenFunc(Handler)
{}

void CanvasUpdater::RemoveOrphans()
{
    for(auto Item = Items.begin(); Item != Items.end();)
    {
        if(Item->first.use_count() == 1)
        {
            std::puts("Destroy");
            Item = Items.erase(Item);
        }
        else
            Item++;
    }
}

void CanvasUpdater::Update()
{
    if(IsOpenFunc() == false)
        return;
    for(CanvasInfo& Item : Items)
        if(Item.second)
            Item.second();
}