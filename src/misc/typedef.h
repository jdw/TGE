#ifndef T_MISC_TYPEDEF_H
#define T_MISC_TYPEDEF_H

//TODO: Forward declare this stuff
#include <boost/shared_ptr.hpp>
#include <vector>
#include <map>

// Class hierarcy
namespace t {
	namespace subsystem {
		enum Name {
			GRAPHICS = 0,
			PHYSICS,
			SOUND,

			MAX // Faulty
		};
	}
	namespace database { class Handler; }
	namespace entity { class Entity; class Handler; }
	namespace graphics { class Frame; class Animation; class Handler; class Image; }
	namespace input {
		namespace key {
			enum Value {
				ARROW_UP = 0, ARROW_RIGHT, ARROW_DOWN, ARROW_LEFT,
				START_, SELECT,
				R1, R2, L1, L2,
				LS, RS,
				A, B, C, D,

				MAX // Faulty
			};

			enum Action {
				PUSHED = 0,
				PUSHING,
				RELEASED,

				//MAX // Faulty
			};
		}
	}
	namespace input { class Handler; class Message; }
	namespace misc {
		namespace interface { class Handler; class Game; class Scene; }
		class Message;
	}
	namespace scene { class Handler; }
	namespace time { class Handler; }
}

// typedefs
namespace t {
	namespace entity {
		typedef boost::shared_ptr<t::entity::Entity> SPENTITY;
		typedef boost::shared_ptr<std::vector<SPENTITY> > SPENTITYS;
		//typedef boost::shared_ptr<t::entity::Handler> SPENTITYHANDLER;

	}

	namespace graphics {
		typedef boost::shared_ptr<Frame> SPFRAME;
		typedef boost::shared_ptr<Image> SPIMAGE;
		typedef boost::shared_ptr<std::vector<SPFRAME> > SPFRAMES; //TODO: Ska det vara map<pair<uns int, frame> istallet?
		typedef boost::shared_ptr<Animation> SPANIMATION;
		typedef boost::shared_ptr<std::vector<SPANIMATION> > SPANIMATIONS;
		//typedef boost::shared_ptr<t::graphics::Handler> SPGRAPHICSHANDLER;
	}

	namespace input {
		typedef boost::shared_ptr<t::input::Message> SPMESSAGE;
		//typedef boost::shared_ptr<t::input::Handler> SPINPUTHANDLER;
	}

	namespace misc {
		typedef std::vector<t::misc::Message> MSGQUE;
	}
	namespace scene {
		typedef boost::shared_ptr<t::misc::interface::Scene> SPSCENE;
		typedef boost::shared_ptr<std::vector<SPSCENE> > SPSCENES;
		//typedef boost::shared_ptr<t::scene::Handler> SPSCENEHANDLER;
	}

	namespace time {
		//typedef boost::shared_ptr<t::time::Handler> SPTIMEHANDLER;
	}
}


#endif // T_TYPEDEF_H
