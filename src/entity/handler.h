#ifndef T_ENTITY_HANDLER_H
#define T_ENTITY_HANDLER_H

#include "../misc/interface/handler.h"

//TODO: Make singleton?

namespace t {
	namespace entity {
		class Handler: public t::misc::interface::Handler {
			public:
				~Handler();

				static Handler* instance();
				int setup();
				int teardown();
				int update(const unsigned int&);
				int fetch(const unsigned int, SPENTITY&);
			protected:

			private:
				Handler();
				int load(const unsigned int);

				std::map<unsigned int, SPENTITY>* m_pEntitys;
				//std::map<unsigned int, SPPFXENT>* m_pPhysics;
				//std::map<unsigned int, SPGFXENT>* m_pGraphics;
				//std::vector<boost::shared_ptr<Animation> > m_animations;
		}; // class EntityHHandler
		//typedef boost::shared_ptr<t::entity::Handler> SPENTITYHANDLER;
	} // namespace handler
} // namespace t

#endif // ENTITYHANDLER_H
