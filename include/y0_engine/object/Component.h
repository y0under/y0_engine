#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_COMPONENT_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_COMPONENT_H

#include "y0_engine/object/Actor.h"

template<typename T>
class Component {
  public:
    Component(Actor* owner, int update_order)
      : owner_(owner),
      update_order_(update_order) {
        owner_->AddComponent(this);
      }

    ~Component() {
      owner_->RemoveComponent(this);
    }

    void Update(float delta_time)
    {
    }

    int GetUpdateOrder() const { return update_order_; }
  protected:
    class Actor<T>* owner_;
    int update_order_;
};

#endif
