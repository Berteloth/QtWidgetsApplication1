#include "Song.h"

Song::Song()
{
	this->title = nullptr;
	this->artist = nullptr;
	this->duration.first = 0.f;
	this->duration.second = 0.f;
	this->link = nullptr;
}

Song::Song(std::string title1, std::string artist1, std::pair<int,int> duration1, std::string link1)
{
	
	this->title = title1;
	this->artist = artist1;
	this->duration.first = duration1.first;
	this->duration.second = duration1.second;
	this->link = link1;

}

std::string Song::getTitle()
{
	return this->title;
}

std::string Song::getArtist()
{
	return this->artist;
}

std::pair<int, int> Song::getDuration()
{
	return this->duration;
}

std::string Song::getLink()
{
	return this->link;
}

void Song::setTitle(std::string title1)
{
	this->title = title1;
}


void Song::setArtist(std::string artist1)
{
	this->artist = artist1;
}

void Song::setDuration(std::pair<int, int> duration1)
{
	this->duration = duration1;
}


void Song::setLink(std::string link1)
{
	this->link = link1;
}

bool Song::operator==(const Song& a) const
{
	if (this->artist == a.artist && this->title == a.title && this->duration == a.duration && this->link == a.link)
		return 1;
	return 0;
}

