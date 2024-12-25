# About the project
<div align="center">
  <img src="media/images/zmall_world_logo.png" alt="Zmall World">
</div>
Zmall World is a web platform for running other web apps, developed in javascript and C++. The purpose is to build a solution which utilizes one single front end written in pure HTML and Javascript which is being used to all the apps added to the platform. The apps therefore only need to provide back ends which can be written in any language as needed. The platform will redirect the use to the apps upon request.

The client uses web sockets for communication and receives and processes general draw instructions which renders unto a double buffered HTML5 canvas.

## Build with
* [Boost](https://www.boost.org)

# Getting started

Clone the repo

    git clone https://github.com/Zmallwood/ZmallWorld.git

Enter project directory

    cd ZmallWorld

# Build instructions

## Prerequisites

**Build system - xmake**

Install instructions can be found at [xmake.io](https://xmake.io)

**Build command**

    make

# Running instructions

**Run command for development**

This will start up the Zmall World server along with the provided default app Dark World and open the client html file directly without a web server.

    make run_dev

# Provided default apps
<div align="center">
  <img src="media/images/dark_world_logo.png" alt="Dark World">
</div>

Dark World is an online role playing game using the Zmall World platform.

# Roadmap
- [X] Create README
- [X] Create working prototype for Zmall World
- [ ] Create working prototype for Dark World

# License
Distributed under the MIT License. See LICENSE file for more information.

# Contact
Andreas Åkerberg - zmallwood@proton.me

Project Link: https://github.com/ZmallWood/ZmallWorld

# Acknowledgements
* [xmake](https://xmake.io)
* [Daimonin](https://www.daimonin.org)
* [The Mana World](https://www.themanaworld.org)
