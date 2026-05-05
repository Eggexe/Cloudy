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
