#ifndef T_MISC_MESSAGE_H
#define T_MISC_MESSAGE_H

namespace t {
	namespace misc {
		class Message {
			public:
				Message() { nullify(); }
				void nullify() { this->layer = 0; this->assetId = 0; this->posX = 0; this->posY = 0; this->posZ = 0; }
				bool isNull() {
					if (layer) return false;
					if (assetId) return false;
					if (posX) return false;
					if (posY) return false;
					if (posZ) return false;

					return  true;
				}

				char layer;
				unsigned int assetId;
				int posX, posY, posZ;
		}; // class Image
	} // namespace graphics
} // namespace t

#endif // T_MISC_MESSAGE_H
