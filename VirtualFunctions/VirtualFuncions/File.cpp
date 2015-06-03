#include <iostream>
#include <string>
#include "File.h"

File::File(std::string name)
{
	this->fileName = name;
}

std::string File::GetName() const
{
	return this->fileName;
}

ImageFile::ImageFile(std::string name, int width, int height):File(name)
{
	this->width = width;
	this->height = height;
}

void TextFile::PrintContent() const
{
	std::cout << "This file contains: " << content << std::endl;
}

void TextFile::SetContent(std::string& content)
{
	this->content = content;
}