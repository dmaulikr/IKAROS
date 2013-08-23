#define IMAGE_LOADER_H_INCLUDED

//Represents an image
class Image 
{
	public:
		Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) 
		{ }
		~Image() 
		{
			delete[] pixels;
		}
		char* pixels;
		int width;
		int height;
};

//Reads a bitmap image from file
Image* loadBMP(const char*);