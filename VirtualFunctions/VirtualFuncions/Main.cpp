#include <iostream>
#include "File.h"
#include "Folder.h"

int main ()
{
	ImageFile* car = new PngImageFile("lamborgini.png", 200, 300);
	std::cout << car->GetData()[0] << std::endl; // 0
	ImageFile* windowsXp = new JpgImageFile("green_hill.jpg", 100, 200);
	std::cout << windowsXp->GetData()[1] << std::endl; // 1
	TextFile* favoriteSites = new DocTextFile("bookmarks.doc");
	std::string sites = "reddit.com, omgbasinerda.bg, neshtodrugokoetonqmadaprochete.net, penisland.net";
	favoriteSites->SetContent(sites);
	favoriteSites->PrintContent(); // reddit.com, omgbasinerda.org, neshtodrugokoetonqmadaprochetete.net, penisland.net

	Folder* documents = new Folder("C:\\Documents");
	documents->AddFile(favoriteSites);
	Folder* images = new Folder("C:\\Documents\\Images");
	documents->AddFolder(images);
	images->AddFile(car);
	images->AddFile(windowsXp);

	std::cout << documents->GetFiles()[0]->GetName() << std::endl; // bookmarks.doc
	std::cout << documents->GetFolders()[0]->GetName() << std::endl; // C:\Documents\Images
	std::cout << documents->GetFolders()[0]->GetFiles()[0]->GetName() << std::endl; // lamborgini.png

	documents->MoveFileTo(favoriteSites, images);
	File* pointerToSites = documents->GetFolders()[0]->GetFiles()[2];
	TextFile* textPointerToSites = static_cast<TextFile*>(pointerToSites);
	textPointerToSites->PrintContent(); //reddit.com, omgbasinerda.org, neshtodrugokoetonqmadaprochete.net, penisland.net

	system("pause");
	return 0;
}