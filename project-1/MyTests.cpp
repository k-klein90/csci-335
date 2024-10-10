#include "File.hpp"
#include "Folder.hpp"
#include <iostream>

int main() {
   File f{"abc.docx", "asdfghjkl"};
   std::cout << f << std::endl;
   File i;
   Folder folder;
   bool added = folder.addFile(i);
   if (added) {
      std::cout << "Added" << std::endl;
   } else {
      std::cout << "Not Added" << std::endl;
   }
   folder.display();
}