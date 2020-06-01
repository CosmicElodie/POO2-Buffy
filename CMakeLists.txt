cmake_minimum_required(VERSION 3.15)
project(POO2_Buffy)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Humanoids)
include_directories(Humanoids/Monster)
include_directories(Humanoids/Slayer)
include_directories(Humanoids/Victim)

add_executable(POO2_Buffy
    Humanoids/Hunter/Monster/Vampire.cpp
    Humanoids/Hunter/Monster/Vampire.h
    Humanoids/Hunter/Slayer/Buffy.cpp
    Humanoids/Hunter/Slayer/Buffy.h
        Humanoids/Victim/Lambda.cpp
    Humanoids/Victim/Lambda.h
    Humanoids/Humanoid.cpp
    Humanoids/Humanoid.h
        Humanoids/Hunter/Hunter.cpp
        Humanoids/Hunter/Hunter.h
        Action/Action.cpp
        Action/Action.h
    Field.cpp
    Field.h
    main.cpp Action/Moving/RunFrom.cpp Action/Moving/RunFrom.h Action/Kill.cpp Action/Kill.h Action/Moving/Move.cpp Action/Moving/Move.h Action/Moving/Wander.cpp Action/Moving/Wander.h)
