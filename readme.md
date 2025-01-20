# VEX V5 Logo Display Test

Thanks for checking out my project!  

This is a proof of concept to show how graphics can be displayed on the VEX Brain without using an SD card or the built-in `drawImageFromFile(filename, x, y)` function. Instead, this approach directly draws pixels using `Brain.Screen.drawPixel(x, y)`.

## Overview

While this method isn't the most efficient way to display an image, it's a fun and educational project to explore the VEX V5 system. The project involves converting an image into pixel data and drawing it programmatically on the screen.

---

## Step-by-Step Guide

### 1. Prepare an SVG File
Start with an SVG file. If you don’t have one, you can convert an image (e.g., PNG) to SVG using an online tool like:
- [Adobe PNG to SVG Converter](https://www.adobe.com/express/feature/image/convert/png-to-svg)

---

### 2. Extract Pixel Coordinates
Extract the `(x, y)` coordinates from the SVG file:
- Use [Spotify’s Coordinator Tool](https://spotify.github.io/coordinator/) to extract the coordinates.
- Download the generated CSV file after customizing the tool's settings to your needs.

---

### 3. Process the Coordinates in Google Sheets
1. Upload the CSV to Google Sheets.
2. Use formulas to modify and format the coordinates:
   - **Scaling**: Ensure coordinates fit the VEX Brain screen (`0-479` for x, `0-239` for y). You can use scaling formulas or modify the scale directly in the Coordinator tool (e.g., set a scale like `0.5` for half-size drawings).
   - **Mirroring/Transforming**: Adjust as needed.
   - **Example Formula to Format Commands**:
     ```excel
     =CONCAT("Brain.Screen.drawPixel(", C1, ",", D1, ");")
     ```
     This generates commands like `Brain.Screen.drawPixel(100, 150);`.

3. Example Google Sheet:
   - [Sample Sheet](https://docs.google.com/spreadsheets/d/1Dn1eNASMr1dJn_pP3AqGoAznHVG-r4NPp1HGcW76rqI/edit?usp=sharing)

---

### 4. Add the Commands to Your Code
1. Copy the generated `drawPixel` commands from your Google Sheet.
2. Paste them into a `.cpp` file (e.g., `image.cpp`) within a function like `drawRaven()`.
3. Include the function in your main program (`main.cpp`).

---

### 5. Optimize the Code
- Place the thousands of `drawPixel` commands into a separate `.cpp` file for better organization.
- Create a function (e.g., `drawRaven()`) that you can call from `main.cpp`.

---

### 6. Add Motion or Effects
Experiment with displaying and clearing the image to create effects such as movement or color transitions. Example:
```cpp
for (int i = 0; i < 10; i++) {
    drawRaven();
    wait(1, seconds);
    Brain.Screen.clearScreen();
    wait(200, msec);
}
