#ifndef T_TIME_HANDLER_H
#define T_TIME_HANDLER_H

#include "../misc/interface/handler.h"

namespace t {
	namespace time {
		class Handler: public t::misc::interface::Handler {
			public:
				Handler();
				~Handler();

				static Handler* instance();
				int setup();
				int teardown();
				int update(const unsigned int&);

				int getTick();
				int started() { return m_started; }
				int paused() { return m_paused; }

				int pause(bool);
				int start();
				int stop();
				//void isRunning();
			protected:

			private:
				bool m_started;
				bool m_paused;
				int m_startTick;
				int m_pauseTick;
				//static Handler* m_pInstance;
		};
	}
}

#endif
