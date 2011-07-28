

-- Create Project if no one is available
if solution() == nil then
    solution "libcpr"
        configurations { "Debug", "Release" }
        location "build"
        targetdir "bin"
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