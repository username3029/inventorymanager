# Inventory Tracking System

A simple console-based inventory tracking system built using C++ and the SplashKit library. This system allows users to manage items organized into categories, track stock quantities, and monitor stock levels.

## Features
*   Create and manage multiple inventory categories.
*   Add items to categories with specified names, quantities, and capacities.
*   Remove items from categories.
*   Update item quantities and capacities.
*   View stock status for items (Low, Medium, High) with color-coded indicators.

## Dependencies
*   [SplashKit](https://splashkit.io/)

## Building and Running

1.  **Ensure SplashKit is installed and configured.**
    Follow the instructions on the [SplashKit website](https://splashkit.io/articles/installation/).

2.  **Navigate to the project directory:**
    ```bash
    cd path/to/inventory3
    ```

3.  **Compile the project using the SplashKit SDK:**
    You can use the `skm build` command, which should automatically find all `.cpp` files:
    ```bash
    skm build
    ```
    Alternatively, you can compile explicitly with `skm g++`:
    ```bash
    skm g++ main.cpp utils.cpp status.cpp display.cpp category_actions.cpp navigation.cpp -o inventory_manager
    ```

4.  **Run the executable:**
    On Windows (if compiled to `inventory_manager.exe` by `skm build` or the g++ command):
    ```bash
    ./inventory_manager.exe
    ```
    Or simply `inventory_manager` if the `.exe` is implicit.
    On macOS/Linux:
    ```bash
    ./inventory_manager
    ```

## Usage
Follow the on-screen prompts to navigate the menus:
*   From the main menu, you can select a category to view its items, create a new category ('C'), or exit the program ('X').
*   Within a category menu, you can add items ('A'), remove items ('R'), change item quantity ('Q'), change item capacity ('C'), or return to the main menu ('X').
