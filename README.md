# ☁️ Cloudy Game Engine

Cloudy is a game engine, written in C and uses SDL2. Designed to be minimal and a proof-of-concept software, it will allow the creation of games and, eventually, an easy integration for Machine Learning capabilities. 

> [!WARNING]
> Cloudy is still relatively new and, as a result, will change frequently.  
> Ensure to keep yourself up to date with the latest changes as and when they come.

## ☀️ How to use the software?

**Cloudy's Requirements:** SDL2, GCC  

To install on your preferred Linux distro:  

*Arch-based*  
```bash
sudo pacman -S sdl2 gcc
```

*Debian-based*  
```bash
sudo apt install sdl2 gcc
```

*Fedora-based*
```bash
sudo dnf install sdl2 gcc
```

Should you use any other distro and want to place your installation instructions here, or some are outright wrong, feel free to make a PR to fix!  

### 🔨 Building
Cloudy uses cmake by default, so I'd recommend installing it by getting the `cmake` package from your repository.  Clone the repository and then type `make` in the repo in your to compile cloudy, which will produce a binary called "cloudy" which you can then execute. 

```bash
make
./cloudy
```

> You can edit the Makefile to change the name of the compiled binary to whatever you like, don't think its a requirement to keep my awful name.

## 🛠️ Cloudy Roadmap

See below for a list of the latest changes

### 🟦 v1 - Prototype
- [x] Window & Renderer
- [x] Game loop
- [x] Input Manager
- [ ] Entity System
- [ ] Scene System
- [ ] Pong game demo

### 🟥 v2 - Proper release
- [ ] Entity Component System
- [ ] Component Handling
- [ ] Event bus
- [ ] Old systems refactor

## 🖋️ Naming Conventions

| Type | Convention | Example |
|---|---|---|
| Functions | `CDY_PascalCase` | `CDY_EntityCreate` |
| Structs | `CDY_PascalCase` | `CDY_Entity` |
| Struct fields | `camelCase` | `posX`, `awake` |
| Local variables | `snake_case` | `entity_manager` |
<br>
While this table is here, some variables do not follow this case as this was formalised later on in development, feel free to point out these erroneous variables for the V2 clean up. 

## ⚙️ Engine Breakdown
Todo, write when v1 finished <3

## 🥕 Contributing & License

> ⚠️ Cloudy is in early development and will change frequently, Cloudy APIs will change unexpectedly.

Cloudy is a personal development project under the **MIT License**, <ins>do what you want with it</ins>. Feel free to send a PR if you want to help with something, or don't I'm not too bothered.
