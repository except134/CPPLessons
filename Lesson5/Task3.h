#pragma once

template<typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
    StringValuePair(const std::string& s, T v) :
        Pair<std::string, T>(s, v)
    {}
};