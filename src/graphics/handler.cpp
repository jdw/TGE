#include "handler.h"
#include "../misc/define.h"
#include "../misc/message.h"
#include "image.h"

#include <SDL/SDL.h>
#include <iostream>

using namespace t::graphics;

static t::graphics::Handler* g_pHandlerInstance = NULL;

Handler::Handler():
t::misc::interface::Handler(), m_resolutionX(0), m_resolutionY(0), m_isFullscreen(false) {
	for (int i = 0; i < 100; i++) m_pGraphics[i] = NULL;
	for (int i = 0; i < 256; i++) m_pFonts[i] = NULL;
}

Handler::~Handler() {
	delete[] m_pFonts;
	delete[] m_pGraphics;
	delete m_pScreen;
}

int Handler::setup() { START
	// initialize SDL video
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    m_pScreen = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if (!m_pScreen) {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

	try {
    m_pFonts['0'] = new Image(0, "data/fonts/0.png");
    m_pFonts['1'] = new Image(0, "data/fonts/1.png");
    m_pFonts['2'] = new Image(0, "data/fonts/2.png");
    m_pFonts['3'] = new Image(0, "data/fonts/3.png");
    m_pFonts['4'] = new Image(0, "data/fonts/4.png");
    m_pFonts['5'] = new Image(0, "data/fonts/5.png");
    m_pFonts['6'] = new Image(0, "data/fonts/6.png");
    m_pFonts['7'] = new Image(0, "data/fonts/7.png");
    m_pFonts['8'] = new Image(0, "data/fonts/8.png");
    m_pFonts['9'] = new Image(0, "data/fonts/9.png");
	} catch(std::string& i) {
		std::cout << i << std::cout;
	}
STOP }

int Handler::teardown() { START

STOP }

int Handler::update(const unsigned int& i_time) { START
	SDL_FillRect(m_pScreen, 0, SDL_MapRGB(m_pScreen->format, 0, 0, 0));

	// Draw graphics
	for (unsigned int i = 0; i < getQue()->size(); i++) {
		if (getQue()->at(i).isNull()) continue;
		if (HUD == getQue()->at(i).layer) continue;

		SDL_Rect t_rect;
		t_rect.x = getQue()->at(i).posX;
		t_rect.y = getQue()->at(i).posY;
		t_rect.h = 10;
		t_rect.w = 10;
		if (m_pGraphics[getQue()->at(i).assetId])
			SDL_BlitSurface(m_pGraphics[getQue()->at(i).assetId]->getSurface(), 0, m_pScreen, &t_rect);
		else
			std::cout << __FILE__ << __LINE__ << "found null graphics: " << (int)getQue()->at(i).layer << "," << getQue()->at(i).assetId << std::endl;
		getQue()->at(i).nullify();
	}

	// Draw HUD
	for (unsigned int i = 0; i < getQue()->size(); i++) {
		if (getQue()->at(i).isNull()) continue;
std::cout << "hud stuff "<< std::endl;
		SDL_Rect t_rect;
		t_rect.x = getQue()->at(i).posX;
		t_rect.y = getQue()->at(i).posY;
		t_rect.h = 10;
		t_rect.w = 10;
		if (m_pFonts[getQue()->at(i).assetId]) SDL_BlitSurface(m_pFonts[getQue()->at(i).assetId]->getSurface(), 0, m_pScreen, &t_rect);
		else std::cout << __FILE__ << __LINE__ << "found null graphics: " << getQue()->at(i).assetId << std::endl;
		getQue()->at(i).nullify();
	}

	SDL_Flip(m_pScreen);
STOP }

int Handler::fetch(const unsigned int& i_aid, unsigned int& i_gid) { START
	for (int i = 0; i < 100; i++)
		if (m_pGraphics[i] != NULL)
			if (m_pGraphics[i]->getID() == i_aid) {
				i_gid = i;
				return 0;
			}

	load(i_aid, i_gid);
STOP }

int Handler::load(const unsigned int& i_aid, unsigned int& i_gid) { START
	int t_pos = -1;

	for (int i = 0; i < 100; i++)
		if (NULL == m_pGraphics[i]) {
			t_pos = i;
			break;
		}

	//TODO: what to do if t_pos == -1 here?

	switch (i_aid) {
		case 1: {
			m_pGraphics[t_pos] = new Image(i_aid, "data/gfx/cb.bmp");
			i_gid = t_pos;
		} break;
		case 2: {
			m_pGraphics[t_pos] = new Image(i_aid, "data/gfx/blockgreen.bmp");
			i_gid = t_pos;
		} break;
		case 3: {
			m_pGraphics[t_pos] = new Image(i_aid, "data/gfx/blockblue.bmp");
			i_gid = t_pos;
		} break;
		case 4: {
			m_pGraphics[t_pos] = new Image(i_aid, "data/gfx/shot.png");
			i_gid = t_pos;
		} break;

		default: { std::cout << "Unhandled GFX id: " << i_gid << std::endl; i_gid = 0; } break;
	}
STOP }

Handler* Handler::instance() {
	if (NULL == g_pHandlerInstance) g_pHandlerInstance = new Handler();

	return g_pHandlerInstance;
}
