#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"

namespace Enemy
{
    class EnemyView;
    class EnemyModel;

    enum class EnemyType;
    enum class EnemyState;

    public:
    void fireFrostBeam();  //modify the classes representing different enemy types to enable them to fire their respective types of bullets with delays between each shot.

    class EnemyController : public Collision::ICollider
    {
    protected:
        float vertical_movement_speed = 30.f;
        float horizontal_movement_speed = 200.0f;

        float rate_of_fire = 3.f;
        float elapsed_fire_duration = 0.f;

        int reward = 1;

        EnemyView* enemy_view;
        EnemyModel* enemy_model;

        virtual void move() = 0;

        sf::Vector2f getRandomInitialPosition();
        void handleOutOfBounds();
        virtual void destroy();
       
    public:
        EnemyController(EnemyType type);
        virtual ~EnemyController();

        virtual void initialize();
        void update();
        void render();

        sf::Vector2f getEnemyPosition();
        EnemyState getEnemyState();
        EnemyType getEnemyType();

        const sf::Sprite& getColliderSprite() override;
        virtual void onCollision(ICollider* other_collider) override;

        virtual void processScore();
    };
}
void Enemy::fireFrostBeam() {
    // Check if enough time has passed since the last beam was fired
    if (/* Check delay condition */) {
        // Create and spawn a frost beam
        // Add the beam to the game world
        // Reset the firing delay timer
    }
}
