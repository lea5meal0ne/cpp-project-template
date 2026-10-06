#include "project/example.hpp"

#include <fmt/core.h>
#include <spdlog/spdlog.h>

int main()
{
    spdlog::info("Application started");

    const int result = project::add(20, 22);
    fmt::print("20 + 22 = {}\n", result);

    return 0;
}
