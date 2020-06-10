#include "Handlers.hpp"

void Handlers::HandleVScrollbar(tgui::Canvas::Ptr Canvas, tgui::Scrollbar::Ptr VerticalScroll)
{
    sf::View CanvasView;
    uint ViewportSize = VerticalScroll->getViewportSize() / 2;
    uint Value = VerticalScroll->getValue();
    CanvasView.setCenter(Canvas->getView().getCenter().x, static_cast< float >(Value + ViewportSize));
    CanvasView.setSize(Canvas->getSize());
    Canvas->setView(CanvasView);
}

void Handlers::HandleHScrollbar(tgui::Canvas::Ptr Canvas, tgui::Scrollbar::Ptr HorizontalScroll)
{
    sf::View CanvasView;
    uint Value = HorizontalScroll->getValue();
    uint ViewportSize = HorizontalScroll->getViewportSize() / 2;
    CanvasView.setCenter(static_cast< float >(Value + ViewportSize), Canvas->getView().getCenter().y);
    CanvasView.setSize(Canvas->getSize());
    Canvas->setView(CanvasView);
}

void Handlers::Handle2DList(tgui::ListView::Ptr ListView)
{
    std::size_t ColumnsCount = ListView->getColumnCount();
    float ColumnWidth = ListView->getSize().x / static_cast< float >(ColumnsCount);
    
    for (size_t Index = 0; Index < ColumnsCount - 1; Index++)
        ListView->setColumnWidth(Index, ColumnWidth);
}

void Handlers::ScaleScrollableCanvas(tgui::Group::Ptr BoxLayout, tgui::Canvas::Ptr Canvas, 
    tgui::Scrollbar::Ptr VerticalScroll, tgui::Scrollbar::Ptr HorizontalScroll)
{
    sf::Vector2f CanvasSize = BoxLayout->getSize() - sf::Vector2f(20.f, 20.f);
    Canvas->setSize(CanvasSize);
    Canvas->setView(sf::View({
        static_cast< float >(HorizontalScroll->getValue()), 
        static_cast< float >(VerticalScroll->getValue()), 
        CanvasSize.x, CanvasSize.y
    }));

    VerticalScroll->setPosition({CanvasSize.x , 0.f});
    VerticalScroll->setSize({20.f, CanvasSize.y});
    VerticalScroll->setViewportSize(static_cast< uint >(CanvasSize.y));

    HorizontalScroll->setPosition({0.f, CanvasSize.y});
    HorizontalScroll->setSize({CanvasSize.x, 20.f});
    HorizontalScroll->setViewportSize(static_cast< uint >(CanvasSize.x));
}