#include "image_browser.hpp"
#include "html_writer.hpp"
#include <array>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using namespace html_writer;
using namespace image_browser;

void AddFullRow(const ImageRow &row, bool first_row = false) {
  bool first_img;
  for (auto col = row.begin(); col != row.end(); ++col) {
    if (col == row.begin()) {
      first_img = true;
    } else {
      first_img = false;
    }
    AddImage(get<0>(*col), get<1>(*col), first_img);
  }
}
void CreateImageBrowser(const std::string &title, const std::string &stylesheet,
                        const std::vector<ImageRow> &rows) {

  bool first_row;
  OpenDocument();
  CloseDocument();
  AddCSSStyle(stylesheet);
  AddTitle(title);
  OpenBody();
  for (auto row = rows.begin(); row != rows.end(); row++) {
    if (row == rows.begin()) {
      first_row = true;
    } else {
      first_row = false;
    }
    image_browser::AddFullRow(*row, first_row);
  }
}