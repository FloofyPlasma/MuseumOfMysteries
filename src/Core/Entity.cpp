#include "Core/Entity.h"

Entity::Entity() { }

Entity::~Entity() { }

void Entity::AddChild(Entity* child, std::string name)
{ 
	if (this->children.count(name) == 0)
	{
		this->children[name] = child;
	}
	else
	{
		// TODO: Error(?)
		// We already have a child with this name
	}
}

Entity* Entity::GetChild(std::string name) { return this->children[name]; }

void Entity::RemoveChild(std::string name) { this->children.erase(name); }

void Entity::RemoveAllChildren() { this->children.clear(); }

void Entity::UpdateChildren(float delta)
{
	for (auto& child : this->children)
	{
		child.second->Update(delta);
	}
}

void Entity::RenderChildren()
{
	for (auto& child : this->children)
	{
		child.second->Render();
	}
}


void Entity::Update(float delta) 
{
	this->UpdateChildren(delta);
 }


void Entity::Render()
{
	this->sprite.Draw(this->position, this->scale);
	this->RenderChildren();
}

void Entity::SetPosition(Vec2 position) { this->position = position; }

void Entity::SetScale(Vec2 scale) { this->scale = scale; }

void Entity::SetSprite(Sprite sprite) { this->sprite = sprite; }