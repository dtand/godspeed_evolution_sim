# Godspeed Evolution Simulator

A genetic algorithm simulation built on a custom C++ game engine using SDL2. This project visualizes evolutionary principles through a population of colored entities that reproduce, mutate, and evolve over time based on fitness values.

## Overview

The Godspeed Evolution Simulator demonstrates natural selection and genetic algorithms in a visual, interactive environment. Individuals with higher fitness values have better chances of passing their genes to the next generation, creating an evolving population that changes over time through crossover and mutation.

## Features

- **Genetic Algorithm Implementation**: Full genetic algorithm with selection, crossover, and mutation
- **Fitness-Based Selection**: Individuals with higher fitness values have proportionally better chances of reproduction
- **Visual Representation**: Each individual is represented as a colored entity on screen with randomly assigned RGB values
- **Time-Based Evolution**: World operates on a day/night cycle with mating occurring every 3 days
- **Console Logging**: Real-time feedback about births, mating, and population statistics
- **Custom Game Engine**: Built on the Godspeed Game Engine with support for game objects, rendering, and timing

## Architecture

### Core Components

#### World System
- **World**: Manages the simulation environment, population, and time progression
  - Initializes population with 1-5 random individuals
  - Tracks day cycles (60 seconds per day)
  - Triggers mating every 3 days
  - Manages the lifecycle of all individuals

#### Genetic Algorithm Components
- **Individual**: Represents a single entity with genetic traits
  - DNA encoded as fitness value (5-100 range)
  - Visual representation through RGB color values (20-230 range)
  - Random initial positioning within the game window
  
- **MatingPool**: Handles selection and reproduction
  - Creates fitness-proportionate selection pool
  - Higher fitness individuals appear more frequently in the pool
  - Randomly selects parent pairs for breeding
  
- **MatingHandler**: Manages genetic operations
  - Crossover between parent genes
  - Mutation with 2% probability
  - Creates offspring with inherited and mutated traits

#### Game Engine (Godspeed)
- **Game**: Abstract base class for game loop management
- **GameObject**: Base class for all renderable entities
- **GameProcessor**: Handles rendering and game state
- **Window**: SDL2 window management
- **GS_Timer**: Precise timing for events and updates
- **RandomNumberGenerator**: Utility for random value generation

## How It Works

1. **Initialization**: World spawns 1-5 random individuals with random fitness, color, and position
2. **Daily Cycle**: Each game day lasts 60 seconds of real time
3. **Mating Phase**: Every 3 days, reproduction occurs:
   - Fitness values are normalized across the population
   - A mating pool is created where individuals appear proportionally to their fitness
   - Each existing individual produces one offspring
   - Parents are randomly selected from the mating pool (weighted by fitness)
   - Offspring inherit traits through crossover and may undergo mutation
4. **Evolution**: Over generations, individuals with higher fitness become more prevalent

## Project Structure

```
Godspeed_Game_Engine/
├── Core Game Engine
│   ├── Game.cpp/h              - Main game loop and architecture
│   ├── GameObject.cpp/h        - Base class for all game entities
│   ├── GameProcessor.cpp/h     - Rendering and game state processing
│   └── Window.cpp/h            - SDL2 window management
│
├── Simulation Components
│   ├── World.cpp/h             - Simulation environment manager
│   ├── Individual.cpp/h        - Entity with genetic traits
│   ├── MatingPool.cpp/h        - Fitness-proportionate selection
│   └── MatingHandler.cpp/h     - Crossover and mutation operations
│
├── Utilities
│   ├── GS_Timer.cpp/h          - Event timing
│   ├── GS_StopWatch.cpp/h      - Time measurement
│   ├── RandomNumberGenerator.cpp/h - Random utilities
│   └── GlobalFunctions.cpp/h   - Helper functions
│
├── Graphics (Future/Unused)
│   ├── Sprite.cpp/h            - Basic sprite rendering
│   ├── AnimatedSprite.cpp/h    - Animated sprite support
│   └── SpriteSheet.cpp/h       - Sprite sheet management
│
└── main.cpp                    - Entry point

DerivedData/Frameworks/
├── SDL2.framework              - Core SDL2 library
├── SDL2_image.framework        - Image loading support
├── SDL2_mixer.framework        - Audio support
└── SDL2_ttf.framework          - TrueType font support
```

## Requirements

- **macOS**: Configured for macOS (Apple Silicon and Intel supported)
- **Homebrew**: Package manager for installing dependencies
- **SDL2**: Simple DirectMedia Layer 2
  - SDL2
  - SDL2_image
  - SDL2_mixer
  - SDL2_ttf
- **C++11** or later
- **Clang++**: C++ compiler (included with Xcode Command Line Tools)

## Building

### Prerequisites

1. **Install Xcode Command Line Tools** (if not already installed):
   ```bash
   xcode-select --install
   ```

2. **Install Homebrew** (if not already installed):
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

3. **Install SDL2 libraries**:
   ```bash
   brew install sdl2 sdl2_image sdl2_mixer sdl2_ttf
   ```

### Compile and Run

**Option 1: Use the build script**
```bash
cd /path/to/godspeed_evolution_sim
chmod +x build.sh
./build.sh
./godspeed_evolution_sim
```

**Option 2: Manual compilation**
```bash
cd /path/to/godspeed_evolution_sim

clang++ -std=c++11 \
  -I/opt/homebrew/include/SDL2 \
  -I/opt/homebrew/include \
  -L/opt/homebrew/lib \
  -I Godspeed_Game_Engine \
  Godspeed_Game_Engine/*.cpp \
  -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf \
  -o godspeed_evolution_sim

./godspeed_evolution_sim
```

**Option 3: Using Xcode (original method)**
1. Open `Godspeed_Game_Engine.xcodeproj` in Xcode
2. Ensure all SDL2 frameworks are properly linked
3. Build and run (⌘R)

> **Note**: The original Xcode project uses older Intel-only SDL2 frameworks located in `DerivedData/Frameworks/`. For Apple Silicon Macs, use the Homebrew installation method instead.

## Evolution Parameters

| Parameter | Value | Description |
|-----------|-------|-------------|
| Initial Population | 1-5 | Random starting population size |
| Fitness Range | 5-100 | Range of possible fitness values |
| Color Range | 20-230 | RGB value range for visual representation |
| Day Length | 60 seconds | Duration of each simulation day |
| Mating Frequency | Every 3 days | How often reproduction occurs |
| Mutation Rate | 2% | Probability of genetic mutation |
| Time Per Birth | 500ms | Delay between initial population spawns |

## Console Output

The simulation provides real-time console feedback:
- Entity birth announcements with fitness values
- Day progression tracking
- Mating pool initialization messages
- Parent and child information during breeding

## Future Enhancements

- Interactive fitness modification
- Multiple genetic traits beyond fitness
- Environmental selection pressures
- Population statistics and graphing
- Save/load simulation states
- Configurable evolution parameters
- Predator-prey dynamics
- Resource competition

## License

Copyright (c) 2015-2016 Daniel Anderson

## Author

Daniel Anderson (2015-2016)
