#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_ACTOR_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_ACTOR_H

#include <vector>
#include "y0_core/Vector3.h"

template<typename T>
class Actor
{
public:
	enum State
	{
		Active,
		Paused,
		Dead
	};

	Actor(class T* owner);
	virtual ~Actor();

	void Update(float delta_time);
	void UpdateComponents(float delta_time);
	virtual void UpdateActor(float delta_time);

	inline const Vector3& GetPosition() const { return position_; }
	inline void SetPosition(const Vector3& position) { position_ = position; }
	inline float GetScale() const { return scale_; }
	inline void SetScale(float scale) { scale_ = scale; }
	inline float GetRotation() const { return rotation_; }
	inline void SetRotation(float rotation) { rotation = rotation_; }
	inline State GetState() const { return state_; }
	inline void SetState(State state) { state_ = state; }
	inline T* GetParent() { return owner_; }

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);
private:
	State state_;

	Vector3 position_;
	float scale_;
	float rotation_;

	std::vector<class Component*> components_;
	class Parent* owner_;
};

#endif
