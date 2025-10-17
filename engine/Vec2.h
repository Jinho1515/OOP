#pragma once
#include <cmath>
struct Vec2 {
    float x{0}, y{0};
    Vec2() = default;
    Vec2(float x_, float y_) : x(x_), y(y_) {}
};
inline float dist2(const Vec2& a, const Vec2& b){ float dx=a.x-b.x, dy=a.y-b.y; return dx*dx+dy*dy; }
inline float dist (const Vec2& a, const Vec2& b){ return std::sqrt(dist2(a,b)); }
inline Vec2  lerp (const Vec2& a, const Vec2& b, float t){ return Vec2(a.x+(b.x-a.x)*t, a.y+(b.y-a.y)*t); }
