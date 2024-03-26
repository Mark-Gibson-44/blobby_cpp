#pragma once

#include <concepts>

template <class T>
inline T IsWithinRange(T uPosition, T uOtherPosition, T uRadius)
{
    static_assert(std::is_integral<T>() && !std::is_signed<T>());

    return (uRadius + uPosition > uOtherPosition && uPosition - uRadius < uOtherPosition);
}