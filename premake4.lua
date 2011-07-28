

-- Create Project if no one is available
if solution() == nil then
    solution "libcpr"
        configurations { "Debug", "Release" }
        location "build"
end


-- libcpr - c portable runtime
project "libcpr"
    kind "SharedLib"
    language "C"
    includedirs { "include" }
    files { "src/**.c" }
    targetname "cpr"
    targetdir "bin"

    configuration { "linux", "gmake" }
        buildoptions { "-ansi", "-std=c99", "-fPIC" }