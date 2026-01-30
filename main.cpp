#include "include/constants.hpp"
#include "include/mandelbrot.hpp"
#include <iostream>
#include <raylib.h>
#include <thread>
#include <vector>

Color LerpColor(Color a, Color b, float t) {
  return {(unsigned char)(a.r + (b.r - a.r) * t),
          (unsigned char)(a.g + (b.g - a.g) * t),
          (unsigned char)(a.b + (b.b - a.b) * t), 255};
}

void renderStrip(int xStart, int yStart, int xEnd, int yEnd,
                 std::vector<Color> &pixels, double maxReal, double minReal,
                 double maxImag, double minImag) {
  using namespace Constants;

  double xNorm{};
  double yNorm{};
  double cReal{};
  double cImag{};

  for (int x{xStart}; x < xEnd; ++x) {
    for (int y{yStart}; y < yEnd; ++y) {
      xNorm = x / static_cast<double>(windowWidth);
      yNorm = y / static_cast<double>(windowHeight);

      cReal = minReal + xNorm * (maxReal - minReal);
      cImag = minImag + yNorm * (maxImag - minImag);

      int iterationsMandelbrot{calculateMandelbrot(cReal, cImag)};

      if (iterationsMandelbrot - 1 == maxIterations) {
        pixels[static_cast<size_t>(y * windowWidth + x)] = BLACK;
      } else {
        float t = static_cast<float>(iterationsMandelbrot) / maxIterations;
        Color color = LerpColor(BLUE, RED, t);
        pixels[static_cast<size_t>(y * windowWidth + x)] = color;
      }

      // std::cout << "Iterations: " << iterationsMandelbrot << '\n';
    }
  }
}

bool checkForRedraw(double &maxReal, double &minReal, double &maxImag,
                    double &minImag) {
  using namespace Constants;
  if (IsKeyPressed(KEY_UP)) {
    maxImag += 0.1;
    minImag += 0.1;
    std::cout << "Runter!" << '\n';
    return true;
  }
  if (IsKeyPressed(KEY_DOWN)) {
    maxImag -= 0.1;
    minImag -= 0.1;
    std::cout << "Hoch!" << '\n';
    return true;
  }
  if (IsKeyPressed(KEY_LEFT)) {
    maxReal += 0.1;
    minReal += 0.1;
    std::cout << "Links!" << '\n';
    return true;
  }
  if (IsKeyPressed(KEY_RIGHT)) {
    maxReal -= 0.1;
    minReal -= 0.1;
    std::cout << "Rechts!" << '\n';
    return true;
  }
  return false;
}

void reDraw(std::vector<Color> &pixels, double &maxReal, double &minReal,
            double &maxImag, double &minImag) {
  using namespace Constants;
  std::thread t1(renderStrip, 0, 0, windowWidth, windowHeight * 0.25,
                 std::ref(pixels), maxReal, minReal, maxImag, minImag);
  std::thread t2(renderStrip, 0, windowHeight * 0.25, windowWidth,
                 windowHeight * 0.5, std::ref(pixels), maxReal, minReal,
                 maxImag, minImag);
  std::thread t3(renderStrip, 0, windowHeight * 0.5, windowWidth,
                 windowHeight * 0.75, std::ref(pixels), maxReal, minReal,
                 maxImag, minImag);
  std::thread t4(renderStrip, 0, windowHeight * 0.75, windowWidth, windowHeight,
                 std::ref(pixels), maxReal, minReal, maxImag, minImag);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
}

int main() {
  double maxReal{1.0};
  double minReal{-2.5};
  double maxImag{1.25};
  double minImag{-1.25};
  std::vector<Color> pixels(Constants::windowWidth * Constants::windowHeight);

  InitWindow(Constants::windowWidth, Constants::windowHeight,
             "Mandelbrot Plot");
  SetTargetFPS(60);
  Texture2D texture{};
  {
    Image img =
        GenImageColor(Constants::windowWidth, Constants::windowHeight, BLACK);
    texture = LoadTextureFromImage(img);
    UnloadImage(img);
  }
  reDraw(pixels, maxReal, minReal, maxImag, minImag);
  BeginDrawing();
  ClearBackground(BLACK);
  UpdateTexture(texture, pixels.data());
  DrawTexture(texture, 0, 0, WHITE);
  EndDrawing();

  while (!WindowShouldClose()) {
    if (checkForRedraw(maxReal, minReal, maxImag, minImag)) {
      reDraw(pixels, maxReal, minReal, maxImag, minImag);
    }

    BeginDrawing();
    ClearBackground(BLACK);
    UpdateTexture(texture, pixels.data());
    DrawTexture(texture, 0, 0, WHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
