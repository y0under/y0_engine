#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_ACTOR_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_ACTOR_H

#include <vector>
#include "y0_core/math/Vector3.h"
#include "y0_engine/object/Component.h"

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

    explicit Actor(T *owner)
      : state_(Active),
      position_(y0_engine::Vector3<float>::zero_),
      scale_(1.0f),
      rotation_(0.0f),
      owner_(owner) {
        owner->AddActor(this);
      }
    ~Actor() {
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

    void Update(float delta_time) {
      if (state_ != Active)
        return;

      UpdateComponents(delta_time);
      UpdateActor(delta_time);
    }
    void UpdateComponents(float delta_time) {
      for (auto component : components_)
      {
        component->Update(delta_time);
      }
    }
    void UpdateActor(float delta_time) {
    }

    inline const y0_engine::Vector3<float>& GetPosition() const { return position_; }
    inline void SetPosition(const y0_engine::Vector3<float>& position) { position_ = position; }
    inline float GetScale() const { return scale_; }
    inline void SetScale(float scale) { scale_ = scale; }
    inline float GetRotation() const { return rotation_; }
    inline void SetRotation(float rotation) { rotation = rotation_; }
    inline State GetState() const { return state_; }
    inline void SetState(State state) { state_ = state; }
    inline T* GetParent() { return owner_; }

    // note:
    //   i wonder able to use priority queue
    void AddComponent(Component *component) {
      int order = component->GetUpdateOrder();
      auto iter = components_.begin();
      for (; iter != components_.end(); ++iter)
      {
        if (order < (*iter)->GetUpdateOrder())
        {
          break;
        }
      }
      void RemoveComponent(Component *component) {
        auto iter = std::find(components_.begin(), components_.end(), component);
        if (iter == components_.end())
          return;

        components_.erase(iter);
      }
      private:
      State state_;

      y0_engine::Vector3<float> position_;
      float scale_;
      float rotation_;

      std::vector<Component*> components_;
      class Parent* owner_;
    };

#endif
