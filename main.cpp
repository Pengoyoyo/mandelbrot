#include "include/constants.hpp"
#include "include/mandelbrot.hpp"
#include <iostream>
#include <raylib.h>

Color LerpColor(Color a, Color b, float t) {
  return {(unsigned char)(a.r + (b.r - a.r) * t),
          (unsigned char)(a.g + (b.g - a.g) * t),
          (unsigned char)(a.b + (b.b - a.b) * t), 255};
}

void drawMandelbrot() {
  using namespace Constants;

  double xNorm{};
  double yNorm{};
  double cReal{};
  double cImag{};

  for (int x{}; x <= Constants::windowWidth; ++x) {
    for (int y{}; y <= Constants::windowHeight; ++y) {
      xNorm = x / static_cast<double>(Constants::windowWidth);
      yNorm = y / static_cast<double>(Constants::windowHeight);

      cReal = negRealRange + xNorm * (posRealRange - negRealRange);
      cImag = negImagRange + yNorm * (posImagRange - negImagRange);

      int iterationsMandelbrot{calculateMandelbrot(cReal, cImag)};

      float t = static_cast<float>(iterationsMandelbrot) / maxIterations;
      Color color = LerpColor(BLUE, RED, t);
      DrawPixel(x, y, color);
      // std::cout << "Iterations: " << iterationsMandelbrot << '\n';
    }
  }
}

int main() {
  InitWindow(Constants::windowWidth, Constants::windowHeight,
             "Mandelbrot Plot");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawMandelbrot();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
