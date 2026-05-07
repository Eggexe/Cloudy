# The Design Document

Welcome to the Design Document, a very lengthy and potentially boring explanation of why things work around here, covering Architecture, future design for ECS, and the eventual ML system.  

## Why is this required?
Firstly, why is this created? Well following the formal release of V1 for Cloudy, it seriously lacked a formal architecture, standard procedure and had the awful hardcoded attributes for entities. This had to change, and with V2 being a longer and more ambitious project, I do need a way to write what I’m thinking.  

That's the main gist of the creation of this document, is to have a place to be able to write down my own thoughts on different parts of this so-called "Engine" and take it to a direction of actual professionalism.  

While I'm fully aware there will be 0 practical application for this Software and no reason as to why anyone in their right mind would bother to use this engine over one that can do what I've attempted about 10x better, I still feel it is important to document what I want, write about it (so I don't forget) and have something that looks presentable with (hopefully) something presentable at the end.  

This Design Document (DD) will cover some fairly basic features that I want to implement. Whether everything listed will be added for V2 or may occur as a staggered release (ECS for V2 and ML for V3), I don't know yet. Which is also why this exists! It is also worth noting that a lot of these topics are very new for me and, assuming you may have some greater knowledge than I, you may feel very confused about why X occured, if so, chalk it up to my lack of knowledge!

- Architecture overview -> How does the engine handle data and other bits and pieces?
- Entity representation -> How are entities represented within my engine?
- Component storage -> How are components stored and summoned in the engine (is that the right word)?
- System design -> Cant have an E without the C or a C without the S, basically covers how the engine (and components) handle systems.
- ML Agent Interface -> How are Agents constructed in-engine and then in-game?
- World snapshot -> Fancy thing for Agents to read from
- Reward system -> How are rewards handles in-engine?  

And wow, that is a lot to cover. Like I said, the likelihood is that ECS will be implemented first and the ML, seeing as, well, it IS a lot to go over.

### Architecture Overview

The point of Architecture Overview is to answer 3 simple questions: What will Cloudy V2 be at it's core?; Basic principles of the new version; How the major systems mentioned connect.  

Starting off with how Cloudy V2 will differ  from V1, CV2 (Cloudy V2 but shorter) will aim to be a general purpose game engine with a minimalistic Entity Component System architecture, which will be used for making games. Entities will be represented as simple IDs, a numerical value saved in memory. Components can then be attached to these IDs to give entities various functionality. Components will merely store data and nothing else, as that is the core of ECS. Then, a system will define how to use the data it is given. Such as, a spriteComponent may take a path to a file, the System will then take the component and then enact its data onto the screen, hope that makes sense!  

All gameplay, whether it's an action, event or whatever, will be placed into a large data bank (clarify later) for an Agent to read off of. The idea will be to have the engine publish to a "World snapshot" as it has been called, which the Agent can read from. The engine will provide the tools to publish to the world snapshot, however it is up to the developer what gets published. By default, no engine internals are published whatsoever, to reduce noise within RL algorithms.  

Finally, a reward system shall be in place to suit RL algorithms. As with the world snapshot system, reward systems are kept internally within the engine as a definition for what they are and how they are used. However, the engine will provide functionality to allow for the game developer to utilise the engine's reward system to modify it and utilise it where necessary.  

To summarise:
- Entities are pure integers
- Components are pure data
- Systems enact logic with component data
- AI can be optional, it is not a requirement
- All input sources should be kept equal

## Entity Representation

As stated in Architecture Overview, entities are purely integers. Currently, entities posses these basic attributes: `id`, `awake`, `posX`, `posY`, `scaleX`, `scaleY`. This was badly designed for V1's engine where, if I were to make an entity to play music, it wouldn't need a scale. Speaking of scale, it is worth mentioning scaleX and scaleY are referring to width and height respectively. I initially wrote scale variables as a means to scale entities by X number. Now, in practise this had no use and I also realised that I would need some form of width and height variable so these became very poorly named variables for that case. Going back to the original point, forcing all entities to have these 6 attributes is bad design inherently, referring to the given example.  

For an ECS implementation, entities have already been described as purely integers. As of writing this (2026-05-07), I have already written the updated entity code to only feature an ID. I was debating forcing the awake state but that would break the ECS architecture I want to follow so likely I'll be making a component that tracks an awake state. With entities being represented as integers, the next step to assess is components. How should components work?

## Component Storage

So components in ECS hold pure data, which is great. Why is this great? Well it means that components can merely be structs, without needing any other weird features, just write the data you want a component to hold and there, it holds it. However, one thing that has been bothering me is how systems grab the component's data. Do I list all component structs in one massive file? Probably not, systems could potentially access other component data which isnt cool. What about having 1 file per component and 1 file per system? I believe this is likely the better solution as it's easier to manage and track who uses what (and you're less likely to attach a system to the wrong component). Another thing is how do systems use components? Well the simplest answer is components will probably be some form of a header file. Speaking of:

### Header files
So when designing my pong.c game, there were like 8 lines of include directories. Not only does this look very ugly but it also:  
- Kind of exposes part of the engine
- Also just is very pain stakingly boring

While it does allow users to nitpick parts of the engine they want, I feel it would be more useful to have 1 global header which then imports all the others. How to do this? No idea, but it is something to definitely look into.  

This does also allow for modularity when designing games in the engine as, as stated before, Agents in games that are made should not be required. This can be solved by, for example, not including a `CloudyAI.h` file. This can be done for components too within the engine however, since they are a core component for V2, they'll be included by default in the future global Cloudy header.  

## Systems Design

Final letter now. So systems are supposed to use the structs in their respective component to be able to manipulate. Now there are 2 issues with this. 1, the systems may not be able to actually modify the struct in the header (am yet to test but if its my idea, it probably won't work), and 2, how can the header files be tied to an integer?  

This is my first main issue with the current implementation of my architecture.
