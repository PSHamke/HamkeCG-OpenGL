
workspace "HamkeCG-OpenGL"
	platforms {"Win32"}

	startproject "HamkeCG-OpenGL"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	filter "platforms:Win32"
        architecture "x86"
		
outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	characterset ("MBCS")

	
project "HamkeCG-OpenGL"
	location "HamkeCG-OpenGL"
	kind "WindowedApp"
	language "C++"
	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")
	
	links
	{
		"opengl32.lib",
		"glu32.lib",
		"glaux.lib",
		"odbc32.lib",
		"odbccp32.lib"
	}
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/csv-parser"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"


	
	filter "configurations:Debug"
		defines "__DEBUG__"
		symbols "On"

	filter "configurations:Release"
		defines "__RELEASE__"
		symbols "On"

	filter "configurations:Dist"
		defines "__DIST__"
		symbols "On"


		