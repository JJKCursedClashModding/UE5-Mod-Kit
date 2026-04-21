#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameLicenseLanguageSelectWidget.generated.h"

class UGameLicenseListView;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLicenseLanguageSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameLicenseListView* LicenseListView;
    
public:
    UGameLicenseLanguageSelectWidget();

};

