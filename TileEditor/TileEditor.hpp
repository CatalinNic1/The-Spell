#pragma once

#include "Session/EditorSession.hpp"

class TileEditor
{
private:
    //
    EditorSession Session;
public:
    ///
    ///
    ///
    void Work()
    {
        Session.Edit();
    }
};