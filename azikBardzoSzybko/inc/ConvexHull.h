#pragma once

#include <iostream>
#include <ostream>
#include <vector>

#include "vector.h"

typedef Vector<double, 3>           Vector3D;

struct ConvexHull {
    typedef Vector<double, 3>       Vector3D;
    std::vector<Vector3D>           vectors;
public:
    explicit ConvexHull(void) = default;

    std::vector<Vector3D>& get(void) noexcept
        { return vectors; }
    std::vector<Vector3D> const& get(void) const noexcept
        { return vectors; }

    friend bool notIntersect(ConvexHull const& left, ConvexHull const& right) noexcept;
};

