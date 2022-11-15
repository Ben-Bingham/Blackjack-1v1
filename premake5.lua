workspace "Blackjack"
	configurations { "Debug", "Release" }
	platforms { "x64" }

	startproject "Blackjack"

	filter "platforms:x64"
		architecture "x64"

	filter "configurations:Debug"
		symbols "On"

	filter "configurations:Release"
		optimize "On"

	filter {}

    project "Blackjack"
        kind "ConsoleApp"
        language "C++"
        location "Blackjack"
        cppdialect "C++17"

        targetdir ("%{wks.location}/build/bin/%{prj.name}")
        objdir ("%{wks.location}/build/bin-int/%{prj.name}")

        files {
            "Blackjack/src/**.h",
            "Blackjack/src/**.cpp"
        }

        includedirs {
            "src"
        }
