#include <iostream>

class Shape {};

class TwoDimensionalShape : public Shape {};

class ThreeDimensionalShape : public Shape {};

class Circle : public TwoDimensionalShape {};

class Square : public TwoDimensionalShape {};

class Triangle : public TwoDimensionalShape {};

class Shere : public ThreeDimensionalShape {};

class Cube : public ThreeDimensionalShape {};

class Terahdron : public ThreeDimensionalShape {};
