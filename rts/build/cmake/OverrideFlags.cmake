# This file is part of the Spring engine (GPL v2 or later), see LICENSE.html

# Sets the overrides for compiler flags
# Only executed ONCE (on the initial cmake run)

if(MSVC)
	set(MSVC_EXTRA_DEFINES "/DWINDOWS /D_CRT_SECURE_NO_WARNINGS")
	set(MSVC_EXTRA_FLAGS "/wd4244 /wd4018 /wd4800 /wd4305 /wd4514 /wd4996 /wd4710 /wd4820")

	set(CMAKE_CXX_FLAGS_INIT "${MSVC_EXTRA_DEFINES} ${MSVC_EXTRA_FLAGS} /DWIN32 /D_WINDOWS /W3 /EHa /GR")
	set(CMAKE_CXX_FLAGS_DEBUG_INIT 			"/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1")
	set(CMAKE_CXX_FLAGS_MINSIZEREL_INIT     "/MD /O1 /Ob1 /D NDEBUG")
	set(CMAKE_CXX_FLAGS_RELEASE_INIT        "/MD /O2 /Ob2 /D NDEBUG")
	set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "/MD /Zi /O2 /Ob1 /D NDEBUG")

	set(CMAKE_C_FLAGS_INIT "${MSVC_EXTRA_DEFINES} ${MSVC_EXTRA_FLAGS} /DWIN32 /D_WINDOWS /W3")
	set(CMAKE_C_FLAGS_DEBUG_INIT 			"/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1")
	set(CMAKE_C_FLAGS_MINSIZEREL_INIT     "/MD /O1 /Ob1 /D NDEBUG")
	set(CMAKE_C_FLAGS_RELEASE_INIT        "/MD /O2 /Ob2 /D NDEBUG")
	set(CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "/MD /Zi /O2 /Ob1 /D NDEBUG")
endif ()
