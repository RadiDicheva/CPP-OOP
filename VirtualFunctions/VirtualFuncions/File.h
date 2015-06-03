#ifndef FILE_H_
#define FILE_H_
#include <iostream>
#include <string>
#include <vector>

class File
{
protected:
	std::string fileName;
public:
	File ();
	File(std::string name);
	~File()
	{
		std::cout << "DESTROYING FILE" << std::endl;
	}
	std::string GetName() const;
	virtual void Open() const
	{
		std::cout << "Opening file: " << fileName << std::endl;
	}
};

class ImageFile : public File
{
protected:
	int width, height;
public:
	ImageFile(std::string name, int width, int height);
	virtual int* GetData() const
	{
		int *arr = new int[width*height];
		return arr;
	}
	~ImageFile()
	{
		std::cout << "DESTROYING IMAGEFILE" << std::endl;
	}
};

class TextFile : public File
{
protected:
	std::string content;
public:
	TextFile(std::string name):File(name){}
	~TextFile()
	{
		std::cout << "DESTROYING TEXTFILE" << std::endl;
	}
	void PrintContent() const;
	void SetContent(std::string& content);
};

class PngImageFile : public ImageFile
{
public:
	PngImageFile (std::string name, int width, int height): ImageFile(name, width, height){}
	~PngImageFile()
	{
		std::cout << "DESTROYING PNGIMAGEFILE" << std::endl;
	}
	void Open() const
	{
		std::cout << "Opening a png." << std::endl;
	}
	int* GetData() const
	{
		int *arr = new int[width*height];
		for (int i = 0; i<=(width*height)-1; ++i)
		{
			*(arr+i)=0; 
		}
		return arr;
	}
};

class JpgImageFile : public ImageFile
{
public:
	JpgImageFile (std::string name, int width, int height): ImageFile(name, width, height){}
	~JpgImageFile()
	{
		std::cout << "DESTROYING JPGIMAGEFILE" << std::endl;
	}
	void Open() const
	{
		std::cout << "Opening a jpg." << std::endl;
	}
	int* GetData() const
	{
		int *arr = new int[width*height];
		for (int i = 0; i<=(width*height)-1; ++i)
		{
			*(arr+i)=1; 
		}
		return arr;
	}
};

class BmpImageFile : public ImageFile
{
public:
	BmpImageFile (std::string name, int width, int height): ImageFile(name, width, height){}
	~BmpImageFile()
	{
		std::cout << "DESTROYING BMPIMAGEFILE" << std::endl;
	}
	void Open() const
	{
		std::cout << "Opening a bmp." << std::endl;
	}
	int* GetData() const
	{
		int *arr = new int[width*height];
		for (int i = 0; i<=(width*height)-1; ++i)
		{
			*(arr+i)=2; 
		}
		return arr;
	}
};

class PdfTextFile : public TextFile
{
public:
	PdfTextFile(std::string name) : TextFile(name){}
	~PdfTextFile()
	{
		std::cout << "DESTROYING PDFTEXTFILE" << std::endl;
	}
	void Open() const
	{
		std::cout << "Opening a pdf." << std::endl;
	}
};

class DocTextFile : public TextFile
{
public:
	DocTextFile(std::string name) : TextFile(name){}
	~DocTextFile()
	{
		std::cout << "DESTROYING DOCTEXTFILE" << std::endl;
	}
	void Open() const
	{
		std::cout << "Opening a doc." << std::endl;
	}
};

class TxtTextFile : public TextFile
{
public:
	TxtTextFile(std::string name) : TextFile(name){}
	~TxtTextFile()
	{
		std::cout << "DESTROYING TXTTEXTFILE" << std::endl;
	}
	void Open() const
	{
		std::cout << "Opening a txt." << std::endl;
	}
};

#endif