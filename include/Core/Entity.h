#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <unordered_map>

#include "Render/Sprite.h"

class Entity
{
	public:
	Entity();
	virtual ~Entity();

/**
 * @brief Add a child to this entity
 * 
 * @param child 
 * @param name 
 */
	void AddChild(Entity* child, std::string name);

	/**
	 * @brief Get the Child entity by name
	 * 
	 * @param name 
	 * @return Entity* 
	 */
	Entity* GetChild(std::string name);

	/**
	 * @brief Remove a child entity by name
	 * 
	 * @param name 
	 */
	void RemoveChild(std::string name);

	/**
	 * @brief Remove all child entities
	 * 
	 */
	void RemoveAllChildren();

/**
 * @brief Update the entity
 * @note This calls update on **ALL** children
 * 
 * @param delta 
 */
	virtual void Update(float delta);

	/**
	 * @brief Render the sprite
	 * @note This calls render on **ALL** children
	 * 
	 */
	virtual void Render();

/**
 * @brief Set the Position 
 * 
 * @param position 
 */
	void SetPosition(Vec2 position);

	/**
	 * @brief Set the Scale
	 * 
	 * @param scale 
	 */
	void SetScale(Vec2 scale);

	/**
	 * @brief Set the Sprite
	 * 
	 * @param sprite 
	 */
	void SetSprite(Sprite sprite);

	protected:
	/**
	 * @brief Update child entities
	 * 
	 * @param delta 
	 */
		void UpdateChildren(float delta);

		/**
		 * @brief Render child entities
		 * 
		 */
		void RenderChildren();
		std::unordered_map<std::string, Entity*> children;

	private:
		Sprite sprite;
		Vec2 position;
		Vec2 scale;
};

#endif