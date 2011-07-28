
solution "libcpr"
    configurations { "Debug", "Release" }

-- libcpr
project "libcpr"
    kind "SharedLib"
    language "C"
    includedirs { "include" }
    files { "src/**.c" }
    targetname "cpr"
    location "build"
    targetdir "bin"

    configuration { "linux", "gmake" }
        buildoptions { "-ansi", "-std=c99", "-fPIC" }