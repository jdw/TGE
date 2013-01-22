#include "image.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "../misc/define.h"
#include "../misc/include.h"

using namespace t::graphics;

Image::Image()
: m_id(0), m_pSurface(NULL), m_refCount(0) {

}

Image::Image(unsigned int in_id, const std::string i_file)
: m_id(in_id), m_refCount(0) {
	this->m_pSurface = IMG_Load(i_file.c_str());
	if (!this->m_pSurface)
		throw "m_pSurface not loaded correctly: " + i_file;
	this->m_pSurface->refcount = 1;
}

Image::~Image() {
	if (m_pSurface)
		if (0 >= --m_pSurface->refcount) delete m_pSurface;
}

SDL_Surface* Image::getSurface() const {
	return m_pSurface;
}

Image Image::operator=(const Image& i_img) {
	this->m_pSurface = i_img.getSurface();
	this->m_pSurface->refcount++;
 	this->m_id = i_img.getID();

	return *this;
}
