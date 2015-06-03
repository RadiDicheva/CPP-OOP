#include <iostream>
#include "Folder.h"

Folder::Folder(std::string name)
{
	this->folderName = name;
};

std::string Folder::GetName() const
{
	return this->folderName;
}

std::vector<Folder*>& Folder::GetFolders()
{
	return this->Folders;
}

std::vector<File*>& Folder::GetFiles()
{
	return this->Files;
}

void Folder::AddFolder(Folder* folder)
{
	if (!FolderExists(folder))
		Folders.push_back(folder);
}

void Folder::DeleteFolder(Folder* folder)
{
	for (std::vector<Folder*>::iterator iter = GetFolders().begin(); iter != GetFolders().end(); ++iter)
	{
		if (*iter == folder)
		{
			GetFolders().erase(iter);
			break;
		}
	}
}

void Folder::AddFile(File* file)
{
	if (!FileExists(file))
		Files.push_back(file);
}

void Folder::DeleteFile(File* file)
{
	for (std::vector<File*>::iterator iter = GetFiles().begin(); iter != GetFiles().end(); ++iter)
	{
		if (*iter == file)
		{
			GetFiles().erase(iter);
			break;
		}
	}
}

void Folder::MoveFileTo(File* file, Folder* newFolder)
{
	newFolder->AddFile(file);
	this->DeleteFile(file);
}

bool Folder::FileExists(File* fileAddress)
	{
		size_t filePosition;
		size_t GetFilesSize = GetFiles().size();
		for (filePosition=0; filePosition < GetFilesSize; ++filePosition)
		{
			if (GetFiles().at(filePosition) == fileAddress)
			{
				return true;
			}
		}
		return false;
	}

bool Folder::FolderExists(Folder* folderAddress)
	{
		size_t folderPosition;
		size_t GetFoldersSize = GetFolders().size();
		for (folderPosition=0; folderPosition < GetFoldersSize; ++folderPosition)
		{
			if (GetFolders().at(folderPosition) == folderAddress)
			{
				return true;
			}
		}
		return false;
	}