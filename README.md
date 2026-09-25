# Custom C++ Graphics Renderer
> A lightweight, low-level real-time C++ graphics engine build from scratch. Focuses on memory management, zero-allocation render loops and optimized command buffer architecture.
---

## Preview & Demo
![Renderer Showcase](Media/render_demo.gif)

*Demonstration of rendering
---

## Project Overview & Summary
The **C++ Graphics Renderer** is a low-level graphics framework designed to build a rendering pipeline from the ground up.

### Key Features

---

## Table of Contents
* [Preview & Demo](#preview--demo)
* [Project Overview & Summary](#project-overview--summary)
* [Technology Choices](#technology-choices)
* [GitHub Workflow & Collaboration Rules](#github-workflow--collaboration-rules)
* [Project Logs and Time Tracking](#project-logs-and-time-tracking)
  * [Hubert Time Track](#huba-timesheet)
  * [Josh Time Track](#Josh-timesheet)
* [Technical Breakdown & Architecture](#technical-breakdown--architecture)
  * [Stage 1: Base Framework & Window Context](#stage-1-base-framework--window-context)
* [Challenges & Optimization Hurdles](#challenges--optimization-hurdles)
* [Takeaways & Key Learnings](#takeaways--key-learnings)
* [How to Build & Run](#how-to-build--run)
---

## Technology Choices
### 1. Windowing Library: GLFW over SDL
* **Why:** GLFW is explicitily designed as a lightweight windowing & input-handling library for OpenGL and Vulkan. SDL on the otherhand is a broad multimedia framework containing audio, software renderering and controller systems. Since the renderer is build from scratch, GLFW provides a clean slate with no extra bloat.

### 2. Graphics API: Modern OpenGL over Vulkan
* **Why:** Vulkan requires hundreds of lines of code allocating command pools, handling swapchain recreations and managing sync primitives just to clear the screen. Starting with OpenGL allows focussing on rasterization pipelines, shaders and lighting faster without getting stuck in driver management.
* **Future Porting:** Concepts built here will map directly to Vulkan abstractions for future porting
---

## Github Workflow
To keep the main branch stable and to ensure smooth collaboration, these rules were set in place:
1. **Branching Strategy:**
    * `main`: Fully working code, never commit directly to.
    * `feature/<feature-name>`: Create short-lived feature branches for specific tasks.
    * `bug/<bug-name>`: Short-lived branches for bug fixes.
2. **Pull Requests:**
    * Open a PR when a stage is functional.
    * Requires approval from other team memeber.
---

## Project Logs and Time Tracking

### Hubert Time Track
| Date | Time Window | Session Duration | Focus Area |
| --- | --- | --- | --- |
| **25 Sept 2026** | 11:15-13:00 | 1 hr 45 mins | Inital Setup & Initial Rendering & Basic triangle Rendering |
| **Future Updates** | TBD | TBD | TBD |

* **Project Start Date:** 25 Sept 2026
* **Project Finish Date:** In Progress
* **Hubert Total Time:** 1 hrs 45 mins
---

### Josh Time Track
| Date | Time Window | Session Duration | Focus Area |
| --- | --- | --- | --- |
| **TBD** | TBD-TBD | TBD | TBD |
| **Future Updates** | TBD | TBD | TBD |

* **Josh Total Time:** 0 hrs 0 mins
---

* **Combind Project Hours:** 1 hrs 45 mins (Ongoing)

---

### Technical Breakdown & Architecture

### Stage 1: Base Framework & Window Context
* **Objective:** Establish a CMake build pipeline, GLFW Window management and initialize an OpenGL context to render the first colored mesh.
* **Technical Overview:**
    * **Shader Pipeline:** Create a lightweight `Shader` class to read, compile and link vertex and fragment GLSL shaders at runtime with a built-in error checker.
    * **Geometry & Buffers:** Build a vertex buffer ($XYZ$ positions + $RGB$ colors) passed into GPU memory via a Vertex Buffer Object (VBO), configured vertex attributes within a Vertex Array Object (VAO) and rendered a triangle using an Element Buffer Object (EBO) with `glDrawElements()`.
---

## Challenges & Optimization Hurdles

### 1. More of Project needs to be done
* **Problem:**
* **Solution:**
---

## Takeaways & Key Learnings
1. **VAO State Rendering:** A Vertex Array Object automatically captures buffer bindings and attribute pointers when active, allowing rendering of complex geometry in the loop with a single `glBindVertexArray()` call/
---

## How to Build & Run

### Prerequisites
* **C++ Compiler:** C++17 or C++20 compiler (e.g. GCC)
* **Build System:** CMake 3.16+
* **Dependencies:** GLDW, GLAD

### Building the Project
```bash
# Clone the repo
git clone https://github.com/HubertG07/Custom-C-Graphics-Renderer.git
cd cd Custom-C-Graphics-Renderer

# Generate build files
cmake -B build -DCMAKE_BUILD_TYPE=Release

# Build the exe
cmake --build build --config Release
```

### Running the Renderer
Run the exe in the build/Release folder

## License & Usage
This project is open-source and free to use, adapt or build upon without credit :)