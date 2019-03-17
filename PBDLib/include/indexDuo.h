#ifndef indexDuo_H
#define indexDuo_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

namespace LuHu{
class indexDuo
{
public:
    indexDuo(const int _a, const int _b) :
        p(std::min(_a, _b), std::max(_a, _b))
    {}

    std::pair<int, int> p;

    friend bool operator==(const indexDuo &_p1, const indexDuo &_p2)
    {
        return _p1.p == _p2.p;
    }
};
}

namespace std
{
template <>
struct hash<LuHu::indexDuo>
{
    size_t operator()(const LuHu::indexDuo &_key) const
    {
        return std::hash<size_t>()(std::hash<int>()(_key.p.first)) ^ std::hash<int>()(_key.p.second);
    }
};
}
#endif // indexDuo_H
