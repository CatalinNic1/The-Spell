#include "EditorSession.hpp"

void EditorSession::Edit()
{
    while(Setup::IsOpen())
    {
        while(Setup::PollEvent(EditorEvent))
        {
            SessionSetup.handleGuiEvent(EditorEvent);
        
            if(EditorEvent.type == sf::Event::Closed)
                Setup::Exit();
            else if(EditorEvent.type == sf::Event::Resized)
            {
                Setup::SetWindowView(sf::View(sf::FloatRect(0.f, 0.f, 
                static_cast<float>(EditorEvent.size.width), static_cast<float>(EditorEvent.size.height))));
                SessionSetup.SetGuiView(Setup::GetWindowView());
            }
        }
        
        SessionSetup.draw();
    }
}