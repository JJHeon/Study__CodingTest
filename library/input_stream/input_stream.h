#ifndef _INPUT_STREAM_H_
#define _INPUT_STREAM_H_

#include <string>
#include <ostream>
#include <fstream>

class InputStream {
   public:
    InputStream(const std::string& path);
    bool ReadFile();
    std::ostream& GetStream();    

   private:
    const std::string path_;

    bool IsExitsFile() const;
};

#endif