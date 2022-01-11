#include <chrono>
#include <iostream>

// Base class for all image types. The template
// parameter T is used to know type of derived
// class pointed by pointer.
template <class T>
class Image {
public:
    void Draw()
    {
        // Dispatch call to exact type
        static_cast<T*>(this)->Draw();
    }
};

class TiffImage : public Image<TiffImage> {
public:
    void Draw()
    {
         std::cout << "TiffImage::Draw() called" << std::endl;
    }
};

int main()
{
    Image<TiffImage>* pImage = new TiffImage;

    pImage->Draw();

    return 0;
}