#ifndef T_INPUT_HANDLER_H
#define T_INPUT_HANDLER_H

#include "../misc/interface/handler.h"
#include "../misc/typedef.h"

namespace t {
	namespace input {
		class Handler: public t::misc::interface::Handler {
			public:

				~Handler();

				static Handler* instance();
				int setup();
				int teardown();
				int update(const unsigned int&);

				int setMessage(t::input::Message*); //TODO: Friend class to game?
			protected:

			private:
				Handler();
				t::input::Message* m_pMessage;
		}; // class Handler
	} // namespace input
} // namespace t

#endif
