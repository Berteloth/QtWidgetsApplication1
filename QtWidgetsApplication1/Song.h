#pragma once
#include "QtWidgetsApplication1.h"
#include <iostream>
class Song
{
private:
	std::string title;
	std::string artist;
	std::pair<int, int>duration;
	std::string link;
public:
	Song();
	~Song() = default;
	Song(std::string title1, std::string artist1, std::pair<int,int> duration1, std::string link1);
	std::string getTitle();
	std::string getArtist();
	std::pair<int, int> getDuration();
	std::string getLink();
	
	void setTitle(std::string title1);
	void setArtist(std::string artist1);
	void setDuration(std::pair<int,int> duration1);
	void setLink(std::string link1);

	bool operator==(const Song& a) const;
};

