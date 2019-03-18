#ifndef VEC3DUO_H
#define VEC3DUO_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

namespace LuHu{
class vec3Duo
{
public:
    vec3Duo(const uint _a, const uint _b) :
        p(std::min(_a, _b), std::max(_a, _b))
    {}

    std::pair<uint, uint> p;

    friend bool operator==(const vec3Duo &_a, const vec3Duo &_b)
    {
        return _a.p == _b.p;
    }
};
}

namespace std
{
template <>
struct hash<LuHu::vec3Duo>
{
    size_t operator()(const LuHu::vec3Duo &_key) const
    {
        return std::hash<size_t>()(std::hash<uint>()(_key.p.first)) ^ std::hash<uint>()(_key.p.second);
    }
};
}
#endif // VEC3DUO_H
