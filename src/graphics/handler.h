#ifndef T_GRAPHICS_HANDLER_H
#define T_GRAPHICS_HANDLER_H

#include "../misc/interface/handler.h"

class SDL_Surface;

namespace t {
	namespace graphics {
		class Handler: public t::misc::interface::Handler {
			public:
				virtual ~Handler();

				static Handler* instance();
				const unsigned int& getResolutionX() const { return this->m_resolutionX; }
				const unsigned int& getResolutionY() const { return m_resolutionY; }
				const bool& getFullscreen() const { return m_isFullscreen; }

				int setup();
				int teardown();
				int update(const unsigned int&);
				int fetch(const unsigned int&, unsigned int&);
			protected:

			private:
				Handler();

				int load(const unsigned int&, unsigned int&);

				unsigned int m_resolutionX, m_resolutionY;
				bool m_isFullscreen;
				SDL_Surface* m_pScreen;
				Image* m_pGraphics[100];
				Image* m_pFonts[256];
		}; // class Handler
	} // namespace graphics
} // namespace t

#endif // T_GRAPHICS_HANDLER_H
