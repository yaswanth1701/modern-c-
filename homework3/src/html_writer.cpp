#include "api/html_writer.hpp"
#include <fmt/core.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void html_writer::OpenDocument() {
  string open_html = fmt::format("<!DOCTYPE html> \n <html> ");
  cout << open_html << endl;
}

void html_writer::CloseDocument() {
  string close_html = fmt::format("</html>");
  cout << close_html << endl;
}

void html_writer::AddCSSStyle(const string &stylesheet) {
  string add_css =
      fmt::format("<head> \n <link rel = \"{}\" type = \"text/css\" "
                  "href = \"style.css\" /> \n </head>",
                  stylesheet);
  cout << add_css;
}

void html_writer::AddTitle(const string &title) {
  string add_title = fmt::format("<title> {} </title>", title);
  cout << "\n <title>" + title + "</title> \n";
}

void html_writer::OpenBody() { cout << "\n <body>"; }

void html_writer::CloseBody() { cout << "\n </body>\n"; }

void html_writer::OpenRow() { cout << "\n <div class= \"row\"> \n"; }

void html_writer::CloseRow() { cout << "\n </div>"; }

void html_writer::AddImage(const string &img_path, float score,
                           bool highlight) {
  string open_col, img_name, img_floder;
  stringstream image_path(img_path);
  getline(image_path, img_floder, '/');
  getline(image_path, img_name, '/');
  if (highlight) {
    open_col = fmt::format(
        "<div class=\"column\" style=\"border: 5px solid green;\">");
  } else {
    open_col = fmt::format("<div class=\"column\">");
  }

  string add_name = fmt::format("<h2>{}</h2>", img_name);
  string add_src = fmt::format("<img src=\"{}\" />", img_path);
  string add_score = fmt::format("<p> score= {:.2f} </p>", score);
  string close_col = "</div>";
  cout << open_col << "\n";
  cout << add_name << "\n";
  cout << add_src << "\n";
  cout << add_score << "\n";
  cout << close_col << "\n";
}