#include "message.h"
#include "../misc/define.h"
#include "../misc/include.h"

using namespace t::input;

Message::Message() {
	/*m_up = false,
	m_right = false;
	m_down = false;
	m_left = false;
	m_a = false;
	m_b = false;
	m_start = false;
	m_select = false;
	m_mouseLeft = false;
	m_mouseRight = false;
	*/
	for (int i = 0; i < t::input::key::MAX; i++)
		m_keys[i] = 0;

	m_mouseX = 0;
	m_mouseY = 0;
}

Message::~Message() {

}

const char& Message::getKey(const t::input::key::Value i_key) const {
	return m_keys[i_key];
	/*
	switch (i_key) {
		case t::input::key::SELECT: { return m_select; } break;
		case t::input::key::START_: { return m_start; } break;
		case t::input::key::ARROW_UP: { return m_up; } break;
		case t::input::key::ARROW_RIGHT: { return m_right; } break;

		default: { std::cout << "No key defined: " << i_key << std::endl; } break;
	}

	return false;
	*/
}

int Message::setKey(const t::input::key::Value i_key, const int i_value) { START
	m_keys[i_key] = (char)i_value;
STOP }
