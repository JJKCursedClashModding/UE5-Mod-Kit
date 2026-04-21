#include "GameDataTableRow_Effect.h"

FGameDataTableRow_Effect::FGameDataTableRow_Effect() {
    this->PoolCount = 0;
    this->EffectType = EGameEffectType::None;
    this->Life_Time = 0.00f;
    this->Life_Distance = 0.00f;
    this->Life_Hit = 0;
    this->Collision_Priority = 0;
    this->Collision_Delay_Time = 0.00f;
    this->bThroughCharacterWallEnabled = false;
    this->bThroughCharacterEnabled = false;
    this->bThroughBackgroundEnabled = false;
    this->ThroughDestructibleObjectType = EGameEffectThroughDestructibleObjectType::None;
    this->NullifiesEffectType = EGameNullifiesEffectType::None;
    this->GroundCheckTargetType = EGameEffectGroundCheckTargetType::None;
    this->GroundCheckDistance = 0.00f;
    this->bNotControlDecalEnabled = false;
    this->DecalScale = 0.00f;
    this->ExternalForce_Time = 0.00f;
    this->ExternalForce_Strength = 0.00f;
    this->ExternalForce_Range = 0.00f;
    this->ExternalForce_FixedRange = 0.00f;
    this->ExternalForce_GravityCorrect = 0.00f;
    this->bIsEffectExternalForceEnabled = false;
    this->PushExternalForce_Time = 0.00f;
    this->PushExternalForce_Strength = 0.00f;
    this->PushExternalForce_Range = 0.00f;
    this->PushExternalForce_Height = 0.00f;
    this->PushExternalForce_HeightOffset = 0.00f;
}

