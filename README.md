# **Thanks for checking out my Game Engine project!**

I developed this engine using C++ and SDL to better understand how game engines work behind the scenes. My goal was to create a simple engine with reusable systems that could support different 2D games. I used the Singleton Pattern for the different managers and a shared Object class to keep the engine organized and reusable. Have a look at the additional details below.

#

**Rendering & Textures:**

Handles rendering game objects, loading textures, and displaying them on screen.

**Input Manager:** 

Tracks keyboard input and checks when keys are pressed or held.

**Object Manager:** 

Manages game objects, their updates, rendering, and collisions.

**Collision System:** 

Uses rectangle and circle colliders to detect collisions between objects and trigger their responses.

**Time Manager:** 

Tracks frame time and provides timers for gameplay.

**Math Manager:** 

Handles random number generation and basic vector calculations.

#

**Two games to test the engine and its systems:**

 <br/>


Flappy Bird             |  Crate Run
:-------------------------:|:-------------------------:
<img width="828" height="500" alt="Screenshot 2026-10-23 020138" src="https://github.com/user-attachments/assets/0f43ef35-402f-40f7-8894-64b1d9aa877b" />  |   <img width="825" height="504" alt="Screenshot 2026-10-23 020255" src="https://github.com/user-attachments/assets/4ce54d64-285b-4eac-854e-7e209a1aae2d" />
A game with jumping, moving pipes, and collision detection. | A game where players move left and right to avoid falling crates.

