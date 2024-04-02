#pragma once

#include <deque>
#include <format>
#include <string>
#include <string_view>

#include <glm/glm.hpp>

template<typename ...Args>
inline std::string A_Format(std::string_view fmt, Args&&... args) {
    return std::vformat(fmt, std::make_format_args(args...));
}

template<>
struct std::formatter<glm::vec2> {
    template<class ParseCtx>
    constexpr auto parse(ParseCtx& ctx) const {
        return ctx.begin();
    }

    template<class FmtCtx>
    auto format(const glm::vec2& v, FmtCtx& ctx) const {
        return std::format_to(ctx.out(), "{} {}", v.x, v.y);
    }
};

template<>
struct std::formatter<glm::vec3> {
    template<class ParseCtx>
    constexpr auto parse(ParseCtx& ctx) const {
        return ctx.begin();
    }

    template<class FmtCtx>
    auto format(const glm::vec3& v, FmtCtx& ctx) const {
        return std::format_to(ctx.out(), "{} {} {}", v.x, v.y, v.z);
    }
};

template<>
struct std::formatter<glm::vec4> {
    template<class ParseCtx>
    constexpr auto parse(ParseCtx& ctx) const {
        return ctx.begin();
    }

    template<class FmtCtx>
    auto format(const glm::vec4& v, FmtCtx& ctx) const {
        return std::format_to(ctx.out(), "{} {} {} {}", v.x, v.y, v.z, v.w);
    }
};

