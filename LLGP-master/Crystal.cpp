#include "Crystal.h"
#include "CircleCollider.h"
namespace LLGP {
	Crystal::Crystal() {
		transform = AddComponent<Transform>();
		spriteRenderer = AddComponent<SpriteRenderer>();
		AddComponent<CircleCollider>()->SetRadius(7);
		spriteRenderer->LoadTexture("assets/sprites/EXTRA_LIFE.png");
		spriteRenderer->GetSprite()->setScale({ 2.f, 2.f });
	}
}
