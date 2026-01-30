#include "include/constants.hpp"
#include "include/mandelbrot.hpp"
#include <iostream>
#include <raylib.h>

Color LerpColor(Color a, Color b, float t) {
  return {(unsigned char)(a.r + (b.r - a.r) * t),
          (unsigned char)(a.g + (b.g - a.g) * t),
          (unsigned char)(a.b + (b.b - a.b) * t), 255};
}

void drawMandelbrot(double maxReal = 1.0, double minReal = -2.5,
                    double maxImag = 1.25, double minImag = -1.25) {
  using namespace Constants;

  double xNorm{};
  double yNorm{};
  double cReal{};
  double cImag{};

  for (int x{}; x <= windowWidth; ++x) {
    for (int y{}; y <= windowHeight; ++y) {
      xNorm = x / static_cast<double>(Constants::windowWidth);
      yNorm = y / static_cast<double>(Constants::windowHeight);

      cReal = minReal + xNorm * (maxReal - minReal);
      cImag = minImag + yNorm * (maxImag - minImag);

      int iterationsMandelbrot{calculateMandelbrot(cReal, cImag)};

      if (iterationsMandelbrot - 1 == maxIterations) {
        DrawPixel(x, y, BLACK);
      } else {
        float t = static_cast<float>(iterationsMandelbrot) / maxIterations;
        Color color = LerpColor(BLUE, RED, t);
        DrawPixel(x, y, color);
      }

      // std::cout << "Iterations: " << iterationsMandelbrot << '\n';
    }
  }
}

int main() {
  double maxReal{1.0};
  double minReal{-2.5};
  double maxImag{1.25};
  double minImag{-1.25};
  InitWindow(Constants::windowWidth, Constants::windowHeight,
             "Mandelbrot Plot");
  SetTargetFPS(60);

  RenderTexture2D target =
      LoadRenderTexture(Constants::windowWidth, Constants::windowHeight);
  bool needsRedraw = true;

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_UP)) {
      maxImag += 0.1;
      minImag += 0.1;
      needsRedraw = true;
      std::cout << "Runter!" << '\n';
    }
    if (IsKeyPressed(KEY_DOWN)) {
      maxImag -= 0.1;
      minImag -= 0.1;
      needsRedraw = true;
      std::cout << "Hoch!" << '\n';
    }
    if (IsKeyPressed(KEY_LEFT)) {
      maxReal += 0.1;
      minReal += 0.1;
      needsRedraw = true;
      std::cout << "Links!" << '\n';
    }
    if (IsKeyPressed(KEY_RIGHT)) {
      maxReal -= 0.1;
      minReal -= 0.1;
      needsRedraw = true;
      std::cout << "Rechts!" << '\n';
    }

    if (needsRedraw) {
      BeginTextureMode(target);
      ClearBackground(RAYWHITE);
      drawMandelbrot(maxReal, minReal, maxImag, minImag);
      EndTextureMode();
      needsRedraw = false;
    }

    BeginDrawing();
    DrawTextureRec(
        target.texture,
        {0, 0, (float)target.texture.width, -(float)target.texture.height},
        {0, 0}, WHITE);
    EndDrawing();
  }

  UnloadRenderTexture(target);
  CloseWindow();
  return 0;
}
