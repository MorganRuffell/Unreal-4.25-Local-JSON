# Unreal Engine JSON Implementation

This is a simple programming project built on the back of the Unreal Engine RPG Template that works with the FGameplayAbilitySystem.

The purpose of this project was to experiment with creating new systems inside of Unreal Engine 4.25, and refactor existing Blueprint code to C++. This was more of a learning 
exercise than anything else. I've developed this further after the completion of the unit as there was a lot of things I wanted to add that wasn't part of the brief.

I've always been fascinated by the concept of dynamic memory allocation, so I've updated a lot of the 'solid' objects in the blueprint to use lamba and async loading in 
the refactoring, this has been done in a safe way that ensures that the objects we are not unloading are not used beyond the scope of the required functions.

This is not a production ready project, it's more of creating an interesting back end that allows the creation of JSON objects that allow modification of game data at runtime.
this project was produced as part of Games System Design as part of my Degree in Games Technology.

The project uses the darker nodes and the electronic nodes plugin inside of the editor. 

## Tasks

- [X] Refactor material system on the player controller
- [X] Change the data types to allow export of XML, TXTs and CSV, in their approriate format rather than just JSON Strings
- []  Connect to Google Sheets and retrieve and save data from there

## Supported Editor & IDE

- Visual Studio 2019
- Unreal Engine 4.25


## External Links

Original Project:

https://docs.unrealengine.com/4.26/en-US/Resources/SampleGames/ARPG/
