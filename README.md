# MuseumOfMysteries
[![Hits-of-Code](https://hitsofcode.com/github/floofyplasma/museumofmysteries?branch=main)](https://hitsofcode.com/github/floofyplasma/museumofmysteries/view?branch=main)

My (WIP) game for the Breda University Intake assignment.

See my [devlog](./DEVLOG.md) for progress updates.

I used some free assets for this game, find any neccessary credits in the [credits](./CREDITS.md) file.

You are free to check out my source code and use it as a learning resource, just note I won't be taking contributions for now.

# TODO List

- [ ] Cross-Platform support
    - [x] Visual Studio Solution
    - [ ] *nix CMakeLists.txt
    - [x] Bundle all dependencies as a submodule
    - [ ] Automated build scripts
- [ ] Audio
    - [ ] Multi-Channel audio support
    - [ ] Volume controls
    - [ ] Basic positional audio(?)
    - [ ] Audio streaming
- [ ] Rendering Pipeline
    - [ ] Sprite/Surface layers (using multiple SDL textures for layering)
    - [ ] Texture atlas loading (to optimize performance and memory use)
    - [ ] Basic effects (e.g., grayscale, tinting, blending) using texture blending modes
    - [x] Animation support (e.g., sprite sheets or frame-based animation)
    - [ ] Parallax scrolling for multi-layer backgrounds
    - [ ] Frame rate cap or V-Sync 
- [ ] UI System (maybe dearimgui?)
    - [ ] Text rendering (using SDL_ttf for font support)
    - [ ] Buttons (with hover and click effects, e.g., changing texture color or opacity)
    - [ ] Sliders and input fields (for settings like volume)
    - [ ] HUD display and (basic) inventory management
    - [ ] Dialog boxes or notifications
- [ ] Gameplay Systems
    - [ ] ECS(?)
    - [ ] Physics and collision handling (using SDL_Rect for bounding box collisions)
    - [ ] Input mapping and configuration (supporting keyboard, mouse, and controller)
    - [ ] State management (for switching between game states like menu, play, and pause)
- [ ] Save/Load System
    - [ ] Basic save/load game functionality
    - [ ] Settings save/load (e.g., for volume)
    - [ ] JSON or XML serialization for game data
- [ ] Debugging Tools
    - [ ] Frame rate counter (could be rendered as a simple text overlay)
    - [ ] In-game debugging console(?) (for logging gameplay events or errors)
    - [ ] Logging system for gameplay events or errors
- [ ] Optimizations
    - [ ] Efficient memory management (for loading/unloading textures and audio assets as needed)
    - [ ] Texture atlas utilization (to reduce SDL texture binds and optimize rendering)
    - [ ] Batch rendering techniques (minimizing SDL_RenderPresent calls)
    - [ ] Asynchronous asset loading (loading textures/audio in background threads where feasible)