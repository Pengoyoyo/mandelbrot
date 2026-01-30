#include "include/mandelbrot.hpp"
#include "include/constants.hpp"

int calculateMandelbrot(double cReal, double cImag) {
  double zImag{0};
  double zReal{0};
  double zImagNeu{};
  double zRealNeu{};
  double zImagSquared{};
  double zRealSquared{};
  int iterations{};

  for (; iterations <= Constants::maxIterations; ++iterations) {
    zRealSquared = (zReal * zReal);
    zImagSquared = (zImag * zImag);

    zRealNeu = zRealSquared - zImagSquared + cReal;
    zImagNeu = 2 * zReal * zImag + cImag;

    zReal = zRealNeu;
    zImag = zImagNeu;

    if (zRealSquared + zImagSquared > 4) {
      break;
    }
  }
  return iterations;
}
