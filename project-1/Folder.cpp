#include "Folder.hpp"

Folder::Folder(const std::string& name) : name_{"NewFolder"} {
   if (name.empty()) { return; }

   for (const char& c : name) {
      if (!std::isalnum(c)) {
         throw InvalidFormatException("Invalid folder name: " + name);
      }
   }
   
   name_ = name;
}

std::string Folder::getName() const {
   return name_;
}

bool Folder::rename(const std::string& new_foldername) {
   for (const char& c : new_foldername) {
      if (!std::isalnum(c)) { return false; }
   }

   name_ = new_foldername;
   return true;
}

void Folder::display() {
   std::sort(files_.begin(), files_.end());

   std::cout << getName() << std::endl;
   for (auto it = files_.begin(); it != files_.end(); ++it) { std::cout << "   " << it->getName() << std::endl; }
}

//                       DO NOT EDIT ABOVE THIS LINE. 
//             (unless you want your work to be tested incorrectly)
//    That also means includes. Remember, all other includes go in .hpp
// =========================== YOUR CODE HERE ===========================

size_t Folder::getSize() const {
   return files_.size();
}

bool Folder::addFile(File& new_file) {
   for (File& file : files_) {
      if (file.getName() == new_file.getName()) { //if name is already present in folder
         return false;
      }
   }

   files_.push_back(std::move(new_file));
   return true;
}

bool Folder::removeFile(const std::string& name) {
   auto itr = files_.begin();
   while ((*itr).getName() != name && itr != files_.end()) { //find file
      ++itr;
   }
   if (itr != files_.end()) { //if file was found
      files_.erase(itr);
      return true;
   }
   return false;
}

bool Folder::moveFileTo(const std::string& name, Folder& destination) {
   if (this != &destination) {
      auto itr = files_.begin();
      while ((*itr).getName() != name && itr != files_.end()) { //find file
         ++itr;
      }
      bool ifMoved = destination.addFile(*itr);
      // removeFile(name);
      return ifMoved;
   }
   return false;
}

bool Folder::copyFileTo(const std::string& name, Folder& destination) {
   if (this != &destination) {
      auto itr = files_.begin();
      while ((*itr).getName() != name && itr != files_.end()) { //find file
         ++itr;
      }
      File copy{*itr};
      bool ifCopied = destination.addFile(copy);
      return ifCopied;
   }
   return false;
}