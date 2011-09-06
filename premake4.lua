
local include_tests = false

-- Create Project if no one is available
if solution() == nil then
    solution "libcpr"
        configurations { "Debug", "Release" }
        location "build"
        targetdir "bin"
        libdirs { "bin" }

    include_tests = true

end


-- libcpr - c portable runtime
project "libcpr"
    kind "SharedLib"
    language "C"
    includedirs { "include" }
    files { "src/**.c" }
    targetname "cpr"

    configuration { "linux", "gmake" }
        buildoptions { "-ansi", "-std=c99", "-fPIC" }



if include_tests then

project "libcpr_test"
    kind "ConsoleApp"
    language "C"
    includedirs { "include" }
    files { "tests/main.c" }
    links { "cpr", "check" }
    targetname "cpr_test"


end