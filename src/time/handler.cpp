#include "handler.h"

#include "../misc/define.h"

#include <SDL/SDL.h>

using namespace t::time;

static t::time::Handler* g_pHandlerInstance = NULL;

Handler::Handler():
t::misc::interface::Handler(),
m_started(false), m_paused(false), m_startTick(0), m_pauseTick(0) {

}

Handler::~Handler() {

}

int Handler::setup() { START

STOP }

int Handler::teardown() { START

STOP }

int Handler::update(const unsigned int& i_time) { START

STOP }

int Handler::start() { START
	m_started = true;
	m_paused = false;
	m_startTick = SDL_GetTicks();
	m_pauseTick = 0;
STOP }

int Handler::stop() { START
	m_started = false;
	m_paused = false;
STOP }

int Handler::pause(const bool i_pause) { START
	if (i_pause) { // Set the timer to paused state if not already paused
		if (m_started && !m_paused) {
			m_paused = true;
			m_pauseTick = SDL_GetTicks() - m_startTick;
		}
	}
	else { // Unpause the timer if paused
		if (m_paused) {
			m_paused = false;
			m_startTick = SDL_GetTicks() - m_pauseTick;
			m_pauseTick = 0;
		}
	}
STOP }

int Handler::getTick() { START
	if (!m_started) return 0;
	if (m_paused) return m_pauseTick;

	return SDL_GetTicks() - m_startTick;
STOP }

Handler* Handler::instance() {
	if (NULL == g_pHandlerInstance)
		g_pHandlerInstance = new Handler();

	return g_pHandlerInstance;
}
