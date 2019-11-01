
#include "Image.h"
#include <gtest/gtest.h>
using namespace ::testing;
// for more details on gtest see here https://github.com/google/googletest/blob/master/googletest/docs/primer.md
// my lecture https://nccastaff.bournemouth.ac.uk/jmacey/PP/slides/testing/slides.html#/
TEST(Image, defaultCtor)
{
    Image i;
    EXPECT_EQ(i.width(),0);
    EXPECT_EQ(i.height(),0);
    EXPECT_EQ(i.channels(),3);
    EXPECT_EQ(i.pixels(),nullptr);

}

TEST(Image, userCtor)
{
    Image i(100,100);
    EXPECT_EQ(i.width(),100);
    EXPECT_EQ(i.height(),100);
    EXPECT_EQ(i.channels(),3);
    EXPECT_NE(i.pixels(),nullptr);
}


TEST(Image, setPixel)
{
    Image i(100,100);
    i.setPixel(10,10,255,128,12);   //set first pixel to red
    unsigned char r,g,b;
    i.getPixel(10,10,r,g,b);
    EXPECT_EQ(r,255);
    EXPECT_EQ(g,128);
    EXPECT_EQ(b,12);
}

TEST(Image, writeFile)
{
    int length = 100;
    Image i(length, length);
    for (int j = 30; j < 60;j += 3)
    {
        for (int k = 30;k < 60;k += 3)
        {
            i.setPixel(j,k,255,0,0);
            i.setPixel(j+1,k+1,0,255,0);
            i.setPixel(k+2,k+2,0,0,255);
        }
    }

    i.write("test.png");
    EXPECT_TRUE(i.write("test.png"));

}

TEST(Image, clearColour)
{
    Image i(100,100);
    i.clearColour(128,128,128);
    i.setPixel(0,0,255,0,0);
    i.setPixel(1,0,0,255,0);
    i.setPixel(2,0,0,0,255);
    EXPECT_TRUE(i.write("test.png"));
}

TEST(Image, copyColour)
{
    Image i(100, 100);
    i.clearColour(128,128,128);
    i.setPixel(0,0,255,0,0);
    i.setPixel(1,0,0,255,0);
    i.setPixel(2,0,0,0,255);

    Image image2 = i;
    unsigned char r,g,b;
    i.getPixel(1,0,r,g,b);
    EXPECT_EQ(r,0);
    EXPECT_EQ(g,255);
    EXPECT_EQ(b,0);
}


