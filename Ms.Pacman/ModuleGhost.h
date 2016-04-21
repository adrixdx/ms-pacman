#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider;

class ModuleGhost
{
protected:
	Animation* animation;
	Collider* collider;

public:
	iPoint position;

public:
	ModuleGhost();
	ModuleGhost(int x, int y);
	virtual ~ModuleGhost();

	const Collider* GetCollider() const;

	virtual void Move() {};
	virtual void Draw(SDL_Texture* sprites);
};

#endif // __ENEMY_H__