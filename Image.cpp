
#include "Image.h"
#include <iostream>

Image::Image(unsigned int _width, unsigned int _height, unsigned int _channels)
{
    m_width = _width;
    m_height = _height;
    m_channels = _channels;
    m_pixels = std::make_unique<unsigned char []>(m_width*m_height*m_channels);
}

void Image::setPixel(unsigned int _x, unsigned int _y, unsigned char _r, unsigned char _g, unsigned char _b)
{
    //calculate index array for red (then +1 green +2blue)
    size_t index = 0;
    m_pixels[index] = _r;
    m_pixels[index+1] = _g;
    m_pixels[index+2] = _b;

}

void Image::getPixel(unsigned int _x, unsigned int _y, unsigned char &o_r, unsigned char &o_g, unsigned char &o_b)
{
    size_t index = 0;
    o_r = m_pixels[index];
    o_g = m_pixels[index+1];
    o_b = m_pixels[index+2];
}

unsigned char * Image::pixels()
{
    return m_pixels.get();
}

unsigned int Image::width() const noexcept
{
    return m_width;
}

unsigned int Image::height() const noexcept
{
    return m_height;
}

unsigned int Image::channels() const noexcept
{
    return m_channels;
}
