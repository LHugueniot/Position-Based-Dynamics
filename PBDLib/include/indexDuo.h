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

    /// @brief Constructor
    /// @param p pair of uints used as indices, when index duo is constructed they are sorted by value

    indexDuo(const int _a, const int _b) :
        p(std::min(_a, _b), std::max(_a, _b))
    {}

    /// @param p pair of uints

    std::pair<int, int> p;

    /// @brief operator== overload operate for std::unique to use

    friend bool operator==(const indexDuo &_p1, const indexDuo &_p2)
    {
        return _p1.p == _p2.p;
    }
};

class indexTrio
{
public:

    /// @brief Constructor
    /// @param p1 index to p1 of face
    /// @param p2 index to p1 of face
    /// @param p3 index to p1 of face

    indexTrio(const int _a, const int _b, const int _c) :
        p1(_a),
        p2(_b),
        p3(_c)
    {}

    int p1
    ,p2
    ,p3;

    friend bool operator==(const indexTrio &_p1, const indexTrio &_p2)
    {
        return _p1 == _p2;
    }
};
}

#endif // indexDuo_H
