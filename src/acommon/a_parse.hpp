#pragma once

#include <array>
#include <deque>
#include <string_view>
#include <charconv>
#include <system_error>

#include <cstdlib>

#include <glm/glm.hpp>

#include "acommon.h"
#include "a_string.h"
#include "a_type.h"

inline bool A_Split(std::string_view s, A_OUT std::deque<std::string>& v) {
    v = std::deque<std::string>(); 

    if (s.empty())
        return false;

    size_t pos_start = 0, pos_end;
    std::string token;

    while ((pos_end = s.find(' ', pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + 1;
        if ((token.find_first_not_of(" \n") != std::string::npos) 
            && !token.empty()
        ) {
            v.push_back(token);
        }
    }

    token = s.substr(pos_start);
    if ((token.find_first_not_of(" \n") != std::string::npos) && !token.empty())
        v.push_back(token);

    return true;
}

inline bool A_Parse(std::string_view s, A_OUT bool& value) {
    value = false;

    int i = 0;
    auto r = std::from_chars(s.data(), s.data() + s.size(), i);
    if (r.ec == std::errc()) {
        value = i != 0;
        return true;
    } else if (r.ec == std::errc::invalid_argument) {
        str_t n        = A_literal_internal(s.data(), s.length());
        string_t lower = A_tolower(&n);
        str_t ltrue    = A_literal("true");
        str_t lfalse   = A_literal("false");
        if (A_streq(&lower, &ltrue))
            value = true;
        else if (A_streq(&lower, &lfalse))
            value = false;

        A_strdrop(&lower);
        return true;
    }
    return false;
}

inline bool A_Parse(std::string_view s, A_OUT int& value) {
    value = 0;

    auto r = std::from_chars(s.data(), s.data() + s.size(), value);
    if (r.ec == std::errc()) {
        return true;
    }

    return false;
}

inline bool A_Parse(std::string_view s, A_OUT float& value) {
    value = (float)atof(std::string(s).data());
    return true;
}

inline bool A_Parse(
    const std::array<std::string_view, 2>& v, A_OUT glm::vec2& value
) {
    value = glm::vec2(0.0f, 0.0f);

    std::string_view xs = std::string_view(v[0]);
    float x = (float)atof(std::string(xs).data());

    std::string_view ys = std::string_view(v[1]);
    float y = (float)atof(std::string(ys).data());

    value = glm::vec2(x, y);

    return true;
}

inline bool A_Parse(std::string_view s, A_OUT glm::vec2& value) {
    std::deque<std::string> v;
    A_Split(s, v);

    if (v.size() < 2)
        return false;

    return A_Parse(std::array<std::string_view, 2> { v[0], v[1] }, value);
}

bool inline A_Parse(
    const std::array<std::string_view, 3>& v, A_OUT glm::vec3& value
) {
    value = glm::vec3(0.0f, 0.0f, 0.0f);

    std::string_view xs = std::string_view(v[0]);
    float x = (float)atof(std::string(xs).data());
    
    std::string_view ys = std::string_view(v[1]);
    float y = (float)atof(std::string(ys).data());
    
    std::string_view zs = std::string_view(v[2]);
    float z = (float)atof(std::string(zs).data());

    value = glm::vec3(x, y, z);

    return true;
}

inline bool A_Parse(std::string_view s, A_OUT glm::vec3& value) {
    std::deque<std::string> v;
    A_Split(s, v);

    if (v.size() < 3)
        return false;

    return A_Parse(
        std::array<std::string_view, 3> { v[0], v[1], v[2] }, value
    );
}

inline bool A_Parse(
    const std::array<std::string_view, 4>& v, A_OUT glm::vec4& value
) {
    value = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);

    std::string_view xs = std::string_view(v[0]);
    float x = (float)atof(std::string(xs).data());
    
    std::string_view ys = std::string_view(v[1]);
    float y = (float)atof(std::string(ys).data());
    
    std::string_view zs = std::string_view(v[2]);
    float z = (float)atof(std::string(zs).data());

    std::string_view ws = std::string_view(v[3]);
    float w = (float)atof(std::string(ws).data());

    value = glm::vec4(x, y, z, w);

    return true;
}

inline bool A_Parse(std::string_view s, A_OUT glm::vec4& value) {
    std::deque<std::string> v;
    A_Split(s, v);

    if (v.size() < 4)
        return false;

    return A_Parse(
        std::array<std::string_view, 4> { v[0], v[1], v[2], v[3] }, value
    );
}
