[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]

<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li><a href="#getting-started">Getting Started</a></li>
    <li><a href="#build-instructions">Build Instructions</a></li>
    <li><a href="#running-instructions">Running Instructions</a></li>
    <li>
      <a href="#provided-default-apps">Provided Default Apps</a>
      <ul>
        <li><a href="#dark-world">Dark World</a></li>
      </ul>
    </li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>

# About the project

<div align="center">
  <img src="media/images/zmall_world_logo.png" alt="Zmall World">
</div>
Zmall World is a web platform for running other web apps, developed in javascript and C++. The purpose is to build a solution which utilizes one single front end written in pure HTML and Javascript which is being used to all the apps added to the platform. The apps therefore only need to provide back ends which can be written in any language as needed. The platform will redirect the use to the apps upon request.

The client uses web sockets for communication and receives and processes general draw instructions which renders unto a double buffered HTML5 canvas.

## Built with

- [Boost](https://www.boost.org)

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
## Dark World
<div align="center">
  <img src="media/images/dark_world_logo.png" alt="Dark World">
</div>

Dark World is an online role playing game using the Zmall World platform. The game features a unique combination of game mechanics in the form of:
* Perma-death
* Instagib
* Player-versus-player combat

# Roadmap

- [x] Create README
- [x] Create working prototype for Zmall World
- [ ] Create working prototype for Dark World

# License

Distributed under the MIT License. See LICENSE file for more information.

# Contact

Andreas Åkerberg - zmallwood@proton.me

Project Link: https://github.com/ZmallWood/ZmallWorld

# Acknowledgements

- [xmake](https://xmake.io)
- [Best-README-Template](https://github.com/othneildrew/Best-README-Template)
- [Daimonin](https://www.daimonin.org)
- [The Mana World](https://www.themanaworld.org)

[contributors-shield]: https://img.shields.io/github/contributors/ZmallWood/ZmallWorld.svg?style=for-the-badge
[contributors-url]: https://github.com/ZmallWood/ZmallWorld/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/ZmallWood/ZmallWorld.svg?style=for-the-badge
[forks-url]: https://github.com/ZmallWood/ZmallWorld/network/members
[stars-shield]: https://img.shields.io/github/stars/ZmallWood/ZmallWorld.svg?style=for-the-badge
[stars-url]: https://github.com/ZmallWood/ZmallWorld/stargazers
[issues-shield]: https://img.shields.io/github/issues/ZmallWood/ZmallWorld.svg?style=for-the-badge
[issues-url]: https://github.com/ZmallWood/ZmallWorld/issues
[license-shield]: https://img.shields.io/github/license/ZmallWood/ZmallWorld.svg?style=for-the-badge
[license-url]: https://github.com/ZmallWood/ZmallWorld/blob/master/LICENSE
