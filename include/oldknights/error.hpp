#pragma once

#include <string>
#include <exception>

namespace oldknights {

class GameError : public std::exception {
    char const* excuse;
public:
    GameError(char const* what) noexcept
        : excuse(what) {}
    ~GameError() override = default;

    const char* what() const noexcept override {
        return excuse;
    }
};

}
