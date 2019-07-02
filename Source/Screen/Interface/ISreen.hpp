#ifndef _LoX_STATE
#define _LoX_STATE

#pragma once

class IScreen
{

public:

    IScreen( ) = default;

    virtual ~IScreen( ) = default;

    virtual void Update( ) = 0;

    virtual void Draw( ) = 0;

    virtual void OnEntry() = 0;

    virtual void OnExit() = 0;

    virtual void NextScreen() = 0;

};

#endif
