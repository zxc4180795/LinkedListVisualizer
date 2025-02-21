# Sorting Visualization Project

This is a sorting algorithm visualization project developed using the OpenFrameworks framework. Through this project, users can visually observe and understand the execution process of different sorting algorithms. The project transforms abstract algorithm steps into dynamic visual effects through graphical representation, making learning and demonstrating sorting algorithms more vivid and easier to understand.

## Features

- Generate and display 5 random numbers (range: 10-100)
- Visualize numbers as solid green circles
- Support multiple sorting algorithms
- Include shuffle functionality

## Sorting Algorithms

The project implements the following sorting algorithms:
1. Bubble Sort
2. Insertion Sort
3. Merge Sort
4. Quick Sort

## Keyboard Controls

- `r`: Generate new random numbers
- `b`: Execute Bubble Sort
- `i`: Execute Insertion Sort
- `m`: Execute Merge Sort
- `q`: Execute Quick Sort
- `s`: Execute Fisher-Yates Shuffle

## Project Structure

```
project/
│
├── src/
│   ├── main.cpp          # Program entry
│   ├── ofApp.cpp         # Main implementation
│   └── ofApp.h           # Header file
│
└── README.md             # Project documentation
```

## Technical Details

- Written in C++
- Based on OpenFrameworks framework
- Visual effects:
  - Black background
  - Solid green circles
  - Black text for numbers
  - Circle size proportional to value

## Installation Guide

1. Ensure OpenFrameworks is installed
2. Clone this project to OF project directory
3. Generate project files using project generator
4. Compile and run the project

## Development Requirements

- Latest version of OpenFrameworks
- C++ compiler
- IDE (Visual Studio or Xcode recommended)

## Implementation Details

### Data Structure
- Uses `std::vector<int>` for number storage
- Constants defined for circle display parameters

### Visualization Implementation
- Circle radius = value * 0.5
- Horizontal spacing between circles: 150 pixels
- Vertical position: 300 pixels
- Starting X coordinate: 200 pixels

### Random Number Generation
- Uses `std::random_device` and `std::mt19937` for high-quality random numbers
- Range: integers between 10 and 100

## Notes

- Program window size: 1024x768
- Ensure sufficient monitor resolution for full display
- Keep window focused for keyboard input

## Contribution Guidelines

1. Fork this project
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create Pull Request

