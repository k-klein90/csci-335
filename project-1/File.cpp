#include "File.hpp"

#include <algorithm>

std::string File::getName() const {
   return filename_;
}

std::string File::getContents() const {
   return contents_;
}

void File::setContents(const std::string &new_contents) {
   contents_ = new_contents;
}

int *File::getIcon() const {
   return icon_;
}

void File::setIcon(int *new_icon) {
   if (icon_) { delete[] icon_; }
   icon_ = new_icon;
}

std::ostream &operator<<(std::ostream &os, const File &target) {
   os << "Name: " << target.getName() << std::endl;
   os << "Size: " << target.getSize() << " bytes" << std::endl;
   os << "Contents: " << target.getContents();
   return os;
}

bool File::operator<(const File &rhs) const {
   return getName() < rhs.getName();
}

//                       DO NOT EDIT ABOVE THIS LINE. 
//             (unless you want your work to be tested incorrectly)
//    That also means includes. Remember, all other includes go in .hpp

// However, you may notice an operator overload you don't recognize (<<)
// Try calling the following once you've implemented a constructor & getSize():
//    File a; 
//    std::cout << a << std::endl;

// =========================== YOUR CODE HERE ===========================

File::File(const std::string& filename, const std::string& contents, int* icon) {
   if (std::count(filename.begin(), filename.end(), '.') > 1) {
      throw InvalidFormatException("Invalid file name: " + filename);
   }
   for (const char& c : filename) {
      if (!std::isalnum(c) && c != '.') {
         throw InvalidFormatException("Invalid file name: " + filename);
      }
   }
   if (filename.empty()) {
      ;
   } else if (filename.find('.') == std::string::npos) {
      filename_ = filename + ".txt";
   } else if (filename.find('.') == filename.size()-1) {
      filename_ = filename + "txt";
   } else {
      filename_ = filename;
   }

   setContents(contents);
   setIcon(icon);
}

size_t File::getSize() const {
   return getContents().size();
}

File::File(const File& rhs) {
   filename_ = rhs.filename_;
   contents_ = rhs.contents_;
   icon_ = rhs.icon_;
}

File& File::operator=(const File& rhs) {
   File copy{rhs};
   std::swap(*this, copy);
   return *this;
}

File::File(File&& rhs) noexcept {
   filename_ = std::move(rhs.filename_);
   contents_ = std::move(rhs.contents_);
   icon_ = rhs.icon_;
   rhs.icon_ = nullptr;
}

File& File::operator=(File&& rhs) noexcept {
   if (this != &rhs){
      filename_ = std::move(rhs.filename_);
      contents_ = std::move(rhs.contents_);
      delete[] icon_;
      icon_ = rhs.icon_;
      rhs.icon_ = nullptr;
   }
   return *this;
}

File::~File() {
   delete[] icon_;
   icon_ = nullptr;
}