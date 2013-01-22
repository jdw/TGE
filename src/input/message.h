#ifndef T_INPUT_MESSAGE_H
#define T_INPUT_MESSAGE_H

#include "../misc/typedef.h"

namespace t {
	namespace input {
		class Message {
			public:
				Message();
				~Message();
				const char& getKey(const t::input::key::Value) const;
				int setKey(const t::input::key::Value, const int); //TODO: Friend class input::Handler

			protected:
			private:
			//TODO: Some bitshifting here? Right?
				bool m_up, m_right, m_down, m_left;
				bool m_a, m_b;
				bool m_start, m_select;

				// Mouse
				bool m_mouseLeft, m_mouseRight;
				int m_mouseX, m_mouseY;
				// How do scroll wheel?

				char m_keys[t::input::key::MAX];
		};
	}
}
#endif
