#ifndef FOLDER_H_
#define FOLDER_H_
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "File.h"

class Folder
{

public:
	Folder(std::string name);
	std::string GetName() const;
	std::vector<Folder*>& GetFolders();
	std::vector<File*>& GetFiles();
	void AddFolder(Folder* folder);
	void DeleteFolder(Folder* folder);
	void AddFile(File* file);
	void DeleteFile(File* file);
	void MoveFileTo(File* file, Folder* newFolder);

private:
	std::string folderName;
	std::vector<Folder*> Folders;
	std::vector<File*> Files;
	bool FileExists(File* fileAddress);
	bool FolderExists(Folder* folderAddress);
};

#endif