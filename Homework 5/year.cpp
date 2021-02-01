#include "year.h"

namespace EXP5
{
// remove inline definition
#define inline

// year implementation

inline year::year(int y)
    : y_(static_cast<decltype(y_)>(y))
{
}

// TODO1 ++/++, --/--, +=, -=
inline year& year::operator++()
{
    ++y_;
    return *this;
}

inline year year::operator++(int)
{
    year temp = *this;
    y_++;
    return temp;
}

inline year& year::operator--()
{
    --y_;
    return *this;
}

inline year year::operator--(int)
{
    year temp = *this;
    --y_;
    return temp;
}

inline year& year::operator+=(const years &y)
{
    y_ += y.count();
    return *this;
}

inline year& year::operator-=(const years &y)
{
    y_ -= y.count();
    return *this;
}
//

inline year year::operator-() const { return year{-y_}; }

inline year year::operator+() const { return *this; }

inline year::operator int() const { return y_; }

inline bool operator==(const year &x, const year &y)
{
    return static_cast<int>(x) == static_cast<int>(y);
}

inline bool operator<(const year &x, const year &y)
{
    return static_cast<int>(x) < static_cast<int>(y);
}

inline bool operator>(const year &x, const year &y)
{
    return y < x;
}

// TODO2 !=, <=, >=
inline bool operator!=(const year &x, const year &y)
{
    return static_cast<int>(x) != static_cast<int>(y);
}

inline bool operator<=(const year &x, const year &y)
{
    return y >= x;
}

inline bool operator>=(const year &x, const year &y)
{
    return y <= x;
}
//

inline years operator-(const year &x, const year &y)
{
    return years{static_cast<int>(x) - static_cast<int>(y)};
}

inline year operator-(const year &x, const years &y)
{
    return year{static_cast<int>(x) - y.count()};
}

inline year operator+(const year &x, const years &y)
{
    return year{static_cast<int>(x) + y.count()};
}

inline year operator+(const years &x, const year &y)
{
    return y + x;
}

// TODO3 : ok, is_leap
inline bool year::ok() const
{
    return *this >= year::min() && *this < year::max();
}

inline bool year::is_leap() const
{
    return *this < year::min() || *this >= year::max();
}
//

std::ostream &operator<<(std::ostream &os, const year &y)
{
    os << static_cast<int>(y);
    return os;
}

namespace literals
{
year operator"" _y(unsigned long long y)
{
    return year(static_cast<int>(y));
}
} // namespace literals

}; // namespace EXP5