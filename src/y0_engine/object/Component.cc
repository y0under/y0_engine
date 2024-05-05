#ifndef Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_COMPONENT_H
#define Y0_ENGINE_INCLUDE_Y0_ENGINE_OBJECT_COMPONENT_H

#include "Actor.h"

class Component {
  public:
    Component(class Actor* owner, int updateOrder = 128);
    virtual ~Component();
    virtual void Update(float delta_time);

    inline int GetUpdateOrder() const { return update_order_; }
  protected:
    class Actor* owner_;
    int update_order_;
};

#endif
