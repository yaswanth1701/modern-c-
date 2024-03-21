#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "html_writer.hpp"
using namespace html_writer;
using namespace std;

ofstream html_file("web_site.html");
streambuf *coutbuf = std::cout.rdbuf();
cout.rdbuf(out.rdbuf());

void OpenDocument(){
    cout << "<!DOCTYPE html> \n <html> " << endl;
}

void CloseDocument(){
    cout << "</html>" <<endl;
    html_file.close()
}

void AddCSSStyle(const string& stylesheet){
    stringstream add_css_style
    add_css_style << "\n" << "<head>" << "\n" << "<link rel="stylesheet" type="text/css" href="style.css" />" << "\n"
    << "</head>"
    cout << add_css_style.str()
}

void AddTitle(const string& title){
    cout << "\n <title>" + title + "</title>"
}

void OpenBody(){
    cout << "\n <body>"
}

void CloseBody(){
    cout << "\n </body>"
}

void OpenRow(){
    cout << "\n <div class="row">"
}

void CloseRow(){
    cout << "\n </div>"
}

void AddImage