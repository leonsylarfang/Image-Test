
#ifndef IMAGE_H
#define IMAGE_H
class Image
{
  public :
    Image()=default;
    ~Image() noexcept =default;
    Image(const Image &)=default;
    Image & operator=(const Image &)=default;
    Image(Image &&)=default;
    Image & operator=(Image &&)=default;
};

#endif
