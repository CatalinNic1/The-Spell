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
        }
        
        SessionSetup.draw();
    }
}