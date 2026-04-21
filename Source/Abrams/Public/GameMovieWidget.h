#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameMovieWidget.generated.h"

class AGameMovieActor;
class UFileManaMovie;
class UImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameMovieWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* MovieImage;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFileManaMovie* FileManaMovie;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameMovieActor* MovieActor;
    
public:
    UGameMovieWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnClosedMovie();
    
};

