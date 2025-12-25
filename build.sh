#!/bin/bash

echo "Building Godspeed Evolution Simulator..."

clang++ -std=c++11 \
  -I/opt/homebrew/include/SDL2 \
  -I/opt/homebrew/include \
  -L/opt/homebrew/lib \
  -I Godspeed_Game_Engine \
  Godspeed_Game_Engine/*.cpp \
  -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf \
  -o godspeed_evolution_sim

if [ $? -eq 0 ]; then
    echo "✓ Build successful! Run './godspeed_evolution_sim' to start the simulation."
else
    echo "✗ Build failed."
    exit 1
fi
