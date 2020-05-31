cmake_minimum_required(VERSION 3.15)
project(POO2_Buffy_Crull_Lagier)

set(CMAKE_CXX_STANDARD 20)

add_executable(POO2_Buffy_Crull_Lagier main.cpp Humanoids/Humanoid.cpp Humanoids/Humanoid.h Humanoids/Slayer/Buffy.cpp Humanoids/Slayer/Buffy.h Humanoids/Slayer/Faith.cpp Humanoids/Slayer/Faith.h Humanoids/Monster/Vampire.cpp Humanoids/Monster/Vampire.h Humanoids/Hunter.cpp Humanoids/Hunter.h Humanoids/Victim/Person.cpp Humanoids/Victim/Person.h Field.cpp Field.h Action.cpp Action.h)