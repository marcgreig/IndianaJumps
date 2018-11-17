#ifndef __j1BIRD_H__
#define __j1BIRD_H__

#include "j1EntityManager.h"
#include "j1Entity.h"
#include "j1Pathfinding.h"
#include "j1Textures.h"
#include "Animation.h"
#include "p2Point.h"
#include "p2DynArray.h"



struct SDL_Texture;
//struct Collider;

class j1Bird : public j1Entity
{
public:
	j1Bird(int x, int y, ENTITY_TYPES type);

	virtual ~j1Bird();

	bool Awake(pugi::xml_node&);
	bool Start();
	bool Update(float dt);
	bool CleanUp();

	void OnCollision(Collider* c1, Collider* c2);
	void CheckCollision();

	//bool Load(pugi::xml_node&);
	//bool Save(pugi::xml_node&) const;

	//void Move(p2DynArray<iPoint>& path, float dt);

public:

	Animation fly_left;
	Animation fly_right;

public:
	fPoint initialPosition;

	iPoint margin;
	iPoint colliderSize;

	uint c = 0;

	bool move = false;
	bool die = false;

	bool path_created = false;

};
#endif // __j1HARPY_H__