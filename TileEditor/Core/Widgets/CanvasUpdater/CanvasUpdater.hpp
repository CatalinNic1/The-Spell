#pragma once

#include <functional>
#include <vector>
#include <TGUI/Widgets/Canvas.hpp>

class CanvasUpdater
{
private:
    using CanvasInfo = std::pair< tgui::Canvas::Ptr, std::function< void() > >;
    //
    using CanvasesInfo = std::vector< CanvasInfo >;
    //
    std::function< bool() > IsOpenFunc;
    //
    CanvasesInfo Items;
public:
    ///
    ///
    ///
    CanvasUpdater(std::function< bool() > Handler);
    ///
    ///
    ///
    void add(const CanvasInfo& Item);
    ///
    ///
    ///
    void RemoveOrphans();
    ///
    ///
    ///
    void Update();
};