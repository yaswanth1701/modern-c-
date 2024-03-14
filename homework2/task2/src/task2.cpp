#include <iostream>
#include <sstream>

int main(int argc, char const* argv[])
{
  if (argc > 3)
  {
    std::cerr << "wrong number of arguments" << std::endl;
  }

  int condition;
  std::stringstream filename1, filename2;
  int file_no1, file_no2;
  std::string file_ext1, file_ext2;
  filename1 << argv[1];
  filename2 << argv[2];
  filename1 >> file_no1 >> file_ext1;
  filename2 >> file_no2 >> file_ext2;
  if ((file_ext1 != ".txt" && file_ext1 != ".png") || (file_ext2 != ".txt" && file_ext2 != ".png"))
  {
    std::cerr << "invalid file extension" << std::endl;
  }
  else if (file_ext1 == ".png" && file_ext2 == ".png")
  {
    std::cout << (file_no1 + file_no2) << std::endl;
  }
  else if (file_ext1 == ".txt" && file_ext2 == ".txt")
  {
    std::cout << (file_no1 + file_no2) / 2 << std::endl;
  }
  else
  {
    std::cout << (file_no1 % file_no2) << std::endl;
  }
  return 0;
}