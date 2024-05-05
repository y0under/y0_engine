#include "y0_engine/object/actor.h"

Actor::Actor(T *owner)
  : state_(Active),
  position_(Vector3::zero_)
  , scale_(1.0f)
  , rotation_(0.0f)
    , owner_(owner)
{
  owner->AddActor(this);
}

Actor::~Actor()
{
  try {
    owner_->RemoveActor(this);
    while (!components_.empty())
    {
      delete components_.back();
    }
  }
  catch {
  }
}

void Actor::Update(float delta_time)
{
  if (state_ != Active)
    return;

  UpdateComponents(delta_time);
  UpdateActor(delta_time);
}

void Actor::UpdateComponents(float delta_time)
{
  for (auto component : components_)
  {
    component->Update(delta_time);
  }
}

void Actor::UpdateActor(float delta_time)
{
}

// note:
//   i wonder able to use priority queue
void Actor::AddComponent(Component *component)
{
  int order = component->GetUpdateOrder();
  auto iter = components_.begin();
  for (; iter != components_.end(); ++iter)
  {
    if (order < (*iter)->GetUpdateOrder())
    {
      break;
    }
  }

  components_.insert(iter, component);
}

void Actor::RemoveComponent(Component *component)
{
  auto iter = std::find(components_.begin(), components_.end(), component);
  if (iter == components_.end())
    return;

  components_.erase(iter);
}
