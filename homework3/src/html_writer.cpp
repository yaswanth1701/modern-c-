#include "api/html_writer.hpp"
#include <fmt/core.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace html_writer;
using namespace std;

void OpenDocument() {
  string open_html = fmt::format("<!DOCTYPE html> \n <html> ");
  cout << open_html << endl;
}

void CloseDocument() {
  string close_html = fmt::format("</html>");
  cout << close_html << endl;
}

void AddCSSStyle(const string &stylesheet) {
  string add_css = fmt::format("<head> \n <link rel = {} type = 'text/css' "
                               "href = 'style.css' /> \n </head>",
                               stylesheet);
  cout << add_css;
}

void AddTitle(const string &title) {
  string add_title = fmt::format("<title> {} </title>", title);
  cout << "\n <title>" + title + "</title>";
}

void OpenBody() { cout << "\n <body>"; }

void CloseBody() { cout << "\n </body>"; }

void OpenRow() { cout << "\n <div class='row'>"; }

void CloseRow() { cout << "\n </div>"; }

void AddImage(const string &img_path, float score, bool highlight = false) {
  string open_col, img_name, img_floder;
  stringstream image_path(img_path);
  getline(image_path, img_floder, '/');
  getline(image_path, img_name, '/');
  if (highlight) {
    open_col =
        fmt::format("<div class='column' style='border: 5px solid green;'>");
  } else {
    open_col = fmt::format("<div class='column'>");
  }

  string add_name = fmt::format("<h2>{}</h2>", img_name);
  string add_src = fmt::format("<img src='{}' />", img_path);
  string add_score = fmt::format("<p> score= {:.2f} </p>", score);
  string close_col = "</div>";
  cout << open_col << "\n";
  cout << add_name << "\n";
  cout << add_src << "\n";
  cout << add_score << "\n";
  cout << close_col << "\n";
}