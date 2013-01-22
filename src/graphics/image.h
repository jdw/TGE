#ifndef T_GRAPHICS_IMAGE_H
#define T_GRAPHICS_IMAGE_H

#include "../misc/define.h"
#include "../misc/include.h"

class SDL_Surface;

namespace t {
	namespace graphics {
		class Image {
			public:
				Image();
				Image(unsigned int, const std::string);
				~Image();

				const unsigned int getID() const { return m_id; }
				SDL_Surface* getSurface() const;

				Image operator=(const Image&);
			protected:
			private:
				/*const */unsigned int m_id;
				SDL_Surface* m_pSurface;
				unsigned int m_refCount;
		}; // class Image
		//typedef boost::shared_ptr<Frame> SPIMAGE;
		//typedef boost::shared_ptr<std::vector<SPIMAGE> > SPIMAGES;
	} // namespace graphics
} // namespace t

#endif // T_GRAPHICS_IMAGE_H
