#ifndef T_MISC_INTERFACE_HANDLER_H
#define T_MISC_INTERFACE_HANDLER_H

#include "../typedef.h"
#include "../message.h"


namespace t {
	namespace misc {
		namespace interface {
			class Handler {
				public:
					virtual ~Handler() {
					}

					virtual int setup() = 0;
					virtual int teardown() = 0;
					virtual int update(const unsigned int&) = 0;
					t::misc::MSGQUE* getQue() { return m_pQue; }
				protected:
					Handler() { m_pQue = new t::misc::MSGQUE(); }

				private:
					t::misc::MSGQUE* m_pQue;

			};
		}
	}
}

#endif // T_MISC_INTERFACE_HANDLER_H
