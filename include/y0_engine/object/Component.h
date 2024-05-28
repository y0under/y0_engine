#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_COMPONENT_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_COMPONENT_H

#include "y0_engine/object/Actor.h"

namespace y0_engine {
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

        virtual void Update(float delta_time)
        {
        }

        inline int GetUpdateOrder() const { return update_order_; }

      protected:
        Actor<T>* owner_;
        int update_order_;
    };
}

#endif
