# Anemone

## Introduction
Anemone aims to be a game engine / game engine generator. This means we want to build a highly modular engine which should, later down the line, include features such as code generation with parameters or easy editing of the engine's code. These features should help people create engines specific to games, while keeping the software lightweight and the generation thereof streamlined.

## How does modularity work here?
We plan to make Anemone module using largely just macros and definitions, alongside a script to add and remove these things from a set of important files. This means that the user can simply start the script and tell it to add or remove configurations, or to choose specific modules. However, we want to keep this as debugger friendly as possible, so we will try and keep things relatively simple on the level of macros.

## What are we using?
Anemone will use Vulkan with GLFW. Math should happen using GLM at first, but in the spirit of modularity, this library should be made easy to switch out with a user-made one.
