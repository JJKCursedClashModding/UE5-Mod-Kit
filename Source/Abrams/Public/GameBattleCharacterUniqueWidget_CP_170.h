#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameBattleCharacterUniqueWidget.h"
#include "GameBattleCharacterUniqueWidget_CP_170.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleCharacterUniqueWidget_CP_170 : public UGameBattleCharacterUniqueWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor IconEnabledColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor IconDisabledColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BulletImage1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BulletImage2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BulletImage3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BulletImage4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BulletImage5;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BulletImage6;
    
public:
    UGameBattleCharacterUniqueWidget_CP_170();

};

