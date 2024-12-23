
add_requires("nlohmann_json")
add_requires("boost", {configs = {beast=true}})
target("DarkWorld")
    set_kind("binary")
    add_files("src/**.cpp")
    add_packages("nlohmann_json")
    add_packages("boost", {components="beast"})
    set_pcxxheader("src/pch/pch.hpp")
    add_cxxflags(
      "-std=c++20",
      "-I", "src/",
      { force = true }
    )