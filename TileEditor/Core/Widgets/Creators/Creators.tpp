#pragma once

#include <TGUI/SignalImpl.hpp>

#include "Creators.hpp"

tgui::ChildWindow::Ptr Creators::CreateChildWindow(
    const tgui::Layout2d& Position, const tgui::Layout2d& Size, const std::string& Title)
{
    tgui::ChildWindow::Ptr ChildWindow = tgui::ChildWindow::create(Title);
    ChildWindow->setPosition(Position);
    ChildWindow->setSize(Size);
    ChildWindow->setTitleTextSize(0);
    ChildWindow->setTitleAlignment(tgui::ChildWindow::TitleAlignment::Center);

    return ChildWindow;
}

template< typename Variable >
tgui::EditBox::Ptr Creators::CreateEditBox(
    const tgui::Layout2d& Position, const tgui::Layout2d& Size, const std::string& DefaultText, 
    const std::string& Signal, const InputType& Type, Variable& Var)
{
        tgui::EditBox::Ptr Editbox = tgui::EditBox::create();
        Editbox->setPosition(Position);
        Editbox->setSize(Size);
        Editbox->setTextSize(0);
        Editbox->setDefaultText(DefaultText);
        if(Type != InputType::String)
        {
            Editbox->setMaximumCharacters(9);
            if(Type == InputType::Int)
            {
                Editbox->setInputValidator(tgui::EditBox::Validator::Int);
                Editbox->connect(Signal, Getters::getInt, Editbox, std::ref(Var));
            }
            else
            {
                Editbox->setInputValidator(tgui::EditBox::Validator::Float);
                Editbox->connect(Signal, Getters::getFloat, Editbox, std::ref(Var));
            }
        }
        else
            Editbox->connect(Signal, Getters::getString, Editbox, std::ref(Var));

        return Editbox;
} 

template< typename Func, typename... Args >
tgui::Button::Ptr Creators::CreateButton(const tgui::Layout2d& Position, const tgui::Layout2d& Size, 
    const std::string& DefaultText, const std::string& Signal, Func&& Function, Args&&... Arguments)
{
    tgui::Button::Ptr Button = tgui::Button::create(DefaultText);
    Button->setPosition(Position);
    Button->setSize(Size);
    Button->setTextSize(0);
    Button->connect(Signal, Function, Arguments...);
}