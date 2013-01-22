#include "handler.h"
#include "message.h"
#include "../misc/define.h"
#include <SDL/SDL.h>

#include <iostream>

using namespace t::input;

static t::input::Handler* g_pHandlerInstance = NULL;

Handler::Handler():
t::misc::interface::Handler() {
	m_pMessage = NULL;
}

Handler::~Handler() {

}

int Handler::setup() { START

STOP }

int Handler::teardown() { START

STOP }

int Handler::update(const unsigned int& i_time) { START
	SDL_Event t_event;
	if (m_pMessage == NULL) { ERROR_INCREMENT }
	else {
		while (SDL_PollEvent(&t_event)) {
			if(t_event.type == SDL_KEYDOWN) {
				switch(t_event.key.keysym.sym) {
					case SDLK_ESCAPE: { m_pMessage->setKey(t::input::key::SELECT, 1); } break;
					case SDLK_RETURN: { m_pMessage->setKey(t::input::key::START_, 1); } break;
					case SDLK_UP: { m_pMessage->setKey(t::input::key::ARROW_UP, 1); } break;
					case SDLK_RIGHT: { m_pMessage->setKey(t::input::key::ARROW_RIGHT, 1); } break;
					case SDLK_DOWN: { m_pMessage->setKey(t::input::key::ARROW_DOWN, 1); } break;
					case SDLK_LEFT: { m_pMessage->setKey(t::input::key::ARROW_LEFT, 1); } break;
					case SDLK_SPACE: { m_pMessage->setKey(t::input::key::A, 1); } break;
					default: { std::cout << __FILE__ << __LINE__ << "Unhandled key: " << t_event.key.keysym.sym << std::endl; } break;
				}
			}
		}
	}

STOP }

int Handler::setMessage(t::input::Message* i_pMessage) { START
	//TODO: Check ptr and other stuff
	m_pMessage = i_pMessage;
STOP }

Handler* Handler::instance() {
	if (NULL == g_pHandlerInstance) g_pHandlerInstance = new Handler();

	return g_pHandlerInstance;
}
