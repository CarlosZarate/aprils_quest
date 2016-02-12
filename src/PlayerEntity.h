
#pragma once
#include "Urho3D/Scene/LogicComponent.h"
#include "Urho3D/Input/Controls.h"
#include "Urho3D/Scene/Node.h"
#include "Urho3D/Container/Vector.h"

// All Urho3D classes reside in namespace Urho3D
namespace Urho3D
{

	/// Enemy died
	URHO3D_EVENT(E_PLAYERDIED, PlayerDied)
	{                                           // bool
		URHO3D_PARAM(P_NODE, NodePtr);                 // Node Ptr
	}
}

using namespace Urho3D;

const int CTRL_UP = 1;
const int CTRL_DOWN= 2;
const int CTRL_LEFT = 4;
const int CTRL_RIGHT = 8;
const int LOOK_LEFT = 16;
const int CHANGE_TARGET = 32;

const float MOVE_FORCE = 1.5f;

class PlayerEntity : public LogicComponent
{
	//OBJECT(PlayerEntity);
public:
	//-------------------------------------------------------------------------
	// Constructors & Destructors
	//-------------------------------------------------------------------------
	PlayerEntity(Context* context);
	~PlayerEntity();

	/// Register object factory.
	static void RegisterObject(Context* context);

	/// Called when the component is added to a scene node. Other components may not yet exist.
	virtual void Start();
	/// Called before the first update. At this point all other components of the node should exist. Will also be called if update events are not wanted; in that case the event is immediately unsubscribed afterward.
	virtual void DelayedStart();
	/// Called when the component is detached from a scene node, usually on destruction.
	virtual void Stop();
	/// Called on scene update, variable timestep.
	virtual void Update(float timeStep);

	void Shoot();

	void ChangeTarget();

    Node* CurrentTarget = 0;

	/// Movement controls. Assigned by the main program each frame.
    Controls controls_;
private:

    void AutoTarget();
    Vector<Node*> TargetList;
    Node* weaponnode;
    void UpdateBehaviour();
};
