#include "api/image_browser.hpp"
#include "api/html_writer.hpp"
#include <array>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
using namespace html_writer;

void image_browser::AddFullRow(const ImageRow &row, bool first_row) {
  bool first_img;
  OpenRow();
  for (auto col = row.begin(); col != row.end(); ++col) {
    if (col == row.begin() && first_row) {
      first_img = true;
    } else {
      first_img = false;
    }
    AddImage(get<0>(*col), get<1>(*col), first_img);
  }
  CloseRow();
}

void image_browser::CreateImageBrowser(const std::string &title,
                                       const std::string &stylesheet,
                                       const std::vector<ImageRow> &rows) {

  bool first_row;
  OpenDocument();
  AddTitle(title);
  AddCSSStyle(stylesheet);
  OpenBody();
  for (auto row = rows.begin(); row != rows.end(); row++) {
    if (row == rows.begin()) {
      first_row = true;
    } else {
      first_row = false;
    }
    AddFullRow(*row, first_row);
  }
  CloseBody();
  CloseDocument();
}