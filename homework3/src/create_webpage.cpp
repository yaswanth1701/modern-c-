#include "homework_3.h"
#include <iostream>
using namespace image_browser;

int main() {
  std::string title = "TEST WEBSITE", stylesheet = "stylesheet";
  ScoredImage img1 = std::make_tuple("data/000000.png", 0.5768);
  ScoredImage img2 = std::make_tuple("data/000100.png", 0.8961);
  ScoredImage img3 = std::make_tuple("data/000200.png", 0.1341);
  ImageRow row1 = {img1, img2, img3};
  ScoredImage img4 = std::make_tuple("data/000300.png", 0.7171);
  ScoredImage img5 = std::make_tuple("data/000400.png", 0.1223);
  ScoredImage img6 = std::make_tuple("data/000500.png", 0.4510);
  ImageRow row2 = {img3, img4, img5};
  ScoredImage img7 = std::make_tuple("data/000600.png", 0.9107);
  ScoredImage img8 = std::make_tuple("data/000700.png", 0.6969);
  ScoredImage img9 = std::make_tuple("data/000800.png", 0.3197);
  ImageRow row3 = {img7, img8, img9};
  std::vector<ImageRow> rows = {row1, row2, row3};
  CreateImageBrowser(title, stylesheet, rows);
}