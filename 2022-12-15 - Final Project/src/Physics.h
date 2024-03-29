
#pragma once

#include "Common.h"
#include "Entity.h"
#include <math.h>

struct Intersect { bool result; Vec2 pos; };
                                            
namespace Physics
{
    bool IsInside(const Vec2& pos, std::shared_ptr<Entity> e);
    Vec2 GetOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b);
    Vec2 GetPreviousOverlap(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b);

    Intersect LineIntersect(const Vec2& a, const Vec2& b, const Vec2& c, const Vec2& d);
    bool EntityIntersect(const Vec2& a, const Vec2& b, std::shared_ptr<Entity> e);
    int orientation(const Vec2& a, const Vec2& b, const Vec2& c);
}

