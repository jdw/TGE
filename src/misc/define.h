#ifndef T_DEFINE_H
#define T_DEFINE_H

/*
#include "singleton.h"
#include "graphics/frame.h"
#include "graphics/animation.h"
#include "entity/entity.h"
#include "scene/scene.h"
#include "database/databasehandler.h"
#include "entity/entityhandler.h"
#include "game.h"
*/

#define HUD 100
#define FPS 30

#ifdef DEBUG_DATABASE
//#define LOGF(f, s...) LogFile(__FILE__, __FUNCTION__, __LINE__, f, s)
//#define LOG(f) LogFile(__FILE__, __FUNCTION__, __LINE__, f)
#define START int err = 0;
//#define STOP if (err) {} else return 0;
#define STOP return err;
#define ERROR_ADD err +=
#define ERROR_INCREMENT err++;
#else
#define START
#define STOP return 0;
#define ERROR_INCREMENT
#define ERROR_ADD
#endif

#endif // T_DEFINE_H
