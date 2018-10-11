#ifndef __j1GAMEPHYSICS_H__
#define __j1GAMEPHYSICS_H__

#include "SDL/include/SDL_rect.h"
#include "j1Module.h"
#include "p2List.h"
#include "p2Point.h"

#define MAX_COLLIDERS 600

enum COLLIDER_TYPE {
	COLLIDER_NONE = -1,
	COLLIDER_PLAYER,
	COLLIDER_WALL,
	COLLIDER_DEATH,
	COLLIDER_END,
	COLLIDER_MAX
};

struct Collider
{
	SDL_Rect rect;
	bool to_delete = false;
	COLLIDER_TYPE type;
	j1Module* callback = nullptr;


	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, j1Module* callback = nullptr) :
		rect(rectangle), 
		type(type), 
		callback(callback) 
	{ }

	bool Update();

	void setPos(int x, int y) 
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r) const;
};

class j1GamePhysics : public j1Module
{
public:

	j1GamePhysics();
	~j1GamePhysics();

	bool PreUpdate();
	bool Update(float dt);
	bool CleanUp();

	Collider* AddCollider(SDL_Rect rect, COLLIDER_TYPE type, j1Module* callback = nullptr);
	bool EraseCollider(Collider* collider);
	void DebugDraw();

	bool debug = false;

private:

	Collider * colliders[MAX_COLLIDERS];
	bool matrix[COLLIDER_MAX][COLLIDER_MAX];

};

extern j1GamePhysics* collision;
#endif