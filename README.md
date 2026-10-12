# Image-Representation
# Baby PhotoShop (CS213 - Assignment 1)

## Overview
**BabyPhotoshop** is an interactive C++ image processing application that allows users to apply a variety of digital filters easily. The user can load an image, apply multiple filters sequentially, and then save the final result with the same or a new name.

---

## Student Team Info

| # | Name | ID | Filters Implemented |
| :-: | :--- | :-: | :--- |
| **1** | Haneen Osama Reda | 20250206 |  Grayscale Conversion, Flip Image, Merge Images, Sunlight Filter |
| **2** | Sara Hamada Mohamed | 20250270 |  Black & White, Rotate Image, Detect Image Edges, Old TV Effect |
| **3** | Nermeen Hesham Ezz El-Din | 20250706 |  Invert Image, Darken and Lighten Image, Crop Images, Purple Effect |
| **4** | Haya Hany Fathy | 20250725 |  Add Frame, Resize Images, Blur Images, Infrared Photography |

---

## Features & Filters (18 Filters)

| # | Filter Name | Description |
| :-: | :--- | :--- |
| **1** | **Grayscale Conversion** | Converts the image into grayscale tones. |
| **2** | **Black & White** | Converts the image into pure black and white. |
| **3** | **Invert Image** | Inverts the colors of the image. |
| **4** | **Add Frame** | Adds a simple or fancy frame with chosen colors. |
| **5** | **Flip Image** | Flips the image horizontally or vertically. |
| **6** | **Rotate Image** | Rotates the image by 90°, 180°, or 270°. |
| **7** | **Lighten / Darken Image** | Adjusts the brightness of the image. |
| **8** | **Resize Image** | Resizes the dimensions of the entire image. |
| **9** | **Merge Images** | Merges two images together. |
| **10** | **Detect Image Edges** | Identifies and highlights the boundaries of objects within an image. |
| **11** | **Crop Image** | Crops a specific region of the image based on start point and dimensions. |
| **12** | **Blur Image** | Smooths and reduces the level of detail or sharpness in the image. |
| **13** | **Sunlight Filter** | Enhances the warm natural sunlight of the image. |
| **14** | **Old TV Effect** | Adds scanlines and retro screen artifacts. |
| **15** | **Purple Filter** | Applies a purple tint effect across the image. |
| **16** | **Infrared Photography** | Simulates infrared light capture effects. |
| **17** | **Skewing Filter** | Processing technique used to distort or skew an image. |
| **18** | **Oil painting Filter** | Applies a stylized effect to make the image look like an oil painting. |

---

## How It Works

1. The program starts by prompting the user to load an image file to work on.
2. It verifies that the file exists and has a supported extension (.jpg, .bmp, .png, etc.).
3. A menu is displayed to choose from available filters, load a new image, save the current image, or exit.
4. After applying any filter, the result becomes the current image for any subsequent filters.
5. At any point, the user can save the current image.

---

## How to Run

1. Open the project folder in your IDE.
2. Compile and run main.cpp.
3. Follow the on-screen menu to load an image, apply filters, and save the output.


## How to Run (GUI Version)

1. Open the ".pro" project file in Qt Creator.
2. Ensure the MinGW C++ compiler is configured for the project.
3. Click the 'Run' button (or press Ctrl+R) to launch the BabyPhotoshop graphical interface.
4. Use the on-screen buttons to load an image, select from the 18 available filters via the dropdown menu, and save the result.

---

## Technologies Used

- **Language:** C++
- **Development Environments & Tools:** 
  * Visual Studio Code / Qt Creator
  * MinGW C++ Compiler
- **Library:** Custom `Image_Class` (for handling image operations)

---

## Notes

- The image must be located in the same directory as the executable file.
- Always include the correct file extension (e.g., `.jpg` or `.png`).
