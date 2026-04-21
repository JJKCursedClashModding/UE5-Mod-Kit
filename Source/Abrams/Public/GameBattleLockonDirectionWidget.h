#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "Templates/SubclassOf.h"
#include "GameBattleLockonDirectionWidget.generated.h"

class AGameBattleLockonDirectionActor;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleLockonDirectionWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGameBattleLockonDirectionActor> LockonDirectionActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ScaleOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor ActorColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EmissiveIntensity;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameBattleLockonDirectionActor* LockonDirectionActor;
    
public:
    UGameBattleLockonDirectionWidget();

    UFUNCTION(BlueprintCallable)
    void SetScaleOffset(const FVector& InScaleOffset);
    
    UFUNCTION(BlueprintCallable)
    void SetLocationOffset(const FVector& InLocationOffset);
    
    UFUNCTION(BlueprintCallable)
    void SetEmissiveIntensity(const float InEmissiveIntensity);
    
    UFUNCTION(BlueprintCallable)
    void SetActorColor(const FColor& InActorColor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetScaleOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetLocationOffset() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetEmissiveIntensity() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FColor GetActorColor() const;
    

    // Fix for true pure virtual functions not being implemented
};

