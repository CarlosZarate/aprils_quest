#pragma once

#include "BaseApplication.h"
#include "StateManager.h"

namespace Urho3D
{
    class Node;
    class Scene;
}

/// Urho2D sprite example.
/// This sample demonstrates:
///     - Creating a 2D scene with sprite
///     - Displaying the scene using the Renderer subsystem
///     - Handling keyboard to move and zoom 2D camera
class AprilsQuest : public BaseApplication
{
    URHO3D_OBJECT(AprilsQuest, BaseApplication);

public:
    /// Construct.
    AprilsQuest(Context* context);

    /// Setup after engine initialization and before running the main loop.
    virtual void Start();

protected:

private:
    SharedPtr<StateManager> stateManager_;
};
