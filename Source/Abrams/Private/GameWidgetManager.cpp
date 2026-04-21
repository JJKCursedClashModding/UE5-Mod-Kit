#include "GameWidgetManager.h"
#include "Components/SceneComponent.h"

AGameWidgetManager::AGameWidgetManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    this->RichTextStyleData = NULL;
    this->CommonDecorator = NULL;
    this->TimeParameterCollection = NULL;
    this->CharacterCaptureActorBP = NULL;
    this->ExchangeImageParameter = NULL;
    this->CaptureParameter = NULL;
    this->KeyRepeatParameter = NULL;
    this->DynamicIconParameter = NULL;
    this->CharacterParameter = NULL;
    this->FontParameter = NULL;
    this->StoryDemoParameter = NULL;
    this->ConfigParameter = NULL;
    this->TextScrollParameter = NULL;
}


