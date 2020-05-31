cmake_minimum_required(VERSION 3.15)
project(POO2_Buffy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Humanoids)
include_directories(Humanoids/Monster)
include_directories(Humanoids/Slayer)
include_directories(Humanoids/Victim)

add_executable(POO2_Buffy
    Humanoids/Monster/Vampire.cpp
    Humanoids/Monster/Vampire.h
    Humanoids/Slayer/Buffy.cpp
    Humanoids/Slayer/Buffy.h
        Humanoids/Victim/Lambda.cpp
    Humanoids/Victim/Lambda.h
    Humanoids/Humanoid.cpp
    Humanoids/Humanoid.h
    Humanoids/Hunter.cpp
    Humanoids/Hunter.h
    Action.cpp
    Action.h
    Field.cpp
    Field.h
    main.cpp)
