#include "Application.h"
#include "ModuleGhost.h"
#include "ModuleCollision.h"
#include "ModuleRender.h"

ModuleGhost::ModuleGhost(int x, int y) : position(x, y), collider(nullptr)
{}

ModuleGhost::~ModuleGhost()
{
	if(collider != nullptr)
		App->collision->EraseCollider(collider);
}

const Collider* ModuleGhost::GetCollider() const
{
	return collider;
}

void ModuleGhost::Draw(SDL_Texture* sprites)
{
	if(collider != nullptr)
		collider->SetPos(position.x, position.y);

	App->render->Blit(sprites, position.x, position.y, &(animation->GetCurrentFrame()));
}
