#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameArcadeRootInfoWidget.generated.h"

class UGameArcadeRootInfoMissionDetailWidget;
class UGameArcadeRootInfoMissionWidget;
class UGameArcadeRootInfoProgressBarWidget;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameArcadeRootInfoWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoMissionWidget* Mission_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoMissionWidget* Mission_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoMissionWidget* Mission_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoMissionWidget* Mission_4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoMissionWidget* Mission_5;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoMissionDetailWidget* MissionDetail_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoMissionDetailWidget* MissionDetail_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoMissionDetailWidget* MissionDetail_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoMissionDetailWidget* MissionDetail_4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoMissionDetailWidget* MissionDetail_5;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoProgressBarWidget* ProgressBar_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoProgressBarWidget* ProgressBar_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoProgressBarWidget* ProgressBar_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoProgressBarWidget* ProgressBar_4;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UTexture2D*> DynamicLoadTextureMap;
    
public:
    UGameArcadeRootInfoWidget();

};

